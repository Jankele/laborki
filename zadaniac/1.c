#include <stdio.h>
#include <stdlib.h>

void rozdzial2()
{
	int liczba[3];
	printf("1.2.1\nHello World!\n\n");
	printf("1.2.2\nBardzo\ndlugi\nnapis\n");
	printf("1.2.3\nNapis zawaierajacy rozne dziwne znaczki // \\ \\ $ & %%\n");
	printf("1.2.6\n");
	for(int i=0;i<3;i++)
	{
		printf("Podaj liczbe\n");
		scanf("%d", &liczba[i]);
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
		printf("%d\n", liczba[i]);
	}
}

int rozdzial3()
{
	int dzialanie = 0;
	int a, b;
	int i=0;
	float aa, bb;
	printf("1.3.9 Kalkulator\n");
	while(i == 0)
	{
		printf("\nMENU\n1.Dodawanie\n2.Odejmowanie\n3.Mnozenie\n4.Dzielenie\n5.Wyjdz\n");
		printf("Podaj numer dzialania: ");
		scanf("%d", &dzialanie);
		switch(dzialanie)
		{
			case 1:
				printf("\nPodaj pierwszą liczbe: ");
				scanf("%d", &a);
				printf("\nPodaj druga liczbe: ");
                                scanf("%d", &b);
				printf("\n%d + %d = %d\n", a, b, a+b);
				break;
                        case 2:
                                printf("\nPodaj pierwszą liczbe: ");
                                scanf("%d", &a);
                                printf("\nPodaj druga liczbe: ");
                                scanf("%d", &b);
                                printf("\n%d - %d = %d\n", a, b, a-b);
				break;
                        case 3:
                                printf("\nPodaj pierwszą liczbe: ");
                                scanf("%d", &a);
                                printf("\nPodaj druga liczbe: ");
                                scanf("%d", &b);
                                printf("\n%d * %d = %d\n", a, b, a*b);
				break;
                        case 4:
                                printf("\nPodaj pierwszą liczbe: ");
                                scanf("%f", &aa);
                                printf("\nPodaj druga liczbe: ");
                                scanf("%f", &bb);
                                printf("\n%.1f / %.1f = %.1f\n", aa, bb, aa/bb);
				break;
			case 5:
				return 0;
				break;
			default:
				printf("\nNie ma takiej pozycji w menu\n");
				break;
		}
	}
}

void rozdzial4(int n)
{	int ciag[n];
	for(int i=0;i<n;i++)
		ciag[i]=i;
	for(int i=0;i<n;i++)
	{
		ciag[i+2] = ciag[i]+ciag[i+1];
	}
	printf("\nciag od %d wynosi: %d\n", n , ciag[n]);
}

void zadanie148()
  {
          int n;
          printf("\nzadanie 1.4.8\nciong fibonaciego\nPodaj dlugosc ciongu:");
          scanf("%d", &n);
	  rozdzial4(n);
  }


int main()
{
	//rodzial2();
	//rozdzial3();
	zadanie148();
	return 0;
}
