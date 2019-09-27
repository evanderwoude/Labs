#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int toGrayScaleAverage(int r, int g, int b){
  return round(((double)r+g+b)/3);
}

int max(int r, int g, int b){
  if(r>b && r>g){
    return r;
  }else if (b>r && b>g){
    return b;
  }else{
    return g;
  }
}

int min(int r, int g, int b){
    if(r<b && r<g){
    return r;
  }else if (b<r && b<g){
    return b;
  }else{
    return g;
  }
}

int toGrayScaleLightness(int r, int g, int b){
  return ((max(r,g,b) + min(r,g,b))/2);
}

int toGrayScaleLuminosity(int r, int g, int b){
  return round(.21*r+.72*g+.07*b);
}

int toSepiaRed(int r, int g, int b){
  return (0.393*r + 0.769*g + 0.189*b);
}

int toSepiaGreen(int r, int g, int b){
  return (0.349*r + 0.686*g + 0.168*b);
}

int toSepiaBlue(int r, int g, int b){
  return (0.272*r + 0.534*g + 0.131*b);
}