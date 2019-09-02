
#include <stdlib.h>
#include <stdio.h>

#include "imageUtils.h"

int main(int argc, char **argv) {

  int h, w;
  Pixel **image = loadImage("yourImage.jpeg", &h, &w);

  saveImage("copy.jpg", image, h, w);

  return 0;
}
