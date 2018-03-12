#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define ILOSC 10
#define KONIEC 5

int bufor[ILOSC], i;
pthread_mutex_t muteks;
pthread_cond_t zrobione;// wyczyszczony;

void push_front(int wartosc)
{
	if(i < ILOSC)
		bufor[i++] = wartosc;
}

int pop_front()
{
	if(i > 0)
		return bufor[--i];
}

void* producent(void* arg)
{
	int wartosc = 1, czy = 1;
	while(czy <= (KONIEC * ILOSC))
	{
		pthread_mutex_lock(&muteks);
			while(i == ILOSC)
				pthread_cond_wait(&zrobione, &muteks);
			push_front(wartosc);
			printf("producent wyprodukował: %d\n", wartosc++);
			if(i == 1)
				pthread_cond_signal(&zrobione);

			czy++;
		pthread_mutex_unlock(&muteks);
	}
}

void* konsument(void* arg)
{
	int wynik, czy = 1;

	while(czy <= (KONIEC * ILOSC))
	{
		pthread_mutex_lock(&muteks);
			while(i == 0)
				pthread_cond_wait(&zrobione, &muteks);
			wynik = pop_front();
			printf("-----------------------konsument skonsumował : %d\n", wynik);
			if(i == ILOSC - 1)
				pthread_cond_signal(&zrobione);

			czy++;
		pthread_mutex_unlock(&muteks);
	}
}

int main()
{
	pthread_t zapisz, wyczysc;

	pthread_mutex_init(&muteks, NULL);
	{
//		pthread_cond_init(&wyczyszczony, NULL);
		pthread_cond_init(&zrobione,  NULL);

		pthread_create(&zapisz, NULL, producent, NULL);
		pthread_create(&wyczysc, NULL, konsument, NULL);
		pthread_join(zapisz, NULL);
		pthread_join(wyczysc,  NULL);
	}
	pthread_mutex_destroy(&muteks);

//	pthread_cond_destroy(&wyczyszczony);
	pthread_cond_destroy(&zrobione);

	return 0;
}
