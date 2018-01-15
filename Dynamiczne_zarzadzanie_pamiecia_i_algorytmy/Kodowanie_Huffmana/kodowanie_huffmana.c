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

typedef struct node
{
	char znak;
	int ilosc;
	struct node *lewa;
	struct node *prawa;
} node;

typedef struct lista
{
	struct node *lisc;
	struct lista *next; 
} lista;



char *czytaj_plik(const char *plik)
{	
	char *tekst = NULL;
	FILE *fd;
	size_t dlugosc;

	if(fd = fopen(plik, "rb"))
	{
		fseek(fd, 0, SEEK_END);
		dlugosc = ftell(fd);
		rewind(fd);
		++dlugosc;
		if(!(tekst = malloc(sizeof(char) * dlugosc)))
			puts("Nie mozna przypisac pamieci dla zmiennej tekst!");
		fgets(tekst, dlugosc, fd);
		fclose(fd);
	}
	else
	{
		puts("Blad podczas otwierania pliku!");
		exit(EXIT_FAILURE);
	}
	return tekst;
}

void stworz_glowe(char znak, lista **glowa)
{
	*glowa = malloc(sizeof(lista));
	(*glowa)->lisc = malloc(sizeof(node));
	(*glowa)->next = NULL;
	(*glowa)->lisc->znak = znak;
	(*glowa)->lisc->lewa = NULL;
	(*glowa)->lisc->prawa = NULL;
	(*glowa)->lisc->ilosc = 1;
}

void push_front_and_count(char znak, lista **glowa)
{	
	//FUNKCJA TWORZY
		lista *tmp = NULL; 
		tmp = *glowa;
		int czy_znak_wystapil = 0;
		while(tmp != NULL)
		{
			if(tmp->lisc->znak == znak)
			{
				tmp->lisc->ilosc += 1;
				czy_znak_wystapil++;
				break;//nie potrzebujemy dalej przechodzic
			}
			tmp = tmp->next;	
		}
		if(czy_znak_wystapil == 0)
		{
		lista *tmp = NULL;
		tmp = malloc(sizeof(lista));
		tmp->lisc = malloc(sizeof(node));
		tmp->next = NULL;
		tmp->lisc->znak = znak;
		tmp->lisc->lewa = NULL;
		tmp->lisc->prawa = NULL;
		tmp->lisc->ilosc = 1;
		tmp->next = *glowa;
		*glowa = tmp;
		}
}

void stworz_drzewo_HF()
{

}
void usun_drzewo_HF()
{

}
void wyswietl_powtorzenia(lista **glowa)
{
	lista *tmp = NULL;
	tmp = *glowa;
	while(tmp)
	{
		if(tmp->lisc->znak == 32)
			printf("Spacja : %d\n", tmp->lisc->ilosc);
		else if(tmp->lisc->znak == 10)
			printf("Znak EOL : %d\n", tmp->lisc->ilosc);
		else
			printf("Znak %c : %d\n", tmp->lisc->znak, tmp->lisc->ilosc);
		tmp = tmp->next;
	}
	free(tmp);
}

void kodowanie_HF()
{

}


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