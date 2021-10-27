#include "DIO.h"
#include "MEMORY.h"



  void dio_intialise(void)
		{  ///// do not forgot to enable the clock otherwise it will not going to work
			//// Also assign the address
	  	  gpio_registers_address_assign(GPIOA,GPIOA_BASE_ADDRESE); //// Give it the GPIO I want to intialise and I the GPIO Base address


         *GPIOa.MODER = ((*GPIOa.MODER) &(~(0xfff<<0)))  |(GPIOA_MODE  <<0) ;/// Make sure not to change pin PA13, PA14 beacue they are used for depuging





        }


  void set_GPIO_bit_atomic (GPIO *gpio, int pin_number)
  	  {

	    *(gpio->BSRR) |=(1<<pin_number);

  	  }


  void clear_GPIO_bit_atomic (GPIO *gpio, int pin_number)
   	   {

	    *(gpio->BSRR) |=(1<<(pin_number+16));

   	   }


  void assign_GPIO_bit_atomic (GPIO *gpio,int pin_number, int value)
   		{

   			if(value==1)

   			  {
   					*(gpio->BSRR) |=(1<<pin_number);          /// i use * becuse i want to change the value the bssr point to
   			   }else

   				{
   					*(gpio->BSRR) |=(1<<(pin_number+16));
   				}
        }


  void GPIO_pullup_down (GPIO*gpio,int pin_number,  int pull_status) // make the pin pull Up or down or off
   		{
   			*(gpio->PUPDR) = (*(gpio->PUPDR)&(~(0b11<<pin_number*2)))  |(pull_status  <<(pin_number*2)); // same as  (*(gpio->PUPDR= (*(gpio->PUPDR) & (~(0b11<<pin_number*2)))  |(pull_status  <<pin_number*2);
   		}


  int GPIO_read_bit ( GPIO *gpio, int pin_number)
  		{



   			return    ((*gpio->IDR)&(1<<pin_number));
        }

  void GPIO_toggle_atomic( GPIO *gpio, int pin_number  )

   		{
   			int x;
   			// result = comparison ? if_true : if_false;
   			//	(*(gpio->BSRR)) =(((*gpio->ODR)&(1<<pin_number))==0)?(1<<pin_number):(1<<(pin_number+16)); /// I can use  (*(gpio->ODR)) ^=(1<<pin_number)

   			x=(*(gpio->ODR))&(1<<pin_number);
   			if(x==0)
   			  {
			     (*(gpio->BSRR)) =(1<<(pin_number));

		       }else
	            	{

		    	   	   (*(gpio->BSRR)) =(1<<(pin_number+16));
	            	}




   			//(*(gpio->ODR))	=(*(gpio->ODR)) ^(1<<pin_number);

   		}


   void gpio_registers_address_assign( GPIO *gpio,uint32_t GPIOx_BASE_ADDRESE)
     {    //// continu the rest of registers addresses

	   gpio->MODER=GPIOx_BASE_ADDRESE;

	   gpio->OTYPER=GPIOA_BASE_ADDRESE+GPIOx_OTYPER_OFFSET;
	   gpio->OSPEEDR=GPIOA_BASE_ADDRESE+GPIOx_OSPEEDR_OFFSET;

	   gpio->BSRR=GPIOx_BASE_ADDRESE+GPIOx_BSRR_OFFSET;
	   gpio->PUPDR=GPIOx_BASE_ADDRESE+GPIOx_PUPDR_OFFSET;
	   gpio->IDR= GPIOx_BASE_ADDRESE+GPIOx_IDR_OFFSET;
	   gpio->ODR= GPIOx_BASE_ADDRESE+GPIOx_ODR_OFFSET;

	   gpio->LCKR= GPIOx_BASE_ADDRESE+GPIOx_LCKR_OFFSET;
	   gpio->AFRL= GPIOx_BASE_ADDRESE+GPIOx_AFRL_OFFSET;
	   gpio->AFRHy= GPIOx_BASE_ADDRESE+GPIOx_AFRHy_OFFSET;
     }





/* ceate Data type struct
 *
 * typedef struct {
 //fields
 * unsigned int phoneno;
 * unsigned char id;
 * float salary;
 * }employee;

  void restemployee(employee * person);


 int main (void)
 {
 employee Andrew ;

 Andrew.id=1;

 Andrew.phoneno=73333;
 Andrew.salary=5555252.75
}



void restemployee(employee * person)
{
   Person->phoneno ////use arrow when dealing with pointer to the structure



}






 */
