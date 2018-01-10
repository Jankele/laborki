#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10

int tablica[N] = {0};
unsigned short iterator = 0;

int push_pop(int *node, int a)
{
    if(iterator > N || iterator < 1)
    {
        return(-1);
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

void *producent(void *arg)
{

}

void *konsument(void *arg)
{

}

int main()
{

    return 0;
}
