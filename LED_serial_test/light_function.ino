void allLight(int r_in, int g_in, int b_in){ //for test
  for(int j=0;j<NUMPIXELS;j++){
      p.setPixelColor(j, p.Color(r_in,g_in,b_in));
    }
    p.show();
    delay(10);
}

void flushLight(int r_in, int g_in, int b_in){ //for test
  allLight(r_in,g_in,b_in);
  delay(30);
  allLight(0,0,0);
}
