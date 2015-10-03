// ----------------------------------------------------------------------------
//         ATMEL Microcontroller Software Support  -  ROUSSET  -
// ----------------------------------------------------------------------------
// DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
// DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
// OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ----------------------------------------------------------------------------
// File Name           : AT91SAM7SE-EK.h
// Object              : AT91SAM7SE-EK Evaluation Board Features Definition File
// Creation            : JPP 09-May-2006
//  ----------------------------------------------------------------------------

#ifndef AT91SAM7SE_EK_H
#define AT91SAM7SE_EK_H


/*-----------------*/
/* LEDs Definition */
/*-----------------*/
#define AT91B_LED1          (1<<1)   // PA1          PA1/PWM1/A1/NBS2
#define AT91B_LED2          (1<<2)   // PA2          PA2/PWM2/A2
#define AT91B_POWERLED      (1<<0)   // PA0          PA0/PWM0/A0/ NBS0
#define AT91B_NB_LEB        3
#define AT91B_LED_MASK      (AT91B_POWERLED|AT91B_LED1|AT91B_LED2)
#define AT91D_BASE_PIO_LED  (AT91C_BASE_PIOA)
#define AT91D_ID_PIO_LED    (AT91C_ID_PIOA)
/*-------------------------------*/
/* JOYSTICK Position Definition  */
/*-------------------------------*/
#define AT91B_SW1    (1<<23)  // PB23 Up Button	        PB23/PWM0/D21
#define AT91B_SW2    (1<<24)  // PB24 Down Button       PB24/PWM1/D22
#define AT91B_SW3    (1<<27)  // PB27 Push Button       PB27/TIOB2/D25
#define AT91B_SW4    (1<<26)  // PB26 Right Button      PB26/TIOA2/D24
#define AT91B_SW5    (1<<25)  // PB25 Push Button       PB25/PWM2/D23

#define AT91B_BP1    (1<<25)  // PB25 left click / Push Button PB25/PWM2/D23
#define AT91B_BP2    (1<<22)  // PB22 Right Clic               PB22/NPCS3/D20

#define AT91B_SW_MASK  (AT91B_SW1|AT91B_SW2|AT91B_SW3|AT91B_SW4|AT91B_SW5)
#define AT91B_BP_MASK  (AT91B_BP1|AT91B_BP2)
#define AT91D_BASE_PIO_SW   (AT91C_BASE_PIOB)
#define AT91D_ID_PIO_SW     (AT91C_ID_PIOB)

#define AT91B_DBGU_BAUD_RATE	115200

/*---------------*/
/* SPI interface */
/*---------------*/
/* MN5 SERIAL DATAFLASH AT45DB642E
   SPI   Name : Port
   SPI  SCK  PA14 / SPI_SPCK
   CS        PA11 / SPI_NPCS0
   SO        PA12 /SPI_MISO
   SI        PA13 /SPI_MOSI
*/
#define DATAFLASH_PERI Peripheral_A
#define DATAFLASH_SI   AT91C_PA13_MOSI
#define DATAFLASH_SO   AT91C_PA12_MISO
#define DATAFLASH_CS   AT91C_PA11_NPCS0
#define DATAFLASH_SCK  AT91C_PA14_SPCK

/*---------------*/
/* Clocks       */
/*--------------*/
#define AT91B_MAIN_OSC        18432000               // Main Oscillator MAINCK
#define AT91B_MCK             ((18432000*73/14)/2)   // Output PLL Clock (48 MHz)
#define AT91B_MASTER_CLOCK     AT91B_MCK

#endif /* AT91SAM7SE-EK_H */
