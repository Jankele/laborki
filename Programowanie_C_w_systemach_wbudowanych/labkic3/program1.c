#include <stdio.h>

int main()
{
	int liczba;
	int potega;
	FILE *file = fopen("plik1.txt", "r");
	FILE *file2 = fopen("plik2.txt", "w");
	while(file != EOF){
	fscanf(file, "%d", &liczba);
	potega = liczba*liczba;
	fprintf(file2, "%d ", potega);}
	fclose(file);
	fclose(file2);
	return 0; 
}
