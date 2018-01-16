/*	Kodowanie Huffmana
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------
AAA*
+++ Czytamy z pliku tekst.txt ktory musi znajdowac sie w tym samym katologu w ktorym uruchamiamy program.
+++ Adres glowy przekazywany jest do funkcji jako wartosc, dzieki czemu nie musze uzywac zmiennych globalnych.
+++ Program wczytuje tylko pierwsza linie pliku tekstowego.
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
TODO ---  DOKONCZYC DOKUMENTACJE U GORY AAA* , ZROBIC FUNKCJE Z TWORZENIA LISTY BBB*
SFORMATOWAC WYSWIETLANIE WYJSCIA STD ZEBY LADNIE WYGLADALO,
OPISAC URUCHAMIANIE ZE MAKE RUN I POTEM DODAC OBSLUGE WLASNYCH PLIKOW TEKSTOWYCH
JESC, SPAC, KODOWAC! ;P
JESLI CZYTA TO JAKIS PIECZON, TO KURWA DO ROBOTY!!! DZIODO I BEDALE!!!
------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

int main()
{
	node *wezel = NULL;
	lista *glowa = NULL; 
	char *tekst = czytaj_plik("tekst.txt");
	printf("%s\n", tekst);
	int dlugosc = strlen(tekst);
	printf("Ilosc znakow: %d\n\n", dlugosc);
	stworz_glowe(tekst[0], &glowa);
	// BBB*
	for(int i=1;i<dlugosc;i++)
		dodanie_elementu_na_poczatek_oraz_zliczanie_powtorzen(tekst[i], &glowa);
	wyswietl_powtorzenia(glowa);
	sortowanie_listy(&glowa);
	wyswietl_powtorzenia(glowa);
	return EXIT_SUCCESS;
}
