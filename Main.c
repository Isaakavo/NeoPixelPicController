/* 
 * File:   Main.c
 * Author: Isaakavo
 *
 * Main file that control all the patterns.
 * The system works via BLuetooth. I use an interrupt via USART to catch all the 
 * command that an Android aplication sends.
 * The aplication send an array of values that let the PIC use the different pattern
 * from Patterns.c.
 * Besides that, the application allows to use a predetermined Rainbow patter
 * This patter put all the rainbow colors on the strip.
 * You also can set up the time that the pattern will be used, you can do that 
 * using BT_Time.
 * 
 */

#include "Main.h"

/*
 * 
 */
void __interrupt() ISR(void){
    if(PIR1bits.RCIF){
        BT_RC[BT_Buff] = RCREG;
        BT_Buff++;
        checkBuff();
        if (BT_Buff == 5)
        {
            BT_Buff = 0;
        }
        PIR1bits.RCIF = 0;
    }
}

void checkBuff(void){
    if(BT_RC[0] == 0x38 && BT_RC[4] == 0x30){
        if(BT_RC[1] == 0x42 && BT_RC[2] == 0x43 && BT_RC[3] == 0x44){
            BT_Patron = 1;
        }
        if(BT_RC[1] == 0x45 && BT_RC[2] == 0x46 && BT_RC[3] == 0x47){
            BT_Patron = 2;
        }
        if(BT_RC[1] == 0x48 && BT_RC[2] == 0x49 && BT_RC[3] == 0x50){
            BT_Patron = 3;
        }
        if(BT_RC[1] == 0x51 && BT_RC[2] == 0x52 && BT_RC[3] == 0x53){
            BT_Patron = 4;
        }
        if(BT_RC[1] == 0x54 && BT_RC[2] == 0x55 && BT_RC[3] == 0x56){
            BT_Patron = 5;
        }
        if(BT_RC[1] == 0x57 && BT_RC[2] == 0x58 && BT_RC[3] == 0x59){
            BT_Patron = 6;
        }
        if(BT_RC[1] == 0xFF && BT_RC[2] == 0xFF && BT_RC[3] == 0xFF){
            BT_Patron = 7;
        }
        if(BT_RC[1] == 0x60 && BT_RC[2] == 0x61 && BT_RC[3] == 0x62){
            BT_Patron = 8;
        }
        if(BT_RC[1] == 0x63 && BT_RC[2] == 0x64 && BT_RC[3] == 0x65){
            BT_Patron = 9;
        }
    }
    if(BT_RC[0] == 0x40 && BT_RC[4] == 0x32){
        BT_Time = BT_RC[2];
    }
    if(BT_RC[0] == 0x39 && BT_RC[4] == 0x31){
        BT_RGB[0] = BT_RC[1];
        BT_RGB[1] = BT_RC[2];
        BT_RGB[2] = BT_RC[3];
    }
    if(BT_RC[0] == 0x41 && BT_RC[4] == 0x42){
        if(BT_RC[1] == 0xAA && BT_RC[2] == 0xAA && BT_RC[3] == 0xAB){
            BT_rainbow = 1;
        }else if(BT_RC[1] == 0xAB && BT_RC[2] == 0xAA && BT_RC[3] == 0xAA){
            BT_rainbow = 0;
        }
    }
}
void turnOff(void){
    setAll(0,0,0);
    BT_Patron = 0;
    __delay_us(5);
    SLEEP();
    
}
void initiateLeds(void){
    BT_Patron = 2;
    RGBLoop();
    BT_Patron = 8;
    BT_rainbow = 0;
    BT_RGB[0] = 255;
    BT_RGB[1] = 0;
    BT_RGB[2] = 0;
}
int main() {

    Config4550();
    Delay_ms(500);
    initiateLeds();
    while(1){        
        switch (BT_Patron){
            case 1:
                if(BT_rainbow){
                    colorWipeRainbow();
                }else{
                  colorWipe();  
                }
                break;
            case 2:
                if(BT_rainbow){
                    fadeInOutRainbow();;
                }else{
                  FadeInOut();  
                }
                break;
            case 3:
                if(BT_rainbow){
                    theaterChaseRainbow();
                }else{
                  theaterChase();  
                }
                break;
            case 4:
                if(BT_rainbow){
                    CycloneBounceRainbow(6);
                }else{
                   CylonBounce(6); 
                }
                break;
            case 5:
                if(BT_rainbow){
                    rainbowCycle();
                }else{
                    SetAllColor();
                }
                break;
            case 6:
                if(BT_rainbow){
                    strobeallColors();
                }
                else{
                    Strobe();
                }
                break;
            case 7:
                turnOff();
                break;
           case 8:
               if(BT_rainbow){
                   FadeAllcolors();
               }
               else{
                    SetAllcolors();
               }
               break;
           case 9:
               if(BT_rainbow){
                   RunningLightsRainbow();
               }
               else{
                   RunningLights();
               }
               break;
            default:
                turnOff();
                break;
       }
    }
}

