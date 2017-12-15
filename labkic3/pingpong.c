#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t pingc, pongc;
int jesli = 0, stop = 0;
void *pingf()
{
	while(stop<20)
	{			
		pthread_mutex_lock( &mutex );
			if(jesli == 1)
				pthread_cond_wait(&pingc, &mutex);
			printf("ping\n");
			jesli = 1;
			stop++;
			usleep(250000);
			pthread_cond_signal(&pongc);
		pthread_mutex_unlock( &mutex );
	}
	pthread_exit(0);
}

void *pongf()
{
	while(stop<20)
	{
		pthread_mutex_lock( &mutex );
		if(jesli == 0)
			pthread_cond_wait(&pongc, &mutex);
		printf("pong\n");
		jesli = 0;
		stop++;
		usleep(250000);
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
//terminacja mutexu oraz zmiennych warunkowych
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&pingc);
	pthread_cond_destroy(&pongc);

	return 0;
}

