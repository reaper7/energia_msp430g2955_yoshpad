/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Rei VILO
  *     Contribution: Eric Brundick <spirilis@linux.com>
  *
  ***********************************************************************
  Derived from:
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

//SELECT PCB (OLD / NEW) *************************************************************************
//#define OLD_CONFIG_18_19  //DEFAULT OLD CONFIG ENABLED (P2.6 and P2.7 available on PINS 19 and 18) 
#undef OLD_CONFIG_18_19  //DEFAULT NEW CONFIG ENABLED (P1.1 and P3.7 available on PINS 19 and 18) 

//SELECT SPI BETWEEN USCI A0 / B0 ****************************************************************
#define USE_USCI_A0       //DEFAULT SPI ENABLED ON USCI_A0
//#undef USE_USCI_A0        //DEFAULT SPI ENABLED ON USCI_B0


#ifdef USE_USCI_A0 //USCI_A0
static const uint8_t SS      = 7;  /* P3.3 */
static const uint8_t SCK     = 6;  /* P3.0 */
static const uint8_t MOSI    = 4;  /* P3.4 */
static const uint8_t MISO    = 3;  /* P3.5 */
#else //USCI_B0
static const uint8_t SS      = 6;  /* P3.0 */
static const uint8_t SCK     = 7;  /* P3.3 */
static const uint8_t MOSI    = 15; /* P3.1 */
static const uint8_t MISO    = 14; /* P3.2 */
#endif

static const uint8_t TWISCL1  = 9;   /* P2.1 SW I2C */
static const uint8_t TWISDA1  = 10;  /* P2.2 SW I2C */
static const uint8_t TWISDA0  = 15;  /* P3.1 */
static const uint8_t TWISCL0  = 14;  /* P3.2 */
static const uint8_t DEBUG_UARTRXD = 3;  /* Receive  Data (RXD) at P3.5 */
static const uint8_t DEBUG_UARTTXD = 4;  /* Transmit Data (TXD) at P3.4 */
#define TWISDA1_SET_MODE  (INPUT)
#define TWISCL1_SET_MODE  (INPUT)
#define TWISDA0_SET_MODE  (PORT_SELECTION0 /* | INPUT_PULLUP*/) /* do not enable the pull ups for this device */
#define TWISCL0_SET_MODE  (PORT_SELECTION0 /* | INPUT_PULLUP*/)
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#define SPISCK_SET_MODE (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)

/* Define the default I2C settings */
#define DEFAULT_I2C -1 /* indicates SW I2C on pseudo module 1 */
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE

#define DEBUG_UART_MODULE_OFFSET 0x0

#define DEBUG_UART_MODULE 0x0

// ANALOG PINS
static const uint8_t A0  = 8;
static const uint8_t A1  = 9;
static const uint8_t A2  = 10;
static const uint8_t A3  = 11;
static const uint8_t A4  = 12;
static const uint8_t A5  = 6;
static const uint8_t A6  = 5;
#ifndef OLD_CONFIG_18_19
static const uint8_t A7  = 18; //?? replace (to pin J2/18)
#endif
//not available directly
#ifdef OLD_CONFIG_18_19
static const uint8_t A7  = 29; //?? replace (to pin J2/18)
#endif
static const uint8_t A12 = 24;
static const uint8_t A13 = 25;
static const uint8_t A14 = 26;
static const uint8_t A15 = 27;

static const uint8_t A8 = 128 + 8;  // special.  This is the VeREF+ signal
static const uint8_t A9 = 128 + 9;  // special.  This is Vref- / VeREF-
static const uint8_t A10 = 128 + 10; // special. This is the internal temp sensor
static const uint8_t A11 = 128 + 11; // special.  This is Vcc/2

static const uint8_t TEMPSENSOR = 128 + 10;

//                Yosh's MSP430G2955 20-pin mini PCB
//                Utilizing the MSP430G2955IRHA40R (VQFN-40)
//
//             J1                                                 J2
//        +-------------------------------------------------------------+
//        | Vcc  (1)       3.3V            |                  (20) GND  |
//        | P1.0 (2)  [29] PUSH1           |       PUSH2 [30] (19) P1.1 | P2.6 OLD_CONFIG_18_19
//        | P3.5 (3)  [24] MISO_A0/RXD     |          A7 [26] (18) P3.7 | P2.7 OLD_CONFIG_18_19
//        | P3.4 (4)  [23] MOSI_A0/TXD     |             [37] (17) TEST |
//        | P3.6 (5)  [25] A6              |             [ 5] (16) RST# |
//        | P3.0 (6)  [ 9] SCK_A0/CS_B0/A5 | SDA/MOSI_B0 [10] (15) P3.1 |
//        | P3.3 (7)  [12] CS_A0/SCK_B0    | SCL/MISO_B0 [11] (14) P3.2 |
//        | P2.0 (8)  [ 6] A0              |             [40] (13) P2.5 |
//        | P2.1 (9)  [ 7] A1              |          A4 [28] (12) P2.4 |
//        | P2.2 (10) [ 8] A2              |          A3 [27] (11) P2.3 |
//        +-------------------------------------------------------------+
//
// Pin names based on the silkscreen
//
static const uint8_t P1_0 = 2;   //[29]
static const uint8_t P3_5 = 3;   //[24]
static const uint8_t P3_4 = 4;   //[23]
static const uint8_t P3_6 = 5;   //[25]
static const uint8_t P3_0 = 6;   //[ 9]
static const uint8_t P3_3 = 7;   //[12]
static const uint8_t P2_0 = 8;   //[ 6]
static const uint8_t P2_1 = 9;   //[ 7]
static const uint8_t P2_2 = 10;  //[ 8]
static const uint8_t P2_3 = 11;  //[27]
static const uint8_t P2_4 = 12;  //[28]
static const uint8_t P2_5 = 13;  //[40]
static const uint8_t P3_2 = 14;  //[11]
static const uint8_t P3_1 = 15;  //[10]
#ifndef OLD_CONFIG_18_19
static const uint8_t P3_7 = 18;  //[26] //?? replace (to pin J2/18)
static const uint8_t P1_1 = 19;  //[30] //?? replace (to pin J2/19)
#else
static const uint8_t P2_7 = 18;  //[ 2] ?? internally for quartz
static const uint8_t P2_6 = 19;  //[ 3] ?? internally for quartz
#endif
//not available directly
static const uint8_t P4_0 = 21;  //[15]
static const uint8_t P4_1 = 22;  //[16]
static const uint8_t P4_2 = 23;  //[17]
static const uint8_t P4_3 = 24;  //[18]
static const uint8_t P4_4 = 25;  //[19]
static const uint8_t P4_5 = 26;  //[20]
static const uint8_t P4_6 = 27;  //[21]
static const uint8_t P4_7 = 28;  //[22]
#ifdef OLD_CONFIG_18_19
static const uint8_t P3_7 = 29;  //[26] //?? replace (to pin J2/18)
static const uint8_t P1_1 = 30;  //[30] //?? replace (to pin J2/19)
#else
static const uint8_t P2_7 = 29;  //[ 2] ?? internally for quartz
static const uint8_t P2_6 = 30;  //[ 3] ?? internally for quartz
#endif
static const uint8_t P1_2 = 31;  //[31]
static const uint8_t P1_3 = 32;  //[32]
static const uint8_t P1_4 = 33;  //[33]
static const uint8_t P1_5 = 34;  //[34]
static const uint8_t P1_6 = 35;  //[35]
static const uint8_t P1_7 = 36;  //[36]
//buttons
static const uint8_t PUSH1 = 2;
static const uint8_t PUSH2 = 19;

#ifdef ARDUINO_MAIN

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
	(uint16_t) &P3IN,
	(uint16_t) &P4IN
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
	(uint16_t) &P3OUT,
	(uint16_t) &P4OUT
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
	(uint16_t) &P3DIR,
	(uint16_t) &P4DIR
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
	(uint16_t) &P3REN,
	(uint16_t) &P4REN
};

const uint16_t port_to_sel0[] = {  /* put this PxSEL register under the group of PxSEL0 */
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
	(uint16_t) &P3SEL,
	(uint16_t) &P4SEL
};

const uint16_t port_to_sel2[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL2,
	(uint16_t) &P2SEL2,
	(uint16_t) &P3SEL2,
	(uint16_t) &P4SEL2
};


/* 
 * PWM output for Timer_A3 and Timer_B3 instances.
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy    */
	NOT_ON_TIMER, /* 1.  Vcc   */
	NOT_ON_TIMER, /* 2.  P1.0  */	
	NOT_ON_TIMER, /* 3.  P3.5  */
	NOT_ON_TIMER, /* 4.  P3.4  */
	T1A1,         /* 5.  P3.6  */
	NOT_ON_TIMER, /* 6.  P3.0  */
	NOT_ON_TIMER, /* 7.  P3.3  */					
	NOT_ON_TIMER, /* 8.  P2.0  */
	NOT_ON_TIMER, /* 9.  P2.1  */	
	T0B0,         /* 10. P2.2  */	
	T0A1,         /* 11. P2.3  */
	T0A2,         /* 12. P2.4  */
	T1B0,         /* 13. P2.5  */
	NOT_ON_TIMER, /* 14. P3.2  */
	NOT_ON_TIMER, /* 15. P3.1  */
	NOT_ON_TIMER, /*   RST#    */
	NOT_ON_TIMER, /*   TEST    */	
#ifndef OLD_CONFIG_18_19
	T1A2,         /* 18. P3.7  */  //?? replace (to pin J2/18)
	T0A0,         /* 19. P1.1  */  //?? replace (to pin J2/19)
#else
	NOT_ON_TIMER, /* 18. P2.7  */  //?? internally for quartz
	NOT_ON_TIMER, /* 19. P2.6  */  //?? internally for quartz
#endif
	NOT_ON_TIMER, /*   GND     */	
//not available directly
	T0B0,         /* 21. P4.0  */	
	T0B1,         /* 22. P4.1  */
	T0B2,         /* 23. P4.2  */
	T0B0,         /* 24. P4.3  */
	T0B1,         /* 25. P4.4  */	
	T0B2,         /* 26. P4.5  */		
	NOT_ON_TIMER, /* 27. P4.6  */
	NOT_ON_TIMER, /* 28. P4.7  */
#ifdef OLD_CONFIG_18_19
	T1A2,         /* 29. P3.7  */  //?? replace (to pin J2/18)
	T0A0,         /* 30. P1.1  */  //?? replace (to pin J2/19)
#else
	NOT_ON_TIMER, /* 29. P2.7  */  //?? internally for quartz
	NOT_ON_TIMER, /* 30. P2.6  */  //?? internally for quartz
#endif
	T0A1,         /* 31. P1.2  */
	T0A2,         /* 32. P1.3  */
	NOT_ON_TIMER, /* 33. P1.4  */
	T0A0,         /* 34. P1.5  */
	T0A1,         /* 35. P1.6  */
	T0A2          /* 36. P1.7  */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,    /*  dummy    */
	NOT_A_PIN,    /* 1.  Vcc   */
	P1,           /* 2.  P1.0  */	
	P3,           /* 3.  P3.5  */
	P3,           /* 4.  P3.4  */	
	P3,           /* 5.  P3.6  */	
	P3,           /* 6.  P3.0  */
	P3,           /* 7.  P3.3  */
	P2,           /* 8.  P2.0  */
	P2,           /* 9.  P2.1  */
	P2,           /* 10. P2.2  */
	P2,           /* 11. P2.3  */
	P2,           /* 12. P2.4  */
	P2,           /* 13. P2.5  */	
	P3,           /* 14. P3.2  */
	P3,           /* 15. P3.1  */
	NOT_A_PIN,    /*   RST#    */
	NOT_A_PIN,    /*   TEST    */	
#ifndef OLD_CONFIG_18_19
  P3,           /* 18. P3.7  */ //?? replace (to pin J2/18)
	P1,           /* 19. P1.1  */ //?? replace (to pin J2/19)
#else
	P2,           /* 18. P2.7  */  //?? internally for quartz
	P2,           /* 19. P2.6  */  //?? internally for quartz
#endif
	NOT_A_PIN,    /*   GND     */	
//not available directly
	P4,           /* 21. P4.0  */		
	P4,           /* 22. P4.1  */	
	P4,           /* 23. P4.2  */
	P4,           /* 24. P4.3  */
	P4,           /* 25. P4.4  */	
	P4,           /* 26. P4.5  */				
	P4,           /* 27. P4.6  */
	P4,           /* 28. P4.7  */
#ifdef OLD_CONFIG_18_19
  P3,           /* 29. P3.7  */ //?? replace (to pin J2/18)
	P1,           /* 30. P1.1  */ //?? replace (to pin J2/19)
#else
	P2,           /* 29. P2.7  */  //?? internally for quartz
	P2,           /* 30. P2.6  */  //?? internally for quartz
#endif
	P1,           /* 31. P1.2  */
	P1,           /* 32. P1.3  */
	P1,           /* 33. P1.4  */
	P1,           /* 34. P1.5  */
	P1,           /* 35. P1.6  */
	P1            /* 36. P1.7 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,    /*  dummy    */
	NOT_A_PIN,    /* 1.  Vcc   */
	BV(0),        /* 2.  P1.0  */
	BV(5),        /* 3.  P3.5  */
	BV(4),        /* 4.  P3.4  */
	BV(6),        /* 5.  P3.6  */	
	BV(0),        /* 6.  P3.0  */
	BV(3),        /* 7.  P3.3  */
  BV(0),        /* 8.  P2.0  */
	BV(1),        /* 9.  P2.1  */
	BV(2),        /* 10. P2.2  */
	BV(3),        /* 11. P2.3  */	
	BV(4),        /* 12. P2.4  */
	BV(5),        /* 13. P2.5  */
	BV(2),        /* 14. P3.2  */
	BV(1),        /* 15. P3.1  */
	NOT_A_PIN,    /*   RST#    */
	NOT_A_PIN,    /*   TEST    */	
#ifndef OLD_CONFIG_18_19
  BV(7),        /* 18. P3.7  */ //?? replace (to pin J2/18)
	BV(1),        /* 19. P1.1  */ //?? replace (to pin J2/19)
#else
	BV(7),        /* 18. P2.7  */ //?? internally for quartz
	BV(6),        /* 19. P2.6  */ //?? internally for quartz
#endif
	NOT_A_PIN,    /*   GND     */
//not available directly	
	BV(0),        /* 21. P4.0  */	
	BV(1),        /* 22. P4.1  */	
	BV(2),        /* 23. P4.2  */
	BV(3),        /* 24. P4.3  */	
	BV(4),        /* 25. P4.4  */
	BV(5),        /* 26. P4.5  */							
	BV(6),        /* 27. P4.6  */
	BV(7),        /* 28. P4.7  */
#ifdef OLD_CONFIG_18_19
  BV(7),        /* 29. P3.7  */ //?? replace (to pin J2/18)
	BV(1),        /* 30. P1.1  */ //?? replace (to pin J2/19)
#else
	BV(7),        /* 29. P2.7  */ //?? internally for quartz
	BV(6),        /* 30. P2.6  */ //?? internally for quartz
#endif
	BV(2),        /* 31. P1.2  */
	BV(3),        /* 32. P1.3  */
	BV(4),        /* 33. P1.4  */
	BV(5),        /* 34. P1.5  */
	BV(6),        /* 35. P1.6  */
	BV(7)         /* 36. P1.7 */
};

const uint32_t digital_pin_to_analog_in[] = {
	NOT_ON_ADC,   /*      dummy      */
	NOT_ON_ADC,   /* 1.   Vcc        */
	NOT_ON_ADC,   /* 2.   P1.0       */
	NOT_ON_ADC,   /* 3.   P3.5       */
	NOT_ON_ADC,   /* 4.   P3.4       */
	6,            /* 5.   P3.6 - A6  */
	5,            /* 6.   P3.0 - A5  */
	NOT_ON_ADC,   /* 7.   P3.3       */	
  0,            /* 8.   P2.0 - A0  */
	1,            /* 9.   P2.1 - A1  */
	2,            /* 10.  P2.2 - A2  */	
	3,            /* 11.  P2.3 - A3  */
	4,            /* 12.  P2.4 - A4  */
	NOT_ON_ADC,   /* 13.  P2.5       */
	NOT_ON_ADC,   /* 14.  P3.2       */
	NOT_ON_ADC,   /* 15.  P3.1       */	
	NOT_ON_ADC,   /*      RST#       */
	NOT_ON_ADC,   /*      TEST       */
#ifndef OLD_CONFIG_18_19
  7,            /* 18.  P3.7 - A7  */ //?? replace (to pin J2/18)
	NOT_ON_ADC,   /* 19.  P1.1       */ //?? replace (to pin J2/19)
#else
	NOT_ON_ADC,   /* 18.  P2.7       */ //?? internally for quartz
	NOT_ON_ADC,   /* 19.  P2.6       */ //?? internally for quartz
#endif
	NOT_ON_ADC,   /*      GND        */	
//not available directly	
	NOT_ON_ADC,   /* 21.  P4.0       */
	NOT_ON_ADC,   /* 22.  P4.1       */	
	NOT_ON_ADC,   /* 23.  P4.2       */	
	12,           /* 24.  P4.3 - A12 */
	13,           /* 25.  P4.4 - A13 */	
	14,           /* 26.  P4.5 - A14 */					
	15,           /* 27.  P4.6 - A15 */
	NOT_ON_ADC,   /* 28.  P4.7       */
#ifdef OLD_CONFIG_18_19
  7,            /* 29.  P3.7 - A7  */ //?? replace (to pin J2/18)
	NOT_ON_ADC,   /* 30.  P1.1       */ //?? replace (to pin J2/19)
#else
	NOT_ON_ADC,   /* 29.  P2.7       */ //?? internally for quartz
	NOT_ON_ADC,   /* 30.  P2.6       */ //?? internally for quartz
#endif
	NOT_ON_ADC,   /* 31.  P1.2       */
	NOT_ON_ADC,   /* 32.  P1.3       */
	NOT_ON_ADC,   /* 33.  P1.4       */
	NOT_ON_ADC,   /* 34.  P1.5       */
	NOT_ON_ADC,   /* 35.  P1.6       */
	NOT_ON_ADC    /* 36.  P1.7       */
};

#endif
#endif
