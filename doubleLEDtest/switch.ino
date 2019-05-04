void whcich(int p_num, int n, int r, int g, int b){
  switch(p_num){
    case 1:
      p1.setPixelColor(n, p1.Color(r,g,b));
      break;
    case 2:
      p2.setPixelColor(n, p2.Color(r,g,b));
  }
}

void all_show(){
  p1.show();
  p2.show();
}

