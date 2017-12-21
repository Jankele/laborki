#include <stdio.h>
#include <stdlib.h>

#define M 100

int **zad1(int n, int m)
{
	int **tab = malloc(sizeof(int*) * n);
	for(int i=0;i<n;i++)
		tab[i]= malloc(sizeof(int) * m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			tab[i][j]=j+1;
	return tab;
}

void wyswietl(int **tab, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
}

int **zad8(int **tab, int n)
{
	tab = malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
		tab[i] = malloc(sizeof(int)*M);
	for(int i=0;i<n;i++)
		for(int j=0;j<M;j++)
			tab[i][j]=0;
	return tab;
}

int zad17(int **tab, int n, int m)
{
	int max = 0, srednia = 0;
	for(int i=0;i<n;i++)
	{
		srednia = 0;
		for(int j=0;j<m;j++)
			srednia += tab[i][j];
		srednia /= m;
		if (srednia>max)
			max = srednia;
	}
	return max;
}

int main()
{
	int n=5, m=6;
	int **tab1;
	int **tab8;
	tab1 = zad1(n,m);
	tab8 = zad8(tab8, n);
	wyswietl(tab1, n, m);
	printf("\n\n");
	wyswietl(tab8, n, M);
	printf("\n%d\n", zad17(tab1, n, m));
	return 0;
}
