#include <stdlib.h>
#include <stdio.h>
///////////////STRUKTURA/////////////////////////
struct node
{
	int d;
	struct node *n;
}node;

int main ()
{
////////DEKLARACJA I INICJALIZACJA LISTY/////////
	struct node *head; //deklaracja poczatku listy
	struct node *next; //deklaracja elementu
	head = malloc(sizeof(node)); // nadanie poczatkowi listy rozmiaru struktury node
	head->n=NULL; //stworzenie poczatku listy jako jedynej pozycji listy
	head->d=0 ; //przypisanie pierwszemu elementowi wartosci 0
	next = head;
//////////////DODAWANIE///////////////////////////	
	if(next == NULL)
	{
		printf("out of memory");
		return 0;
	}
	for(int i=1;i<5;i++) 
	{
		next = next->n = malloc(sizeof(node));
		next->n=NULL;
		next->d=i;
	}
	
///////////WYSWIETLANIE PRZEZ ITERACJE///////////	
	next = head;
	while ( next != NULL )
	{
    		printf( "%d\n", next->d );
  		next = next->n;
	}
	return 0;
}
