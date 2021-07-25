#include "list.h"

// 任务控制块结构体
typedef struct tskTaskControlBlock {
	volatile StackType_t *pxTopOfStack; //栈顶
	ListItem_t xStateListItem; //任务节点
	StackType_t *pxStack; //任务栈起始地址
	char pcTaskName[configMAX_TASK_NAME_LEN];//任务名称
} tskTCB;
typedef tskTCB TCB_t;


// 定义任务栈
#define TASK1_STACK_SIZE			20
StackType_t Task1Stack[TASK1_STACK_SIZE];
#define TASK2_STACK_SIZE			20
StackType_t Task2Stack[TASK2_STACK_SIZE];


// 定义任务控制块
TCB_t Task1TCB;
TCB_t Task2TCB;


// 定义任务句柄
typedef void * TaskHandle_t;
TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;


// 定义当前正在运行的任务控制块
TCB_t * volatile pxCurrentTCB = NULL;


############################################################
### main.c
############################################################
int main(void)
{	// 初始化任务列表
	prvInitialiseTaskLists();
	
	// 创建任务1
	Task1_Handle = xTaskCreateStatic(
			Task1_Entry,		//任务函数
			"Task1",		//任务名称
			TASK1_STACK_SIZE,	//任务栈大小 
			NULL,			//任务参数
			Task1Stack,		//任务栈起始地址
			&Task1TCB);		//任务控制块指针
	// 核心函数是 vListInsert(), 将任务控制块的列表项插入到就绪列表中
	vListInsert(&pxReadyTasksLists[1], &Task1TCB.xStateListItem);
	
	// 创建任务2
	Task2_Handle = xTaskCreateStatic(
			Task2_Entry,		//任务函数
			"Task2",		//任务名称
			TASK1_STACK_SIZE,	//任务栈大小 
			NULL,			//任务参数
			Task2Stack,		//任务栈起始地址
			&Task2TCB);		//任务控制块指针
	// 核心函数是 vListInsert(), 将任务控制块的列表项插入到就绪列表中
	vListInsert(&pxReadyTasksLists[1], &Task1TCB.xStateListItem);
	
	// 启动任务调度器
	vTaskStartScheduler();

}


// 定义任务函数 1
void Task1_Entry(void *p_arg)
{
	for (;;) {
		flag1 = 1;
		delay(100);
		flag1 = 0;
		delay(100);
		taskYIELD();
	}
}
// 定义任务函数 2
void Task2_Entry(void *p_arg)
{
	for (;;) {
		flag2 = 1;
		delay(100);
		flag2 = 0;
		delay(100);
		taskYIELD();
	}
}
############################################################
###  // 静态任务创建函数
############################################################
TaskHandle_t xTaskCreateStatic(
	TaskFunction_t pxTaskCode,		//任务入口
	const char * const pcName,		//任务名称
	const uint32_t ulStackDepth,		//任务栈大小
	void * const pvParameters,		//任务形参
	StackType_t * const puxStackBuffer,	//任务栈起始地址
	TCB_t * const pxTaskBuffer)		//任务控制块指针
{
	TCB_t *pxNewTCB;
	TaskHandle_t xReturn;
	
	if ((pxTaskBuffer != NULL) && (puxStackBuffer != NULL)) {
		pxNewTCB = (TCB_T*)pxTaskBuffer;
		pxNewTCB->pxStack = (StackType_t *)puxStackBuffer;
		
		//创建新的任务
		prvInitialiseNewTask(pxTaskCode,//任务入口
				pcName,		//任务名称
				ulStackDepth,	//任务栈大小 
				pvParameters,	//任务形参
				&xReturn,	//任务句柄
				pxNewTCB);	//任务栈起始地址
	} else {
		xRetrun = NULL;
	}
	
	//返回任务句柄，如果任务创建成功，此时xRetrun应该指向任务控制块
	return xReturn;
	
}

// 初始化新的任务
static void prvInitialiseNewTask(
	TaskFunction_t pxTaskCode,		//任务入口		
	const char * const pcName,		//任务名称
	const uint32_t ulStackDepth,		//任务栈大小
	void * const pvParameters,		//任务参数
	TaskHandle_t * const pxCreatedTask,	//任务句柄
	TCB_t *pxNewTCB)			//任务控制块指针
{
	StackType_t *pxTopOfStack;
	UBaseType_t x;
	
	//获取栈顶指针
	pxTopOfStack = pxNewTCB->pxStack + (ulStackDepth - (uint32_t)1);
	//向下做8字节对齐
	pxTopOfStack = (StackType_t *)(((uint32_t)pxTopOfStack) & (~((uint32_t)0x0007)));
	
	//将任务的名称存储在TCB中
	for (x = (UBaseType)0; x < (UBaseType_t)configMAX_TASK_NAMe_LEN; x++) {
		pxNewTCB->pcTaskName[x] = pcName[x];
		
		if (pcName[x] == 0x00)
			break;
	}
	
	//任务名字的长度不能超过configMAX_TASK_NAME_LEN
	pxNewTCB->pcTaskName[configMAX_TASK_NAME_LEN - 1] = "\0";
	
	//初始化TCB中的“xStateListItem节点”
	vListInitialiseItem(&(pxNewTCB->xStateListItem));
	
	//设置“xStateListItem节点”的拥有者
	listSET_LIST_ITEM_OWNER(&(pxNewTCB->xStateListItem), pxNewTCB);
	
	//初始化任务栈
	pxNewTCB->pxTopOfStack = pxPortInitialiseStack(pxTopOfStack, pxTaskCode, pvParameters);
	
	//让任务句柄指向任务控制块
	if ((void *)pxCreatedTask != NULL)
		*pxCreatedTask = (TaskHandle_t)pxNewTCB;
}

// 初始化任务栈
StackType_t *pxPortInitialiseStack(
	stackType_t *pxTopOfStack, 
	TaskFunction_t pxCode,
	void *pvParameters)
{
	//异常发生时， 自动加载到CPU寄存器的内容
	pxTopOfStack--;
	// xPSR的bit24必须置“1”
	*pxTopOfStack = portINITIAL_XPSR;
	pxTopOfStack--;
	// 任务入口函数 PC
	*pxTopOfStack = ((StackType_t)pxCode) & portSTART_ADDRESS_MASK;
	pxTopOfStack--;
	// 函数返回地址
	*pxTopOfStack = (StackType_t)prvTaskExitError;
	// r12, r3, r2, r1 默认初始化为“0”
	pxTopOfStack -= 5;
	// r0, 任务形参
	*pxTopOfStack = (StackType_t)pvParameters;
	
	
	//异常发生时， 手动加载到CPU寄存器的内容
	// r11, r10, r9, r8, r7, r6, r5, r4
	pxTopOfStack -= 8;
	//返回栈顶指针，此时pxTopOfStack指向空闲栈
	return pxTopOfStack;
}


############################################################
### % 调度器启动函数
############################################################
//启动任务调度器
BaseType_t xPortStartScheduler(void)
{
	//配置PendSV和SysTick的中断优先级为最低
	portNVIC_SYSPRI12_REG |= portNVIC_PENDSV_PRI;
	portNVIC_SYSPRI12_REG |= portNVIC_SYSTICK_PRI;
	
	// 启动第一个任务，不在返回
	prvStartFirstTask();
	
	// 不应该运行到这里
	return 0;
}

// 启动第一个任务
__asm void prvStartFirstTask(void)
{
	PRESERVVE8
	
	// 0xE000ED08是SCB_VTOR这个寄存器的地址
	// 里面存放的是向量表的起始地址，即MSP的地址
	ldr r0, =0xE000ED08
	ldr r0, [r0]	// r0=0x00000000
	ldr r0, [r0]
	
	// 设置主堆栈指针的值
	msr msp, r0
	
	// 使能全局中断
	cpsie i
	cpsie f
	dsb
	isb
	
	// 调用SVC去启动第一个任务
	svc 0
	nop
	nop
}

// 调用SVC_Handler异常
__asm void vProtSVCHandler(void)
{
	extern pxCurrentTCB;
	PRESERVE8
	
	ldr r3, =pxCurrentTCB; //加载 pxCurrentTCB的地址到r3
	ldr r1, [r3]  //加载 pxCurrentTCB到r1
	ldr r0, [r1] //加载 加载 pxCurrentTCB指向的值到r0，目前r0的值等于第一个任务堆栈的栈顶
	ldmia r0!, {r4-r11}//以r0为基址，将栈里面的内容加载到r4-r11寄存器，同时r0会递增
	msr psp, r0//将r0的值，即任务的栈指针更新到psp
	isb
	mov r0, #0 //设置r0的值为“0”
	msr basepri, r0 //设置basepri寄存器的值为“0”，即所有的中断都没有屏蔽
	//当从SVC中断服务退出前，通过向r14寄存器最后4位按位或上 0x0D，
	//使得硬件在退出时使用进程堆栈指针psp完成出栈操作并返回后进入线程模式，返回Thumb状态。
	orr r14, #0xd
	
	//异常返回，这个时候栈中的剩下内容将会自动加载到CPU寄存器
	//xPSR, PC（任务入口地址）, r14, r12, r3, r2, r1, r0
	//同时PSP的值也将更新，即指向任务栈的栈顶
	bx r14
}



#define xPortPendSVHandler	PendSV_Handler
#define xPortSysTickHandler	SysTick_Handler
#define xPortSVCHandler		SVC_Handler


// 任务切换函数： taskYIELD()
// 任务切换就是在就绪列表中寻找优先级最高的就绪任务，然后去执行该任务。
// portYIEDL的实现很简单，实际就是将PendSV的悬起位置“1”，
当没有其它中断运行的时候响应PendSV中断，去执行我们写好的PendSV中断服务函数
在里面实现任务的切换。
// 中断控制状态寄存器： 0xe00ed04
// Bit28 PENDSVSET: PendSV悬起位
#define protNVIC_INT_CTRL_REG (*((volatile uint32_t *)0xE000ED04))
#define portNVIC_PENDSVSET_BIT (1UL << 28UL)
#define portSY_FULL_READ_WRITE (15)
#define protYIELD()					\
{							\
	// 触发PendSV，产生上下文切换			\
	protNVIC_INT_CTRL_REG = protNVIC_PENDSVSET_BIT;	\
	__dsb(protSY_FULL_READ_WRITE);			\
	__isb(protSY_FULL_READ_WRITE);			\
}


// 调用PendSV_Handler异常
__asm void xPortPendSVHandler(void)
{
	extern pxCurrentTCB;
	extern xTaskSwitchContext;
	PRESERVE8
	// 当进入PendSVC_Handler时，上一个任务运行的环境即：
	// xPSR, PC(任务入口地址), R14, R12, R3, R2, R1, R0(任务形参)，
	// 这些CPU寄存器的值会自动保存到任务的栈中，剩下的 R4~R11需要手动保存
	
	// 获取任务栈指针到R0
	mrs r0, psp
	isb
	
	// 加载pxCurentTCB的地址到r3
	ldr r3, =pxCurrentTCB
	// 加载pxCurentTCB到r2
	ldr r2, [r3]
	
	// 将CPU寄存器R4~R11的值存储到R0指向的地址
	stmdb r0!, {r4-r11}
	// 将任务的栈的新的栈顶指针存储到当前任务TCB的第一个成员，即栈顶指针
	str r0, [r2]
	
	//将R3和R14压入堆栈，因为即将调用函数vTaskSwitchContext,
	//调用函数时，返回地址自动保存到R14中。所以一旦调用发生，R14的值会被覆盖，
	//因些需要入栈保护；R3保存的是当前激活的任务TCB指针(pxCurrentTCB)地址，
	//函数调用后会用到，因些要入栈保护。
	stmdb sp!, {r3, r14}
	
	// 进入临界段
	mov r0, #configMAX_SYSCALL_INTERRUPT_PRIORITY
	msr basepri, r0
	dsb
	isb
	// 调用vTaskSwitchCintext,寻找新的任务运行，
	// 通过使用变量pxCurrentTCB指向新的任务来实现任务切换
	bl vTaskSwitchContex
	//退出临界段
	mov r0, #0
	msr basepri, r0
	//恢复r3和r14
	ldmia sp!, {r3, r14}
	
	//当前激活的任务TCB第一项保存了任务堆栈的栈顶，现在栈顶值存入R0
	ldr r1, {r3}
	ldr r0, {r1}
	ldmia r0!, {r4-r11}
	msr psp, r0
	isb
	
	//异常发生时，R14中保存异常返回标志，包括返回后进入线程模式还是处理器模式，
	//使用的是PSP堆栈指针还是MSP堆栈指针，当调用 bx r14指令后，硬件会知道要从异常返回
	//然后出栈，这个时候堆栈指针PSP已经指向了新任务堆栈的正确位置，
	//当新任务的运行地址被出栈到PC寄存器后，新的任务也会被执行。
	bx r14
}

//两个任务轮流切换
void vTaskSwitchContext(void)
{
	if (pxCurrentTCB == &Task1TCB)
		pxCurrentTCB = &Task2TCB;
	else
		pxCurrentTCB = &Task1TCB;
}


############################################################
### % 就绪列表
############################################################
// 就绪列表实际上就是一个 List_t类型的数组，数组的大小由决定最大任务
// 优先级的宏configMAX_PRIORITIES决定
List_t pxReadyTasksLists[configMAX_PRIORITIES];


// 初始化任务相关的列表
void prvInitialiseTaskLists(void)
{
	UBaseType_t uxPriority;
	
	for (uxPriority = (UBaseType_t)0U; 
	uxPriority < (UBaseType_t)configMAX_PRIORITIES;
	uxPriority++)
		vListInitialise(&(pxReadyTaskLists[uxPriority]));
}


// 将任务插入到就绪列表中
任务控制块里面有一个xStateListItem成员，数据类型为 ListItem_t,
我们将任务插入到就绪列表里面，就是通过将任务控制块的ListItem_t
这个节点插入到就绪列表中来实现的。



// 启动任务调度
void vTaskStartScheduler(void)
{
	//手动指定第一个运行的任务
	pxCurentTCB = &Task1TCB;
	
	//启动调度器
	if (xPortStartScheduler() != pdFALSE) {
	//调度器启动成功，同不会返回， 即不会运行到这里。
	}
	
}


