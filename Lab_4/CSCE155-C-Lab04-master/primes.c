/**
 * This program prints integers up to the input value
 * and prints whether or not they are prime.
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }

  int n = atof(argv[1]);
  int i;

  for(i=2; i<=n; i++) {
    int isPrime = 1;

    for(int j = 2; j <= (i/2); j++){ //from 2 up till the numbers square
      if (i == 4){ //4 is tricky because 2 doesn't work in equation
        isPrime = 0; //false
        break;  //jump out for that number
      }else if(i%j == 0 && i != 2){ //if the number can be divied by another number, up to but not including it's square, it's not prime
        isPrime = 0; //not prime
        break;  //jump out for that number
      }else{    //if number can't be divided then it's prime
        isPrime = 1; //true
      }
    }

    if(isPrime) {
      printf("%d is prime\n", i);
    } else {
      printf("%d is composite\n", i);
    }
  }



  return 0;
}
