#include <stdlib.h> //malloc, etc.
#include <stdio.h> //printf, etc.
#include <string.h> //strlen, etc.
#include "functions.h"

/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
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
		if(!(tekst = malloc(sizeof(char) * dlugosc)))
			puts("Nie mozna przypisac pamieci dla zmiennej tekst!");
		fread(tekst, dlugosc, 1, fd);
		// tylko funkcja fread mozna bezproblemowo i bez uzywania petli
		// mozna skopiowac cala zawartosc pliku do tablicy razem bialymi znakami
		fclose(fd);
	}
	else
	{
		puts("Blad podczas otwierania pliku!");
		exit(EXIT_FAILURE);
	}
	return tekst;
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void stworz_glowe(char znak)
{
	glowa = malloc(sizeof(lista));
	glowa->lisc = malloc(sizeof(node));
	glowa->next = NULL;
	glowa->lisc->znak = znak;
	glowa->lisc->lewa = NULL;
	glowa->lisc->prawa = NULL;
	glowa->lisc->ilosc = 1;
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak)
{	
	//FUNKCJA TWORZY
		lista *tmp = NULL; 
		tmp = glowa;
		int czy_znak_wystapil = 0;
		while(tmp)
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
		tmp->lisc->valid = 1;
		tmp->lisc->kod = NULL;
		tmp->lisc->lewa = NULL;
		tmp->lisc->prawa = NULL;
		tmp->lisc->ilosc = 1;
		tmp->next = glowa;
		glowa = tmp;
		}
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void wyswietl_powtorzenia()
{
	lista *tmp = NULL;
	tmp = glowa;
	while(tmp)
	{
		if(tmp->lisc->znak == 32)
			printf("Znak Spacja %5d\n", tmp->lisc->ilosc);
		else if(tmp->lisc->znak == 10)
			printf("Znak EOL%9d\n", tmp->lisc->ilosc);
		else if(tmp->lisc->znak == 9)
			printf("Znak TAB%9d\n", tmp->lisc->ilosc);
		else
			printf("Znak %c %10d\n", tmp->lisc->znak, tmp->lisc->ilosc);
		tmp = tmp->next;
	}
	free(tmp);
	puts("");
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void zloz_liste(int dlugosc, char *tekst)
{
	for(int i=1;i<dlugosc;i++)
		dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(tekst[i]);
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void sortowanie_listy()
{
	lista *pom = NULL; // obecnie sprawdzany element
	lista *pom_next = NULL; // element nastepny
	lista *pom2 = NULL;
	lista *pom_kontener = NULL; 
	lista *warunek = NULL;

	while(glowa->next != warunek)
	{
		pom = glowa;
		pom2 = pom;
		pom_next = pom->next;
		while(pom != warunek)
		{
			if(pom->lisc->ilosc > pom_next->lisc->ilosc)
			{
				pom_kontener = pom_next->next;
				pom_next->next = pom;
				pom->next = pom_kontener;
				if(pom == glowa)
				{
					glowa = pom_next;
					pom2 = pom_next;
				}
				else
				{
					pom2->next = pom_next;
					pom2 = pom_next;
				}
			}
			else
			{
				pom2 = pom;
				pom = pom->next;
			}
			pom_next = pom->next;
			if(pom_next == warunek)
				warunek = pom;
		}
	}
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
TODO - OGARNAC!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void stworz_drzewo_HF()
{
	if(glowa->next == NULL)
	{
		wezel = glowa->lisc;
		free(glowa);
		glowa = NULL;
	}
	else
	{
		node* pop_kontener = NULL;
		node* pop_kontener2 = NULL;

		if(glowa != NULL)
		{
			lista* tmp = glowa;
			glowa = tmp->next;
			pop_kontener = tmp->lisc;
			free(tmp);
		}
		if(glowa != NULL)
		{
			lista* tmp2 = glowa;
			glowa = tmp2->next;
			pop_kontener2 = tmp2->lisc;
			free(tmp2);
		}

		lista* polaczone_kontenery = NULL;
		polaczone_kontenery  = malloc(sizeof(lista));
		polaczone_kontenery -> lisc = malloc(sizeof(node));
		polaczone_kontenery -> lisc -> znak = '*';
		polaczone_kontenery -> lisc -> ilosc = pop_kontener -> ilosc + pop_kontener2 -> ilosc;
		polaczone_kontenery -> lisc -> valid = 0;
		polaczone_kontenery -> lisc -> kod = NULL;
		polaczone_kontenery -> lisc -> lewa = NULL;
		polaczone_kontenery -> lisc -> prawa = NULL;
		    
		if(pop_kontener -> ilosc > pop_kontener2 -> ilosc)
		{
		    polaczone_kontenery -> lisc -> lewa = pop_kontener;
		    polaczone_kontenery -> lisc -> prawa = pop_kontener2;
		}
		else
		{
		    polaczone_kontenery -> lisc -> lewa = pop_kontener2;
		    polaczone_kontenery -> lisc -> prawa = pop_kontener;
		}

		polaczone_kontenery -> next = NULL;  		
		polaczone_kontenery -> next = glowa;
		glowa = polaczone_kontenery;

		sortowanie_listy(glowa);
	}

}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
TODO - OGARNAC!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void kodowanieHT(node* pom_kontener, char* kodHT, int generacja, int w_ktora_strone)
{

	if(pom_kontener != NULL)
	{
		pom_kontener -> kod = malloc(generacja+1 * sizeof(char));
		if(pom_kontener == wezel)
			sprintf(pom_kontener->kod,"%s","0");
		else
			sprintf(pom_kontener->kod,"%s%c",kodHT, w_ktora_strone);
		
		if(pom_kontener != wezel && pom_kontener -> znak != '*' && pom_kontener-> valid == 1)
		{	
			entry* tmp = NULL;
			tmp = malloc(sizeof(node));
			tmp -> ilosc = pom_kontener -> ilosc;
			tmp -> znak = pom_kontener -> znak;
			tmp -> kod = malloc(generacja+1 * sizeof(char));
			sprintf(tmp->kod,"%s%c",kodHT, w_ktora_strone);
			tmp -> lewa = glowa_listy;
			glowa_listy = tmp;
			dlugosc_kodu += generacja * tmp -> ilosc; 
		} 
		
		if(pom_kontener->lewa != NULL)
			kodowanieHT(pom_kontener->lewa, pom_kontener->kod, generacja+1, LEWA_GALAZ);
		if(pom_kontener->prawa != NULL)
			kodowanieHT(pom_kontener->prawa, pom_kontener->kod, generacja+1, PRAWA_GALAZ);
	}

}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE???
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void usun_drzewo_HF()
{
	if(wezel)
	{
		usun_drzewo_HF(wezel->lewa);
		usun_drzewo_HF(wezel->prawa);
		free(wezel);	
	}
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void sformatuj_tekst(char *tekst, size_t dlugosc)
{
	puts("-------------------------------------------");
	for(int i=0;i<dlugosc;i++)
		printf("%c", tekst[i]);
	puts("");
	puts("-------------------------------------------");
}
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
DONE!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void zniszcz_liste()
{
		while(glowa)
		{
			lista* tmp = NULL;
			tmp = glowa;
			glowa = tmp->next;
			free(tmp);
		}
}

char *przeszukaj_kod(char fragment)
{
	entry* dopisz = NULL;
	dopisz = glowa_listy;
	while(dopisz != NULL)
		{
			if(dopisz->znak == fragment)
			{	
				//return symbol code
				char* code = calloc(strlen(dopisz->kod)+1,sizeof(char));
				memcpy(code,dopisz->kod,strlen(dopisz->kod));
				return(code);
			}
			dopisz = dopisz->lewa;
		}
		return("-");
}