#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(int argc, char **argv){
	int liczba = atoi(argv[1]);
	print_hello();
	printf("silnia z liczby 4 jest rowna: %d", factorial(4));
	if(liczba>0)
	printf("silnia z liczby %d jest rowna: %d\n", liczba, factorial(liczba));
	else
	printf("Liczba niepoprawna\n");
	return 0;
}
