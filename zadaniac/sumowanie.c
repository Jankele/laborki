#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//stala N to rozmiar tablicy czyli maksymalna dlugosc sumowanej liczby
#define N 200

//Funkcja pobiera od użytkownika liczby w postaci znakowej i zapisuje je do tablic przekazanych w parametrach
void liczby(char a[], char b[])
{
	printf("Maksymalna dlugosc liczby to: %d\n", N);
	printf("Podaj pierwsza liczbe:\n");
	scanf("%s", a);
	printf("Podaj druga liczbe:\n");
	scanf("%s", b);
}
//funkcja zamienia miejscami zera z liczba wpisana przez uzytkownika
void doprawej(char a[])
{
	int zera, i=0, czy=1;
	while(czy==1)
	{
		if(a[i]!=0)
			i++;
		else
			czy--;
	}
   	zera = N - i;
	memmove(a+zera,a,i);
	memset(a, 0, zera);
}
//funkcja sumuje liczby oraz przesuwa reszte
void liczenie(char a[], char b[], char wynik1[])
{
	int suma=0, i=N-1, reszta=0;
	for(i;i>=0;i--)
	{
		if ( (a[i] != 0) || (b[i] != 0) )
		{
			if ( (a[i] != 0) && (b[i] != 0) )
			{
				suma = 0;
				suma += reszta;
				suma += a[i] - '0' + b[i] - '0';
				reszta = suma / 10;
				wynik1[i+1] = suma % 10 + '0';
			}
			else
			{
				suma = 0;
				suma += reszta;
				suma += a[i] - '0' + b[i];
				reszta = suma / 10;
				wynik1[i+1] = suma % 10 + '0';
			}
		}
		if ((a[i] == 0) && (b[i] == 0) && (reszta==1))
		{
			wynik1[i+1] = 1 + '0';
			reszta = 0;
		}
	}
}
//funkcja przesuwa wynik do lewej
void dolewej(char a[])
{
	int zera, i=N-1, j=0, czy=1;
	while(czy==1)
	{
		if(a[i]!=0)
			i--;
		else
			czy--;
	}
	memmove(a,a+i+1,N-i);
	memset(a+(N-i),0,i+1);
}

int main(int argc, char* argv[])
{
	unsigned char liczba1 [N] = {'0'};
	unsigned char liczba2 [N] = {'0'};
	unsigned char wynik [N+1] = {0};
	liczby(liczba1,liczba2);
	doprawej(liczba1);
	doprawej(liczba2);
	liczenie(liczba1,liczba2,wynik);
	dolewej(wynik);
	printf("\nSuma wynosi %s.\n", wynik);
	return 0;
}
