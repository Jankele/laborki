#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void liczby(char a[], char b[])
{
	printf ("Podaj liczbe o maksymalnej dlugosci 20 cyfr:\n");
	scanf ("%s", a);
	printf ("Pierwsza liczba wynosi %s.\n",a);
	printf ("Podaj liczbe o maksymalnej dlugosci 20 cyfr:\n");
	scanf ("%s", b);
	printf ("Druga liczba wynosi %s.",b);
}

void doprawej(char a[], char b[])
{
	int przesuniecie1, przesuniecie2, i, j;
	for (i= 0; a[i] != 0; i++)
		a[i] = a[i];
	przesuniecie1 = 20 - i;
	memmove(a+przesuniecie1,a,i);
	memset(a, 0, przesuniecie1);
	 
	for (j= 0; b[j] != 0; j++)
		b[j] = b[j];
	przesuniecie2 = 20 - j;
	memmove(b+przesuniecie2,b,j);
	memset(b, 0, przesuniecie2);
}

void liczenie(char a[], char b[], char wynik1[], int *reszta)
{
	int suma=0;
	int y=0;
	for(y=19; y>=0; y--)
	{ 
		if ( (a[y] != 0) || (b[y] != 0) )
		{
			if ( (a[y] != 0) && (b[y] != 0) )
			{
				suma = 0;
				suma += *reszta;
				*reszta = 0;
				suma += a[y] - '0' + b[y] - '0';
				*reszta = suma / 10;
				wynik1[y+1] = suma % 10 + '0';
			}
			else
			{
				suma = 0;
				suma += *reszta;
				*reszta = 0;
				suma += a[y] - '0' + b[y];
				*reszta = suma / 10;
				wynik1[y+1] = suma % 10 + '0';
			}
		}
	}
}

void dolewej(char wynik1[], char wynik2[])
{
	int b, przesuniecie;
	for (b=20; wynik1[b] != 0; b--)
		wynik1[b] = wynik1[b];
	przesuniecie = b+1;
	memmove(wynik2,wynik1+przesuniecie,20-b);
}

void dodanie_reszty(char liczba1[], char liczba2[], char wynik1[], int *reszta)
{
	int y=0;
	if ((liczba1[y] == 0) && (liczba2[y] == 0) && (*reszta==1))
	{
		wynik1[y+1] = 1 + '0';
		*reszta = 0;
	}
}

int main(int argc, char* argv[])
{
	unsigned char liczba1 [20] = {'0'};
	unsigned char liczba2 [20] = {'0'};
	unsigned char wynik1 [21] = {0};
	unsigned char wynik2 [21] = {0};
	int i, b, przesuniecie, reszta=0;
	liczby(liczba1,liczba2);
	doprawej(liczba1,liczba2);
	liczenie(liczba1,liczba2,wynik1,&reszta);
	dodanie_reszty(liczba1, liczba2, wynik1, &reszta);
	dolewej(wynik1, wynik2);
	printf("\nSuma wynosi %s.\n", wynik2);
	return 0;
}
