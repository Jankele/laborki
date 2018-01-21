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
#include "funkcje.h"

lista* glowa;
node* wezel;
node *glowa_listy;
char* zakodowany_tekst;
int dlugosc_kodu;

int main(int argc, char **argv)
{
	char plik[100];
	//wczytanie tekstu
	printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	scanf("%s", plik);
	char *tekst = czytaj_plik(plik);
	int dlugosc = strlen(tekst);
	int i = 0;
		stworz_glowe(tekst[0]);
		zloz_liste(dlugosc, tekst);
		sortowanie_listy();
		while(glowa != NULL){
			stworz_drzewo_HF();
		}
		kodowanieHT(wezel, "-", 1, LEWA_GALAZ);
		sortowanie_slownika();
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PRZED ZAKODOWANIEM",43);
		printf(" %lu\n", dlugosc*sizeof(char)*8);
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PO ZAKODOWANIU",39);
		printf(" %d\n", dlugosc_kodu);
		sformatuj_tekst("LISTA ZNAKOW ORAZ LICZBA ICH WYSTAPIEN", 38);
		wyswietl_powtorzenia();
		sformatuj_tekst("LISTA ZNAKOW ORAZ ODPOWIADAJACE IM KODY", 39);
		wyswietl_kod();
		zakodowany_tekst = calloc(dlugosc_kodu +1, sizeof(char));

		i = 0;
		while(tekst[i] != '\0'){
		 	char* kod;
		 	kod = przeszukaj_kod(tekst[i]);
		 	strcat(zakodowany_tekst,kod);
		 	free(kod);
		 	i++;
		}
		sformatuj_tekst("TRESC TEKSTU PRZED ZAKODOWANIEM",31);
		printf(" %s\n", tekst);
		sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
		printf(" %s\n\n",zakodowany_tekst);
		posprzataj(&tekst);

	return 0;
}