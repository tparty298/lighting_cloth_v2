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

