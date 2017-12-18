#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void wyczysc(int n, char napis[])
{
	napis[0] = '\0';
}

int dlugosc(char napis[])
{
	 return strlen(napis);
}


int porownaj(char napis[], char napis2[])
{
	if(strlen(napis) == strlen(napis2))
		return 1;
	else
		return 0;
}

void duze(char napis[])
{
	int n = strlen(napis);
	for(int i=0;i<n;i++)
	{
		if( isupper(napis[i]))
			napis[i] -= 32;
	}
}

void duzemale(char napis[])
{
	int n = strlen(napis);
	printf("napis: ");
	for(int i=0;i<n;i++)
	{
		if(napis[i] == ' '){
			printf(" ");}
		else
		{
			if(isupper(napis[i]))
				putchar(tolower(napis[i]));
			if(islower(napis[i]))
				putchar(toupper(napis[i]));
		}
	}
	printf("\n");
}

int main()
{
	int n = 11;
	char napis[11]="JeDeN TrZy";
	char napis2[9]="cztery d";
	printf("napis: %s\n", napis);
//	wyczysc(n, napis);
//	printf("napis: %s\n", napis);
//	int dlugoscc = dlugosc(napis);
//	printf("\n%d\n", dlugoscc);
//	int czy = porownaj(napis, napis2);
//	printf("\n%d\n", czy);
	duzemale(napis);
//	printf("napis po: %s\n", napis);
	return 0;
}
