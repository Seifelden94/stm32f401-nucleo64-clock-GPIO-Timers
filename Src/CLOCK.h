
#ifndef CLOCK_H_
#define CLOCK_H_
#include<stdint.h>







//// I only added what I needed. you can go back to datasheet to see the rest of the bit and how to use them


//////////////////////flash///////

#define flash_interface_register_base_address                   0x40023C00
/*
 * 3.8.1 Flash access control register (FLASH_ACR)
The Flash access control register is used to enable/disable the acceleration features and
control the Flash memory access time according to CPU frequency.
Address offset: 0x00
Reset value: 0x0000 0000
Access: no wait state, word, half-word and byte access
 */
#define FLASH_ACR        (*((volatile uint32_t *) (flash_interface_register_base_address + 0x00)))

/*Bit 10 DCEN: Data cache enable
0: Data cache is disabled
1: Data cache is enabled*/

#define DCEN_OFFSET   10
#define  DCEN_ON      (1<<DCEN_OFFSET)

/*Bit 9 ICEN: Instruction cache enable
0: Instruction cache is disabled
1: Instruction cache is enabled*/
#define ICEN_OFFSET   9
#define  ICEN_ON      (1<<ICEN_OFFSET)


/*Bit 8 PRFTEN: Prefetch enable
0: Prefetch is disabled
1: Prefetch is enabled*/
#define PRFTEN_OFFSET   8
#define  PRFTEN_ON     ( 1<<PRFTEN_OFFSET)


/*Bits 7:4 Reserved, must be kept cleared.
Bits 3:0 LATENCY: Latency
These bits represent the ratio of the CPU clock period to the Flash memory access time.
0000: Zero wait state
0001: One wait state
0010: Two wait states
---
1110: Fourteen wait states
1111: Fifteen wait states*/

#define LATENCY_OFFSET 0
#define LATENCY_VALUE      0b0010     ////////////////////////////choose two wait statments, becuse this what come out when I used cubeIDE and decided the clock , this is the value I got in the congigration

//////////end flash///////////


///////////////////// PWR

#define PWR_BASE_ADDRESS        0x40007000


///////PWR power control register (PWR_CR)
#define PWR_CR        (*((volatile uint32_t *) (PWR_BASE_ADDRESS + 0x00)))  /// 32 bits
/*Bits 15:14 VOS[1:0]: Regulator voltage scaling output selection
These bits control the main internal voltage regulator output voltage to achieve a trade-off
between performance and power consumption when the device does not operate at the
maximum frequency (refer to the corresponding datasheet for more details).
These bits can be modified only when the PLL is OFF. The new value programmed is active
only when the PLL is ON. When the PLL is OFF, the voltage regulator is set to scale 3
independently of the VOS register content.
00: Reserved (Scale 3 mode selected)
01: Scale 3 mode
10: Scale 2 mode
11: Reserved (Scale 2 mode selected)*/

#define  VOS_OFFSET 14

#define  VOS_MODE_VALUE     0b10

/////////////end PWR


////////////// RCC begin

#define RCC_BASE_ADDRESE      0x40023800



//////////////////RCC clock control register (RCC_CR)
#define RCC_CR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x00)))  /// 32 bits



/*Bit 25 PLLRDY: Main PLL (PLL) clock ready flag
Set by hardware to indicate that PLL is locked.
0: PLL unlocked
1: PLL locked*/
#define    PLLRDY_OFFSET     25
#define    PLLRDY_READY      (1<<PLLRDY_OFFSET)

/*Bit 24 PLLON: Main PLL (PLL) enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit cannot be reset if PLL
clock is used as the system clock.
0: PLL OFF
1: PLL ON*/

#define PLLON_OFFSET                     24
#define PLLON_ON_VALUE                         1

/*Bit 17 HSERDY: HSE clock ready flag
Set by hardware to indicate that the HSE oscillator is stable. After the HSEON bit is cleared,
HSERDY goes low after 6 HSE oscillator clock cycles.
0: HSE oscillator not ready
1: HSE oscillator ready*/

#define HSERDY_OFFSET      17
#define HSERDY_v          (1<<HSERDY_OFFSET)
/*Bit 16 HSEON: HSE clock enable
Set and cleared by software.
Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
0: HSE oscillator OFF
1: HSE oscillator ON*/
#define HSEON_OFFSET     16
#define HSEON_enable      (1<<HSEON_OFFSET)

/*Bit 1 HSIRDY: Internal high-speed clock ready flag
Set by hardware to indicate that the HSI oscillator is stable. After the HSION bit is cleared,
HSIRDY goes low after 6 HSI clock cycles.
0: HSI oscillator not ready
1: HSI oscillator ready*/

#define  HSIRDY_OFFST       1

/*Bit 0 HSION: Internal high-speed clock enable
Set and cleared by software.
Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode or in
case of a failure of the HSE oscillator used directly or indirectly as the system clock. This bit
cannot be cleared if the HSI is used directly or indirectly as the system clock.
0: HSI oscillator OFF
1: HSI oscillator ON*/

#define HSION_OFFST      0     /// bit number 0




//////////////////RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_PLLCFGR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x04)))  /// 32 bits





/*Bit 22 PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
Set and cleared by software to select PLL and PLLI2S clock source. This bit can be written
only when PLL and PLLI2S are disabled.
0: HSI clock selected as PLL and PLLI2S clock entry
1: HSE oscillator clock selected as PLL and PLLI2S clock entry*/

#define  PLLSRC_OFFST               22
#define  PLLSRC_Choose_HSI                0
#define  PLLSRC_Choose_HSE               1




/*Bits 17:16 PLLP: Main PLL (PLL) division factor for main system clock
Set and cleared by software to control the frequency of the general PLL output clock. These
bits can be written only if PLL is disabled.
Caution: The software has to set these bits correctly not to exceed 84 MHz on this domain.
PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
00: PLLP = 2
01: PLLP = 4
10: PLLP = 6
11: PLLP = 8*/

#define PLLP_OFFST         16
#define PLLP_VALUE         0b00


/*Bits 14:6 PLLN: Main PLL (PLL) multiplication factor for VCO
Set and cleared by software to control the multiplication factor of the VCO. These bits can
be written only when PLL is disabled. Only half-word and word accesses are allowed to
write these bits.
Caution: The software has to set these bits correctly to ensure that the VCO output
frequency is between 192 and 432 MHz. (check also Section 6.3.20: RCC PLLI2S
configuration register (RCC_PLLI2SCFGR))
VCO output frequency = VCO input frequency × PLLN with 192 ≤ PLLN ≤ 432
000000000: PLLN = 0, wrong configuration
000000001: PLLN = 1, wrong configuration
...
...
110110000: PLLN = 432
110110001: PLLN = 433, wrong configuration
...
111111111: PLLN = 511, wrong configuration*/

#define PLLN_OFFST        6
#define PLLN_VALUE         84
/*
 *Bits 5:0 PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
Set and cleared by software to divide the PLL and PLLI2S input clock before the VCO.
These bits can be written only when the PLL and PLLI2S are disabled.
Caution: The software has to set these bits correctly to ensure that the VCO input frequency
ranges from 1 to 2 MHz. It is recommended to select a frequency of 2 MHz to limit
PLL jitter.
VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
000000: PLLM = 0, wrong configuration
000001: PLLM = 1, wrong configuration
000010: PLLM = 2
000011: PLLM = 3
000100: PLLM = 4
...
111110: PLLM = 62
111111: PLLM = 63
 */
#define PLLM_OFFST    0
#define PLLM_VALUE   4



//////////////////RCC clock configuration register (RCC_CFGR)
#define RCC_CFGR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x08)))  /// 32 bits

/*Bits 15:13 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control APB high-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 84 MHz on this domain.
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
PPRE2 write.
0xx: AHB clock not divided
100: AHB clock divided by 2
101: AHB clock divided by 4
110: AHB clock divided by 8
111: AHB clock divided by 16
**/
#define PPRE2_OFFST        13
#define PPRE2_VALUE         0                                /////////////////////////////// choose desird value

/*Bits 12:10 PPRE1: APB Low speed prescaler (APB1)
Set and cleared by software to control APB low-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 42 MHz on this domain.
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
PPRE1 write.
0xx: AHB clock not divided
100: AHB clock divided by 2
101: AHB clock divided by 4
110: AHB clock divided by 8
111: AHB clock divided by 16*/

#define PPRE1_OFFST        10
#define PPRE1_VALUE        0b100                                ///////////////////////////////choose desird value

/*
Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control AHB clock division factor.
Caution: The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
HPRE write.
0xxx: system clock not divided
1000: system clock divided by 2
1001: system clock divided by 4
1010: system clock divided by 8
1011: system clock divided by 16
1100: system clock divided by 64
1101: system clock divided by 128
1110: system clock divided by 256
1111: system clock divided by 512*/

#define HPRE_OFFST      4
#define HPRE_value      0b0000

/*
 * Bits 3:2 SWS: System clock switch status
Set and cleared by hardware to indicate which clock source is used as the system clock.
00: HSI oscillator used as the system clock
01: HSE oscillator used as the system clock
10: PLL used as the system clock
11: not applicable
 */
#define SWS_OFFSET  2
#define SWS_MASK  (0b11<<SWS_OFFSET)
#define SWS_PLL_USED_READY   (0b10 <<SWS_OFFSET)

/*Bits 1:0 SW: System clock switch
Set and cleared by software to select the system clock source.
Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in
case of failure of the HSE oscillator used directly or indirectly as the system clock.
00: HSI oscillator selected as system clock
01: HSE oscillator selected as system clock
10: PLL selected as system clock
11: not allowed*/
#define SW_OFFSET        0
#define SW_CHOOSE_HSI     0b00
#define SW_CHOOSE_HSE     0b01
#define SW_CHOOSE_PLL     0b10


//////////////////RCC clock interrupt register (RCC_CIR)
#define RCC_CIR       (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x0c)))  /// 32 bits

//////////////////RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
#define RCC_AHB1RSTR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x10)))  /// 32 bits

//////////////////RCC AHB2 peripheral reset register (RCC_AHB2RSTR)
#define RCC_AHB2RSTR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x14)))  /// 32 bits

//////////////////RCC APB1 peripheral reset register for (RCC_APB1RSTR)
#define RCC_APB1RSTR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x20)))  /// 32 bits

//////////////////RCC APB2 peripheral reset register (RCC_APB2RSTR)
#define RCC_APB2RSTR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x24)))  /// 32 bits

//////////////////RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define RCC_AHB1ENR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x30)))  /// 32 bits

/*
Bits 11:8 Reserved, must be kept at reset value.
Bit 7 GPIOHEN: IO port H clock enable
Set and reset by software.
0: IO port H clock disabled
1: IO port H clock enabled
*/
#define GPIOHEN_OFFSET            8


/*Bit 4 GPIOEEN: IO port E clock enable
Set and cleared by software.
0: IO port E clock disabled
1: IO port E clock enabled*/
#define GPIOEEN_OFFSET            4


/*
Bit 3 GPIODEN: IO port D clock enable
Set and cleared by software.
0: IO port D clock disabled
1: IO port D clock enabled*/

#define GPIODEN_OFFSET            3

/*Bit 2 GPIOCEN: IO port C clock enable
Set and cleared by software.
0: IO port C clock disabled
1: IO port C clock enabled*/

#define GPIOCEN_OFFSET            2

/*Bit 1 GPIOBEN: IO port B clock enable
Set and cleared by software.
0: IO port B clock disabled
1: IO port B clock enabled*/
#define GPIOBEN_OFFSET            1

/*Bit 0 GPIOAEN: IO port A clock enable
Set and cleared by software.
0: IO port A clock disabled
1: IO port A clock enabled*/

#define GPIOAEN_OFFSET            0
#define GOIOAEN_ON                1










//////////////////RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_AHB2ENR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x34)))  /// 32 bits


//////////////////RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define RCC_APB1ENR         (*((volatile uint32_t *) ((RCC_BASE_ADDRESE+ 0x40))))  /// 32 bits

/*
 * Bit 2 TIM4EN: TIM4 clock enable
Set and cleared by software.
0: TIM4 clock disabled
1: TIM4 clock enabled
 */
#define  TIM4EN_OFFSET    2
#define TIM4EN_ON         1
/* Bit 0 TIM2EN: TIM2 clock enable
Set and cleared by software.
0: TIM2 clock disabled
1: TIM2 clock enabled
 */
#define TIM2EN_OFFSET     0
#define TIM2EN_ON         1
/*
 * Bit 28 PWREN: Power interface clock enable
Set and cleared by software.
0: Power interface clock disabled
1: Power interface clock enable
 */

#define PWREN_OFFSET  28
#define PWREN_ENABLE_ON    (0b1<<PWREN_OFFSET)


//////////////////RCC APB2 peripheral clock enable register(RCC_APB2ENR)
#define RCC_APB2ENR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x44)))  /// 32 bits

//////////////////RCC AHB1 peripheral clock enable in low power mode register(RCC_AHB1LPENR)
#define RCC_AHB1LPENR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x50)))  /// 32 bits

//////////////////RCC AHB2 peripheral clock enable in low power mode register(RCC_AHB2LPENR)
#define RCC_AHB2LPENR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x54)))  /// 32 bits

//////////////////RCC APB1 peripheral clock enable in low power mode register(RCC_APB1LPENR)
#define RCC_APB1LPENR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x60)))  /// 32 bits

//////////////////RCC APB2 peripheral clock enabled in low power mode register(RCC_APB2LPENR)
#define RCC_APB2LPENR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x64)))  /// 32 bits




//////////////////RCC Backup domain control register (RCC_BDCR)
#define RCC_BDCR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x70)))  /// 32 bits



/*
 * Bit 15 RTCEN: RTC clock enable
Set and cleared by software.
0: RTC clock disabled
1: RTC clock enabled
*/

#define  RTC__CLOCK_Enable_OFFSET            15
#define  RTC__CLOCK_Enable_VALUE              1


//Bits 14:10 Reserved, must be kept at reset value.

/*
Bits 9:8 RTCSEL[1:0]: RTC clock source selection
Set by software to select the clock source for the RTC. Once the RTC clock source has been
selected, it cannot be changed anymore unless the Backup domain is reset. The BDRST bit
can be used to reset them.
00: No clock
01: LSE oscillator clock used as the RTC clock
10: LSI oscillator clock used as the RTC clock
11: HSE oscillator clock divided by a programmable prescaler (selection through the
RTCPRE[4:0] bits in the RCC clock configuration register (RCC_CFGR)) used as the RTC
clock*/

#define RTC_CLOCK_SOURCE_SELECTION_OFFSET                   8
#define RTC_CLOCK_SOURCE_SELECTION_VALUE                   01

/*
Bits 7:3 Reserved, must be kept at reset value.
Bit 2 LSEBYP: External low-speed oscillator bypass
Set and cleared by software to bypass oscillator in debug mode. This bit can be written only
when the LSE clock is disabled.
0: LSE oscillator not bypassed
1: LSE oscillator bypassed
 */

/*
 * Bit 1 LSERDY: External low-speed oscillator ready
Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After
the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock
cycles.
0: LSE clock not ready
1: LSE clock ready*/

#define  LSERDY_OFFSET       1

/*Bit 0 LSEON: External low-speed oscillator enable
Set and cleared by software.
0: LSE clock OFF
1: LSE clock ON
 */

#define  LSERON_OFFSET       0

#define  LSERON_VALUE       1




///////////////

//////////////////RCC clock control & status register (RCC_CSR)
#define RCC_CSR        (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x74)))  /// 32 bits

//////////////////RCC spread spectrum clock generation register (RCC_SSCGR)
#define RCC_SSCGR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x80)))  /// 32 bits

//////////////////RCC PLLI2S configuration register (RCC_PLLI2SCFGR)
#define RCC_PLLI2SCFGR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x84)))  /// 32 bits

///////////////////RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)
#define RCC_DCKCFGR         (*((volatile uint32_t *) (RCC_BASE_ADDRESE+ 0x8c)))  /// 32 bits

///////////////////////////////////RCC finished/////////////////////////////////////////
































void clock_initialization(void);





#endif
