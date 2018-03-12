#include <stdio.h>
#include <stdlib.h>
//sortowanie babelkowe
int main()
{
	int tab[9] = {3,2,6,9,1,12,4,24,7};
	int temp = 0;
	int n = sizeof(tab) / sizeof(int);
////////////////////////WYSWIETLANIE//////////////
	for (int i=0;i<n;i++)
	{
		printf("Tablica: %d\n", tab[i]);
	}
/////////////////////////SORTOWANIE//////////////
	while(n>1)
	{
		for(int i=0;i<n-1;i++)
		{
			if (tab[i] > tab[i+1])
			{
				temp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = temp;
			}
		}
		n = n-1;
	}
	printf("\n\n\n");
	n = sizeof(tab) / sizeof(int);
//////////////////////WYSWIETLANIE///////////////
	        for (int i=0;i<n;i++)
        {
                printf("Tablica: %d\n", tab[i]);
        }

}
