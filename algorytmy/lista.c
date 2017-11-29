#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dane;
    struct node *wezel;
}node;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja dodajaca element na koniec listy
void pushl(node **node, int a)
{
    struct node *tmp = malloc(sizeof(node));//wskazniki pomocnicze
    tmp->wezel = NULL;
    tmp->dane = a;
    struct node *pom = *node;
    if(*node == NULL)
    {
        *node = tmp;
    }
    else
    {
        while(pom->wezel)//tmp przechodzi na koniec listy
        pom = pom->wezel;
        pom->wezel = tmp;
        tmp=NULL;
    }
}

void pushf(node **node, int a)
{
    struct node *tmp = malloc(sizeof(node));
    tmp->wezel = NULL;
    tmp->dane = a;
    if(*node != NULL)
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
    pom->wezel = NULL;//uwalniamy wskaznik na ostatni, nieistniejacy juz element
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
//funkcja wyswietlajaca cala liste
int wyswietl(node *node)
{
    if(node == NULL)
    {
    printf("Lista jest pusta\n");
    return 0;
    }
    else
    {
    while(node)
    {
        printf("%d\n", node->dane);
        node = node->wezel;
    }
    }
    printf("\n");
    return 0;
}

void flush(node **node)
{
    while(*node)
    {
        struct node *tmp = *node;
        *node = (*node)->wezel;
        free(tmp);
    }
}

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
