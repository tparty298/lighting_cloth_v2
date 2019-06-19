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

  //LED tape setup//////////////////////////////////////////////////////////
  p1.begin();
  p2.begin();
  p1.setBrightness(BRIGHTNESS);
  p2.setBrightness(BRIGHTNESS);
  for(int i=0;i<NUMPIXELS;i++){
    //p.setPixelColor(i, p.Color(0,0,0));
    Dwhich(i,0,0,0);//here
  }
  //p.show();
  all_show();
  /////////////////////////////////////////////////////////////////////////

  //Music setup/////////////////////////////////
  beat_sec=60000.0/float(bpm);
  //////////////////////////////////////////////

  //MsTimer setup//////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////

}

void loop() { 
   //Serial///////////////////////
    if(Serial.available()>0){//Serial.available()>0
      for(int i=0;i<4;i++){
        serial[i]=Serial.read();
        Serial.print(" ");
      }
      Serial.print(" ");
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
   color_LED_first[0]=HSV_to_R(h_LED_first,255,value);//s,v=0~255
   color_LED_first[1]=HSV_to_G(h_LED_first,255,value);//s,v=0~255
   color_LED_first[2]=HSV_to_B(h_LED_first,255,value);//s,v=0~255
   if(serial[1]>=101&&serial[1]<=200){
     h_LED_second=map(serial[1],101,200,0,360);
   }
   color_LED_second[0]=HSV_to_R(h_LED_second,255,value);//s,v=0~255
   color_LED_second[1]=HSV_to_G(h_LED_second,255,value);//s,v=0~255
   color_LED_second[2]=HSV_to_B(h_LED_second,255,value);//s,v=0~255
   /*
   if(serial_in>=1&&serial_in<=200){
     if(serial_in<=100){
      h_LED=map(serial_in,1,100,0,360);
      color_LED_first[0]=HSV_to_R(h_LED,255,255);//s,v=0~255
      color_LED_first[1]=HSV_to_G(h_LED,255,255);//s,v=0~255
      color_LED_first[2]=HSV_to_B(h_LED,255,255);//s,v=0~255
      allLight(255,0,0);
     }else{//予約色のとき
      h_LED=map(serial_in,101,200,0,360);
      color_LED_second[0]=HSV_to_R(h_LED,255,255);//s,v=0~255
      color_LED_second[1]=HSV_to_G(h_LED,255,255);//s,v=0~255
      color_LED_second[2]=HSV_to_B(h_LED,255,255);//s,v=0~255
     }
   }
   */
   //////////////////////////////
   
   //Light Cloth ここでオペレーションをする//////////////////
   switch(mode){
    case 0:
      break;
    case 201:
      allLight(0,0,0);
      break;
    case 202:
      //allLight(20,0,0);
      allLight(10,10,10);
      break;
    case 203:
      runningLight(color_LED_first[0],color_LED_first[1],color_LED_first[2],loopCount);
      break;
    case 204:
      runningLight(color_LED_second[0],color_LED_second[1],color_LED_second[2],loopCount);
      break;
    case 205:
      allLight(color_LED_first[0],color_LED_first[1],color_LED_first[2]);
      break;
    case 206:
      allLight(color_LED_second[0],color_LED_second[1],color_LED_second[2]);
      break;
    case 207:
      noiseLight(color_LED_first[0],color_LED_first[1],color_LED_first[2],color_LED_second[0],color_LED_second[1],color_LED_second[2]);
      break;
    case 208:
      noiseLightDelete(color_LED_first[0],color_LED_first[1],color_LED_first[2]);
      break;
    case 209:
      noiseLightDelete(color_LED_second[0],color_LED_second[1],color_LED_second[2]);
      break;
    case 210:
      rainbowLight(loopCount);
      break;
    default:
      break;
   }
   /*
   Serial.print(h_LED_first);
   Serial.print(" ");
   Serial.print(h_LED_first);
   Serial.print(" ");
   Serial.print(mode);
   Serial.print(" ");
   Serial.print(value);
   */
   Serial.flush();
   //////////////////////////////
  
  loopCount++;
}
