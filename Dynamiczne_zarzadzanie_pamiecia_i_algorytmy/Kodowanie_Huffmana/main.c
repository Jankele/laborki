/*	Kodowanie Huffmana v0.3
	01.2018
	Jan Komorkiewicz
--------------------------------------------------------
+++ Czytamy z pliku podanego na starcie programu, ktory musi znajdowac sie w tym samym katologu w ktorym uruchamiamy program.
+++ Adres glowy przekazywany jest do funkcji jako wartosc, dzieki czemu nie musze uzywac zmiennych globalnych.
+++ Funkcja wyswietlajaca ilosc wystapien danego znaku nie zapewnia obslugi wszystkich znakow specjalnych,
	przez co znaki tj. "vertical tab" lub niektore znaki oprocz spacji i znaku EOL moga sie wyswietlac bez opisu.
+++ Wycieki pamieci sprawdzone valgrindem
+++ czyszczenie plikow object - make clean
+++ uruchomienie programu - make run
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
	char plik[100];
	char* zakodowany_tekst;
	//wczytanie tekstu
	printf("Podaj nazwe pliku tekstowego do zakodowania: ");
	scanf("%s", plik);
	char *tekst = czytaj_plik(plik);
	int dlugosc = strlen(tekst);
	stworz_glowe(tekst[0]);
	zloz_liste(dlugosc, tekst);
	sortowanie_listy();
	stworz_drzewo_HF();
	kodowanieHT(wezel, "-", 1, LEWA_GALAZ);
	sortowanie_wpisow();
	zakodowany_tekst = calloc(dlugosc_kodu +1, sizeof(char));
	zbuduj_kod(&zakodowany_tekst, tekst);
	{
		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PRZED ZAKODOWANIEM",43);
		printf("%lu\n", dlugosc*sizeof(char)*8);

		sformatuj_tekst("ROZMIAR TEKSTU W BITACH, PO ZAKODOWANIU",39);
		printf("%d\n", dlugosc_kodu);

		sformatuj_tekst("LISTA ZNAKOW ORAZ LICZBA ICH WYSTAPIEN", 38);
		wyswietl_powtorzenia();

		sformatuj_tekst("LISTA ZNAKOW ORAZ ODPOWIADAJACE IM KODY", 39);
		wyswietl_kod();

		sformatuj_tekst("TRESC TEKSTU PRZED ZAKODOWANIEM",31);
		printf("%s\n", tekst);

		sformatuj_tekst("TRESC TEKSTU PO ZAKODOWANIU", 27);
		printf("%s\n\n",zakodowany_tekst);
	}
		posprzataj(tekst, zakodowany_tekst);

	return 0;
}