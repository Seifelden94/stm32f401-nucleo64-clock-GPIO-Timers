

#ifndef MEMORY_H_
#define MEMORY_H_
#include<stdint.h>

#define GPIOx_MODER_OFFSET     0x00    ///
/* Bits 2y:2y+1 MODERy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O direction mode.
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode*/


#define GPIOx_OTYPER_OFFSET      0x04// GPIO port output type register
/*
 * Bits 31:16 Reserved, must be kept at reset value.
Bits 15:0 OTy: Port x configuration bits (y = 0..15)
These bits are written by software to configure the output type of the I/O port.
0: Output push-pull (reset state)
1: Output open-drain*/

#define GPIOx_OSPEEDR_OFFSET      0x08   // GPIO port output speed register
/*Bits 2y:2y+1 OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O output speed.
00: Low speed
01: Medium speed
10: High speed
11: Very high speed
Note: Refer to the product datasheets for the values of OSPEEDRy bits versus VDD
range and external load.
 */
#define GPIOx_PUPDR_OFFSET      0x0c // GPIO port pull-up/pull-down register
/*
 * Bits 2y:2y+1 PUPDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
 */


#define GPIOx_IDR_OFFSET      0x10   //GPIO port input data register
/*
 * Bits 31:16 Reserved, must be kept at reset value.
Bits 15:0 IDRy: Port input data (y = 0..15)
These bits are read-only and can be accessed in word mode only. They contain the input
value of the corresponding
 */
#define GPIOx_ODR_OFFSET      0x14  //GPIO port output data register

/*
 * Bits 31:16 Reserved, must be kept at reset value.
Bits 15:0 ODRy: Port output data (y = 0..15)
These bits can be read and written by software.
Note: For atomic bit set/reset, the ODR bits can be individually set and reset by writing to the
GPIOx_BSRR register (x = A..E and H).
 */
#define GPIOx_BSRR_OFFSET      0x18 //GPIO port bit set/reset register


#define GPIOx_LCKR_OFFSET      0x1c
/*
 * This register is used to lock the configuration of the port bits when a correct write sequence
is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
LOCK sequence has been applied on a port bit, the value of this port bit can no longer be
modified until the next MCU or peripheral reset.
Note: A specific write sequence is used to write to the GPIOx_LCKR register. Only word access
(32-bit long) is allowed during this write sequence.
Each lock bit freezes a specific configuration register (control and alternate function
registers).
Address offset: 0x1C
Reset value: 0x0000 0000
Access: 32-bit word only, read/write register
 */
#define GPIOx_AFRL_OFFSET      0x20  //GPIO alternate function low register
/*
 * Bits 31:0 AFRLy: Alternate function selection for port x bit y (y = 0..7)
These bits are written by software to configure alternate function I/Os
AFRLy selection:
0000: AF0
0001: AF1
0010: AF2
0011: AF3
0100: AF4
0101: AF5
0110: AF6
0111: AF7
1000: AF8
1001: AF9
1010: AF10
1011: AF11
1100: AF12
1101: AF13
1110: AF14
1111: AF15
 */
#define GPIOx_AFRHy_OFFSET      0x24 //GPIO alternate function high register
/*Bits 31:0 AFRHy: Alternate function selection for port x bit y (y = 8..15)
These bits are written by software to configure alternate function I/Os
AFRHy selection:
0000: AF0
0001: AF1
0010: AF2
0011: AF3
0100: AF4
0101: AF5
0110: AF6
0111: AF7
1000: AF8
1001: AF9
1010: AF10
1011: AF11
1100: AF12
1101: AF13
1110: AF14
1111: AF15
*/

///////////PORTA//
#define   GPIOA_BASE_ADDRESE    0x40020000

#define GPIOA_MODER         (*((volatile uint32_t *)( GPIOA_BASE_ADDRESE+ GPIOx_MODER_OFFSET)))  /// 32 bits
#define GPIOA_OTYPER        (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_OTYPER_OFFSET ) ))  /// 32 bits
#define GPIOA_OSPEEDR       (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_OSPEEDR_OFFSET ) ))  /// 32 bits
#define GPIOA_PUPDR         (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_PUPDR_OFFSET  )))  /// 32 bits
#define GPIOA_IDR           (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_IDR_OFFSET )))  /// 32 bits
#define GPIOA_ODR           (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_ODR_OFFSET )))  /// 32 bits
#define GPIOA_BSRR          (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_BSRR_OFFSET)))  /// 32 bits
#define GPIOA_LCKR          (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_LCKR_OFFSET)))  /// 32 bits
#define GPIOA_AFRL          (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_AFRL_OFFSET)))  /// 32 bits
#define GPIOA_AFRHy         (*((volatile uint32_t *) (GPIOA_BASE_ADDRESE+GPIOx_AFRHy_OFFSET)))  /// 32 bits

//////////////////////////////////////////////////////////////







// PORTB//

#define   GPIOB_BASE_ADDRESE    0x40020400

#define GPIOB_MODER         (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+ GPIOx_MODER_OFFSET)))  /// 32 bits
#define GPIOB_OTYPER        (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_OTYPER_OFFSET ) ))  /// 32 bits
#define GPIOB_OSPEEDR       (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_OSPEEDR_OFFSET ) ))  /// 32 bits
#define GPIOB_PUPDR         (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_PUPDR_OFFSET  )))  /// 32 bits
#define GPIOB_IDR           (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_IDR_OFFSET )))  /// 32 bits
#define GPIOB_ODR           (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_ODR_OFFSET )))  /// 32 bits
#define GPIOB_BSRR          (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_BSRR_OFFSET)))  /// 32 bits
#define GPIOB_LCKR          (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_LCKR_OFFSET)))  /// 32 bits
#define GPIOB_AFRL          (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_AFRL_OFFSET)))  /// 32 bits
#define GPIOB_AFRHy         (*((volatile uint32_t *) (GPIOB_BASE_ADDRESE+GPIOx_AFRHy_OFFSET)))  /// 32 bits

//////////////////////////////////

//////PORTC//
#define   GPIOC_BASE_ADDRESE    0x40020800

#define GPIOC_MODER         (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+ GPIOx_MODER_OFFSET)))  /// 32 bits
#define GPIOC_OTYPER        (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_OTYPER_OFFSET  )))  /// 32 bits
#define GPIOC_OSPEEDR       (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_OSPEEDR_OFFSET  )))  /// 32 bits
#define GPIOC_PUPDR         (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_PUPDR_OFFSET  )))  /// 32 bits
#define GPIOC_IDR           (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_IDR_OFFSET )))  /// 32 bits
#define GPIOC_ODR           (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_ODR_OFFSET )))  /// 32 bits
#define GPIOC_BSRR          (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_BSRR_OFFSET)))  /// 32 bits
#define GPIOC_LCKR          (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_LCKR_OFFSET)))  /// 32 bits
#define GPIOC_AFRL          (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_AFRL_OFFSET)))  /// 32 bits
#define GPIOC_AFRHy         (*((volatile uint32_t *) (GPIOC_BASE_ADDRESE+GPIOx_AFRHy_OFFSET)))  /// 32 bits
///////////////////






#define   GPIOD_BASE_ADDRESE    0x40020C00
#define   GPIOE_BASE_ADDRESE    0x40020C00
#define   GPIOH_BASE_ADDRESE    0x40021C00


////////////////








#endif
