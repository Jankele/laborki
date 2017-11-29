#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct node
{
    int dane;
    struct node *wezel;
}node;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja dodajaca element na koniec listy
void pushl(node **node, int a)
{
    //wskaznik pomocniczny
    struct node *tmp = malloc(sizeof(node));
    tmp->wezel = NULL;
    tmp->dane = a;
    //przypisanie glowy listy do tymczasowego wskaznika
    struct node *pom = *node;
    //jesli glowa jest pusta przypisz do niej nowy element
    if(*node == NULL)
    {
        *node = tmp;
    }
    else
    {
        //przejdz do ostatniego elementu
        while(pom->wezel)
        pom = pom->wezel;
        //ostatni element wskazuje na nowy element
        pom->wezel = tmp;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja dodajaca element na poczatek listy
void pushf(node **node, int a)
{
    /*funkcja dziala identycznie do ww.
      jednak bez przejscia na ostatni element
      zamiast tego wskaznik pomocniczy zaczyna wskazywac na glowe
      i potem glowa przypisywana jest do wskaznika pomocniczego co czyni z niej nowy start listy*/
    struct node *tmp = malloc(sizeof(node));
    tmp->wezel = NULL;
    tmp->dane = a;
    if(*node == NULL)
    {
        *node = tmp;
    }
    else
    {
        tmp->wezel = *node;
        *node = tmp;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja usuwajaca ostatni element z listy
void popl(node **node)
{
    struct node *tmp = malloc(sizeof(node)); //wskazniki pomocnicze
    struct node *pom = malloc(sizeof(node));
    tmp = *node; //ustawiam tmp na poczatku listy
    while(tmp->wezel != NULL)//tmp przechodzi na koniec listy
    {
        pom = tmp;//przed przejsciem do ostatniego elementu do pom zostaje wrzucony element przedostatni
        tmp = tmp->wezel;
    }
    free(tmp);//uwalniamy ostatni element
    pom->wezel = NULL;//kasujemy wskaznik na ostatni, nieistniejacy juz element
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja usuwajaca pierwszy element z listy
void popf(node **node)
{
    if((*node)->wezel != NULL)
    {
        struct node *tmp = *node;
        *node = (*node)->wezel;
        free(tmp);
    }
    else
    {
        printf("lista jest pusta\n");
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja wyswietlajaca cala liste
int wyswietl(node *node)
{
    //jesli lista nie ma elementow wypisz komunikat i wyjdz z funkcji, w innym wypadku wypisz element a nastepnie ustaw sie na nastepnym
    if(node != NULL)
    {
        while(node)
        {
            printf("%d\n", node->dane);
            node = node->wezel;
        }
    }
    else
    {
        printf("lista jest pusta");
    }
    printf("\n");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja czyszczaca cala liste
void flush(node **node)
{
    //jesli istnieje element listy, wskaz na niego wskaznikiem pomocniczym, ustaw glowe na nastepny element i zwolnij stara glowe
    while(*node)
    {
        struct node *tmp = *node;
        *node = (*node)->wezel;
        free(tmp);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    struct node *head = NULL;
    for(int i=1;i<6;i++)
        pushl(&head, i);
    printf("Lista po wypelnieniu: \n");
    wyswietl(head);
    popf(&head);
    printf("Lista po usunieciu pierwszego elementu: \n");
    wyswietl(head);
    popl(&head);
    printf("Lista po usunieciu ostatniego elementu: \n");
    wyswietl(head);
    for(int i=7;i<10;i++)
    pushf(&head, i);
    printf("lista po dodaniu elementu na poczatek: \n");
    wyswietl(head);
    flush(&head);
    printf("Lista po jej wyczyszczeniu: \n");
    wyswietl(head);
    return 0;
}
