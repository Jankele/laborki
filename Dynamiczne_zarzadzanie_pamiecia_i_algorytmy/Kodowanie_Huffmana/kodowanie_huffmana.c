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

typedef struct lista
{
	struct node *lisc;
	struct lista *next; 
} lista;

node *wezel = NULL;
lista *glowa = NULL; 

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

void stworz_lisc(char znak)
{
	lista *tmp = NULL;
	int czy_znak_wystapil = 0;
	//ALOKACJA PAMIECI DLA TYMCZASOWEGO ELEMENTU STOSU
	if(!(tmp = malloc(sizeof(lista))))
	{	
		perror("Blad podczas alokowania pamieci");
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next = NULL;
		tmp->lisc->znak = znak;
		tmp->lisc->lewa = NULL;
		tmp->lisc->prawa = NULL; 
	}
	//ZLICZENIE ZNAKOW ORAZ ZMIANA WSKAZNIKA GLOWY NA TYMCZASOWY ELEMENT
	if(glowa == NULL)
	{
		tmp->lisc->ilosc = 1;
		glowa = tmp;
	}
	else
	{
		tmp = glowa;
		while(tmp)
		{
			if(tmp->lisc->znak == znak)
			{
				tmp->lisc->ilosc += 1;
				czy_znak_wystapil++;
			}
			tmp = tmp->next;	
		}
		if(czy_znak_wystapil == 0)
		{
			tmp->lisc->ilosc = 1;
			tmp->next = glowa;
			glowa = tmp;
		}
	}
}

void stworz_drzewo_HF()
{

}
void usun_drzewo_HF()
{

}
void wyswietl_powtorzenia(lista *node)
{
	lista *tmp = NULL;
	tmp = node;
	while(tmp)
	{
		printf("Znak %c : %d\n", tmp->lisc->znak, tmp->lisc->ilosc);
		tmp = tmp->next;
	}
	free(tmp);
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
	for(int i=0;i<dlugosc;i++)
		stworz_lisc(tekst[0]);
	wyswietl_powtorzenia(glowa);
	return EXIT_SUCCESS;
}