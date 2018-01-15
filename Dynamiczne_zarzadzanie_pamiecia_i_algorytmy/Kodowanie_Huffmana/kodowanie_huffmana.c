/*	Kodowanie Huffmana
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------

Czytamy z pliku tekst.txt ktory musi znajdowac sie w tym samym katologu w ktorym uruchamiamy program
*/

#include <stdlib.h> //malloc, etc.
#include <stdio.h> //printf, etc.
#include <string.h> //strlen, etc.

typedef struct node
{
	char znak;
	int ilosc;
	struct node *lewa;
	struct node *prawa;
} node;

char *czytaj_plik(const char *plik)
{	
	char *tekst = NULL;
	FILE *fd;
	size_t dlugosc;

	if(fd = fopen(plik, "rb"))
	{
		fseek(fd, 0, SEEK_END);
		dlugosc = ftell(fd);
		rewind(fd);
		++dlugosc;
		if(!(tekst = malloc(sizeof(char) * dlugosc)))
			puts("Nie mozna przypisac pamieci dla zmiennej tekst!");
		fgets(tekst, dlugosc, fd);
		fclose(fd);
	}
	else
	{
		puts("Blad podczas otwierania pliku!");
		exit(EXIT_FAILURE);
	}
	return tekst;
}

void zlicz_liczbe_wystapien(char znak)
{
	
}

void stworz_drzewo_HF()
{

}
void usun_drzewo_HF()
{

}
void wyswietl()
{

}
void kodowanie_HF()
{

}


int main()
{
	char *tekst = czytaj_plik("tekst.txt");
	printf("%s\n", tekst);
	int dlugosc = strlen(tekst);
	printf("%d\n", dlugosc);
	return EXIT_SUCCESS;
}