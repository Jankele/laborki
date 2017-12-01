#include <stdio.h>
#include <stdlib.h>

void merge(int lewa[], int tab[], int prawa[], int lewa_dlugosc, int prawa_dlugosc)
{
    int lewa_licznik=0;
    int prawa_licznik=0;
    int tab_licznik=0;
    while(lewa_licznik < lewa_dlugosc && prawa_licznik < prawa_dlugosc)
    {
        if(lewa[lewa_licznik] < prawa[prawa_licznik])
            tab[tab_licznik++]=lewa[lewa_licznik++];
        else
            tab[tab_licznik++]=prawa[prawa_licznik++];
    }
    while(lewa_licznik < lewa_dlugosc)
        tab[tab_licznik++] = lewa[lewa_licznik++];
    while(prawa_licznik<prawa_dlugosc)
        tab[tab_licznik++] = prawa[prawa_licznik++];
}

void sort(int tab[], int n)
{
    int lewa_dlugosc = n/2;
    int prawa_dlugosc = n-lewa_dlugosc;
    int lewa[lewa_dlugosc];
    int prawa[prawa_dlugosc];
    if(n<2)
        return;
    for(int i=0;i<lewa_dlugosc;i++)
        lewa[i] = tab[i];
    for(int i=lewa_dlugosc;i<n; i++)
        prawa[i - lewa_dlugosc] = tab[i];
    sort(lewa,lewa_dlugosc);
    sort(prawa, prawa_dlugosc);
    merge(lewa, tab, prawa, lewa_dlugosc, prawa_dlugosc);
}

void wyswietl(int tab[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int wypelnij(int tab[])
{
    int n;
    printf("Podaj dlugosc tablicy: ")
    fgets(n);
    for(int i)
}
int main()
{
    int tab[] = wypelnij(tab);
    int n = sizeof(tab) / sizeof(int);
    printf("Tablica przed sortowaniem:\n");
    wyswietl(tab, n);
    sort(tab,n);
    wyswietl(tab,n);
    return 0;
}
