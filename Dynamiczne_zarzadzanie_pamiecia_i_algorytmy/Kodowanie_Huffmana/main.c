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
	node *wezel = NULL;
	lista *glowa = NULL;
	char plik[100];
	printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	scanf("%s", plik);
	char *tekst = czytaj_plik(plik);
	int dlugosc = strlen(tekst);

	sformatuj_tekst("TRESC TEKSTU Z WCZYTANEGO PLIKU",31);
	printf("%s\n", tekst);

	stworz_glowe(tekst[0], &glowa);
	zloz_liste(dlugosc, &glowa, tekst);

	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PRZED SORTOWANIEM", 42);
	wyswietl_powtorzenia(glowa);

	sortowanie_listy(&glowa);

	sformatuj_tekst("LISTA ZNAKOW ZE STOSU, PO SORTOWANIU", 37);
	wyswietl_powtorzenia(glowa);

	sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
	printf("W BUDOWIE\n\n");

	sformatuj_tekst("ROZMIAR CZYSTEGO TEKSTU W BITACH",32);
	printf("%d\n\n", dlugosc*8);

	sformatuj_tekst("ROZMIAR ZAKODOWANEGO TEKSTU W BITACH",36);
	printf("W BUDOWIE\n\n");

	zniszcz_liste(&glowa);

	return EXIT_SUCCESS;
}
