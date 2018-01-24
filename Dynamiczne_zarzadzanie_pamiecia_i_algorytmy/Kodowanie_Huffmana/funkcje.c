#include <stdlib.h> //malloc, calloc, free
#include <stdio.h> //printf, scanf
#include <string.h> //strlen, strcat
#include "funkcje.h"

char* czytaj_plik(const char* plik)
{
	char *tekst = NULL;
	FILE *fd;
	size_t dlugosc;

	if(fd = fopen(plik, "rb"))
	{
		fseek(fd, 0, SEEK_END);
		dlugosc = ftell(fd);
		rewind(fd);
		if(!(tekst = malloc(sizeof(char) * dlugosc+1)))
			puts("Nie mozna przypisac pamieci dla zmiennej tekst!");
		fread(tekst, dlugosc, 1, fd);
		// tylko funkcja fread mozna bezproblemowo i bez uzywania petli
		// mozna skopiowac cala zawartosc pliku do tablicy razem bialymi znakami
		fclose(fd);
		tekst[dlugosc] = '\0';
	}
	else
	{
		puts("Blad podczas otwierania pliku!");
		exit(EXIT_FAILURE);
	}
	return tekst;
}



void dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(char znak)
{
	lista* pom_kontener = NULL;
	pom_kontener = glowa;
	int czy_znak_wystapil = 0;

	while(pom_kontener)
	{
		if(pom_kontener -> lisc -> znak == znak)
		{
			czy_znak_wystapil++;
			pom_kontener -> lisc -> ilosc = pom_kontener -> lisc -> ilosc + 1;
			break;
		}
		pom_kontener = pom_kontener -> next;
	}

	if(czy_znak_wystapil == 0)
	{
		lista* pom_kontener = NULL;
	    pom_kontener  = malloc(sizeof(lista));
	    pom_kontener -> lisc = malloc(sizeof(node));
	    pom_kontener -> lisc -> znak = znak;
	    pom_kontener -> lisc -> ilosc = 1;
	    pom_kontener -> lisc -> gotowy = 1;
	    pom_kontener -> lisc -> prawa = NULL;
	    pom_kontener -> next = NULL; 		
		pom_kontener -> next = glowa;
		glowa = pom_kontener;
	}	
}

void sortowanie_listy()
{	
	lista *pom = NULL;
	lista *pom_next = NULL;
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



void sortowanie_wpisow()
{	
	node *pom = NULL;
	node *pom_next = NULL;
	node *pom2 = NULL;
	node *pom_kontener = NULL; 
	node *warunek = NULL;

	while(glowa_listy->lewa != warunek)
	{
		pom = glowa_listy;
		pom2 = pom;
		pom_next = pom->lewa;
		while(pom != warunek)
		{
			if(pom->ilosc > pom_next->ilosc)
			{
				pom_kontener = pom_next->lewa;
				pom_next->lewa = pom;
				pom->lewa = pom_kontener;
				if(pom == glowa_listy)
				{
					glowa_listy = pom_next;
					pom2 = pom_next;
				}
				else
				{
					pom2->lewa = pom_next;
					pom2 = pom_next;
				}
			}
			else
			{
				pom2 = pom;
				pom = pom->lewa;
			}
			pom_next = pom->lewa;
			if(pom_next == warunek)
				warunek = pom;
		}
	}
}



void stworz_drzewo_HF()
{
	while(glowa)
	{
		if(glowa->next == NULL)
		{
			wezel = glowa->lisc;
			free(glowa);
			glowa = NULL;
		}
		else
		{
			node* pop_kontener;
			node* pop_kontener2;

			if(glowa)
			{
				lista* tmp = glowa;
				glowa = tmp->next;
				pop_kontener = tmp->lisc;
				lista* tmp2 = glowa;
				glowa = tmp2->next;
				pop_kontener2 = tmp2->lisc;
				free(tmp);
				free(tmp2);
			}

			lista* polaczone_kontenery;
			polaczone_kontenery  = malloc(sizeof(lista));
			polaczone_kontenery -> lisc = malloc(sizeof(node));
			polaczone_kontenery -> lisc -> ilosc = pop_kontener -> ilosc + pop_kontener2 -> ilosc;
			polaczone_kontenery -> lisc -> gotowy = 0;
			    
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
}

void kodowanieHT(node* pom_kontener, char* kodHT, int generacja, char w_ktora_strone)
{
	if(pom_kontener)
	{
		pom_kontener -> kod = malloc(generacja * sizeof(char));
		if(pom_kontener == wezel)
			sprintf(pom_kontener->kod,"%s","");
		if(pom_kontener != wezel)
			sprintf(pom_kontener->kod,"%s%c",kodHT, w_ktora_strone);		
		if(pom_kontener != wezel && pom_kontener-> gotowy == 1)
		{	
			node* tmp;
			tmp = malloc(sizeof(node));
			tmp -> ilosc = pom_kontener -> ilosc;
			tmp -> znak = pom_kontener -> znak;
			tmp -> kod = malloc(generacja+1 * sizeof(char));
			sprintf(tmp->kod,"%s%c",kodHT, w_ktora_strone);
			tmp -> lewa = glowa_listy;
			glowa_listy = tmp;
			dlugosc_kodu += generacja * tmp -> ilosc; 
		} 
		
		if(pom_kontener->lewa)
			kodowanieHT(pom_kontener->lewa, pom_kontener->kod, generacja+1, LEWA_GALAZ);
		if(pom_kontener->prawa)
			kodowanieHT(pom_kontener->prawa, pom_kontener->kod, generacja+1, PRAWA_GALAZ);
	}

}

void wyswietl_powtorzenia()
{
		node *tmp = NULL;
	tmp = glowa_listy;
	while(tmp)
	{
		if(tmp->znak == 32)
			printf("Znak Spacja %5d\n", tmp->ilosc);
		else if(tmp->znak == 10)
			printf("Znak EOL%9d\n", tmp->ilosc);
		else if(tmp->znak == 9)
			printf("Znak TAB%9d\n", tmp->ilosc);
		else
			printf("Znak %c %10d\n", tmp->znak, tmp->ilosc);
		tmp = tmp->lewa;
	}
	free(tmp);
	puts("");
}

void wyswietl_kod()
{
		node *tmp = NULL;
	tmp = glowa_listy;
	while(tmp)
	{
		if(tmp->znak == 32)
			printf("Znak Spacja %11s\n", tmp->kod);
		else if(tmp->znak == 10)
			printf("Znak EOL%15s\n", tmp->kod);
		else if(tmp->znak == 9)
			printf("Znak TAB%15s\n", tmp->kod);
		else
			printf("Znak %c %16s\n", tmp->znak, tmp->kod);
		tmp = tmp->lewa;
	}
	free(tmp);
	puts("");
}

char* przeszukaj_kod(char znak)
{
	node* pom_kontener = NULL;
	pom_kontener = glowa_listy;

	while(pom_kontener){
		if(pom_kontener -> znak == znak)
		{
			char* kod = calloc(strlen(pom_kontener->kod)+1,sizeof(char));
			memcpy(kod,pom_kontener->kod,strlen(pom_kontener->kod));
			return(kod);
		}
		pom_kontener = pom_kontener->lewa;
	}
	return("-");
}

void zniszcz_liste(){
	while(glowa_listy){
		node* pom_kontener = NULL;
		pom_kontener = glowa_listy;
		glowa_listy = pom_kontener->lewa;

		free(pom_kontener->kod);
		free(pom_kontener);
	}

}

void usun_drzewo_HF(node* galaz){
	
	if(galaz){
		
		usun_drzewo_HF(galaz->lewa);
		usun_drzewo_HF(galaz->prawa);
		free(galaz->kod);
		free(galaz);
		
	}
}

void stworz_glowe(char znak)
{
		lista* pom_kontener = NULL;
	    pom_kontener  = malloc(sizeof(lista));
	    pom_kontener -> lisc = malloc(sizeof(node));
	    pom_kontener -> lisc -> znak = znak;
	    pom_kontener -> lisc -> ilosc = 1;
	    pom_kontener -> lisc -> gotowy = 1;
	    pom_kontener -> next = NULL;  		
	    glowa = pom_kontener;
}

void zloz_liste(int dlugosc, char *tekst)
{
	for(int i=1;i<dlugosc;i++)
		dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(tekst[i]);
}

void sformatuj_tekst(char *tekst, size_t dlugosc)
{
	puts("-------------------------------------------");
	for(int i=0;i<dlugosc;i++)
		printf("%c", tekst[i]);
	puts("");
	puts("-------------------------------------------");
}

void posprzataj(char *tekst, char *zakodowany_tekst)
{
	zniszcz_liste();
 	usun_drzewo_HF(wezel);
	free(glowa);
	free(tekst);
	free(zakodowany_tekst);
}

void zbuduj_kod(char *zakodowany_tekst, char *tekst)
{
	int i = 0;
	
	while(tekst[i])
	{
		 char* kod;
		 kod = przeszukaj_kod(tekst[i]);
		 strcat(zakodowany_tekst,kod);
		 free(kod);
		 i++;
	}
}

void stopien_kompresji(int dlugosc, int dlugosc_kodu)
{
	float wynik = ((float)dlugosc * 8) / (float)dlugosc_kodu;
	printf("%.2f:1\n", wynik);
}