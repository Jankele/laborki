/*	Kodowanie Huffmana
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------
+++ Czytamy z pliku podanego na starcie programu, ktory musi znajdowac sie w tym samym katologu w ktorym uruchamiamy program.
+++ Adres glowy przekazywany jest do funkcji jako wartosc, dzieki czemu nie musze uzywac zmiennych globalnych.
+++ Funkcja wyswietlajaca ilosc wystapien danego znaku nie zapewnia obslugi wszystkich znakow specjalnych,
	przez co znaki tj. "vertical tab" lub niektore znaki oprocz spacji i znaku EOL moga sie wyswietlac bez opisu.
+++ 
*/

#include <stdlib.h> //malloc, etc.
#include <stdio.h> //printf, etc.
#include <string.h> //strlen, etc.
#include "functions.h"

node *wezel = NULL;
lista *glowa = NULL;
node *glowa_listy = NULL;

char *tekst_zakodowany = NULL;
int dlugosc_kodu;
/*
////////////////////////////////////////////////////////////////////////////////////
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
------------------------------------------------------------------------------------
TODO ---  DOKONCZYC DOKUMENTACJE U GORY,
DOKONCZYC PROGRAM ;P
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

int main()
{

	int dlugosc_kodu;
	char plik[100];
	//printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	//scanf("%s", plik);
	char *tekst = czytaj_plik("tekst.txt");
	int dlugosc = strlen(tekst);

	sformatuj_tekst("TRESC TEKSTU Z WCZYTANEGO PLIKU",31);
	printf("%s\n", tekst);

	stworz_glowe(tekst[0]);
	zloz_liste(dlugosc, tekst);

	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PRZED SORTOWANIEM", 42);
	wyswietl_powtorzenia();

	sortowanie_listy();
	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PO SORTOWANIU", 37);
	wyswietl_powtorzenia();

	while(glowa != NULL)
		stworz_drzewo_HF();
	puts("asddsfsdfsdfsdfsdfsdf");
	tekst_zakodowany = calloc(dlugosc_kodu +1, sizeof(char));


	int i = 0;
		while(tekst[i] != '\0'){
		 	char* code = NULL;



	node* current = NULL;
	current = dictionary_head;

	while(current != NULL){
		if(current -> znak == tekst[i]){
			//return symbol code
			char* code = calloc(strlen(current->kod)+1,sizeof(char));
			memcpy(code,current->kod,strlen(current->kod));
		}
		current = current->lewa;
	}

		 	
		 	
		 	strcat(tekst_zakodowany,code);
		 	free(code);
		 	i++;
		}


	sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
	printf("W BUDOWIE\n\n");

	sformatuj_tekst("ROZMIAR CZYSTEGO TEKSTU W BITACH",32);
	printf("%d\n\n", dlugosc*8);

	sformatuj_tekst("ROZMIAR ZAKODOWANEGO TEKSTU W BITACH",36);
	printf("W BUDOWIE\n\n");

	zniszcz_liste();
	//usun_drzewo_HF();
	free(tekst_zakodowany);
	free(tekst);
	return EXIT_SUCCESS;
}
