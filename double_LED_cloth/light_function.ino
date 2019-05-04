void allLight(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      //p.setPixelColor(j, p.Color(r_in,g_in,b_in));
      Dwhich(j,r_in,g_in,b_in);
    }
    //p.show();
    all_show();
    //delay(10);
}

void runningLight(int r_in, int g_in, int b_in, int loopCount){
  int run_num=30;
  for(int i=0;i<NUMPIXELS;i++){
    if((loopCount%run_num)==(i%run_num)){
      //p.setPixelColor(i, p.Color(r_in,g_in,b_in));
      Dwhich(i,r_in,g_in,b_in);
    }
  }
  //p.show();
  all_show();
}

void noiseLight(int r1_in, int g1_in, int b1_in,int r2_in, int g2_in, int b2_in){
  for(int i=0;i<NUMPIXELS;i++){
    if(random(2)%2==0){
      //p.setPixelColor(i, p.Color(r1_in,g1_in,b1_in));
      Dwhich(i,r1_in,g1_in,b1_in);
    }else{
      //p.setPixelColor(i, p.Color(r2_in,g2_in,b2_in));
      Dwhich(i,r2_in,g2_in,b2_in);
    }
  }
  //p.show();
  all_show();
}


void noiseLightDelete(int r_in, int g_in, int b_in){
  for(int i=0;i<NUMPIXELS;i++){
    if(random(2)%2==0){
      //p.setPixelColor(i, p.Color(r_in,g_in,b_in));
      Dwhich(i,r_in,g_in,b_in);
    }else{
      //p.setPixelColor(i, p.Color(0,0,0));
      Dwhich(i,0,0,0);
    }
  }
  //p.show();
  all_show();
}

void rainbowLight(int loopNum){
  //int timeNow=int(millis()*rainbow_change_speed)%360;
  int timeNow=int((millis()%360)*rainbow_change_speed)%360;
  for(int j=0;j<NUMPIXELS;j++){
      int hue=map(j,0,NUMPIXELS,0,360); 
      hue+=timeNow;
      if(hue>360){
        hue-=360;
      }
      int red=HSV_to_R(hue,255,255);
      int green=HSV_to_G(hue,255,255);
      int blue=HSV_to_B(hue,255,255);
      //p.setPixelColor(j, p.Color(red,green,blue));
      Dwhich(j,red,green,blue);
    }
  all_show();
  //p.show();
}

