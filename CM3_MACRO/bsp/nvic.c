#include "nvic.h"

/*---------------------------------------------------------------------------*/
/** @brief 设置中断优先级组
 * 31:16 (访问钥匙密)任何对该寄存器的写操作,都必须同时写入“0x05FA”
 * 10:8  (优先级分组)指定先占优先级和从优先级位数
Cortex-M3共有8位可配置的优先级，但STM32F10x只用到“高”4位
 * 111   (0位抢占优先级, 4位响应优先级)	7
 * 110   (1位抢占优先级, 3位响应优先级)	6
 * 101   (2位抢占优先级, 2位响应优先级)	5
 * 100   (3位抢占优先级, 1位响应优先级)	4
 * 011   (4位抢占优先级, 0位响应优先级)	3
 */
void nvic_set_priority_group(void)
{
	/* 清除高16位和低(10,9,8)位 */ 
	SCB->AIRCR &= (uint32_t)(0x0000F8FF);
	/* 2位抢占优先级, 2位响应优先级 */
	SCB->AIRCR |= (uint32_t)(0x05FA0000 | 0x00000500);
}

/** @brief 设置外部中断的先占优先级和从优先级
 * @param[in] uint8_t irq, 选择外部中断编号
 * @param[in] uint8_t priority, 设置它对应的先占优先级和从优先级
 */
void nvic_set_irq_priority(uint8_t irq, uint8_t priority)
{
	NVIC->IP[irq] = priority;
}



/*---------------------------------------------------------------------------*/
/** @brief NVIC Enable Interrupt
 *
 * Enables a user interrupt.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 */
void nvic_enable_irq(uint8_t irqn)
{
	NVIC->ISER[irqn / 32] = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Disable Interrupt
 *
 * Disables a user interrupt.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 */
void nvic_disable_irq(uint8_t irqn)
{
	NVIC->ICER[irqn / 32] = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Pending Interrupt
 *
 * True if the interrupt has occurred and is waiting for service.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 * @return Boolean. Interrupt pending.
 */
uint8_t nvic_get_pending_irq(uint8_t irqn)
{
	return NVIC->ISPR[irqn / 32] & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Set Pending Interrupt
 *
 * Force a user interrupt to a pending state. This has no effect if the
 * interrupt is already pending.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 */
void nvic_set_pending_irq(uint8_t irqn)
{
	NVIC->ISPR[irqn / 32] = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Clear Pending Interrupt
 *
 * Force remove a user interrupt from a pending state. This has no effect if
 * the interrupt is actively being serviced.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 */
void nvic_clear_pending_irq(uint8_t irqn)
{
	NVIC->ICPR[irqn / 32] = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Enabled Interrupt
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 * @return Boolean. Interrupt enabled.
 */
uint8_t nvic_get_irq_enabled(uint8_t irqn)
{
	return NVIC->ISER[irqn / 32] & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Active Interrupt
 *
 * Interrupt has occurred and is currently being serviced.
 *
 * @param[in] irqn Unsigned int8. Interrupt number
 * @return Boolean. Interrupt active.
 */
uint8_t nvic_get_active_irq(uint8_t irqn)
{
	return NVIC->IABR[irqn / 32] & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Software Trigger Interrupt
 *
 * Generate an interrupt from software. This has no effect for unprivileged
 * access unless the privilege level has been elevated through the System
 * Control Registers.
 *
 * @param[in] irqn Unsigned int16. Interrupt number (0 ... 239)
 */
void nvic_generate_software_interrupt(uint16_t irqn)
{
	if (irqn <= 239) {
		NVIC->STIR |= irqn;
	}
}
