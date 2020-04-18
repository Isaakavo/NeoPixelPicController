
#include "Main.h"
#include "NeoFunctions.h"

/*
    Functions that are inspired on Adafruit NeoPixel Library
 * 
 * setPixel takes as arguments the RGB color code to put on WS2812B
 * I use an array to store all the different colors for all pixels
 * 
 * The show() functions allow to put the values onto the WS2812B calling the asm
 * code "Enviar_Bits". That asm code allows a precise time control.
 * 
 * setAll() its just a function that allows to put all the strip with the same color.
 * 
 
 */


void show(void){
    int *ptrInicial = &NumofBytes[0];
    
    for(int i=0;i<NeoNum;i++){
        ByteR = ptrInicial[rOffset];
        ByteG = ptrInicial[gOffset];
        ByteB = ptrInicial[bOffset];
        ptrInicial+=3;
        Enviar_Bits();
    }
    __delay_us(150);
}
void setAll(unsigned char Red, unsigned char Green, unsigned char Blue){
    //int i;
    
    for(int i = 0; i < NeoNum; i++) {
        setPixel(i, Red, Green, Blue);
    }
    show();
}

void setPixel(int n, unsigned char red,
        unsigned char green, unsigned char blue){
    int *ptr;
    
    if(n < NeoNum){
        //Apuntamos al valor inicial de cada arreglo de color R, G, B
        ptr = &NumofBytes[n*3];
    
        ptr[rOffset] = red;          // R,G,B always stored
        ptr[gOffset] = green;
        ptr[bOffset] = blue;
    }
    
}
