#include "TIMERS.h"
#include"CLOCK.h"


///Read note
////!!!!! UIF flage take while to get set, a round a minute, Then it start to work fine.. when UIF flag got set it indiacte that sucssefully we wrote to the timer register.

 void timer2_initi(void)
 {RCC_APB1ENR  = (((RCC_APB1ENR  ) &(~(0b1<<TIM2EN_OFFSET ))) |(TIM2EN_ON    <<TIM2EN_OFFSET )) ;  //enable the clock for time2


	 TIM2_CR1 = (((TIM2_CR1 ) &(~(0b1<<CEN_OFFSET))) |(CEN_ON <<CEN_OFFSET)) ;  /// put one in CEN to enable the count in the time counter


	 TIM2_PSC= PSC_VALUE;                                                     //// Set the desired prescaler

     while(!(TIM2_SR&(1<<UIF_OFFSET)));      ////! is general true or fales not a bit operation this is very important to make sure that registers got the new values. it give me an error and it took me while to figure it out

  }



 void delaytime2_msec(int msec) /// time2  has 32 bit counter

 { TIM2_CNT=0;                 ///  Put zero in the count register to start count from zero


    while(TIM2_CNT<(msec*1000));  // My max frequency is 84M so I set prescaller to be 83. so I divided 84M by(83+1) so every count represent Micro secound. thus I multiblied how many msec I want to wait by 1000 to transfer it Micro Sec


  }



 void timer4_initi(void)
  {RCC_APB1ENR  = (((RCC_APB1ENR  ) &(~(0b1<<TIM4EN_OFFSET ))) |(TIM4EN_ON    <<TIM4EN_OFFSET )) ;


	 TIM4_CR1 = (((TIM4_CR1 ) &(~(0b1<<CEN_OFFSET))) |(CEN_ON <<CEN_OFFSET)) ;


	 TIM4_PSC= PSC_time4_VALUE;

    while(!(TIM4_SR&(1<<UIF_OFFSET)));      ////! is general true or fales not a bit operation

  }



 void delaytime4_micro_sec(int microsec) /// 16 bit counter

  { TIM4_CNT=0;


     while(TIM4_CNT<microsec);


  }



 void delaytime4_msec(int msec)
  {
	 for(int i=0; i<msec;i++)                                ////// every 1msec =1000 micro thus  delaytime4_mecro_sec(1000)
	 {
		 delaytime4_micro_sec(1000);
	 }


   }

