#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int *r, int *g, int *b, Mode mode) {
  if(r == NULL || g == NULL || b == NULL){
    return ERROR_NULL;
  } else if(r < 0 || g < 0 || b < 0){
    return ERROR_NEGATIVE;
  } else if(mode < 0 || mode > 2 ){
    return NO_MODE;
  } else{
    if(mode == 0){
      *r = *g = *b = ((*r + *g + *b)/3);
    }else if(mode == 1){
      *r = *g = *b = ((max(*r, *g, *b) + min(*r, *g, *b))/2);
    }else if(mode == 2){
      *r = *g = *b = (.21*(*r) + .72*(*g) + .07*(*b));
    }
    return NO_ERROR;
  }
}

int toSepia(int *r, int *g, int *b) {
	*r = 0.393*(*r) + .769*(*g) + .189*(*b);
  *g = 0.349*(*r) + .686*(*g) + .168*(*b);
  *b = 0.272*(*r) + .534*(*g) + .131*(*b);
}