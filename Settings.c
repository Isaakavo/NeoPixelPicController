/* 
 * File:   Settings.c
 * Author: isaak
 *
 * Created on 17 de abril de 2020, 08:28 PM
 */
#include "Main.h"
#include "Settings.h"


/*
 * 
 */
void Config4550(void){
    while(!OSCCONbits.OSTS);
    
    OSCCONbits.IDLEN = 1;
    
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;
    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    //Config del TMR1
    TMR1H = 0xE8;             
    TMR1L = 0xEE;   //Interrupcion cada milisegundo
    T1CON = 0x91;   // Timer1 Registers Prescaler= 2 - TMR1 Preset = 59536 - Freq = 1000.00 Hz - Period = 0.001000 seconds
    
    //Config EUSART
    //TRISC |= 0b11000000;
    TRISCbits.TRISC6 = 1;
    TRISCbits.TRISC7 = 1;
    //ANSELC = 0;
    SPBRG = 0xE1; //Baudrate a 9600
    SPBRGH = 0x04;
    TXSTA = 0x24; //BRGH activo
    RCSTA = 0x90;
    BAUDCON = 0x08; //16 bit activo
    //Config de interrupciones
    //TMR1IE = 1;
    PIE1bits.RCIE = 1;
    RCONbits.IPEN = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE=1;
}

