#include "task.h"

/* 创建任务 */
task_handle_t task_create(
	task_function_t 	task_entry,		//任务入口
	const char * const 	task_name,		//任务名称
	const uint32_t 	task_stack_size,	//任务栈大小
	void * const 		task_parameter,		//任务形参
	uint32_t * const 	task_stack_addr,	//任务栈起始地址
	tcb_t * const 		tcb_ptr)		//任务控制块指针
{
	tcb_t *new_tcb;
	//定义一个任务句柄task_handle，任务句柄用于指向任务的TCB
	task_handle_t task_handle;
	
	if ((task_stack_addr != NULL) && (new_tcb != NULL)) {
		new_tcb = (tcb_t *)tcb_ptr;
		new_tcb->stack = (uint32_t *)task_stack_addr;
	
		//任务初始化
		task_initialize(
			task_entry,		//任务入口
			task_name,		//任务名称
			task_stack_size,	//任务栈大小
			task_parameter,		//任务形参
			&task_handle,		//任务句柄
			new_tcb);		//任务控制块指针
		
	} else {
		task_handle = NULL;
	}
	
	/* 返回任务句柄，如果任务创建成功，此时 task_handle 应该指向任务控制块 */
	return task_handle;
}

/* 任务初始化 */
static void task_initialize(
	task_function_t 	task_entry,	//任务入口
	const char * const 	task_name,	//任务名称
	const uint32_t 	task_stack_size,//任务栈大小
	void * const 		task_parameter,	//任务形参
	task_handle_t * const 	task_handle,	//任务句柄
	tcb_t *			new_tcb)	//任务控制块指针
{
	uint32_t *top_stack;
	uint32_t x;
	
	//获取栈顶指针
	top_stack = new_tcb->stack + (task_stack_size - (uint32_t)1);
	//向下做8字节对齐
	top_stack = (uint32_t *)(((uint32_t)top_stack) & (~((uint32_t)0x0007)));
	//将任务的名字存储在TCB(任务控制块)中
	for (x = (uint32_t)0; x < (uint32_t)MAX_TASK_NAME_LEN; x++) {
		new_tcb->name[x] = task_name[x];
		if (task_name[x] == 0x00)
			break;
	}
	//任务名字长度不能超过MAX_TASK_NAME
	new_tcb->name[MAX_TASK_NAME - 1] = '\0';
	
	//初始化TCB中的state_list_item节点
	list_item_initialize(&(new_tcb->state_list_item));
	//设置state_list_item节点的拥有者
	SET_LIST_ITEM_OWNER(&(new_tcb->state_list_item), new_tcb);
	
	//初始化任务栈
	new_tcb->top_stack = task_stack_initialize(
		top_stack,
		task_entry,
		task_parameter);
	//让任务句柄指向任务控制块
	if ((void *)task_handle != NULL)
		*task_handle = (task_handle_t)new_tcb;
}

static void task_exit_error(void)
{
	for (;;);
}


/* 任务栈初始化 */
uint32_t *task_stack_initialize(
	uint32_t *top_stack,
	task_function_t task_entry,
	void *task_parameter)
{
	//异常发生时，自动加载到CPU寄存器的内容
	top_stack--;
	//xPSR的bit24必须置1，即0x01000000
	*top_stack = INITIAL_XPSR;
	top_stack--;
	//任务的入口地址
	*top_stack = ((uint32_t)task_entry) & START_ADDRESS_MASK;
	top_stack--;
	//任务的返回地址，通常任务是不会返回的，如果返回了就跳转到task_exit_error， 
	//该函数是一个无限循环
	*top_stack = (uint32_t)task_exit_error;
	//R12, R3, R2 and R1 默认初始化为0
	top_stack -= 5;
	*top_stack = (uint32_t)task_parameter;
	
	//异常发生时，手动加载到CPU寄存器的内容
	top_stack -= 8;
	
	//返回栈顶指针
	return top_stack;
}
