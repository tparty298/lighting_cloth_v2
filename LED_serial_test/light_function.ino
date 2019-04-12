void allLight(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(r_in,g_in,b_in));
    }
    p.show();
    //delay(10);
}

void runningLight(int r_in, int g_in, int b_in, int loopCount){
  int run_num=30;
  for(int i=0;i<NUMPIXELS;i++){
    if((loopCount%run_num)==(i%run_num)){
      p.setPixelColor(i, p.Color(r_in,g_in,b_in));
    }
  }
  p.show();
}

void noiseLight(int r1_in, int g1_in, int b1_in,int r2_in, int g2_in, int b2_in){
  for(int i=0;i<NUMPIXELS;i++){
    if(random(2)%2==0){
      p.setPixelColor(i, p.Color(r1_in,g1_in,b1_in));
    }else{
      p.setPixelColor(i, p.Color(r2_in,g2_in,b2_in));
    }
  }
  p.show();
}

