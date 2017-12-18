#include <stdio.h>
#include <stdlib.h>

void zadanie1(unsigned int n, int tab[])
{
	for(int i=0;i<n;i++)
	{
		tab[i] = 0;
	}
	for(int i=0;i<n;i++)
        {
                printf("%i\n", tab[i]);

        }
	printf("\n\n\n\n");
	for(int i=0;i<n;i++)
        {
                tab[i] = i;
        }
	for(int i=0;i<n;i++)
        {
                printf("%i\n", tab[i]);
        }
	printf("\n\n\n\n");
	for(int i=0;i<n;i++)
        {
        	tab[i] = i*2;
        }
        for(int i=0;i<n;i++)
        {
                printf("%i\n", tab[i]);
	}
        printf("\n\n\n\n");
        for(int i=0;i<n;i++)
        {
		tab[i] = i*(-1);
	}
	for(int i=0;i<n;i++)
	{
        	printf("%i\n", tab[i]);
        }
}

int zadanie3(unsigned int n, const int tab[])
{
	int srednia=0;
	for(int i=0;i<n;i++)
	{
		srednia += tab[i];
	}
	return srednia / n;
}

void zadanie19(unsigned int n, int tab1[])
{
	int ilosc=0;
	for(int i=0;i<n;i++)
	{
		if(tab1[i]>0)
			ilosc++;
	}

	int tab2[ilosc];
	int index2=0;
	for(int i=0;i<n;i++)
        {
                if(tab1[i]>0)
		{
			tab2[index2] = tab1[i];
			index2++;
		}
        }

	for(int i=0;i<ilosc;i++)
        {
                 printf("%i\n", tab2[i]);
        }
}

void zadanie16(double tab[])
{
	free(tab);
	tab = NULL;
}

void wyswietl(unsigned int n, double tab[])
{
	for(int i=0;i<n;i++)
	{
		printf("%0.f\n", tab[i]);
	}
}
int main()
{
	unsigned int n = 6;
	int tab[n];
	const int tab2[] = {20, 30, 40, 50, 60, 70};
	int tablica[]= {12, 0, 13, 0, 0, 44};
	zadanie1(n, tab);
	int srednia = zadanie3(n, tab2);
	printf("\n%d\n", srednia);
	printf("\n");
	zadanie19(n, tablica);
	double * tabd = malloc(sizeof(double) * n);
	for(int i=0;i<n;i++)
		tabd[i]=i;
	printf("\n\n");
	wyswietl(n, tabd);
	zadanie16(tabd);
	printf("\n\n");
	wyswietl(n, tabd);
	return 0;
}
