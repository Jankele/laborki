#include <stdio.h>
#define MAX 10

int tab1[MAX] = {100,102,104,106,108}; 
char napis[]="programowanie\n";
int x=100, y=200;

int *wsk1, *wsk2;
char *wskc;

int dodaj(int cel, int v){
return cel+v;}

int main()
{
	wsk1 = &x;
/*	//printf("x: %d\nwsk: %p\n*wsk: %d\n", x, wsk1, *wsk1 );
	//y = dodaj(x,2);
	//printf("y = %d\n", y);
	printf("adres x: &x=%p wsk1=%p\n",&x,wsk1);
	*wsk1 = 5;
	printf("x=%d wsk1=%p *wsk1=%d\n",x,wsk1,*wsk1);
	wsk2 = wsk1;
	printf("tymczasem *wsk2=%d bo wsk2=%p\n",*wsk2,wsk2);
//	*wsk2 = *wsk1; // pod adres wsk2 koppiowana jest wartosc spod adresy wsk1
//	wsk2 = wsk1; // adres wsk2 zmienia sie na adres wsk1

	printf("x=%d wsk=%p *wsk1=%d wsk1=%p wsk2=%d\n", ++x, wsk1, *wsk1, wsk2, *wsk2);

printf("x=%d wsk=%p *wsk1=%d wsk1=%p wsk2=%d\n", x, wsk1, *wsk1, wsk2, *wsk2);*/
printf("\nTABLICE:\n");
wsk2 = tab1;
for(int i=0;i<MAX;i++)
/*printf("%5d", tab1[i]);
printf("\n");
wsk1=&tab1[0];
wsk2=tab1;
printf("%5d, %d\n", *wsk1, *wsk2);
printf("++*wsk1=%d *++wsk1=%d *(wsk2+3)=%d *wsk1-10=%d\n",++*wsk1, *++wsk1,  *(wsk2+3), *wsk2-10);
printf("wsk2=%p (wsk2+3)=%p\n", wsk2, wsk2+3);

printf("size of int=%lu\n", sizeof(int));
printf("size of  memory pointed by wsk2=%lu\n", sizeof(*wsk2));*/
printf("*(wsk2+%d)=%d\n", i, *(wsk2+i)); 
printf("napis=%p napis=%s", napis, napis);
wskc = napis+3;
printf("wskc=%p wskc=%s", wskc, wskc);
*wskc+=3;
printf("wskc=%p wskc=%s", wskc, wskc);

	return x; 
}

