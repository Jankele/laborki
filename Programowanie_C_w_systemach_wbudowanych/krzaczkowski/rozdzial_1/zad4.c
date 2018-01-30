/* 
Zdefiniuj strukturę trojkat przechowującą długości boków
trójkąta. Napisz funkcję, która otrzymuje jako argument zmienną typu
struct trojkat, i zwraca jako wartość obwód trójkąta przekazanego
w argumencie.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct trojkat
{
	int a, b, c;

}trojkat;

int funkcja(trojkat t)
{
	return (t.a + t.b + t.c);
}

int main()
{
	trojkat t;
	t.a = 4;
	t.b = 5;
	t.c = 4;
	printf("%d\n", funkcja(t));
	return 0;
}
