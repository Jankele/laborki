#include <stdio.h>

int main()
{
	int znak = 0;
	int potega = 0;
	FILE *filein = fopen("zad3.txt", "r");
	FILE *fileout = fopen("out.txt", "w");
	while((fscanf(filein, "%d", &znak)) != EOF)
	{
		potega = znak * znak;	
		fprintf(fileout, "%d ", potega);
	}
	fprintf(fileout, "%s", "\n");
	fclose(filein);
	fclose(fileout);
	

}
