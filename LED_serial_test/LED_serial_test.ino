#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>
#define PININIT        13
#define NUMPIXELS      296
#define BRIGHTNESS     255

Adafruit_NeoPixel p=Adafruit_NeoPixel(NUMPIXELS, PININIT, NEO_GRB + NEO_KHZ800);

//general variable////////////////
int loopCount=0;
int h_in=0;
int h_LED=0;
int color_LED[3]={0,0,0};
float beat_sec;
/////////////////////////////////

//change variable///////////////
int bpm=128;
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
  MsTimer2::set(100,timerFire);//fire per 100ms timerFire function
  MsTimer2::start();
  /////////////////////////////////////////////////////////////////////////

}

void loop() { 
   //Serial///////////////////////
    Serial.println("start");
    h_in=Serial.read();
    Serial.println(h_in);
   ///////////////////////////////

   //color set/////////////////
   h_LED=h_in*10;//h_in is 0~36, h_LED is 0~360
   color_LED[0]=HSV_to_R(h_LED,255,255);//s,v=0~255
   color_LED[1]=HSV_to_G(h_LED,255,255);//s,v=0~255
   color_LED[2]=HSV_to_B(h_LED,255,255);//s,v=0~255
   Serial.println("to RGB");
   Serial.println(color_LED[0]);
   Serial.println(color_LED[1]);
   Serial.println(color_LED[2]);
   //////////////////////////////
   
   //Light Cloth//////////////////
   allLightFlash(color_LED[0],color_LED[1], color_LED[2]);
   //////////////////////////////
  
  loopCount++;
}

void timerFire() {//per beat_sec ms
   
}

void allLightFlash(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(r_in,g_in,b_in));
    }
    p.show();
    
}
/*
 * for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(tmp[0],tmp[1],tmp[2]));
    }
    p.show();
 */



