#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fibonacci(int n){
	if(n == 0){
		return 0;
	} else if (n == 1){
		return 1;
	}else{
		return fibonacci(n-1) + 2*(fibonacci(n-2));
	}
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	printf("%d, %d\n", n, fibonacci(n));
	return 0;
}