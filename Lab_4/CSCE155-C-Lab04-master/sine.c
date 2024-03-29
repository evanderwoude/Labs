/**
 * This program uses a Taylor Series to compute a value
 * of sine.
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * A function to compute the factorial function, n!.
 */
long factorial(int n) {
  long result = 1, i;
  for(i=2; i<=n; i++) {
    result *= i;
  }
  return result;
}

int main(int argc, char **argv) {

  if(argc != 3) {
    fprintf(stderr, "Usage: %s x n\n", argv[0]);
    exit(1);
  }

  double x = atof(argv[1]);
  int n = atoi(argv[2]);

  double result = 0.0;

  //compute sin(x) using a taylor series out to n terms
  for (int i = 0; i < n; ++i)
  {
    result = result + ((pow(-1,i)/(factorial((2*i + 1))))*(pow(x,((2*i) +1.0))));
  }

  printf("sin(%f) = %f\n", x, result);

  return 0;
}
