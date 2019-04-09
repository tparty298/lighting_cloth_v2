void allLight(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(r_in,g_in,b_in));
    }
    p.show();
    //delay(10);
}

void runningLight(int r_in, int g_in, int b_in){
  int run_num=10;
  for(int i=0;i<run_num;i++){
    for(int j=0;j<NUMPIXELS;j++){
        if(j%run_num==i){
          p.setPixelColor(j, p.Color(r_in,g_in,b_in));
        }else{
          p.setPixelColor(j, p.Color(0,0,0));
        }
     }
     p.show();
  }
}

