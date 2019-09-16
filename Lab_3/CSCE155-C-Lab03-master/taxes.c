/**
 * This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  double agi = 0.0;
  char c = 'N';
  double tax = 0.0;
  double childCredit = 0.0;
  double totalTax = 0.0;
  int numChildren = 0;

  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);

  printf("Do you have any children? (Y) or (N)? ");
  getchar(); //remove the endline character
  c = getchar();

  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? ");
    scanf("%d", &numChildren);
  }

  childCredit = numChildren*1000;

  //TODO: compute the tax, child credit, and total tax:
  if (agi >= 0 && agi <= 17000)
  {
    tax = .1;
    tax = (tax*agi);
  }else if (agi >= 17000 && agi <= 69000)
  {
    tax = .15;
    tax = (tax*(agi-17000)+1700);
  }else if (agi >= 69000 && agi <= 139350)
  {
    tax = .25;
    tax = (tax*(agi-69000)+9500);
  }else if (agi >= 139350 && agi <= 212300)
  {
    tax = .28;
    tax = (tax*(agi-139350)+27087.50);
  }else if (agi >= 212300 && agi <= 379150)
  {
    tax = .33;
    tax = (tax*(agi-212300)+47513.50);
  }else if (agi >= 379150)
  {
    tax = .35;
    tax = (tax*(agi-379150)+102574.00);
  }

  totalTax = tax - childCredit;

  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);

  return 0;
}