#include <stdio.h>
#include <stdlib.h>

int main()
{
	int znak;
	FILE *file = fopen("tekstowy", "wb");
	printf("podaj liczbe do wczytania: ");
	scanf("%d", &znak);
	fwrite(&znak, sizeof(int), znak, file);
	fclose(file);
	FILE *file2 = fopen("tekstowy", "rb");
	fscanf(file2, "%d", &znak);
	printf("\n%d\n", znak);
	return 0;
}
