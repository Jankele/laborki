#include <stdio.h>
#include <stdlib.h>

int zmienna = 0;

int sumowanie()
{
	static int sumka;
	int tmp;
	printf("\nPodaj liczbe: ");
	scanf("%d", &tmp);
	printf("Dotychczasowa suma wynosi: %d\n", sumka += tmp);
	return sumka;
}

int wczytanie()
{
	int wartosc;
	printf("\npodaj liczbe: \n");
	scanf("%d", &wartosc);
	return wartosc;
}

void bezwzgledna(int a)
{
	printf("\nWartosc bezwzgledna z %d wynosi: %d\n", a, a*(-1));
}

unsigned int potegowanie(unsigned int a)
{
	unsigned int potega = 2;
	for (unsigned int i=1;i<a;i++)
		potega = potega * 2;
	return potega;
}

unsigned int potegowanie2(unsigned int a, unsigned int b)
{
	int i = 1;
	unsigned int tmp = a;
	while(i<b)
	{
		a = a * tmp;
		i++;
	}
	return a;
}

unsigned int silnia(unsigned int a)
{
	if(a>1)
	{
		a = a * silnia(a-1);
	}
	return a;
}

void ile()
{
	zmienna++;
	printf("Funkcja wykonała się %d razy.\n", zmienna);
}
int main()
{
//	unsigned int a = wczytanie();
//	unsigned int b = wczytanie();
//	bezwzgledna(a);
//	int wynik = potegowanie2(a, b);
//	printf("\nwynik wynosi: %d", wynik);
//	printf("\n");
	for(int i=0;i<5;i++)
//		ile();
	sumowanie();
	return 0;
}
