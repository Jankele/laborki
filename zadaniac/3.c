#include <stdio.h>
#include <stdlib.h>

int zadanie1(int * a, int * b)
{
	if(*a < *b)
		return *a;
	else
		return *b;
}

int * zadanie2(int * a, int * b)
{
        if(*a < *b)
                return a;
        else
                return b;
}

void zadanie3(int * a, int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void zadanie4(int * a, int * b)
{
	if(*a > *b)
	{
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
	}
}

int * zadanie9()
{
	int *a = NULL;
	a = malloc(sizeof(int *));
	*a = 5;
	return a;
}

int main()
{
	int a, b;
	int * ap = &a;
	int * bp = &b;
	printf("podaj pierwsza liczbe: ");
	scanf("%d", &a);
	printf("\npodaj druga liczbe: ");
	scanf("%d", &b);
	int wynik = zadanie1(ap, bp);
	printf("\nWynik wynosi: %d\n", wynik);
	int *wynikk = zadanie2(ap, bp);
	printf("\nWynik wynosi: %i\n", *wynikk);
	zadanie3(ap, bp);
	printf("a = %d\nb = %d\n", *ap, *bp);
	zadanie4(ap, bp);
        printf("a = %d\nb = %d\n", *ap, *bp);
	int * wynikkk = zadanie9();
	printf("\nzadanie 9 = %p\n wartosc = %d\n", wynikkk, *wynikkk);
	return 0;
}
