/*
Write a program that will convert US Dollars to British Pounds and Japanese JPY. 10%
of the total amount of US Dollars will be taken as an exchange fee. For the rest of the
US Dollars, half will be changed to British Pounds and the other half to JPY. Assume
the exchange rate is: 1 US Dollar = 0.6 British Pound; 1 US Dollar = 76.8 JPY. The
3
program should ask the user to input the amount of US dollars then print an appropriate
output. An example run would look something like the following:
*/

#include <stdlib.h>
#include <stdio.h>

double main (){
	double USD, BP, JPY;

	printf("Please input the total amount of US Dollars: ");
	scanf("%lf", &USD);

	USD = USD*.9;
	USD = USD/2;
	BP = USD*.6;
	JPY = USD*76.8;

	printf("You get %.2lf British Pounds and %.2lf Japanese JPY\n", BP, JPY);
}