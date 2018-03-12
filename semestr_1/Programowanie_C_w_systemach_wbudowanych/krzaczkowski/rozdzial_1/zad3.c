#include <stdio.h>
#include <stdlib.h>

void wytnij(char *tab, int n, int m)
{
	int plus = m - n + 1;
	int l = sizeof(tab) / sizeof(char);
	char *tmp = tab;
	for(int i=0;i<l;i++)
	{
		if(i>=n)
		tab[i] = tmp[i+plus];
	}
}

int main()
{
	int a = 15, n = 3, m = 5;
	char tab[] = "aaabbbcccdddeee";
	for(int i=0;i<a;i++)
		printf("%c", tab[i]);
	puts("");
	wytnij(tab, n, m);
	for(int i=0;i<a;i++)
		printf("%c", tab[i]);
	puts("");
	return 0;
}