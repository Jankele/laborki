#include <stdlib.h> //malloc, etc.
#include <stdio.h> //printf, etc.
#include <string.h> //strlen, etc.
#include "functions.h"

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

void stworz_glowe(char znak, lista **glowa)
{
	*glowa = malloc(sizeof(lista));
	(*glowa)->lisc = malloc(sizeof(node));
	(*glowa)->next = NULL;
	(*glowa)->lisc->znak = znak;
	(*glowa)->lisc->lewa = NULL;
	(*glowa)->lisc->prawa = NULL;
	(*glowa)->lisc->ilosc = 1;
}

void push_front_and_count(char znak, lista **glowa)
{	
	//FUNKCJA TWORZY
		lista *tmp = NULL; 
		tmp = *glowa;
		int czy_znak_wystapil = 0;
		while(tmp != NULL)
		{
			if(tmp->lisc->znak == znak)
			{
				tmp->lisc->ilosc += 1;
				czy_znak_wystapil++;
				break;//nie potrzebujemy dalej przechodzic
			}
			tmp = tmp->next;	
		}
		if(czy_znak_wystapil == 0)
		{
		lista *tmp = NULL;
		tmp = malloc(sizeof(lista));
		tmp->lisc = malloc(sizeof(node));
		tmp->next = NULL;
		tmp->lisc->znak = znak;
		tmp->lisc->lewa = NULL;
		tmp->lisc->prawa = NULL;
		tmp->lisc->ilosc = 1;
		tmp->next = *glowa;
		*glowa = tmp;
		}
}

void stworz_drzewo_HF()
{

}
void usun_drzewo_HF()
{

}
void wyswietl_powtorzenia(lista **glowa)
{
	lista *tmp = NULL;
	tmp = *glowa;
	while(tmp)
	{
		if(tmp->lisc->znak == 32)
			printf("Spacja : %d\n", tmp->lisc->ilosc);
		else if(tmp->lisc->znak == 10)
			printf("Znak EOL : %d\n", tmp->lisc->ilosc);
		else
			printf("Znak %c : %d\n", tmp->lisc->znak, tmp->lisc->ilosc);
		tmp = tmp->next;
	}
	free(tmp);
}

void kodowanie_HF()
{

}