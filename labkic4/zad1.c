#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t pingsem, pongsem;

void *ping(void *arg)
{
	for(int i=0;i<20;i++)
	{
		sem_wait(&pingsem);
		usleep(250000);
		printf("ping\n");
		sem_post(&pongsem);
	}	
}

void *pong(void *arg)
{
	for(int i=0;i<20;i++)
	{
		sem_wait(&pongsem);
		usleep(250000);
		printf("pong\n");
		sem_post(&pingsem);
	}
}

int main()
{
	sem_init(&pingsem, 0, 1);
	sem_init(&pongsem, 0, 0);
	pthread_t ping_thread, pong_thread;
	pthread_create(&ping_thread, NULL, ping, NULL);
	pthread_create(&pong_thread, NULL, pong, NULL);
	pthread_join(ping_thread, NULL);
	pthread_join(pong_thread, NULL);
	return 0;
}
