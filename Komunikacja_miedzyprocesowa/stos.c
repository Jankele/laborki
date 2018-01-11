#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define N 10

unsigned short iterator = 0;
int *stos;

void push_pop(int *node, int a)
{
    if(iterator > N || iterator < 1)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        node[iterator-1] = a;
        iterator++;
    }
}

int pop_front(int *node)
{
    int pop_value;
    if(iterator < 1)
    {
        return -1;
    }
    else
    {
        pop_value = node[iterator - 1];
        node[iterator-1] = 0;
        iterator--;
        return node[iterator-1];
    }
}

int main()
{
	pid_t pid;
	int shmid, status;
	sem_t pelny;
	sem_t pusty;
	
	if ((shmid = shmget(IPC_PRIVATE, sizeof(int)*N, IPC_CREAT)) == -1)
	{
        perror("shmget error\n");
        exit(EXIT_FAILURE);
    }

	stos = shmat(shmid, NULL);
	
	sem_init(&pusty,  1, 1);
	sem_init(&pelny,  1, 0);

	pid = fork();
	if(pid == -1)
	{
		perror("fork error\n");
		exit(EXIT_FAILURE);		
	}

	else if(pid == 0) //dziecko - producent
	{
		while(1)
		{
			sem_wait(&pelny);
				
			sem_post(&pusty);
		}
		sem_close(pelny);
		sem_close(pusty);
		shmdt(&stos, NULL);
		return 0;
	}
	else // rodzic - konsument
	{
		while(1)
		{
			sem_wait(&pusty);
			
			sem_post(&pelny);
			wait(&status);
		}
		sem_close(pelny);
		sem_close(pusty);
		shmdt(&stos, NULL);
		return 0;
	}
}
