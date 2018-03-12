#include <stdio.h>
#include <stdlib.h> 

void funkcja(int ***a, int n)
{
	*a = (int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
		(*a)[i] = (int*)malloc(sizeof(int*)*n);
}

int main()
{
	int **a;
	int n = 6;
	funkcja(&a, n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = j;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}