int HSV_to_R(int h, int s, int v)
{
  int r;
  
  int MAX=v;
  int MIN=MAX-(((s/float(255))*MAX));

  if(h>=0&&h<=60){
    r=MAX;
  }else if(h>60&&h<=120){
    r=((120-h)/float(60))*(MAX-MIN)+MIN;
  }else if(h>120&&h<=180){
    r=MIN;
  }else if(h>180&&h<=240){
    r=MIN;
  }else if(h>240&&h<=300){
    r=((h-240)/float(60))*(MAX-MIN)+MIN;
  }else if(h>300&&h<=360){
    r=MAX;
  }
  
  return r;
}

int HSV_to_G(int h, int s, int v)
{
  int g;
  
  int MAX=v;
  int MIN=MAX-(((s/float(255))*MAX));

  if(h>=0&&h<=60){
    g=(h/float(60))*(MAX=MIN)+MIN;
  }else if(h>60&&h<=120){
    g=MAX;
  }else if(h>120&&h<=180){
    g=MAX;
  }else if(h>180&&h<=240){
    g=((240-h)/float(60))*(MAX-MIN)+MIN;
  }else if(h>240&&h<=300){
    g=MIN;
  }else if(h>300&&h<=360){
    g=MIN;
  }
  
  return g;
}


int HSV_to_B(int h, int s, int v)
{
  int b;
  
  int MAX=v;
  int MIN=MAX-(((s/float(255))*MAX));

  if(h>=0&&h<=60){
    b=MIN;
  }else if(h>60&&h<=120){
    b=MIN;
  }else if(h>120&&h<=180){
    b=((h-120)/float(60))*(MAX-MIN)+MIN;
  }else if(h>180&&h<=240){
    b=MAX;
  }else if(h>240&&h<=300){
    b=MAX;
  }else if(h>300&&h<=360){
    b=((360-h)/float(60))*(MAX-MIN)+MIN;
  }
  
  return b;
}
