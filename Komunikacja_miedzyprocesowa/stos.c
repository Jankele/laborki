#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10

int stos[N] = {0};
unsigned short iterator = 0;
sem_t pelny;
sem_t pusty;

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
	size_t size = sizeof(stos);
	
	pid = fork();
	if(pid == -1)
		exit(EXIT_FAILURE);
	else if(pid == 0) //dziecko - producent
	{
		while(1)
		{
			sem_wait(&pelny);
				
			sem_post(&pusty);
		}
		sem_close(pelny);
		sem_close(pusty);
		return 0;
	}
	else // rodzic - konsument
	{
		while(1)
		{
			sem_wait(&pusty);
			
			sem_post(&pelny);
		}
		sem_close(pelny);
		sem_close(pusty);
		return 0;
	}
}
