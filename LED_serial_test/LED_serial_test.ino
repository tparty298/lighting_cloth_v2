#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>
#define PININIT        13
#define NUMPIXELS      296
#define BRIGHTNESS     100

Adafruit_NeoPixel p=Adafruit_NeoPixel(NUMPIXELS, PININIT, NEO_GRB + NEO_KHZ800);

//general variable////////////////
int loopCount=0;
int serial_in=0;
int serial[3]={1,101,0};
int h_LED_first=0;
int h_LED_second=0;
int mode=0;
int h_LED=0;
int color_LED_first[3]={0,0,0};
int color_LED_second[3]={0,0,0};
float beat_sec;
int mode_change_flag=0;//モードの変更中は1
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
  p.begin();
  for(int i=0;i<NUMPIXELS;i++){
    p.setPixelColor(i, p.Color(0,0,0));
  }
  p.show();
  p.setBrightness(BRIGHTNESS);
  /////////////////////////////////////////////////////////////////////////

  //Music setup/////////////////////////////////
  beat_sec=60000.0/float(bpm);
  //////////////////////////////////////////////

  //MsTimer setup//////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////

}

void loop() { 
   //Serial///////////////////////
    if(Serial.available()>0){
      for(int i=0;i<3;i++){
        serial[i]=Serial.read();
        Serial.println(" ");
      }
    }
    mode=serial[2];
   ///////////////////////////////

   //color set/////////////////1~100or101~200のとき
   h_LED_first=map(serial[0],1,100,0,360);
   color_LED_first[0]=HSV_to_R(h_LED_first,255,255);//s,v=0~255
   color_LED_first[1]=HSV_to_G(h_LED_first,255,255);//s,v=0~255
   color_LED_first[2]=HSV_to_B(h_LED_first,255,255);//s,v=0~255
   h_LED_second=map(serial[1],101,200,0,360);
   color_LED_second[0]=HSV_to_R(h_LED_second,255,255);//s,v=0~255
   color_LED_second[1]=HSV_to_G(h_LED_second,255,255);//s,v=0~255
   color_LED_second[2]=HSV_to_B(h_LED_second,255,255);//s,v=0~255
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
      allLight(255,0,0);
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
   Serial.flush();
   //////////////////////////////
  
  loopCount++;
}
