#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define N 10

typedef struct str
{
	sem_t pelny;
	sem_t pusty;
	int age;
} str;

unsigned short iterator = 0;


int push_pop(int *node, int a)
{
    if(iterator > N)
    {
        return -1;
    }
    else
    {
        node[iterator-1] = a;
        iterator++;
        return node[iterator-1];
    }
}

int pop_front(int *node)
{
    if(iterator < 1)
    {
        return -1;
    }
    else
    {
        node[iterator-1] = 0;
        iterator--;
        return node[iterator];
    }
}

int main()
{
	pid_t pid;
	int shm_fd = shm_open("/my_shm", O_CREAT | O_EXCL | O_RDWR, 0600);
//	int *stos = NULL;
	str *stos = NULL;
	int status, wynik;
	//int a = rand()%30 + 1;

//	ftruncate(shm_fd, sizeof(int)*N);
	ftruncate(shm_fd, sizeof(str));
//	stos = mmap(NULL, sizeof(int)*N, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	stos = mmap(NULL, sizeof(str), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	sem_init(&stos->pusty,  1, 1);
	sem_init(&stos->pelny,  1, 0);

	if((pid = fork()) == -1)
	{
		perror("fork error\n");
		return 1;	
	}
	else if(pid == 0) //dziecko - producent
	{
		for(int i=0;i<30;i++)
		{
				sem_wait(&stos->pusty);
					//wynik = push_pop(stos, a);
					//printf("Producent wrzucil na stos %d\n", wynik);
				puts("a");
				sem_post(&stos->pelny);
				sleep(1);
		}
		sem_close(&stos->pusty);
		sem_close(&stos->pelny);
		close(shm_fd);
		return 0;
	}
	else // rodzic - konsument
	{
		for(int i=0;i<30;i++)
		{
			sem_wait(&stos->pelny);
				//wynik = pop_front(stos);
				//printf("-----------------------------Konsument sciagnal ze stosu %d\n", wynik);
			puts("b");
			sem_post(&stos->pusty);

		}
		wait(&status);
		sem_close(&stos->pusty);
		sem_close(&stos->pelny);
		close(shm_fd);
		sem_destroy(&stos->pusty);
		sem_destroy(&stos->pelny);
		shm_unlink("/my_shm");
		return 0;
	}
}
