/**
 * This program plays a guessing game with the user.
 * It selects a random number between 1 and 1000 and
 * prompts the user to guess the value, informing them
 * of whether or not it is higher or lower than the
 * actual value.  Once the user guesses correctly, the
 * game ends and the number of guesses is displayed.
 */
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

int main(int argc, char **argv) {

  int n = 1000;
  int i = 1;

  //seed the random number generator
  srand(time(NULL));
  int number = (rand() % n) + 1;

  int guess = -10;
  int num_guesses = 0;

  int upper = n;
  int lower = 0;

  printf("Guess-A-Number Game!\n");
  printf("If you get it wrong it will tell you which half the number is on\n");
  printf("Enter a number between 1 and %d\n", n);

  while(i == 1)
  {
    scanf("%d", &guess); //take in input

    if (guess == number){ //check if number is right if not give a hint
      i--;
    }else if(guess < lower || guess > upper){
      printf("That's outside the range... check your math \n");
    }else{
      if(guess < number){ //if lower than number higher
        printf("Guess higher, between ");
        lower = guess;
        if(number < (upper - (upper-lower)/2)){ // if the number is less than half way between current limit; lower upper
          upper = (upper - ((upper-lower)/2));
        }else{                          // if the number is greater than half way between current limit; rasie lower
          lower = (lower + ((upper-lower)/2));
        }
        printf("%d and %d\n", lower, upper);
      }else if(guess > number){ //if higher than number guess lower
        printf("Guess lower, between ");
        upper = guess;
        if(number < (upper - (upper-lower)/2)){ // if the number is less than half way between current limit; lower upper
          upper = (upper - ((upper-lower)/2));
        }else{                          // if the number is greater than half way between current limit; rasie lower
          lower = (lower + ((upper-lower)/2));
        }
        printf("%d and %d\n", lower, upper);
      }
    }
    num_guesses++;
  }

  printf("Congratulations, you found it!  Number of guesses: %d\n", num_guesses);
  return 0;
}
