/* 
 * File:   Main.h
 * Author: Isaakavo
 *
 * Created on 17 de abril de 2020, 08:18 PM
 */

#ifndef MAIN_H
#define	MAIN_H

// PIC18F4550 Configuration Bit Settings

// CONFIG1L
#pragma config PLLDIV = 2,CPUDIV = OSC1_PLL2,USBDIV = 1

// CONFIG1H
#pragma config FOSC = HSPLL_HS,FCMEN = OFF,IESO = ON

// CONFIG2L
#pragma config PWRT = ON,BOR = ON,BORV = 2,VREGEN = OFF

// CONFIG2H
#pragma config WDT = OFF,WDTPS = 32768

// CONFIG3H
#pragma config CCP2MX = OFF,PBADEN = OFF,LPT1OSC = OFF,MCLRE = OFF

// CONFIG4L
#pragma config STVREN = ON,LVP = OFF,ICPRT = OFF,XINST = OFF

// CONFIG5L
#pragma config CP0 = OFF,CP1 = OFF,CP2 = OFF,CP3 = OFF

// CONFIG5H
#pragma config CPB = OFF,CPD = OFF
// CONFIG6L
#pragma config WRT0 = OFF,WRT1 = OFF, WRT2 = OFF,WRT3 = OFF 

// CONFIG6H
#pragma config WRTC = OFF,WRTB = OFF,WRTD = OFF

// CONFIG7L
#pragma config EBTR0 = OFF,EBTR1 = OFF,EBTR2 = OFF,EBTR3 = OFF

// CONFIG7H
#pragma config EBTRB = OFF

#include <xc.h>
#include "Patterns.h"
#include "NeoFunctions.h"
#include "Settings.h"

#define _XTAL_FREQ 48000000

const int NeoNum = 210;   //Number of pixels to drive.
volatile unsigned char BT_RC[5]; //Array of receive data, coming from master device.
volatile unsigned char BT_Patron; //Flag that sets the current patter.
volatile unsigned char BT_Time; //Variable that set the time for the pattern
volatile unsigned char BT_Buff =0; 
volatile unsigned char BT_RGB[3]; //Variable that lets set the colors on the pixels
volatile __bit BT_rainbow;  //Flag that allows to activate the rainbow patters.


//void __interrupt ISR(void);
void __interrupt() ISR(void);
void checkBuff(void);
void turnOff(void);
void initiateLeds(void);

#endif	/* MAIN_H */

