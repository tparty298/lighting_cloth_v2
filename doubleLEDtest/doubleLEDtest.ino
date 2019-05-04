#include <Adafruit_NeoPixel.h>
#define PININIT        10
#define NUMPIXELS      19
#define BRIGHTNESS     10
#define SIGNAL 2

//Adafruit_NeoPixel pp[SIGNAL];
Adafruit_NeoPixel p1=Adafruit_NeoPixel(NUMPIXELS, PININIT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p2=Adafruit_NeoPixel(NUMPIXELS, PININIT+1, NEO_GRB + NEO_KHZ800);


int loopCount=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  p1.begin();
  p2.begin();
  
  p1.setBrightness(BRIGHTNESS);
  p2.setBrightness(BRIGHTNESS);

  for(int i=0;i<NUMPIXELS;i++){
    p1.setPixelColor(i, p1.Color(0,0,0));
    p2.setPixelColor(i, p2.Color(0,0,0));
  }
  p1.show();
  p2.show();
  /*
  p.begin();
  for(int i=0;i<NUMPIXELS;i++){
    p.setPixelColor(i, p.Color(0,0,0));
  }
  p.show();
  p.setBrightness(BRIGHTNESS);
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  for(int i=0;i<NUMPIXELS;i++){
    p.setPixelColor(i, p.Color(255,0,0));
  }
  p.show();
  */
  for(int j=1;j<=SIGNAL;j++){
    for(int i=0;i<NUMPIXELS;i++){
      if(j==1){
        if(i%2==0){
          whcich(j,i,255,0,0);
        }else{
          whcich(j,i,0,255,0);
        }
      }else{
        if(i%2==0){
          whcich(j,i,255,255,0);
        }else{
          whcich(j,i,0,255,255);
        }
      }
    }
  }
  all_show();
  loopCount++;
}

