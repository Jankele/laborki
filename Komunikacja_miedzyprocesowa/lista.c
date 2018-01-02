#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMS 10
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct List
{
    int value;
    struct List* next;
}List;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja dodajaca element na koniec listy
int push_back(List **node, int a)
{
    //wskaznik pomocniczny
    int i = 1;
    struct List *tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->value = a;
    //przypisanie glowy listy do tymczasowego wskaznika
    struct List *pom = *node;
    //jesli glowa jest pusta przypisz do niej nowy element
    if(*node == NULL)
    {
        *node = tmp;
    }
    else
    {
    	while(pom->next)
        {
        	pom = pom->next;
        	i++;
    	}
        if(i<=MAX_ELEMS)
    		pom->next = tmp;
        else
        	return -1;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja usuwajaca pierwszy element z listy
int pop_front(List **node)
{
    if((*node)->next != NULL)
    {
        struct List *tmp = *node;
        *node = (*node)->next;
        free(tmp);
        printf("pop\n");
    }
    else
    {
        printf("lista jest pusta\n");
        return -1;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja wyswietlajaca cala liste
int wyswietl(List *node)
{
    //jesli lista nie ma elementow wypisz komunikat i wyjdz z funkcji, w innym wypadku wypisz element a nastepnie ustaw sie na nastepnym
    if(node != NULL)
    {
        while(node)
        {
            printf("%d\n", node->value);
            node = node->next;
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
void flush(List **node)
{
    //jesli istnieje element listy, wskaz na niego wskaznikiem pomocniczym, ustaw glowe na nastepny element i zwolnij stara glowe
    while(*node)
    {
        struct List *tmp = *node;
        *node = (*node)->next;
        free(tmp);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    struct List *head = NULL;
    for(int i=1;i<MAX_ELEMS;i++)
        push_back(&head, i);
    printf("Lista po wypelnieniu: \n");
    wyswietl(head);

    pop_front(&head);
    printf("Lista po usunieciu pierwszego elementu: \n");
    wyswietl(head);

    flush(&head);
    printf("Lista po jej wyczyszczeniu: \n");
    wyswietl(head);
    return 0;
}
