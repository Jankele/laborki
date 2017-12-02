#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main(int argc, char* argv[])
{
unsigned char liczba1 [20] = {'0'};
unsigned char liczba2 [20] = {'0'};
unsigned char wynik1 [21] = {0};
unsigned char wynik2 [21] = {0};
int i, x, z, b, przesuniecie1, przesuniecie2, przesuniecie, y=0, suma, reszta=0;
 

printf ("Podaj liczbe o maksymalnej dlugosci 20 cyfr:\n");
scanf ("%s", liczba1);
printf ("Pierwsza liczba wynosi %s.\n",liczba1);
 
printf ("Podaj liczbe o maksymalnej dlugosci 20 cyfr:\n");
scanf ("%s", liczba2);
printf ("Druga liczba wynosi %s.",liczba2);
 
//Shifts the numbers so they are aligned to the right
for (x= 0; liczba1[x] != 0; x++){
    liczba1[x] = liczba1[x];
    }
    przesuniecie1 = 20 - x;
    memmove(liczba1+przesuniecie1,liczba1,x);
    memset(liczba1, 0, przesuniecie1);
 
for (z= 0; liczba2[z] != 0; z++){
    liczba2[z] = liczba2[z];
    }
    przesuniecie2 = 20 - z;
    memmove(liczba2+przesuniecie2,liczba2,z);
    memset(liczba2, 0, przesuniecie2);
 
//Does the math
    for(y=19; y>=0; y--) {      
    if ( (liczba1[y] != 0) || (liczba2[y] != 0) ) {
        if ( (liczba1[y] != 0) && (liczba2[y] != 0) ) {
        suma = 0;
        suma += reszta;
        reszta = 0;
        suma += liczba1[y] - '0' + liczba2[y] - '0';
        reszta = suma / 10;
        wynik1[y+1] = suma % 10 + '0';
        }
    else {
    suma = 0;
    suma += reszta;
    reszta = 0;
    suma += liczba1[y] - '0' + liczba2[y];
    reszta = suma / 10;
    wynik1[y+1] = suma % 10 + '0';
    }
}
 
//Adds the carry if left over
if ((liczba1[y] == 0) && (liczba2[y] == 0) && (reszta==1)){
        wynik1[y+1] = 1 + '0';
        reszta = 0;
    }
}
 
//Shifts the digits back so a bunch of 0's are not leading the number.
    for (b=20; wynik1[b] != 0; b--){
    wynik1[b] = wynik1[b];
    }
    przesuniecie = b+1;
 
    memmove(wynik2,wynik1+przesuniecie,20-b);
  printf("\nSuma wynosi %s.\n", wynik2);
  return 0;
}
