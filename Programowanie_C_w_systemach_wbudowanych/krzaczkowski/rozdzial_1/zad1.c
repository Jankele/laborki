/* 
Napisz program obliczający pole trójkąta na podstawie wymiarów
podanych przez użytkownika. Użytkownik powinien mieć możliwość
podania długości podstawy i wysokości lub wszystkich boków trójkąta.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	unsigned short wybor_menu, warunek_stopu = 1;
	int a, b, c, wysokosc, wynik;
	while(1)
	{
		puts("1. Liczenie pola trojkata na podstawie dlugosc wszystkich bokow");
		puts("2. Liczenie pola na podstawie wysokosci wierzcholka od podstawy trojkata");
		puts("3. Wyjscie z programu");
		scanf("%hu", &wybor_menu);
		
		switch(wybor_menu)
		{
			case 1:
			{
				puts("Podaj boki trojkata");
				scanf("%i%i%i", &a, &b, &c);
				int p = (a+b+c)/2;
				wynik = sqrt(p*(p-a)*(p-b)*(p-c));
				printf("%d\n", wynik);
				break;
			}
			case 2:
			{
				puts("Podaj podstawe trojkata oraz jego wysokosc");
				scanf("%i%i", &a, &wysokosc);
				wynik = a*wysokosc*0.5; 
				printf("%d\n", wynik);
				break;
			}
			case 3:
			{
				exit(EXIT_SUCCESS);
				break;
			}
			default:
			{
				puts("Nie ma takiej pozycji w menu");
				break;
			}
		}
	}
	return 0;
}
