#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define N 5

unsigned short iterator = 0;

int push_pop(int *node);
int pop_front(int *node);

int main()
{
	pid_t pid;
	int status, wynik;
	/*int shm_tab = shm_open("/shm_tab", O_CREAT | O_EXCL | O_RDWR, 0600);
	int shm_pelny = shm_open("/shm_pelny", O_CREAT | O_EXCL | O_RDWR, 0600);
	int shm_pusty = shm_open("/shm_pusty", O_CREAT | O_EXCL | O_RDWR, 0600);
	ftruncate(shm_tab, sizeof(int)*N);
	ftruncate(shm_pelny, sizeof(sem_t));
	ftruncate(shm_pusty, sizeof(sem_t));*/
	int *stos = mmap(NULL, sizeof(int)*N, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	sem_t *pelny = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	sem_t *pusty = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

	sem_init(pusty,  1, 1);
	sem_init(pelny,  1, 0);

	if((pid = fork()) == -1)
	{
		perror("fork error\n");
		return 1;	
	}
	else if(pid == 0) //dziecko - producent
	{
		for(int i=0;i<10;i++)
		{
				sem_wait(pusty);
					wynik = push_pop(stos);
					if(wynik == -1)
						puts("Lista jest przepełniona!");
					else
						printf("Producent wrzucil na stos %d\n", wynik);
				sem_post(pelny);
				usleep(150000);
		}
				for(int i=N;i<=N;i++)
			printf("%d ", stos[i]);
		puts("");
		sem_close(pusty);
		sem_close(pelny);
		/*close(shm_tab);
		close(shm_pelny);
		close(shm_pusty);*/
		return 0;
	}
	else // rodzic - konsument
	{
		for(int i=0;i<10;i++)
		{
			sem_wait(pelny);
				wynik = pop_front(stos);
				if(wynik == -1)
					puts("Lista jest pusta!");
				else
					printf("-----------------------------Konsument sciagnal ze stosu %d | iterator = %d\n", wynik, iterator);
			sem_post(pusty);

		}
		wait(&status);
		sem_close(pusty);
		sem_close(pelny);
		/*close(shm_tab);
		close(shm_pelny);
		close(shm_pusty);*/
		sem_destroy(pusty);
		sem_destroy(pelny);
		/*shm_unlink("/shm_tab");
		shm_unlink("/shm_pelny");
		shm_unlink("/shm_pusty");*/
		return 0;
	}
}

int push_pop(int *node)
{
    if(iterator > N)
    {
        return -1;
    }
    else
    {
    	int a = rand()%30 + 1;
        node[iterator-1] = a;
        iterator++;
        //return node[iterator-1];
        return a;
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
