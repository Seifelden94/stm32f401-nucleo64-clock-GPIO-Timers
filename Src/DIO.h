

#ifndef DIO_H_
#define DIO_H_
#include<stdint.h>



//////// GPIO REGISTER OFFSET AND ITS DETAILS


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

//// GPIO BASE ADDRESSES//////
#define   GPIOB_BASE_ADDRESE    0x40020400
#define   GPIOA_BASE_ADDRESE    0x40020000
#define   GPIOC_BASE_ADDRESE    0x40020800
#define   GPIOD_BASE_ADDRESE    0x40020C00
#define   GPIOE_BASE_ADDRESE    0x40020C00
#define   GPIOH_BASE_ADDRESE    0x40021C00
////////////////



typedef struct  {

	volatile uint32_t* MODER ;
	volatile uint32_t* OTYPER ;
	volatile uint32_t* OSPEEDR;
	volatile uint32_t* BSRR;
	volatile uint32_t* PUPDR;
	volatile uint32_t* IDR;
	volatile uint32_t* ODR ;
	volatile uint32_t* LCKR;
	volatile uint32_t* AFRL;
	volatile uint32_t* AFRHy ;



} GPIO ;

GPIO GPIOa;

#define GPIOA_MODER_L                0b0000010000000000       //// first two bits represent  Pin Zero in Port A. the fowllowing two bits bit 2 and 3 represent  Pin number 1

#define GPIOA_MODER_H                ///first two bit represent Pin number 8

#define GPIOA_ODR_L        0b100000


#define GPIOA_AFRL_L      0b000000001100000

#define GPIOA_BSRR_L       0b100000

#define GPIOA               &GPIOa /// so the user in the main file can use GPIOA inside the functions, instead of &GPIOa


#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7
#define PIN8            8
#define PIN9            9
#define PIN10            10
#define PIN11            11
#define PIN12            12
#define PIN13            13
#define PIN14            14
#define PIN15            15

#define PULLOFF     0
#define PULLUP     1
#define PULLDOWN     2


/// pin mode port A
/*Bits 2y:2y+1 MODERy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O direction mode.
0   0b00: Input (reset state)
1  0b01: General purpose output mode
2   0b10: Alternate function mode
3   0b11: Analog mode
*/

/* PIN A modes        PINAX_MODE  is 2 bits that decide what of the four mode I will be using, ex input, output,another function, anlog.
PINA0_W_mode, W stand for write  is a one bit if It one it will allow me to modify the crosponding two bits of pinA0 mode.
technecally I can write dirrectly to the pins but I only did that to make sure I change only what I need to use.

*/
#define PINA0_W_MODE         0b0
#define PINA0_MODE          0b00

#define PINA1_W_MODE         0b0
#define PINA1_MODE         0

#define PINA2_W_MODE         0b0
#define PINA2_MODE         0

#define PINA3_W_MODE         0b0
#define PINA3_MODE         1

#define PINA4_W_MODE         0b0
#define PINA4_MODE         1

#define PINA5_W_MODE         0b0
#define PINA5_MODE         1

#define PINA6_W_MODE         0b0
#define PINA6_MODE         1

#define PINA7_W_MODE         0b0
#define PINA7_MODE         1

#define PINA8_W_MODE         0b0
#define PINA8_MODE         1

#define PINA9_W_MODE         0b0
#define PINA9_MODE         1

#define PINA10_W_MODE         0b0
#define PINA10_MODE        1

#define PINA11_W_MODE         0b0
#define PINA11_MODE        1

#define PINA12_W_MODE         0b0
#define PINA12_MODE        0b00

#define PINA13_W_MODE         0b0
#define PINA13_MODE        0b00

#define PINA14_W_MODE         0b0
#define PINA14_MODE       0b00

#define PINA15_W_MODE         0b0
#define PINA15_MODE       0b00


//////////


#define  GPIO_W_MODE_L       ((PINA0_W_MODE<<0)|PINA0_W_MODE<<1)|((PINA1_W_MODE<<2)|PINA1_W_MODE<<3)|((PINA2_W_MODE<<4)|PINA2_W_MODE<<5)|((PINA3_W_MODE<<6)|PINA3_W_MODE<<7)|((PINA4_W_MODE<<8)|PINA4_W_MODE<<9)|((PINA5_W_MODE<<10)|PINA5_W_MODE<<11)|((PINA6_W_MODE<<12)|PINA6_W_MODE<<13)|((PINA7_W_MODE<<14)|PINA7_W_MODE<<15)
#define  GPIO_W_MODE_H       ((PINA8_W_MODE<<16)|PINA8_W_MODE<<17)|((PINA9_W_MODE<<18)|PINA9_W_MODE<<19)|((PINA10_W_MODE<<20)|PINA10_W_MODE<<21)|((PINA11_W_MODE<<22)|PINA11_W_MODE<<23)|((PINA12_W_MODE<<24)|PINA12_W_MODE<<9)|((PINA5_W_MODE<<10)|PINA5_W_MODE<<11)|((PINA6_W_MODE<<12)|PINA6_W_MODE<<13)|((PINA7_W_MODE<<14)|PINA7_W_MODE<<15)
#define  GPIO_W_MODE    (GPIO_W_MODE_H<<16|GPIO_W_MODE_L  )

#define GPIOA_MODE         (PINA0_MODE<<0)|(PINA1_MODE<<2) |(PINA2_MODE<<4) |(PINA3_MODE<<6) |(PINA4_MODE<<8) |(PINA5_MODE<<10) |(PINA6_MODE<<12) |(PINA7_MODE<<14) |(PINA8_MODE<<16) |(PINA9_MODE<<18)|(PINA10_MODE<<20) |(PINA11_MODE<<22) |(PINA12_MODE<<24) |(PINA13_MODE<<26) |(PINA14_MODE<<28) |(PINA15_MODE<<30)

//010000000000//
void gpio_registers_address_assign( GPIO *gpio,uint32_t GPIOX_BASE_ADDRESE) ;
void dio_intialise(void) ;

void set_GPIO_bit_atomic (GPIO*gpio, int pin_number);
void clear_GPIO_bit_atomic (GPIO*gpio, int pin_number);
void assign_GPIO_bit_atomic (GPIO*gpio, int pin_number, int value);

void GPIO_pullup_down (GPIO*gpio,int pin_number,  int pull_status);
int GPIO_read_bit ( GPIO *gpio, int pin_number);

void GPIO_toggle_atomic( GPIO *gpio, int pin_number  );








#endif
