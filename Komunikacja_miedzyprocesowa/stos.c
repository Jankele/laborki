/*
+++ podczas kompilacji trzeab zlinkować -pthread -lrt
+++ Program zapisuje/odczytuje z tablicy statycznej, ktora reprezentuje stos.
+++ Stos jest wypełniany pseudolosowymi liczbami z zakresu 1-30.
+++ Po "zdjeciu" elementu ze stosu pod odpowiednim indeksem tablicy wstawiana jest liczba 0.
+++ Proces dziecka odpowiada za zapis, natomiast proces rodzica za odczyt.
+++ Semafor ktory obsluguje synchronizacje po stronie producenta zainicjalizowany jest z wartoscia 
	wieksza od zera, dzieki czemu mamy gwarancje, ze odczyt nigdy nie wykona sie pierwszy.
+++ Dzieki MAP_ANONYMOUS oraz -1 w miejscu deskryptora pliku nie potrzeba otwierac pliku ani ustawiac jego rozmiaru.
+++ Aby umożliwić wypisanie liczby która została wrzucona na stos, obie funkcje sa typu int.


+++ Procesy przed końcem wykonania przejścia w petli zasypiaja, 
	aby lepiej zobrazować zapis/odczyt w toku wykonywania programu.
+++ Wartości usleep różnią się od siebie w celu uniknięcia fałszywej synchronizacji,
	ktora pojawia sie czesto podczas gdy sen trwa taki sam czas
+++ Aby zauważyć działanie warunków w funkcjach push_pop oraz pop_front zakomentowałem semafory.
+++ Po odkomentowaniu semaforow procesy zostana zsynchronizowane,
	dzieki czemu nigdy nie dojdzie do sytuacji w ktorej stos moze byc pusty lub przepelniony.
*/
#include <stdio.h> //printf
#include <unistd.h> //fork
#include <stdlib.h> //exit, rand
#include <semaphore.h> //semafory
#include <sys/wait.h> // wait
#include <sys/mman.h> //dyrektywy na potrzeby pamieci wspoldzielonej

#define N 5 //ilosc elementow w tablicy
#define PETLA 40 //ilosc przejsc w petlach for
#define SEN_P 10000 // dlugosc snu w procesie producenta
#define SEN_K 20000 //dlugosc snu w procesie konsumenta

int push_pop(int *node);
int pop_front(int *node);

int main()
{
	pid_t pid;
	int status, wynik;
	int *stos = mmap(NULL, sizeof(int)*N, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	/*sem_t *pelny = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	sem_t *pusty = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);*/
	for(int i=0;i<=N;i++)
		stos[i]=0;
	/*sem_init(pusty,  1, 1);
	sem_init(pelny,  1, 0);*/

	if((pid = fork()) == -1)
	{
		perror("fork error\n");
		return 1;	
	}
	else if(pid == 0) //dziecko - producent
	{
		printf("PRODUCENT MOWI: MOJ PID TO: %d\n", getpid());
   		printf("PRODUCENT MOWI: PID MOJEGO RODZICA TO: %d\n", getppid());
		for(int i=0;i<PETLA;i++) 
		{
				//sem_wait(pusty); // poczatek sekcji krytycznej
					wynik = push_pop(stos);
					if(wynik == -1)
						puts("Stos jest przepełniony!");
					else
						printf("PRODUCENT WRZUCIL NA STOS %d\n", wynik);
				//sem_post(pelny); // koniec sekcji krytycznej
				usleep(SEN_P);
		}
		/*sem_close(pusty);
		sem_close(pelny);*/
		puts("Dziecko zakonczylo swoja prace");
		exit(EXIT_SUCCESS);
	}
	else // rodzic - konsument
	{
		printf("KONSUMENT MOWI: MOJ PID TO: %d\n", getpid());
   		printf("KONSUMENT MOWI: PID MOJEGO RODZICA TO: %d\n", getppid());
		for(int i=0;i<PETLA;i++) 
		{
			//sem_wait(pelny); // poczatek sekcji krytycznej
				wynik = pop_front(stos);
				if(wynik == -1)
					puts("Stos jest pusty!");
				else
					printf("----------------------KONSUMENT SCIAGNAL ZE STOSU %d\n", wynik);
			//sem_post(pusty); // koniec sekcji krytycznej
			usleep(SEN_K);
		}
		puts("Rodzic zakonczyl swoja prace");
		wait(&status); // czekaj na zakonczenie procesu dziecka
		puts("Dziecko zakonczyło sie z sukcesem");
		/*sem_close(pusty);
		sem_close(pelny);
		sem_destroy(pusty);
		sem_destroy(pelny);*/
		exit(EXIT_SUCCESS);
	}
}

int push_pop(int *node)
{
	unsigned short a = rand()%30 + 1; //losowanie z przedzialu <1-30>
	unsigned short iterator = 0;
	for(int i=0;i<N;i++) //zlicza ilosc elementow na stosie (czyli niezerowych)
	{
		if(node[i] > 0)
			iterator++;
	}
	if(iterator == N) // jesli liczba elementow na stosie rowna sie rozmiarowi tablicy, zwroc -1
		return -1;
	node[iterator] = a;
	return node[iterator];
}

int pop_front(int *node)
{
	unsigned short wynik;
	unsigned short iterator = 0;
	for(int i=0;i<N;i++)
	{
		if(node[i] > 0) //zlicza ilosc elementow na stosie (czyli niezerowych)
			iterator++;
    }
    if(iterator == 0) // jesli liczba elementow na stosie rowna sie 0, zwroc -1
    	return -1;
    wynik = node[iterator-1]; //zwraca ostatni niezerowy element oraz go zwraca
    node[iterator-1] = 0;
    return wynik;
}
