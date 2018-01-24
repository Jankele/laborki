/*	Kodowanie Huffmana v0.3
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------
+++ Czyszczenie plikow object - make clean
+++ Uruchomienie programu - make run, lub ./a.out
+++ Na starcie programu czytamy z pliku podanego w stdin
+++ W celu ulatwienia pisania kodu, wskazniki na strukture list sa globalne
+++ Funkcja wyswietlajaca nie zapewnia obslugi wszystkich bialych znakow, przez co moga sie one wyswietlac bez opisu.
+++ Wycieki pamieci usuniete przy pomocy valgrind
+++ Program nie dekoduje kodu, tylko wyswietla go jako char*
*/

#include <stdlib.h> //malloc, calloc, free
#include <stdio.h> //printf, scanf
#include <string.h> //strlen, strcat
#include "funkcje.h"

lista* glowa;
node* wezel;
node *glowa_listy;

int main()
{
	
	char plik[100];// przechowuje nazwe pliku tekstowego
	char* zakodowany_tekst;
	int dlugosc_kodu;
	printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	scanf("%s", plik);
	char *tekst = czytaj_plik(plik);
	int dlugosc = strlen(tekst);
	stworz_glowe(tekst[0]);
	stworz_liste_powtorzen(dlugosc, tekst);
	sortowanie_listy('0');
	stworz_drzewo_HF();
	kodowanieHT(wezel, "", 1, LEWA_GALAZ, &dlugosc_kodu);
	sortowanie_listy('1');
	zakodowany_tekst = calloc(dlugosc_kodu, sizeof(char)); //calloc rezerwuje i wypelnia zerami, co w naszej sytuacji jest idealnym rozwiazaniem, mimo, ze mniej optymalnym
	zbuduj_kod(zakodowany_tekst, tekst);
	
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PRZED ZAKODOWANIEM",43);
		printf("%lu\n", dlugosc*8*sizeof(char));

		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PO ZAKODOWANIU",39);
		printf("%d\n", dlugosc_kodu);

		sformatuj_tekst("STOPIEN KOMPRESJI",17);
		stopien_kompresji(dlugosc, dlugosc_kodu);

		sformatuj_tekst("LISTA ZNAKOW ORAZ LICZBA ICH WYSTAPIEN", 38);
		wyswietl('0');

		sformatuj_tekst("LISTA ZNAKOW ORAZ ODPOWIADAJACE IM KODY", 39);
		wyswietl('1');

		sformatuj_tekst("TRESC TEKSTU PRZED ZAKODOWANIEM",31);
		printf("%s\n", tekst);

		sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
		printf("%s\n\n",zakodowany_tekst);
	
		posprzataj(tekst, zakodowany_tekst);

	return 0;
}
