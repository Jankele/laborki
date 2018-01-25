/*	Kodowanie Huffmana v1.0
	25.01.2018
	Jan Komorkiewicz
--------------------------------------------------------
+++ Program wczytuje podany tekst i koduje go w ciag uporzadkowanych zer i jedynek zmniejszajac ilosc przez niego zajmowanych bitow. Program nie dekoduje kodu wynikowego.
+++ Uruchomienie programu - make run, lub ./a.out
+++ Czyszczenie plikow object - make clean
+++ Na starcie programu czytamy z pliku podanego w stdin
+++ W celu ulatwienia pisania kodu, wskazniki na strukture list sa globalne
+++ Funkcja wyswietlajaca nie zapewnia obslugi wszystkich bialych znakow, przez co moga sie one wyswietlac bez nazwy.
+++ Wycieki pamieci usuniete przy pomocy valgrind
*/
#include <stdlib.h> //malloc, calloc, free
#include <stdio.h> //printf, scanf
#include <string.h> //strlen, strcat
#include "funkcje.h"
lista* glowa;
node* wezel;
node *glowa_listy;
int dlugosc_kodu;
int main()
{
	char plik[100];// przechowuje nazwe pliku tekstowego
	char* zakodowany_tekst;
	printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	scanf("%s", plik);
	char *tekst = czytaj_plik(plik);
	int dlugosc = strlen(tekst);
	stworz_glowe(tekst[0]);
	stworz_liste_powtorzen(dlugosc, tekst);
	sortowanie_listy('0');
	stworz_drzewo_HF();
	kodowanieHT(wezel, "", 1, LEWA_GALAZ);
	sortowanie_listy('1');
	zakodowany_tekst = calloc(dlugosc_kodu, sizeof(char)); //calloc rezerwuje i wypelnia zerami, co w naszej sytuacji jest idealnym rozwiazaniem, mimo, ze mniej optymalnym
	zbuduj_kod(zakodowany_tekst, tekst);
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PRZED ZAKODOWANIEM",43);
		printf("%lu\n", dlugosc*sizeof(char)*8);
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PO ZAKODOWANIU",39);
		printf("%d\n", dlugosc_kodu);
		sformatuj_tekst("STOPIEN KOMPRESJI",17);
		stopien_kompresji(dlugosc, dlugosc_kodu);
		sformatuj_tekst("LISTA ZNAKOW ORAZ LICZBA ICH WYSTAPIEN", 38);
		wyswietl('0');
		sformatuj_tekst("LISTA ZNAKOW ORAZ ODPOWIADAJACE IM KODY", 39);
		wyswietl('1');
		sformatuj_tekst("TRESC TEKSTU PRZED ZAKODOWANIEM",31);
		printf("%s", tekst);
		sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
		printf("%s\n",zakodowany_tekst);
		sformatuj_tekst("PROGRAM ZAKONCZYL SIE PRAWIDLOWO", 32);
		posprzataj(tekst, zakodowany_tekst);
	return 0;
}
