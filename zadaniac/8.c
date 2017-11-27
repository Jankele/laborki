#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// wypisuje numer zadania
void ktore(int i)
{
	printf("\nZadanie %d:\n", i);
}
//zadanie pierwsze zwraca otwarie pliku na podstawie deskryptora
FILE * zadanie1(char sciezka[])
{
	return fopen(sciezka, "r");
}
// zadanie 2 wypisuje slowa z pliku tekstowego oddzielone spacjami
void zadanie2(FILE *file)
{
	char str[120];
	while(fscanf(file, "%s", str) != EOF)
	{
        	printf("%s", str);
		printf(" ");
	}
	printf("\n");
	fclose(file);
}
// zadanie 3 wypisuje slowa z pliku tekstowego pomijajac biale znaki
void zadanie3(char sciezka[])
{
	char str[120];
	FILE *file = fopen (sciezka, "r");
	while(fscanf(file, "%s", str) != EOF)
		printf("%s", str);
	printf("\n");
	fclose(file);
}
// zadanie 4 zlicza ilosc wystapien danego znaku
int zadanie4(char sciezka[], char c)
{
	int counter = 0;
	FILE * file = fopen(sciezka, "r");
	int znak;
	while((znak = fgetc(file)) != EOF)
	{
		if(znak == (int)c)
			counter++;
	}
	fclose(file);
	return counter;
}
// zadanie 5 zlicza ilosc wystapien znakow kodu ascii
void zadanie5(char sciezka[])
{
	FILE *file = fopen(sciezka, "r");
	int znak;
	int tab[256] = { 0 };
	int ilosc = 0;
	while((znak = fgetc(file)) != EOF)
	{
		tab[znak] = tab[znak] + 1;
	}
	fclose(file);
	for(int i=0; i<256; i++)
	{
		if(tab[i] > 0 && i!=10)
		{
			printf("znak %c wystapil %d razy.\n",i,tab[i]);
			if(ilosc < tab[i])
				ilosc = tab[i];
		}
	}
// zadanie 6 wypisuje najczesciej wystepujacy znak w pliku tekstowym
	ktore(6);
	for(int i=0; i<256; i++)
	{
		if(tab[i] == ilosc)
			printf("najczesciej występujacy element to: %c z iloscia wystapien rowna: %d\n", i, tab[i]);
	}
}
// zadanie 7 zwraca sume wszystkich liczb znajsujacych sie w pliku tekstowym
int zadanie7(char sciezka2[])
{
	int liczba;
	int suma = 0;
	FILE *file2 = fopen(sciezka2, "r");
	while((fscanf(file2, "%d", &liczba)) != EOF)
	{
		suma += liczba;
	}
	fclose(file2);
	return suma;
}
// zadanie 8 wypisuje najmniejsza liczbe znajdujaca sie w pliku tekstowym
int zadanie8(char sciezka2[])
{
	int liczba;
        int najmniejsza = 0;
        FILE *file2 = fopen(sciezka2, "r");
	fscanf(file2, "%d", &najmniejsza);
        while((fscanf(file2, "%d", &liczba)) != EOF)
        {
                if(liczba<najmniejsza)
			najmniejsza=liczba;
        }
	fclose(file2);
        return najmniejsza;
}
// zadanie 9 i 10 porownuje zawartosc dwoch plikow i zwraca prawde lub falsz

int zadanie9(char sciezka[], char sciezka2[])
{
	int znak, znak2;
	FILE *file = fopen(sciezka, "r");
	FILE *file2 = fopen(sciezka2, "r");
	while((znak = fgetc(file)) != EOF && (znak2 = fgetc(file2)) != EOF)
	{
		if (znak != znak2)
			return 0;
	}
	return 1;
}

FILE * zadanie11(char sciezka[])
{
	char c[] = " abc";
	FILE *file;
	if((file = fopen(sciezka, "a")) != NULL)
	{
		printf("poprawnie zwrocono otwarty plik z kursorem ustawionym na koncu pliku.\n");
		return file;
	}
	else
	{
		printf("nie udalo sie otworzyc pliku.\n");
		return NULL;
	}
}

void zadanie12(FILE * file, int n)
{
	char a[50] = "asd";
	char b;
	for (int i=0;i<n;i++)
	{
		printf("Podaj co chcesz dopisac do pliku: ");
		fgets(a, 50, stdin);
		fwrite(a, 1, sizeof(a), file);
	}
	fclose(file);
}

void zadanie13(FILE *odczyt, FILE *zapis)
{
	fseek(odczyt, 0, SEEK_END);
	int rozmiar = ftell(odczyt);
	rewind(odczyt);
	char *bufor = (char*)malloc(sizeof(char)*rozmiar);
	while(fgets(bufor, sizeof(bufor), odczyt) != NULL)
	{
		fwrite(bufor, sizeof(char), sizeof(bufor), zapis);
		memset(&bufor[0], 0, sizeof(bufor));
        printf("poprawnie skopiowano plik.\n");
	}
	free(bufor);
	fclose(odczyt);
	fclose(zapis);
}

void zadanie16(char sciezka[], int *tab, int n)
{
    FILE *file = fopen(sciezka, "a+t");
    for(int i=0;i<n;i++)
    {
        fprintf(file,"%d\n",tab[i]);
    }
    fclose(file);
}
void zadanie17(char sciezka[], int tab[][10], int n)
{
    FILE *file = fopen(sciezka, "wb");
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            fprintf(file, "%d ", tab[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
void zadanie18(char sciezka[], int **tab, int n)
{
    int znak=0;
    tab = malloc(sizeof(int)*n);
    FILE *file = fopen(sciezka, "rb");
    for(int i=0;i<n;i++)
         tab[i] = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            fscanf(file, "%d", &znak);
            tab[i][j] = znak;}
    }
    fclose(file);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }

}

int main()
{
	char c = 'a';
    int n = 10;
    int tab[] = {0,1,2,3,4,5,6,7,8,9,10};
    int tab2[n][n];
    int **tab3;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tab2[i][j] = j;
    char sciezka[] = "tekst.txt";
	char sciezka2[] = "liczby.txt";
	char sciezka3[] = "tekst2.txt";
	char sciezka4[] = "tekst3.txt";
	char sciezka5[] = "tekst4.txt";
	char sciezka6[] = "tekst5.txt";
    char sciezka7[] = "tekst6.txt";
	FILE *file = zadanie1(sciezka);
	FILE *file2 = fopen(sciezka4, "w");
	FILE *file3 = fopen(sciezka5, "r");
	FILE *file4 = fopen(sciezka6, "w");
	ktore(2);
	zadanie2(file);
	ktore(3);
	zadanie3(sciezka);
	ktore(4);
	printf("%d\n", zadanie4(sciezka, c));
	ktore(5);
	zadanie5(sciezka);
	ktore(7);
	printf("suma wynosi: %d\n", zadanie7(sciezka2));
	ktore(8);
	printf("najmniejsza liczba w pliku wynosi: %d\n", zadanie8(sciezka2));
	ktore(9);
	if(zadanie9(sciezka, sciezka3) > 0)
		printf("Pliki mają taką samą treść\n");
	else
		printf("Pliki nie mają takiej samej treści\n");
	ktore(11);
	zadanie11(sciezka3);
//	ktore(12);
//	zadanie12(file2,3);
	ktore(13);
	zadanie13(file3, file4);
	ktore(14);
    printf(" działa tak samo jak 13 z roznica przekazania sciezki zamiast deskryptora.\n");
    ktore(15);
    printf(" działa tak samo jak 13 z roznica otwarcia pliku z parametrem dopisywania 'a'.\n");
    ktore(16);
    zadanie16(sciezka6, tab, n);
//    ktore(17);
 //   zadanie17(sciezka7, tab2, n);
//    ktore(18);
  //  zadanie18(sciezka7, tab3, n);
    return 0;
}
