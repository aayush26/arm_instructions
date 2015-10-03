#include <AT91SAM7SE512.H>              /* AT91SAM7SE512 definitions          */
#include "../AT91SAM7SE-EK.h"           /* AT91SAM7SE-EK board definitions    */

#define SPEED (AT91B_MAIN_OSC/1000)

int i, j;

void delay( unsigned int t){
	j = SPEED;
	while(j>0){
		j-=t*10000;
	}
}
/*
 * Main Program
 */

int main (void) {
  
	//to enable the peripheral clock for the PWMC
	AT91C_BASE_PMC->PMC_PCER= (1 << AT91C_ID_PWMC);		// PID = 10

	//to enable slow clock
	AT91C_BASE_PMC->PMC_MCKR = 0x00000000;
	
	
  //to disable the pins for gpio function
  AT91C_BASE_PIOA->PIO_PDR= AT91C_PIO_PA0 | AT91C_PIO_PA1;

  //to select peripheral A by A-Select-Register(pg-37)
  AT91C_BASE_PIOA->PIO_ASR= AT91C_PA0_PWM0  | AT91C_PA1_PWM1;

  //to disable peripheral B
  AT91C_BASE_PIOA->PIO_BSR=0;
	
	//PWM mode register: clka, clkb turned off; rea, preb set to MCK
	AT91C_BASE_PWMC->PWMC_MR = 0x00000000;
	
	/*===========================================
	PWM channel mode register: 
	CPD=0(0=update duty cycle using PWM_CUPD, 1=update period using PWM_CUPD when channel is enabled); 
	polarity=0(O/P waveform starts at low level); 
	alignment=0(left aligned); 
	CPRE(prescalar)=0(MCK);
	===========================================*/
	AT91C_BASE_PWMC->PWMC_CH[0].PWMC_CMR = AT91C_PWMC_CPRE_MCK | AT91C_PWMC_CALG | AT91C_PWMC_CPOL;
	delay(3000);
	
	//set period
	AT91C_BASE_PWMC->PWMC_CH[0].PWMC_CPRDR = 0x000000FF;
	delay(3000);
	
	//set duty cycle
	AT91C_BASE_PWMC->PWMC_CH[0].PWMC_CDTYR = 220;
	delay(300000);
	
	//enable PWM channel
	AT91C_BASE_PWMC->PWMC_ENA = 1 << 0;
	
	//disable interrupt
	AT91C_BASE_PWMC->PWMC_IDR = 1 << 0;

  // Loop forever
  while(1) {
					
  }
}
