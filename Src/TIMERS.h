#ifndef TIMERS_H_
#define TIMERS_H_
#include<stdint.h>


#define APB1_clock_KH       84000
/*
 * 13.2 TIM2 to TIM5 main features
General-purpose TIMx timer features include:
• 16-bit (TIM3 and TIM4) or 32-bit (TIM2 and TIM5) up, down, up/down auto-reload
counter.
• 16-bit programmable prescaler used to divide (also “on the fly”) the counter clock
frequency by any factor between 1 and 65536.
• Up to 4 independent channels for:
– Input capture
– Output compare
– PWM generation (Edge- and Center-aligned modes)
– One-pulse mode output
• Synchronization circuit to control the timer with external signals and to interconnect
several timers.
• Interrupt/DMA generation on the following events:
– Update: counter overflow/underflow, counter initialization (by software or
internal/external trigger)
– Trigger event (counter start, stop, initialization or count by internal/external trigger)
– Input capture
– Output compare
• Supports incremental (quadrature) encoder and hall-sensor circuitry for positioning
purposes
• Trigger input for external clock or cycle-by-cycle current management


The time-base unit includes:
• Counter Register (TIMx_CNT)
• Prescaler Register (TIMx_PSC):
• Auto-Reload Register (TIMx_ARR)

 */






// TIMx control register 1 (TIMx_CR1)
#define   TIMx_CR1_OFFSET      0x00

//  TIMx control register 2 (TIMx_CR2)
#define       TIMx_CR2_OFFSET  0x04

//TIMx slave mode control register (TIMx_SMCR)
#define TIMx_SMCR_OFFSET    0x08

//TIMx DMA/Interrupt enable register (TIMx_DIER)
#define   TIMx_DIER_OFFSET   0x0c

///TIMx status register (TIMx_SR)
#define   TIMx_SR_OFFSET       0x10

///TIMx event generation register (TIMx_EGR)
#define    TIMx_EGR_OFFSET           0x14


//TIMx capture/compare mode register 1 (TIMx_CCMR1)
#define   TIMx_CCMR1_OFFSET          0x18

//TIMx capture/compare mode register 2 (TIMx_CCMR2)
#define    TIMx_CCMR2_OFFSET        0x1c

//TIMx capture/compare enable register (TIMx_CCER)
#define    TIMx_CCER_OFFSET       0x20

//TIMx counter (TIMx_CNT)
#define    TIMx_CNT      0x24


//13.4.11 TIMx prescaler (TIMx_PSC)
#define      TIMx_PSC_OFFSET              0x28

//TIMx auto-reload register (TIMx_ARR)  Reset value: 0xFFFF FFFF
#define    TIMx_ARR_OFFSET        0x2c

//TIMx capture/compare register 1 (TIMx_CCR1)
#define   TIMx_CCR1_OFFSET     0x34

//TIMx capture/compare register 2 (TIMx_CCR2)
#define      TIMx_CCR2_OFFSET    0x34

//TIMx capture/compare register 3 (TIMx_CCR3)
#define   TIMx_CCR3_OFFSET     0x3c

//TIMx capture/compare register 4 (TIMx_CCR4)
#define   TIMx_CCR4_OFFSET    0x40


//TIMx DMA control register (TIMx_DCR)
#define   TIMx_DCR_OFFSET   0x48

//TIMx DMA address for full transfer (TIMx_DMAR)
#define TIMx_DMAR_OFFSET    0x4c

//TIM2 option register (TIM2_OR)
#define   TIM2_OR_OFFSET   0x50

//TIM5 option register (TIM5_OR)
#define  TIM5_OR_OFFSET   0x50



//// Timer2  0x4000 0000 - 0x4000 03FF

#define  TIMER2_BASE_ADDRESE   0x40000000





#define TIM2_CR1         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+ TIMx_CR1_OFFSET)))  /// 16 bits
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




#define TIM2_CR2         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_CR2_OFFSET )))  /// 16 bits

#define TIM2_SMCR         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+ TIMx_SMCR_OFFSET)))  /// 16 bits

#define TIM2_DIER         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_DIER_OFFSET )))  /// 16 bits



#define TIM2_SR         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_SR_OFFSET )))  /// 16 bits

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




#define TIM2_EGR        (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_EGR_OFFSET )))  /// 16 bits

#define TIM2_CCMR1         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+ TIMx_CCMR1_OFFSET)))  /// 16 bits

#define TIM2_CCMR2         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+ TIMx_CCMR2_OFFSET)))  /// 16 bits

#define TIM2_CCER         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_CCER_OFFSET )))  /// 16 bits


#define TIM2_CNT         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+TIMx_CNT )))  /// 32 bits
//Bits 31:16 CNT[31:16]: High counter value (on TIM2 and TIM5).
//Bits 15:0 CNT[15:0]: Counter value


#define TIM2_PSC         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+TIMx_PSC_OFFSET )))  /// 16 bits
/*
 * Bits 15:0 PSC[15:0]: Prescaler value
The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
PSC contains the value to be loaded in the active prescaler register at each update event
(including when the counter is cleared through UG bit of TIMx_EGR register or through
trigger controller when configured in “reset mode”).
 */
#define PSC_bit_OFFSET     0
#define PSC_VALUE         (84-1)   //  make the clock divide by 1 and 65536   if I  put 0 the clk will be divided by (1+0)=1
// F for timers = F cl/(1+prescaler)

#define TIME2_F_KHZ         (APB1_clock_KH/(PSC_VALUE+1))  /// might use later


//////////////////

#define TIM2_ARR         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+ TIMx_ARR_OFFSET)))  /// 32 bits

#define TIM2_CCR1         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+TIMx_CCR1_OFFSET )))  /// 32 bits

#define TIM2_CCR2         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+ TIMx_CCR2_OFFSET)))  /// 32 bits

#define TIM2_CCR3         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+ TIMx_CCR3_OFFSET)))  /// 32 bits

#define TIM2_CCR4         (*((volatile uint32_t *) (TIMER2_BASE_ADDRESE+ TIMx_CCR4_OFFSET)))  /// 32 bits

#define TIM2_DCR         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_DCR_OFFSET )))  /// 16 bits

#define TIM2_DMAR         (*((volatile uint16_t *) (TIMER2_BASE_ADDRESE+TIMx_DMAR_OFFSET )))  /// 16 bits














/////////////////////////////////////////////////////////////timer4



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
#define PSC_time4_VALUE        (84-1)   //  make the clock divide by 1 and 65536   if I  put 0 the clk will be divided by (1+0)=1
// F for timers = F cl/(1+prescaler)

#define TIME4_F_KHZ         (APB1_clock_KH/(PSC_VALUE+1))



#define TIM4_ARR         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_ARR_OFFSET)))  /// 32 bits

#define TIM4_CCR1         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+TIMx_CCR1_OFFSET )))  /// 32 bits

#define TIM4_CCR2         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR2_OFFSET)))  /// 32 bits

#define TIM4_CCR3         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR3_OFFSET)))  /// 32 bits

#define TIM4_CCR4         (*((volatile uint32_t *) (TIMER4_BASE_ADDRESE+ TIMx_CCR4_OFFSET)))  /// 32 bits

#define TIM4_DCR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_DCR_OFFSET )))  /// 16 bits

#define TIM4_DMAR         (*((volatile uint16_t *) (TIMER4_BASE_ADDRESE+TIMx_DMAR_OFFSET )))  /// 16 bits
//////////////////////////////////////////
void timer2_initi(void);

void delaytime2_msec(int msec);

void timer4_initi(void);
void delaytime4_msec(int msec);
void delaytime4_micro_sec(int microsec);

#endif
