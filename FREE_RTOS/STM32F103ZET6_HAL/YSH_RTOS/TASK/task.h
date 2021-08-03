#ifndef __TASK_H__
#define __TASK_H__
#include "stm32f1xx_hal.h"
#include "list.h"


#define INITIAL_XPSR			(0x01000000)
#define START_ADDESS_MASK		((uint32_t)(0xfffffffeUL))

/* 定义任务栈 */
#define task1_stack_size		128
uint32_t task1_stack[task1_stack_size];

#define task2_stack_size		128
uint32_t task2_stack[task2_stack_size];

#define MAX_TASK_NAME_LEN		16



/* 定义任务控制块 */
struct task_control_block {
	volatile uint32_t 	*top_stack;			//栈顶指针
	list_item_t 		state_list_item;		//任务节点
	uint32_t 		*stack;				//任务栈起始地址
	char 			*name[MAX_TASK_NAME_LEN];	//任务名称
};
typedef struct task_control_block tcb_t;



/* 定义数据类型 */
tcb_t task1_tcb;
tcb_t task2_tcb;
typedef void *task_handle_t;
typedef void (*task_function_t)(void *);

task_handle_t task_create(
	task_function_t 	task_entry,		//任务入口
	const char * const 	task_name,		//任务名称
	const uint32_t 	task_stack_size,	//任务栈大小
	void * const 		task_parameter,		//任务形参
	uint32_t * const 	task_stack_addr,	//任务栈起始地址
	tcb_t * const 		tcb_ptr);		//任务控制块指针

#endif
