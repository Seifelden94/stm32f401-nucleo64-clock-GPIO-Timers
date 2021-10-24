#ifndef COMMAN_H_
#define COMMAN_H_
#include"MEMORY.h"

//the comman macro that i am going to use /////



//#define SET_BIT(bit_number)            output_val |=(1<<bit_number) // shift 1 to the left by the bit number than use or to make sure i will set the specific bit not change the other value in the register


/*Bits 31:16 BRy: Port x reset bit y (y = 0..15)
These bits are write-only and can be accessed in word, half-word or byte mode. A read to
these bits returns the value 0x0000.
0: No action on the corresponding ODRx bit
1: Resets the corresponding ODRx bit
Note: If both BSx and BRx are set, BSx has priority.
Bits 15:0 BSy: Port x set bit y (y= 0..15)
These bits are write-only and can be accessed in word, half-word or byte mode. A read to
these bits returns the value 0x0000.
0: No action on the corresponding ODRx bit
1: Sets the corresponding ODRx bit*/


// result = comparison ? if_true : if_false;

//#define SET_BIT(PORT_NAME,bit_number)            (*PORT_NAME.BSRR) |=(1<<bit_number) // shift 1 to the left by the bit number than use or to make sure i will set the specific bit in GPIOA_BSRR, not change the other value in the register,   GPIOA_BSRR  will st the related bit in GPIOA_ODR



//#define CLEAR_BIT(bit_number)          output_val &=(~(1<<bit_number))  //    shift 1 to the left by the bit number than use not ~ than & to  make sure i will only clear the specific bit and not change the other value in the register

//#define CLEAR_BIT(PORT_NAME, bit_number)          (*PORT_NAME.BSRR) |=((1<<(bit_number+16)))  //    shift 1 to the left by the bit number than use Or to witre to the bitRest  in GPIOA_BSRR that clear the related bit in GPIOA_ODR



#define GET_BIT(PORT_NAME,bit_number)           (((PORT_NAME)>>bit_number)&1)// move the bit I want to read to the first bit than and & it with 1 to read its value, if it was 0 so 0 &1=0. if it was 1 so 1&1=1

//#define GET_BIT(PORT_NAME,bit_number)           (((input_val)>>bit_number)&1)// move the bit I want to read to the first bit than and & it with 1 to read its value, if it was 0 so 0 &1=0. if it was 1 so 1&1=1


//#define ASSIGN_BIT(bit_number,valu)    output_val = ((output_val )&(~(1<<bit_number))) |(valu<<bit_number) // shift 1 to the required bit location than reverse it using not ~ , TAKE THE value of out put value, then make it or with the required value.

//#define ASSIGN_BIT(PORT_NAME,bit_number,valu)    PORT_NAME = ((PORT_NAME )&(~(1<<bit_number))) |(valu<<bit_number) // shift 1 to the required bit location than reverse it using not ~ , TAKE THE value of out put value, then make it or with the required value.

//#define TOGGLE_BIT(bit_number)                   output_val ^=(1<<bit_number) // if it was one it will become zero if it was zero it will become 1 doing that using xor ^

#define TOGGLE_BIT(PORT_NAME,bit_number)                 PORT_NAME ^=(1<<bit_number) // if it was one it will become zero if it was zero it will become 1 doing that using xor ^



// #define GET_BIT_port( port,bit_number)           (((port)>>bit_number)&1)// move the bit I want to read to the first bit than and & it with 1 to read its value, if it was 0 so 0 &1=0. if it was 1 so 1&1=1

///////////////////////

#endif
