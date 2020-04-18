/* 
 * File:   NeoFunctions.h
 * Author: isaak
 *
 * Created on 17 de abril de 2020, 08:32 PM
 */

#ifndef NEOFUNCTIONS_H
#define	NEOFUNCTIONS_H

extern void Enviar_Bits(void);
__near unsigned char ByteR, ByteG, ByteB;
int NumofBytes[630];
const int rOffset = 0, gOffset = 1, bOffset=2;

void show(void);
void setAll(unsigned char Red, unsigned char Green, unsigned char Blue);
void setPixel(int n, unsigned char red,
        unsigned char green, unsigned char blue);

#endif	/* NEOFUNCTIONS_H */

