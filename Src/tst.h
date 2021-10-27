
//// Timer2  0x4000 0000 - 0x4000 03FF

#define  TIMER4_BASE_ADDRESE   0x40000800


#define TIM4_CR1         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+ TIMx_CR1_OFFSET)))  /// 16 bits

/*
 * ARPE: Auto-reload preload enable
0: TIMx_ARR register is not buffered
1: TIMx_ARR register is buffered

 Bit 4 DIR: Direction
0: Counter used as upcounter
1: Counter used as downcounter
Note: This bit is read only when the timer is configured in Center-aligned mode or Encoder
mode.

Bit 0 CEN: Counter enable
0: Counter disabled
1: Counter enabled
Note: External clock, gated mode and encoder mode can work only if the CEN bit has been
previously set by software. However trigger mode can set the CEN bit automatically by
hardware.
CEN is cleared automatically in one-pulse mode, when an update event occurs.
 */
#define CEN_OFFSET         0

#define CEN_ON         1

#define TIM4_CR2         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_CR2_OFFSET )))  /// 16 bits


#define TIM4_SMCR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+ TIMx_SMCR_OFFSET)))  /// 16 bits

#define TIM4_DIER         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_DIER_OFFSET )))  /// 16 bits

#define TIM4_SR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_SR_OFFSET )))  /// 16 bits

/*
 * Bit 0 UIF: Update interrupt flag
″ This bit is set by hardware on an update event. It is cleared by software.
0: No update occurred.
1: Update interrupt pending. This bit is set by hardware when the registers are updated:
″ At overflow or underflow (for TIM2 to TIM5) and if UDIS=0 in the TIMx_CR1 register.
″ When CNT is reinitialized by software using the UG bit in TIMx_EGR register, if URS=0
and UDIS=0 in the TIMx_CR1 register.
When CNT is reinitialized by a trigger event (refer to the synchro control register description),
if URS=0 and UDIS=0 in the TIMx_CR1 register.
 */

#define UIF_OFFSET   0

#define TIM4_EGR        (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_EGR_OFFSET )))  /// 16 bits

#define TIM4_CCMR1         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCMR1_OFFSET)))  /// 16 bits

#define TIM4_CCMR2         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCMR2_OFFSET)))  /// 16 bits

#define TIM4_CCER         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_CCER_OFFSET )))  /// 16 bits

#define TIM4_CNT         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+TIMx_CNT )))  /// 32 bits
//Bits 31:16 CNT[31:16]: High counter value (on TIM2 and TIM5).
//Bits 15:0 CNT[15:0]: Counter value

#define TIM4_PSC         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+TIMx_PSC_OFFSET )))  /// 16 bits
/*
 * Bits 15:0 PSC[15:0]: Prescaler value
The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
PSC contains the value to be loaded in the active prescaler register at each update event
(including when the counter is cleared through UG bit of TIMx_EGR register or through
trigger controller when configured in “reset mode”).
 */

#define PSC_bit_OFFSET     0
#define PSC_VALUE         (100000-1)   //  make the clock divide by 1 and 65536   if I  put 0 the clk will be divided by (1+0)=1
// F for timers = F cl/(1+prescaler)

#define TIME4_F_KHZ         (APB1_clock_KH/(PSC_VALUE+1))

#define TIM4_ARR         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_ARR_OFFSET)))  /// 32 bits

#define TIM4_CCR1         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+TIMx_CCR1_OFFSET )))  /// 32 bits

#define TIM4_CCR2         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR2_OFFSET)))  /// 32 bits

#define TIM4_CCR3         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR3_OFFSET)))  /// 32 bits

#define TIM4_CCR4         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR4_OFFSET)))  /// 32 bits

#define TIM4_DCR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_DCR_OFFSET )))  /// 16 bits

#define TIM4_DMAR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_DMAR_OFFSET )))  /// 16 bits
