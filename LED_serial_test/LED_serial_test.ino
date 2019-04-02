#include <Adafruit_NeoPixel.h>
#define PININIT        13
#define NUMPIXELS      296
#define BRIGHTNESS     255

Adafruit_NeoPixel p=Adafruit_NeoPixel(NUMPIXELS, PININIT, NEO_GRB + NEO_KHZ800);

int loopCount=0;
//int tmp=-1;
int tmp[4];
int get255;
int get254;
int get253;
int sIn;
int colorR[NUMPIXELS];
int colorG[NUMPIXELS];
int colorB[NUMPIXELS];
int r=0,g=0,b=0;
int R[5];
int G[5];
int B[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //p=Adafruit_NeoPixel(NUMPIXELS, PININIT+3, NEO_GRB + NEO_KHZ800);
  //p[0]=Adafruit_NeoPixel(NUMPIXELS, PININIT, NEO_GRB + NEO_KHZ800);
  p.begin();
  for(int i=0;i<NUMPIXELS;i++){
    p.setPixelColor(i, p.Color(0,0,0));
  }
  p.show();
  p.setBrightness(BRIGHTNESS);

  //RGBinit
  for(int i=0;i<5;i++){
    R[i]=0;
    G[i]=0;
    B[i]=0;
  }
}

void loop() {
  /*
  tmp=Serial.read();
  Serial.println(tmp);
  */
  Serial.println("here");
  do{
    get255=Serial.read();
  }while(get255!=255);
  tmp[0]=Serial.read();
  for(int i=1;i<5;i++){
    R[i-1]=R[i];
  }
  R[0]=tmp[0];
  for(int i=1;i<5;i++){
    r+=R[i];
  }
  r/=5;
  
  do{
    get254=Serial.read();
  }while(get254!=254);
  tmp[1]=Serial.read();
  for(int i=1;i<5;i++){
    G[i-1]=G[i];
  }
  G[0]=tmp[1];
  for(int i=1;i<5;i++){
    g+=G[i];
  }
  g/=5;

  
  do{
    get253=Serial.read();
  }while(get253!=253);
  tmp[2]=Serial.read();
  for(int i=1;i<5;i++){
    B[i-1]=B[i];
  }
  B[0]=tmp[2];
  for(int i=1;i<5;i++){
    b+=B[i];
  }
  b/=5;

  
  Serial.println(tmp[0]);
  Serial.println(tmp[1]);
  Serial.println(tmp[2]);
  for(int j=0;j<NUMPIXELS;j++){
    p.setPixelColor(j, p.Color(tmp[0],tmp[1],tmp[2]));
  }
  p.show();
  delay(50);
  /*
  Serial.println("read");
  do{
    tmp=Serial.read();
  }while(tmp!=255);
  //Serial.write(254);

  
  do{
    tmp=Serial.read();
  }while(tmp<0||tmp>250);
  r=tmp;

  do{
    tmp=Serial.read();
  }while(tmp<0||tmp>250);
  g=tmp;
  
  do{
    tmp=Serial.read();
  }while(tmp<0||tmp>250);
  b=tmp;

  for(int j=0;j<NUMPIXELS;j++){
    p.setPixelColor(j, p.Color(r,g,b));
  }
  p.show();
  Serial.println(r);
  Serial.println(g);
  Serial.println(b);
*/

  
  loopCount++;
}

/*   
    if(sIn==1){
      for(int i=0;i<NUMPIXELS;i++){
        p.setPixelColor(i, p.Color(255,0,0));
      }
      p.show();
    }
 */
