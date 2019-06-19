#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>
#define PININIT        10
#define NUMPIXELS      300//両はしは300 真ん中233
#define BRIGHTNESS     150

Adafruit_NeoPixel p1=Adafruit_NeoPixel(NUMPIXELS, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p2=Adafruit_NeoPixel(NUMPIXELS, 11, NEO_GRB + NEO_KHZ800);
//general variable////////////////z
int loopCount=0;
int serial_in=0;
int serial[4]={1,101,0,255};
int h_LED_first=0;
int h_LED_second=0;
int mode=0;
int value=255;
int value_st=255;
int h_LED=0;
int color_LED_first[3]={0,0,0};
int color_LED_second[3]={0,0,0};
float beat_sec;
int mode_change_flag=0;//モードの変更中は1
int running_function_call_num=0;
/////////////////////////////////

//change variable///////////////
int bpm=128;
float rainbow_change_speed=0.5;
////////////////////////////////

void setup() {
  
  //general setup///////////////////////////////////////////////////////////
  Serial.begin(9600);
  //////////////////////////////////////////////////////////////////////////
}

void loop() { 
   //Serial///////////////////////
    if(Serial.available()>0){//Serial.available()>0
      for(int i=0;i<4;i++){
        serial[i]=Serial.read();
        //Serial.print(serial[i]);///
        Serial.write(serial[i]);
        //Serial.print(" ");
        //Serial.print(serial[i]);
      }
      //Serial.println(" ");
      //Serial.print(" ");///
      //Serial.println(value);

      /*
      for(int i=0;i<4;i++){ //send
        Serial.write(serial[i]);
      }
      */
      
      
    }
    if(serial[3]>=221&&serial[3]<=240){
      value=map(serial[3],221,240,0,255);
    }
    if(serial[2]>=201&&serial[2]<=210){
      mode=serial[2];
    }
   ///////////////////////////////

   //color set/////////////////1~100or101~200のとき
   if(serial[0]>=1&&serial[0]<=100){
    h_LED_first=map(serial[0],1,100,0,360);
   }
   if(serial[1]>=101&&serial[1]<=200){
     h_LED_second=map(serial[1],101,200,0,360);
   }
   Serial.flush();
}
