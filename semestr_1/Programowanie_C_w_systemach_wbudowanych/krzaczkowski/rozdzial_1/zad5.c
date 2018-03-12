#include <stdio.h>
#include <stdlib.h>

int main()
{
	wchar_t *tab = NULL;
	FILE* fd = NULL;
	if(!(fd = fopen("tekst.txt", "rb")))
	{
		puts("Nie mozna otworzyc pliku");
		exit(EXIT_SUCCESS);
	}
	fseek(fd, 0, SEEK_END);
	int n = ftell(fd);
	rewind(fd);
	tab = malloc(sizeof(char)*n);
	fread(tab, sizeof(char), n, fd);
	printf("%s", tab);
	fclose(fd);
	free(tab);
	return 0;
}