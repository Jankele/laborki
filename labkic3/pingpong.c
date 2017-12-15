#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t pingc, pongc;
int jesli = 0, stop = 0;
void *pingf()
{
//petla wykonuje sie 20 razy
	while(stop<20)
	{
//blokujemy wykonywanie mutexem			
		pthread_mutex_lock( &mutex );
//sprawdzamy czy drugi watek wykonal juz swoja prace
			if(jesli == 1)
				pthread_cond_wait(&pingc, &mutex);
//wypisujemy "ping" inkrementujemy petle while oraz usypiamy wykonanie watku na 0,25 sekundy w celu lepszego zobrazowania synchronizacji watkow.
			printf("ping\n");
			jesli = 1;
			stop++;
			usleep(250000);
//sygnalizujemy drugi watek o koncu swojej pracy
			pthread_cond_signal(&pongc);
		pthread_mutex_unlock( &mutex );
	}
	pthread_exit(0);
}

void *pongf()
{
//petla wykonuje sie 20 razy
	while(stop<20)
	{
//blokujemy wykonywanie mutexem	
		pthread_mutex_lock( &mutex );
//sprawdzamy czy pierwszy watek wykonal juz swoja prace
		if(jesli == 0)
			pthread_cond_wait(&pongc, &mutex);
//wypisujemy "ping" inkrementujemy petle while oraz usypiamy wykonanie watku na 0,25 sekundy w celu lepszego zobrazowania synchronizacji watkow.
		printf("pong\n");
		jesli = 0;
		stop++;
		usleep(250000);
//sygnalizujemy pierwszy watek o koncu swojej pracy
		pthread_cond_signal(&pingc);
		pthread_mutex_unlock( &mutex );
	}
	pthread_exit(0);
}

int main()
{
//deklaracja watkow
	pthread_t ping, pong;
//inicjalizacja mutexu
	pthread_mutex_init(&mutex, NULL);
//inicjalizacja zmiennych warunku
	pthread_cond_init(&pingc, NULL);
	pthread_cond_init(&pongc, NULL);
//inicjalizacja watkow
	pthread_create( &ping, NULL, pingf, NULL );
	pthread_create( &pong, NULL, pongf, NULL );
//zatrzymanie watkow
	pthread_join( ping, NULL );
	pthread_join( pong, NULL );
//niszczenie mutexu oraz zmiennych warunkowych
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&pingc);
	pthread_cond_destroy(&pongc);

	return 0;
}

