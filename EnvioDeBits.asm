 #include <xc.inc>     

    
    GLOBAL  _ByteR
    GLOBAL  _ByteG
    GLOBAL  _ByteB
    
    GLOBAL  _Enviar_Bits

    PSECT myspace, local, class = CODE, reloc = 2
 
 
_Enviar_Bits:
Enviar_Bit23:
    btfsc   _ByteG, 7
    goto    Enviar_Bit23_1
Enviar_Bit23_0:
    call    NeoBit0
    goto    Enviar_Bit22
 
Enviar_Bit23_1:
    call    NeoBit1
    
Enviar_Bit22:
    btfsc   _ByteG, 6
    goto    Enviar_Bit22_1
Enviar_Bit22_0:
    call    NeoBit0
    goto    Enviar_Bit21
 
Enviar_Bit22_1:
    call    NeoBit1
    
Enviar_Bit21:
    btfsc   _ByteG,5
    goto    Enviar_Bit21_1
Enviar_Bit21_0:
    call    NeoBit0
    goto    Enviar_Bit20
Enviar_Bit21_1:
    call    NeoBit1
    
Enviar_Bit20:
    btfsc   _ByteG,4
    goto    Enviar_Bit20_1
Enviar_Bit20_0:
    call    NeoBit0
    goto    Enviar_Bit19
Enviar_Bit20_1:
    call    NeoBit1
    
Enviar_Bit19:
    btfsc   _ByteG,3
    goto    Enviar_Bit19_1
Enviar_Bit19_0:
    call    NeoBit0
    goto    Enviar_Bit18
Enviar_Bit19_1:
    call    NeoBit1
    
Enviar_Bit18:
    btfsc   _ByteG,2
    goto    Enviar_Bit18_1
Enviar_Bit18_0:
    call    NeoBit0
    goto    Enviar_Bit17
Enviar_Bit18_1:
    call    NeoBit1
    
Enviar_Bit17:
    btfsc   _ByteG,1
    goto    Enviar_Bit17_1
Enviar_Bit17_0:
    call    NeoBit0
    goto    Enviar_Bit16
Enviar_Bit17_1:
    call    NeoBit1
    
Enviar_Bit16:
    btfsc   _ByteG,0
    goto    Enviar_Bit16_1
Enviar_Bit16_0:
    call    NeoBit0
    goto    Enviar_Bit15
Enviar_Bit16_1:
    call    NeoBit1
    
Enviar_Bit15:
    btfsc   _ByteR,7
    goto    Enviar_Bit15_1
Enviar_Bit15_0:
    call    NeoBit0
    goto    Enviar_Bit14
Enviar_Bit15_1:
    call    NeoBit1
    
Enviar_Bit14:
    btfsc   _ByteR,6
    goto    Enviar_Bit14_1
Enviar_Bit14_0:
    call    NeoBit0
    goto    Enviar_Bit13
Enviar_Bit14_1:
    call    NeoBit1
    
Enviar_Bit13:
    btfsc   _ByteR,5
    goto    Enviar_Bit13_1
Enviar_Bit13_0:
    call    NeoBit0
    goto    Enviar_Bit12
Enviar_Bit13_1:
    call    NeoBit1
    
Enviar_Bit12:
    btfsc   _ByteR,4
    goto    Enviar_Bit12_1
Enviar_Bit12_0:
    call    NeoBit0
    goto    Enviar_Bit11
Enviar_Bit12_1:
    call    NeoBit1
    
Enviar_Bit11:
    btfsc   _ByteR,3
    goto    Enviar_Bit11_1
Enviar_Bit11_0:
    call    NeoBit0
    goto    Enviar_Bit10
Enviar_Bit11_1:
    call    NeoBit1
    
Enviar_Bit10:
    btfsc   _ByteR,2
    goto    Enviar_Bit10_1
Enviar_Bit10_0:
    call    NeoBit0
    goto    Enviar_Bit9
Enviar_Bit10_1:
    call    NeoBit1
    
Enviar_Bit9:
    btfsc   _ByteR,1
    goto    Enviar_Bit9_1
Enviar_Bit9_0:
    call    NeoBit0
    goto    Enviar_Bit8
Enviar_Bit9_1:
    call    NeoBit1
    
Enviar_Bit8:
    btfsc   _ByteR,0
    goto    Enviar_Bit8_1
Enviar_Bit8_0:
    call    NeoBit0
    goto    Enviar_Bit7
Enviar_Bit8_1:
    call    NeoBit1
    
Enviar_Bit7:
    btfsc   _ByteB,7
    goto    Enviar_Bit7_1
Enviar_Bit7_0:
    call    NeoBit0
    goto    Enviar_Bit6
Enviar_Bit7_1:
    call    NeoBit1
    
Enviar_Bit6:
    btfsc   _ByteB,6
    goto    Enviar_Bit6_1
Enviar_Bit6_0:
    call    NeoBit0
    goto    Enviar_Bit5
Enviar_Bit6_1:
    call    NeoBit1
    
Enviar_Bit5:
    btfsc   _ByteB,5
    goto    Enviar_Bit5_1
Enviar_Bit5_0:
    call    NeoBit0
    goto    Enviar_Bit4
Enviar_Bit5_1:
    call    NeoBit1
    
Enviar_Bit4:
    btfsc   _ByteB,4
    goto    Enviar_Bit4_1
Enviar_Bit4_0:
    call    NeoBit0
    goto    Enviar_Bit3
Enviar_Bit4_1:
    call    NeoBit1
    
Enviar_Bit3:
    btfsc   _ByteB,3
    goto    Enviar_Bit3_1
Enviar_Bit3_0:
    call    NeoBit0
    goto    Enviar_Bit2
Enviar_Bit3_1:
    call    NeoBit1
    
Enviar_Bit2:
    btfsc   _ByteB,2
    goto    Enviar_Bit2_1
Enviar_Bit2_0:
    call    NeoBit0
    goto    Enviar_Bit1
Enviar_Bit2_1:
    call    NeoBit1
    
Enviar_Bit1:
    btfsc   _ByteB,1
    goto    Enviar_Bit1_1
Enviar_Bit1_0:
    call    NeoBit0
    goto    Enviar_Bit0
Enviar_Bit1_1:
    call    NeoBit1
    
Enviar_Bit0:
    btfsc   _ByteB,0
    goto    Enviar_Bit0_1
Enviar_Bit0_0:
    call    NeoBit0
    return
Enviar_Bit0_1:
    call    NeoBit1
    return
    
;===============================================================================
;   Routine to generate the necessary bits to comunicate the PIC with the
;   WS2812B chip.
;   The documentation ask for a time of 1.25uS +/- 600nS to send the bit.
;   For the bit 0 is required a high time of 0.4 uS +/- 150nS and for the low signal time
;   of 0.85uS +/- 150 ns 
;   For the bit 1 is required a high signal time of 0.8 uS +/- 150 ns and fot the low signal time
;   0.45 uS +/- 150nS
;   The WS2812B chip require a low state reset time when the 24 bits had been send
;   that time must be at least 50uS. That delay is included in the main program.
;   Device clock = 48MHz  ->  Tcy = 83.33333nS
;================================================================================
NeoBit1:
                        ;2 cycles from call
    bsf    LATB,4       ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    ;nop                 ;1 cycle
                        ;Time in high of 750nS
    bcf     LATB,4       ;1 cycle
    return              ;2 cycles
			;Low signal time of 250nS, keep in mind that at
                        ;exit the routine other instructions are executed that
                        ;take time to perform, so they consume low signal time
                        ;routine's total time: 1.166667uS
NeoBit0:
                        ;2 cycles del call
    bsf     LATB,4       ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
    nop                 ;1 cycle
                        ;Time in high de 333.3nS
    bcf     LATB,4       ;1 cycle
    ;nop                 ;1 cycle
    ;nop                 ;1 cycle
    ;nop                 ;1 cycle
    ;nop                 ;1 cycle
    return              ;2 cycles
                        ;Time in low de 583.31 nS
                        ;Tiempo total de la rutina 1.083333uS