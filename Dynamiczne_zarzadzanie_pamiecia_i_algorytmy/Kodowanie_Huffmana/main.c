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
entry *glowa_listy = NULL;
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
//deklaracja zmiennych
	int dlugosc_kodu;
	char plik[100];
	
//wczytanie tekstu
	//printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	//scanf("%s", plik);
	char *tekst = czytaj_plik("tekst.txt");
	int dlugosc = strlen(tekst);

	stworz_glowe(tekst[0]);
	zloz_liste(dlugosc, tekst);
	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PRZED SORTOWANIEM", 42);
	wyswietl_powtorzenia();

	sortowanie_listy();
	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PO SORTOWANIU", 37);
	wyswietl_powtorzenia();

//// stworzenie drzewa
	while(glowa != NULL)
		stworz_drzewo_HF();
//// zakodowanie	
	kodowanieHT(wezel, "-", 1, LEWA_GALAZ);
	tekst_zakodowany = calloc(dlugosc_kodu+1, sizeof(char));
	int i = 0;
	while(tekst[i] != '\0')
	{
		char* code = NULL;
		code = przeszukaj_kod(tekst[i]);		
		strcat(tekst_zakodowany,code);
		puts("sdf");
		free(code);		
		i++;
	}

	sformatuj_tekst("TRESC TEKSTU PRZED ZAKODOWANIEM",31);
	printf("%s\n", tekst);

	sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
	printf("%s", tekst_zakodowany);

	sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PRZED ZAKODOWANIEM",32);
	printf("%d\n\n", dlugosc*8);

	sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PO ZAKODOWANIU",36);
	printf("%d\n\n", dlugosc_kodu);

	zniszcz_liste();
	usun_drzewo_HF();
	free(tekst_zakodowany);
	free(tekst);
	return EXIT_SUCCESS;
}
