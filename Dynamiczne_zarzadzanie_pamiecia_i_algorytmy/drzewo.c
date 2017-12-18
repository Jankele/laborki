#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int dane;
	struct node *root;
	struct node *l;
	struct node *p;
}node;

void dodaj(node **head, int a);
void wypisz(node *head);
void usun(node **head);

int main()
{
	
	return 0;
}

void dodaj(node **head, int a)
{
	node *tmp;
	tmp = malloc(sizeof(node));
	tmp->dane=a;
	tmp->root=NULL;
	tmp->l=NULL;
	tmp->p=NULL;
	if(*head == NULL)
	{
		*head = tmp;
	}
	else
	{
		if(a < (*head)->dane)
		{

		}
		else
		{
			tmp = tmp->p;
		}
	}
}

void wypisz(node *head)
{
	
}

void usun(node **head)
{
	
}
