#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 256;
	char znak[256]= {0};
	int flaga;
	char znak2[2] = "\n";
	FILE *file = fopen("zad.txt", "r");
/*	while(fscanf(file, "%c", &znak) != EOF)
	{
		if((int)znak>48 && (int)znak<57)
		printf("\n%c\n", znak);
	}*/
	while(fgets(znak, n, file) != NULL)
	{
		flaga = 0;
		for(int i=0;i<n;i++)
		{
			if((int)(znak[i])>=48 && (int)(znak[i])<=57)
			flaga++;
		}
		if(flaga > 0)
			printf("%s\n", znak);
	}
	fclose(file);
}
