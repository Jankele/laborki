#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct node
{
	int dane;
	struct node *next;
}node;

void push(node **str, int a);
void wypisz(node *str);
void pop(node **str);
void menu();
int pobierz();
int pobierz2();
void flush(node **str);

int main()
{
	int wybor = 0;
	int wpis = 0;
	int t = 1;
	node *head = NULL;
	printf("Witaj, w interaktywnej obsludze kolejki!\n");
	sleep(1);
	while(t == 1)
	{
		menu();
		wybor = pobierz();
		system ("tput clear");
		switch(wybor)
		{
			case 1:
				wpis = pobierz2();
				push(&head, wpis);
				wpis = 0;
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				wypisz(head);
				break;
			case 4:
				flush(&head);
				break;
			case 5:
				flush(&head);
				return 0;
				break;
			default:
				printf("Zla liczba?!");
		}
	}
	return 0;
}

void wypisz(node *str)
{
	printf("\nWypisanie kolejki: \n");
	while (str != NULL)
	{
		printf("\n%d\n", str->dane);
		str = str->next;
	}
}

void pop(node **str)
{
	if(*str != NULL)
	{
		node *tmp = NULL;
		tmp = *str;
		node *t = NULL;
		if( tmp->next == NULL)
		{
			free(*str);
			*str = NULL;
			printf("Nie mozesz sciac glowy bez kregoslupa");
		}
		else
		{
			while(tmp->next != NULL)
			{
				t=tmp;
				tmp = tmp->next;
			}
			
		free(tmp);
		t->next = NULL;
		}
	}
	else
	{
		printf("Kolejka jest pusta, nie możesz nic usunąć.");
	}

}
void flush(node **str)
{
	while (*str != NULL)
	{
		node *tmp = NULL;
		tmp = *str;
		*str = (*str)->next;
		free(tmp);
	}
}
void menu()
{
	printf("\n\n\n\n\nMENU:\n");
	printf("1. Dodaj element do kolejki.\n");
	printf("2. Usun element z kolejki.\n");
	printf("3. Wyswietl kolejke.\n");
	printf("4. Wyczysc cala kolejke.\n");
	printf("5. Zakoncz program.\n");
}
int pobierz()
{
	int wynik = 0;
	printf("\nPodaj numer polecenia.\n");
	scanf("%d", &wynik);
	return wynik;
}
int pobierz2()
{
	int wynik = 0;
	printf("\nPodaj liczbe ktora chcesz dodac do kolejki.\n");
	scanf("%d", &wynik);
	return wynik;
}
void push(node **str, int a)
{
	node *tmp = NULL;
        tmp = malloc(sizeof(node));
        tmp->next=NULL;
        tmp->dane=a;
        if (*str == NULL)
        {
                *str = tmp;
                tmp = NULL;
        }
        else
        {
                tmp->next=*str;
                *str=tmp;
                tmp=NULL;
        }

}
