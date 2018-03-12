#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

pthread_mutex_t mutex;
pthread_cond_t condvar;

int threads_left = 0;

void *do_pingpong(void *arg)
{
	char *myname = (char*)arg;
	int connt = 0;
	fprintf(stdout, "Thread \"%s\" has started\n", myname);
	threads_left++;
	if(pthread_mutex_lock(&mutex)!=0)
	{
		perror("mutex lock failed!\n");
		exit(-1); 
	}
	while(threads_left++ < 5)
	{
		fprintf(stdout, "Thread %s has started\n", myname);
		pthread_cond_signal(&condvar);
		pthread_cond_wait(&condvar, &mutex);
	}
	if(pthread_mutex_unlock(&mutex)!=0)
	{
		perror("Mutex unlock failed!\n");
		exit(-1);
	}
	fprintf(stdout, "Thread %s has ended\n", myname);
	threads_left--;
	pthread_cond_signal(&condvar);
	return NULL;
}

int main()
{
	char t1name[] = "ping";
	char t2name[] = "pong";
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&condvar, NULL);
	if(pthread_create(&t1, NULL, do_pingpong, (void*)t1name) != 0)
	{
		perror("t1 create failed\n");
		exit(-1);
	}
	if(pthread_create(&t2, NULL, do_pingpong, (void*)t2name) != 0)
	{
		perror("t2 create failed\n");
		exit(-1);
	}
	pthread_detach(t1);
	pthread_detach(t2);
	while(1)
	{
		sleep(1);
		if(threads_left == 0)
			exit(0);	
	}
	return 0;
}
