#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * subtract(char *str, int start){
	if(start>=strlen(str)){
		return NULL;
	}else{
		printf("%s\n", &str[start]);
		return subtract(str, start+1);
	}
}

int main(int argc, char *argv[])
{
	subtract(argv[1], 0);
	return 0;
}
