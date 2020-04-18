/* 
 * File:   Patterns.c
 * Author: isaak
 *
 * Created on 17 de abril de 2020, 08:25 PM
 */


#include "Patterns.h"
#include "Main.h"
#include "NeoFunctions.h"

/*
 * 
 */
void RGBLoop(){
  Time_Check(1);
  for(unsigned char j = 0; j < 3; j++ ) {
    // Fade IN
    for(int k = 0; k < 255; k++) {
        switch(j) {
          case 0: setAll(k,0,0); break;
          case 1: setAll(0,k,0); break;
          case 2: setAll(0,0,k); break;
        }
        if(BT_Patron != 2){
            setAll(0,0,0);
            return;
        }
        Delay_ms(BT_Time);
        }
    // Fade OUT
    for(int k = 255; k > 0; k--) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      if(BT_Patron != 2){
        setAll(0,0,0);
        return;
      }
      Delay_ms(BT_Time);
    }
  }
}
void colorWipe(void) {
    Time_Check(10);
    for(unsigned char i=0; i<NeoNum; i++) {
        setPixel(i, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        //setPixel(i,50,0,0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }   
    for(unsigned char i=0; i<NeoNum; i++) {
        //setPixel(i, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        setPixel(i,0,0,0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for(int i=NeoNum; i >= 0; i--){
        setPixel(i, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        //setPixel(i,50,0,0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for(int i=NeoNum; i >= 0; i--) {
        //setPixel(i, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        setPixel(i, 0, 0, 0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for (int i = 0; i < NeoNum; i++) {
        setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        setPixel(NeoNum-i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for(int i = 0; i < NeoNum; i++){
        setPixel(i,0,0,0);
        setPixel(NeoNum-i,0,0,0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for(int i = NeoNum/2; i >= 0; i--){
        setPixel(NeoNum-i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
    for(int i = NeoNum/2; i >= 0; i--){
        setPixel(NeoNum-i,0,0,0);
        setPixel(i,0,0,0);
        if(BT_Patron != 1|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
    }
}
void colorWipeRainbow(void){
    unsigned char *c;
    Time_Check(5);
    //
    for(unsigned char j=0; j<255;j++){
        for(unsigned char i=0;i<NeoNum;i++){
            c=Wheel((((i*256)/NeoNum)+j) & 255);
            setPixel(i, *c, *(c+1), *(c+2));
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        /*for(unsigned char i=0;i<NeoNum;i++){
            setPixel(i, 0, 0, 0);
            if(BT_Patron != 1){
                 
                setAll(0,0,0);
                return;
            }
            Show();
            Delay_ms(BT_Tiempo);
        }*/
        for(int i=NeoNum; i>=0; i--) {
            c=Wheel(((((NeoNum-i)*256)/NeoNum)+j) & 255);
            setPixel(i, *c, *(c+1), *(c+2));
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        for(int i=NeoNum/2; i>=0; i--) {
            setPixel(i,0,0,0);
            setPixel(NeoNum-i,0,0,0);
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        for (int i = 0; i < NeoNum; i++){
            c=Wheel((((i*256)/NeoNum)+j) & 255);
            setPixel(i,*c, *(c+1), *(c+2));
            setPixel(NeoNum-i,*c, *(c+1), *(c+2));
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        for(int i = 0; i < NeoNum/2; i++){
            setPixel(i,0,0,0);
            setPixel(NeoNum-i,0,0,0);
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        for(int i = NeoNum/2; i >= 0; i--){
            c=Wheel((((i*256)/NeoNum)+j) & 255);
            setPixel(i,*c, *(c+1), *(c+2));
            setPixel(NeoNum-i,*c, *(c+1), *(c+2));
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
        for(int i = NeoNum/2; i >= 0; i--){
            setPixel(NeoNum-i,0,0,0);
            setPixel(i,0,0,0);
            if(BT_Patron != 1 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
    }
}
void FadeInOut(){
    float r, g, b;
    Time_Check(5);
    for(int k = 0; k < 255; k=k+1) {
        r = (k/255.0)*BT_RGB[0];
        g = (k/255.0)*BT_RGB[1];
        b = (k/255.0)*BT_RGB[2];
        setAll(r,g,b);
        if( BT_Patron!= 2|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
  }
    for(int k = 255; k >0; k=k-2) {
        r = (k/255.0)*BT_RGB[0];
        g = (k/255.0)*BT_RGB[1];
        b = (k/255.0)*BT_RGB[2];
        setAll(r,g,b);
        if( BT_Patron!= 2|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
      }
  
}
void fadeInOutRainbow(void){
  unsigned char *c;
  float r, g, b;
    for(unsigned char j = 0; j < 255; j++) {
        for(unsigned char i=0;i<NeoNum;i++){
            c=Wheel((( i * 256 / NeoNum) + j) & 255);
            r = (j/255.0) * (*c);
            g = (j/255.0) * (*(c+1));
            b = (j/255.0) * (*(c+2));
            setPixel(i,r,g,b);
        }
        show();
        if(BT_Patron!= 2 || BT_rainbow != 1)return;
        Delay_ms(BT_Time);
      }
    for(unsigned char j = 255; j > 0; j--) {
        for(unsigned char i=0;i<NeoNum;i++){
              c=Wheel(((i * 256 / NeoNum) + j) & 255);
              r = (j/255.0) * (*c);
              g = (j/255.0) * (*(c+1));
              b = (j/255.0) * (*(c+2));
              setPixel(i,r,g,b);
          }
        show();
        if( BT_Patron!= 2 || BT_rainbow != 1)return;
        Delay_ms(BT_Time);
    }
}
void theaterChase() {
    Time_Check(5);
    for (unsigned char q=0; q < 5; q++) {
        for (int i=NeoNum/2; i>=0; i=i-5) {
            setPixel(i+q, BT_RGB[0], BT_RGB[1], BT_RGB[2]);    //turn every third pixel on
            setPixel((NeoNum-(i+1))-q, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        }
        if(BT_Patron != 3|| BT_rainbow != 0)return;
        setPixel(NeoNum/2, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        show();
        Delay_ms(BT_Time);
        for (int i=NeoNum/2; i>=0; i=i-5) {
            setPixel(i+q, 0,0,0);        //turn every third pixel off
            setPixel((NeoNum-(i+1))-q, 0,0,0);
        }
    }
}
void theaterChaseRainbow() {
    unsigned char *c;
    Time_Check(5);
    for (unsigned char j=0; j < 255; j++) {     // cycle all 256 colors in the wheel
      for (unsigned char q=0; q < 5; q++) {
          for (int i=NeoNum/2; i>=0; i=i-5) {
            c = Wheel( (i+j) % 255);
            setPixel(i+q, *c, *(c+1), *(c+2));    //turn every third pixel on
            setPixel((NeoNum-(i+1))-q, *c, *(c+1), *(c+2));
          }
          if(BT_Patron != 3 || BT_rainbow != 1)return;
          setPixel(NeoNum/2, *c, *(c+1), *(c+2));
          show();
          Delay_ms(BT_Time);
          for (int i=NeoNum/2; i>=0; i=i-5) {
            setPixel(i+q, 0,0,0);        //turn every third pixel off
            setPixel((NeoNum-(i+1))-q,0,0,0);
          }
          if(BT_Patron != 3 || BT_rainbow != 1)return;
      }
    }
}
void CylonBounce(int EyeSize){
    Time_Check(5);
    for(unsigned char i = 0; i < NeoNum-EyeSize-2; i++) {
      setAll(0,0,0);
      //setPixel(i, BT_RGB[0]/10, BT_RGB[1]/10, BT_RGB[2]/10);
      for(unsigned char j = 1; j <= EyeSize; j++) {
        setPixel(i+j, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
      }
      //setPixel(i+EyeSize+1, BT_RGB[0]/10, BT_RGB[1]/10, BT_RGB[2]/10);
      if(BT_Patron != 4|| BT_rainbow != 0)return;
      show();
      Delay_ms(BT_Time);
    }
    for(unsigned char i = NeoNum-EyeSize-2; i > 0; i--) {
      setAll(0,0,0);
      //setPixel(i, BT_RGB[0]/10, BT_RGB[1]/10, BT_RGB[2]/10);
      for(unsigned char j = 1; j <= EyeSize; j++) {
        setPixel(i+j, BT_RGB[0], BT_RGB[1], BT_RGB[2]);
      }
      //setPixel(i+EyeSize+1, BT_RGB[0]/10, BT_RGB[1]/10, BT_RGB[2]/10);
      if(BT_Patron != 4|| BT_rainbow != 0)return;
      show();
      Delay_ms(BT_Time);
    }
}
void CycloneBounceRainbow(int EyeSize){
    unsigned char *c;
    //int position = 0;
    Time_Check(5);
    for(int j=0; j<256;j++){
        for(unsigned char i = 0; i < NeoNum-EyeSize-2; i++) {
            c=Wheel(((i * 256 / NeoNum) + j) & 255);
            setPixel(i, *c/20, *(c+1)/20, *(c+2)/20);
            for(unsigned char j = 1; j <= EyeSize; j++){
                setPixel(i+j, *c, *(c+1), *(c+2)); 
            }
            setPixel(i+EyeSize+1, *c/20, *(c+1)/20, *(c+2)/20);
            if( BT_Patron!= 4 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
            }
            setAll(0,0,0);
        for(unsigned char i = NeoNum-EyeSize-2; i > 0; i--) {
            c=Wheel(((i * 256 / NeoNum) + j) & 255);
            setPixel(i, *c/20, *(c+1)/20, *(c+2)/20);
            for(unsigned char j = 1; j <= EyeSize; j++){
                setPixel(i+j, *c, *(c+1), *(c+2));
            }
            setPixel(i+EyeSize+1, *c/20, *(c+1)/20, *(c+2)/20);
            if( BT_Patron!= 4 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
        }
    }   
}
void rainbowCycle(void) {
    unsigned char *c;
    Time_Check(5);
    /*for(int j=0; j<255; j++) {
        for(int i=NeoNum/2; i >=0; i--) {
          c=Wheel(((i * 255 / NeoNum) + j) & 255);
          setPixel(NeoNum-i, *c, *(c+1), *(c+2));
          setPixel(i, *c, *(c+1), *(c+2));
        }
    if( BT_Patron!= 5)return;
    Show();
    Delay_ms(BT_Tiempo);
    }*/
    for(int j=0; j<255; j++) {
        for(int i=0; i < NeoNum; i++) {
          c=Wheel(((i * 255 / NeoNum) + j) & 255);
          setPixel(NeoNum-i, *c, *(c+1), *(c+2));
          setPixel(i, *c, *(c+1), *(c+2));
        }
    if( BT_Patron!= 5 || BT_rainbow != 1)return;
    show();
    Delay_ms(BT_Time);
  }
}
void SetAllColor(void){
    int flag = 5, counter = 0;
    unsigned char *newBT;
    
    Time_Check(10);
    for(int i= 0; i < 2500; ++i){
        setAll(BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        Delay_ms(20);
        if(BT_Patron != 5|| BT_rainbow != 0)return;
    }
    for(int i = 0; i < NeoNum; ++i){
        if(i < flag){
            newBT = staticWheel();
            setPixel(i,*newBT, *(newBT+1), *(newBT+2));
        }else{
            setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        }
        show();
        if(BT_Patron != 5|| BT_rainbow != 0)return;
        Delay_ms(BT_Time);
        counter++;
        if(counter == flag+5) flag += 10;
    }
    //Show();
    //Delay_ms(100);
    /*for(int i = 0; i < NeoNum; ++i){
        setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        Show();
        Delay_ms(BT_Tiempo);
        if(BT_Patron != 5)return;
    }*/
    flag = 5;
    counter = 0;
    for(int i = 0; i < NeoNum; ++i){
        if(i < flag){
            setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        }else{
            newBT = staticWheel();
            setPixel(i,*newBT, *(newBT+1), *(newBT+2));
        }
        show();
        if(BT_Patron != 5|| BT_rainbow != 0)return;
        Delay_ms(BT_Time);
        counter++;
        if(counter == flag+5) flag += 10;
    }
    //Show();
    Delay_ms(100);
    for(int i = 0; i < NeoNum; ++i){
        setPixel(i,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        show();
        Delay_ms(BT_Time);
        if(BT_Patron != 5|| BT_rainbow != 0)return;
    }
    if(BT_Patron != 5|| BT_rainbow != 0)return;
}

unsigned char* staticWheel(){
    unsigned char temp[3];
    for(int i=0; i< 3; i++){
        temp[i] = BT_RGB[i];
    }
    
    for(int i = 0; i < 3; i++){
        if((temp[i] < 50) && (temp[i] > 10)){
            temp[i] -= 20;
        }
        else if(temp[i] < 100 && temp[i] > 50){
            temp[i] -= 25;
        }
        else if(temp[i] < 150 && temp[i] > 100){
            temp[i] -= 50;
        }
        else if(temp[i] < 200 && temp[i] > 150){
            temp[i] -= 75;
        }
        else if((temp[i] < 255) && (temp[i] > 200)){
            temp[i] -= 100;
        }
    }
    return temp;
}
void Strobe(void){
    Time_Check(1);
    setAll(BT_RGB[0],BT_RGB[1],BT_RGB[2]);
    show();
    Delay_ms(BT_Time);
    setAll(0,0,0);
    show();
    Delay_ms(BT_Time);
    if(BT_Patron != 6|| BT_rainbow != 0)return;
    Delay_ms(BT_Time);
}
void strobeallColors(void){
    unsigned char *c;
    Time_Check(1);
    for(int i=0;i<256;i=i+25){
        c = Wheel(i);
        setAll(*c,*(c+1),*(c+2));
        show();
        Delay_ms(BT_Time);
        setAll(0,0,0);
        show();
        Delay_ms(BT_Time);
    }
    if(BT_Patron != 6)return;
    Delay_ms(BT_Time);
}
void FadeAllcolors(void){
    unsigned char *c;
    float r, g, b;
    Time_Check(5);
    for(int j=0;j<255;j=j+25){
        c = Wheel(j);
        for(int k = 0; k < 255; k=k+1) {
            r = (k/255.0)*(*c);
            g = (k/255.0)*(*(c+1));
            b = (k/255.0)*(*(c+2));
           setAll(r,g,b);
           if( BT_Patron!= 8 || BT_rainbow != 1)return;
            Delay_ms(BT_Time);
        }       
        for(int k = 255; k >0; k=k-2) {
            r = (k/255.0)*(*c);
            g = (k/255.0)*(*(c+1));
            b = (k/255.0)*(*(c+2));
            setAll(r,g,b);
            if( BT_Patron!= 8 || BT_rainbow != 1)return;
            Delay_ms(BT_Time);
      }
    }
}
void SetAllcolors(void){
    unsigned char *c;
    int flag = 10; 
    Time_Check(5);
    for(int j=0;j<255;j+=5){
        setAll( *c, *(c+1), *(c+2));
        for(int i = 0; i < NeoNum; i++){
            c = Wheel(j);
            setPixel(i, *c, *(c+1), *(c+2));
            show();
            Delay_ms(BT_Time);
        }
        Delay_ms(BT_Time);
        if( BT_Patron!= 8 || BT_rainbow != 0)return;
    }
}
void RunningLights(void) {
    int pixelOn= 4;
    int position = 0;
    Time_Check(3);
    for (unsigned char q=0; q < pixelOn; q++) {
        for (int i=NeoNum; i>=0; i=i-pixelOn) {
            setPixel(i+q, BT_RGB[0]/2, BT_RGB[1]/2, BT_RGB[2]/2);
            //setPixel(i+q+1, 0,0,0);
        }
        if(BT_Patron != 9|| BT_rainbow != 0)return;
        show();
        Delay_ms(BT_Time);
        for (int i=NeoNum; i>=0; i=i-pixelOn) {
            setPixel(i+q,BT_RGB[0], BT_RGB[1], BT_RGB[2]);
        }
        if(BT_Patron != 9|| BT_rainbow != 0)return;
    }
   /* for(int j=0; j<NeoNum*2; j++)
  {
      position++; // = 0; //Position + Rate;
      for(int i=0; i<NeoNum; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+position) * 127 + 128)/255)*BT_RGB[0],
                   ((sin(i+position) * 127 + 128)/255)*BT_RGB[1],
                   ((sin(i+position) * 127 + 128)/255)*BT_RGB[2]);
      }
     
      Show();
      Delay_ms(BT_Tiempo);
  }*/
}
void RunningLightsRainbow(void){
    int pixelOn = 5;
    unsigned char *c;
    Time_Check(5);
    
    for(int i = 0; i<255;i++){
        c = Wheel(i);
        for(int q = 0; q<pixelOn; q++){
            for (int i=0; i < NeoNum; i=i+pixelOn) {
                setPixel(i+q, *c/2,*(c+1)/2,*(c+2)/2);
                //setPixel(i+q+2, *c/4,*(c+1)/4,*(c+2)/4);
                //setPixel(i+q+4, *c/6,*(c+1)/6,*(c+2)/6);
            }
            if(BT_Patron != 9 || BT_rainbow != 1)return;
            show();
            Delay_ms(BT_Time);
            for (int i=0; i < NeoNum; i=i+pixelOn) {
                setPixel(i+q,*c,*(c+1),*(c+2));
                //Show();
            }
            if(BT_Patron != 9 || BT_rainbow != 1)return;
        }
    }
}
unsigned char * Wheel(int WheelPos) {
    static unsigned char c[3];

    if(WheelPos < 43) {
        
        c[0]=255;
        c[1]=0;
        c[2]=WheelPos*6;
    } else if(WheelPos < 86) {
     WheelPos -= 43;
        c[0]=255-(WheelPos*6);
        c[1]=0;
        c[2]=255 ;
    } else if(WheelPos < 129){
        WheelPos -= 86;
        c[0]=0;
        c[1]=WheelPos *6;
        c[2]=255;
    }else if(WheelPos < 171){
        WheelPos -= 129;
        c[0]=0;
        c[1]=255;
        c[2]=255 - (WheelPos*6);
    }else if(WheelPos < 213){
        WheelPos -= 171;
        c[0]=WheelPos*6;
        c[1]=255;
        c[2]=0;
    }else{
        WheelPos -= 213;
        c[0]=255;
         c[1]=255-(WheelPos *6);
         c[2]=0;
    }

    return c;
}
void Time_Check(int Time){
    if(BT_Time < Time){
        BT_Time = Time;
    }
    
}
void Delay_ms(int time){
    int l;
    if(time == 0){
        time = 1;
    }
    for(l=0;l<time;l++){
        __delay_ms(1);
    }
}


