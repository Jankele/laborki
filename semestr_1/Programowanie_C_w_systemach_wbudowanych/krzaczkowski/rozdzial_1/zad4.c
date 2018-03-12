/* 
Napisz funkcję, która otrzymuje jako argumenty zmienną troj1
typu struct trojkat zdefiniowanego w zadaniu 7.2.1 oraz zmienną
troj2 wskaźnik na zmienną typu struct trojkat, i przepisuje za-
wartość zmiennej troj1 do zmiennej wskazywanej przez troj2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct trojkat
{
	int a, b, c;

}trojkat;

void funkcja(trojkat t, trojkat **t2)
{
	trojkat *tmp = malloc(sizeof(trojkat));
	tmp->a = t.a;
	tmp->b = t.b;
	tmp->c = t.c;
	*t2 = tmp;
}

int main()
{
	trojkat troj1;
	trojkat *troj2;
	troj1.a = 4;
	troj1.b = 5;
	troj1.c = 4;
	funkcja(troj1, &troj2);
	printf("%d %d %d\n", troj2->a, troj2->b, troj2->c);
	return 0;
}
