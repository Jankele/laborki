#include <stdio.h>
#include <stdlib.h>

//Funkcja merge sortuje i scala elementy podzielonej tablicy
void scalanie(int lewa[], int tab[], int prawa[], int lewa_dlugosc, int prawa_dlugosc)
{
//liczniki tablic potrzebne jako warunki petli
    int lewa_licznik=0;
    int prawa_licznik=0;
    int tab_licznik=0;
//petla wykonujaca sie dopoty, dopoki nie osiagnie rozmiaru jednej z tablic
    while(lewa_licznik < lewa_dlugosc && prawa_licznik < prawa_dlugosc)
    {
//porownujemy elementy z dwoch tablic i przepisujemy mniejszy do glownej tablicy na pozycje lewa
        if(lewa[lewa_licznik] < prawa[prawa_licznik])
            tab[tab_licznik++]=lewa[lewa_licznik++];
        else
            tab[tab_licznik++]=prawa[prawa_licznik++];
    }
//po przejsciu przez sortowanie wypelniamy tablice glowna, reszta liczb ktore zostały nieposortowane
    for(lewa_licznik;lewa_licznik<lewa_dlugosc;tab_licznik++,lewa_licznik++)
	tab[tab_licznik] = lewa[lewa_licznik];
    for(prawa_licznik;prawa_licznik<prawa_dlugosc;tab_licznik++,prawa_licznik++)
        tab[tab_licznik] = prawa[prawa_licznik];
}
//podzial przez rekurencje
void podzial(int tab[], int n)
{
//ustalamy dlugosci tablicy lewej i prawej
    int lewa_dlugosc = n/2;
//w przypadku nieparzystej liczby elementow dlugosc tablicy prawej rowna sie pozostalosci po odjeciu tablicy lewej
    int prawa_dlugosc = n-lewa_dlugosc;
    int lewa[lewa_dlugosc];
    int prawa[prawa_dlugosc];
//jesli tablica sklada sie z jednego elementu, wyjdz z funkcji
    if(n<2)
        return;
//wypelniamy podzielone tablice, wartosciami z tablicy glownej
    for(int i=0;i<lewa_dlugosc;i++)
        lewa[i] = tab[i];
//tablice prawa zaczynamy wypelniac wartosciami zaczynajac od konca strony lewej
    for(int i=0;i<n; i++)
        prawa[i-lewa_dlugosc] = tab[i];
//zaczynamy rekurencje
    podzial(lewa,lewa_dlugosc);
    podzial(prawa, prawa_dlugosc);
//sortujemy podzielone czesci dzieki czemu, wspinajac sie po wywolaniach funkcji do gory laczymy i sortujemy powstale tablice
    scalanie(lewa, tab, prawa, lewa_dlugosc, prawa_dlugosc);
}
//najprostsza funkcja wyswietlajaca cala tablice
void wyswietl(int tab[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
//funkcja pobierajaca elementy tablicy od uzytkownika; funkcja dostaje rozmiar tablicy z maina
int wypelnij(int *tab, int n)
{
    int element;
    for(int i=0;i<n;i++)
    {
	printf("Podaj nastepny element tablicy: \n");
	scanf("%d", &element);
	tab[i] = element;
    }
}
//w mainie deklarujemy tablice oraz pobieramy od uzytkownika jej rozmiar
int main()
{
    int *tab;
    int n;
    printf("Podaj rozmiar tablicy: \n");
    scanf("%d", &n);
    wypelnij(tab, n);
    printf("Tablica przed sortowaniem:\n");
    wyswietl(tab, n);
    podzial(tab,n);
    wyswietl(tab,n);
    return 0;
}
