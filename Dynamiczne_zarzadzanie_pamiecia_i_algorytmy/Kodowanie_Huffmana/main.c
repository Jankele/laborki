/*	Kodowanie Huffmana
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------

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



int main()
{
	node *wezel = NULL;
	lista *glowa = NULL; 
	char *tekst = czytaj_plik("tekst.txt");
	printf("%s\n", tekst);
	int dlugosc = strlen(tekst);
	printf("Ilosc znakow: %d\n\n", dlugosc);


	stworz_glowe(tekst[0], &glowa);


	for(int i=1;i<dlugosc;i++)
		push_front_and_count(tekst[i], &glowa);
	wyswietl_powtorzenia(&glowa);
	return EXIT_SUCCESS;
}