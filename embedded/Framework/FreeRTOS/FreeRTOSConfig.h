#ifndef __FREERTOSCONFIG_H__
#define __FREERTOSCONFIG_H__


/************************ 断言配置 ************************/
#define vAssertCalled(char, int) printf("Error:%s, %d\r\n" char, int)
#define configASSERT(x) if ((x)==0) vAssertCalled(__FILE__, __LINE__)



/************************ 基本配置 ************************/
#define configUSE_PREEMPTION                    1           /* “1”RTOS为抢占式调度 */
#define configUSE_TIME_SLICING                  1           /* “1”使能时间片调度 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1           /* “1”特定硬件方法, 计算前导零指令 */
#define configMAX_PRIORITIES                    32          /* RTOS可以使用的最大优先级 */
                                                            
#define configUSE_TICKLESS_IDLE                 0           /* “0”保持节拍中断始终有效  */
                                                            /* “1”启用功耗tickless模式 */
#define configCPU_CLOCK_HZ                      60000000    /* CPU内核时钟频率 */
#define configTICK_RATE_HZ                      250         /* RTOS系统自己的节拍中断的频率 */
                                              /* 即一秒中断的次数，每次中断RTOS都会进行任务调度 */

#define configMAX_TASK_NAME_LEN                 16          /* 任务名字符串长度 */
#define configUSE_16_BIT_TICKS                  0           /* 系统节拍计数器变量数据类型 */
                                                            /* “0”为32位无符号整形数据 */
#define configIDLE_SHOULD_YIELD                 1           /* “1”空闲任务放弃CPU使用权 */
#define configMINIMAL_STACK_SIZE                128         /* 空闲任务使用的堆栈大小 */
#define configCHECK_FOR_STACK_OVERFLOW          0           /* “0”不使用堆栈溢出检测机制 */
#define configUSE_TASK_NOTIFICATIONS            1           /* “1”使用任务通知 */
#define configAPPLICATION_TASK_TAG              0           /* “0”不使用用户任务标签 */
#define configUSE_MUTEXES                       0           /* “0”不使用互斥信号量 */
#define configUSE_RECURSIVE_MUTEXES             0           /* “0”不使用递归互斥信号量 */
#define configUSE_COUNTING_SEMAPHORES           0           /* “0”不使用计数信号量*/


#define configUSE_QUEUE_SETS                    1           /* “1”启用队列集 */
#define configQUEUE_REGISTRY_SIZE               10          /* 不为“0”时表示启用队列记录 */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5           /*  */


#define configUSE_NEWLIB_REENTRANT              0           /*  */
#define configENABLE_BACKWARD_COMPATIBILITY     0           /*  */
#define configUSE_ALTERNATIVE_API               0           /* Deprecated! */



/************************ 中断配置 ************************/
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS     __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS     4
#endif
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5
#define configKERNEL_INTERRUPT_PRIORITY                 ()
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            ()


#define xPortPendSVHandler  PendSV_Handler
#define vPortSVCHandler     SVC_Handler



/************************ 内存申请 ************************/
#define configSUPPORT_DYNAMIC_ALLOCATION        1                   /* 支持动态内存申请 */
#define configTOTAL_HEAP_SIZE                   ((size_t)(46*1024)) /* 系统所有总堆的大小(46K) */



/************************ 钩子函数 ************************/
#define configUSE_IDLE_HOOK                     0           /* 不使用空闲钩子函数 */
#define configUSE_TICK_HOOK                     0           /* 不使用时间片钩子函数 */           
#define configUSE_MALLOC_FAILED_HOOK            0           /* 不使用内存申请失败钩子函数 */
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0           /*  */



/************************ 运行时间 ************************/
#define configGENERATE_RUN_TIME_STATS           0           /* 不启用运行时间统计 */
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0



/************************ 软件定时器 ************************/
#define configUSE_TIMERS                        1           /* 启用软件定时器 */
#define configTIMER_TASK_PRIORITY               (configMAX_PRIORITIES-1)
#define configTIMER_QUEUE_LENGTH                5
#define configTIMER_TASK_STACK_DEPTH            (configMINIMAL_STACK_SIZE*2)



/************************ 协程相关 ************************/
#define configUSE_CO_ROUTINES                   0           /* 关闭协程 */
#define configMAX_CO_ROUTINE_PRIORITIES         (2)



/************************ 可选配置 ************************/
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_vTaskPrioritySet                1



#endif


