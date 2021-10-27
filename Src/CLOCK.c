#include"CLOCK.h"
#include "MEMORY.h"










	void clock_initialization(void)

	{	RCC_CR |=HSEON_enable ; // turn on the external clock   ///

		while(!(RCC_CR &HSERDY_v) );  //cheke the flag to know if the external clock is ready to be used

		//2- set the power enable clock and voltage regulator

		RCC_APB1ENR=RCC_APB1ENR|PWREN_ENABLE_ON ; //// enable power interface clock register

		///voltage regulator

		PWR_CR = ((PWR_CR ) &(~(0b11<<VOS_OFFSET))) |(VOS_MODE_VALUE <<VOS_OFFSET ) ;



		/// configure the flash related setup

		////Data cache enable/Instruction cache enable/Prefetch enable
       FLASH_ACR=FLASH_ACR|DCEN_ON |  ICEN_ON  |PRFTEN_ON ;  // I do not need to cleer the bit first becaue any way I will write 1

       /*
        * Bits 3:0 LATENCY: Latency
		  These bits represent the ratio of the CPU clock period to the Flash memory access time.
		  0000: Zero wait state
		  0001: One wait state
		  0010: Two wait states
			---
		  1110: Fourteen wait states
		  1111: Fifteen wait states
        */

       FLASH_ACR= ((FLASH_ACR ) &(~(0b1111<<LATENCY_OFFSET))) |(LATENCY_VALUE <<LATENCY_OFFSET ) ;  /// I wanted to make sure that I cleared the first four bit befor I write 0010

		///4- configure the prescalars HCL:,PCLK1,PCLK@

		//////// set PPRE2 prescaller value
		RCC_CFGR = ((RCC_CFGR ) &(~(0b111<<PPRE2_OFFST ))) |(PPRE2_VALUE<<PPRE2_OFFST ) ;

		//////// set PPRE1 prescaller value
		RCC_CFGR = ((RCC_CFGR ) &(~(0b111<<PPRE1_OFFST))) |(PPRE1_VALUE <<PPRE1_OFFST) ;
                                                                                                       ////   1011101
		                                                                                             //////   11
		//////// set HPRE prescaller value                                                             /////  1111101
		RCC_CFGR = (((RCC_CFGR ) &(~(0xf<<HPRE_OFFST))) |(HPRE_value <<HPRE_OFFST)) ;                 ///     0011101
                                                                                                      ////    10
		//// 5- configure the pll ,P,N,M
		RCC_PLLCFGR = (((RCC_PLLCFGR ) &(~(0b11<<PLLP_OFFST ))) |(PLLP_VALUE <<PLLP_OFFST )) ;

		RCC_PLLCFGR = (((RCC_PLLCFGR ) &(~(0b111111111<<PLLN_OFFST)  )) |(PLLN_VALUE <<PLLN_OFFST  )) ;

		RCC_PLLCFGR = (((RCC_PLLCFGR ) &(~(0b111111<<PLLM_OFFST ))) |(PLLM_VALUE <<PLLM_OFFST )) ;


		/// choose the source cloclk for PLL
		RCC_PLLCFGR = (((RCC_PLLCFGR ) &(~(0b111111<<PLLSRC_OFFST  ))) |(PLLSRC_Choose_HSE <<PLLSRC_OFFST  )) ;

		///// 6 enable PLL
		RCC_CR = (((RCC_CR ) &(~(0b111111<<PLLON_OFFSET  ))) |(PLLON_ON_VALUE  <<PLLON_OFFSET  )) ;
		while(!(RCC_CR&PLLRDY_READY));

		///////7- select the clock source to use PLL


		RCC_CFGR = (((RCC_CFGR ) &(~(0b11<<SW_OFFSET))) |(SW_CHOOSE_PLL <<SW_OFFSET)) ;

      /// check the ready flage that endicat that succsfully we choosed PLL as system  clock source
		while( !((RCC_CFGR & SWS_MASK)==SWS_PLL_USED_READY)) ;/// I should use this line


		////RTC intialise




		/////////




			//// enable  GPIOA clock
			RCC_AHB1ENR = (((RCC_AHB1ENR ) &(~(0b1<<GPIOAEN_OFFSET ))) |(GOIOAEN_ON  <<GPIOAEN_OFFSET )) ;

			///////Enable timer2 clock  RCC_AHB2ENR



	}

