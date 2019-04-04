#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>
#define PININIT        13
#define NUMPIXELS      296
#define BRIGHTNESS     10

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
  /////////////////////////////////////////////////////////////////////////

}

void loop() { 
   //Serial///////////////////////
    //Serial.println("start");
    if(Serial.available()>0){
      h_in=Serial.read();
      //Serial.println(h_in);
    }
   ///////////////////////////////

   //color set/////////////////
   h_LED=int(h_in*3.6);//h_in is 0~100, h_LED is 0~360
   Serial.println(h_LED);
   color_LED[0]=HSV_to_R(h_LED,255,255);//s,v=0~255
   color_LED[1]=HSV_to_G(h_LED,255,255);//s,v=0~255
   color_LED[2]=HSV_to_B(h_LED,255,255);//s,v=0~255
   //////////////////////////////
   
   //Light Cloth//////////////////
   allLight(color_LED[0],color_LED[1], color_LED[2]);
   //////////////////////////////
  
  loopCount++;
}


void allLight(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(r_in,g_in,b_in));
    }
    p.show();
    
}


