#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_ELEMS 10
#define N 5


typedef struct List
{
    int value;
    struct List* next;
}List;

List *head = NULL;
unsigned int iterator = 0;
pthread_mutex_t muteks;
pthread_cond_t cond;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja dodajaca element na koniec listy
int push_back(List **node, int a)
{
    if(iterator <= MAX_ELEMS)
   {
        //wskaznik pomocniczny
        struct List *tmp = malloc(sizeof(List));
        tmp->next = NULL;
        tmp->value = a;
        //przypisanie glowy listy do tymczasowego wskaznika
        struct List *pom = *node;
        //jesli glowa jest pusta przypisz do niej nowy element
        if(*node == NULL)
        {
            *node = tmp;
            iterator++;
        }
        else
        {
    	   while(pom->next)
            {
            	pom = pom->next;
                iterator++;
            }
                pom->next = tmp;
        }
        return a;
   }
   else
        return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja usuwajaca pierwszy element z listy
int pop_front(List **node)
{
    if((*node) == NULL)
    {
        return -1;
    }
    else
    {
        struct List *tmp = *node;
        int pop_value = tmp->value;
        *node = (*node)->next;
        free(tmp);
        iterator = 0;
        return pop_value;
    }
}

void *producent(void *arg)
{
    while(1)
    {
        int wartosc = rand()%30;
        pthread_mutex_lock(&muteks); //poczatek sekcji krytycznej
          int value = push_back(&head,wartosc);
         if(value != -1)
           {
            printf("Watek %ld wrzucilem na liste element: %d\n", pthread_self(), value);
            pthread_cond_signal(&cond);
          }
          else
              printf("Watek %ld: lista jest przepełniona\n", pthread_self());
        pthread_mutex_unlock(&muteks); //koniec sekcji krytycznej
        sleep(1);
    }
    pthread_exit(NULL);
}

void *konsument(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&muteks); //poczatek sekcji krytycznej
            int value = pop_front(&head);
            if(value != -1)
            {
                printf("Watek %ld: zdjalem z listy element: %d\n", pthread_self(), value);
                pthread_cond_wait(&cond,&muteks);
            }
            else
                printf("Watek %ld: lista pusta\n", pthread_self());

        pthread_mutex_unlock(&muteks); //koniec sekcji krytycznej
        usleep(500000);
    }
    pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n = N+2;
    pthread_t producent_th[N];
    pthread_t konsument_th[n];

    if(pthread_mutex_init(&muteks,0)!=0)
    {
        perror("Nie moge utworzyc mutexa");
        exit(0);
    }
    if(pthread_cond_init(&cond,0)!=0)
    {
        perror("Nie moge utworzyc cond var");
        exit(0);
    }

    printf("START PRODUCENTOW\n");
    for(unsigned int i=0;i<N;i++)
    {
        if(pthread_create(&producent_th[i],NULL,producent,NULL)==0)
            printf("Stworzony producent %ld: ID =  %lu | Nowy watek: %ld\n", i, pthread_self(), producent_th[i]);
        else
        {
            perror("Blad podczas tworzenia producenta.\n");
            exit(0);
        }
    }

    printf("START KONSUMENTOW\n");
    for(unsigned int i=0;i<n;i++)
    {
        if(pthread_create(&konsument_th[i],NULL,konsument,NULL) == 0)
            printf("Stworzony konsument %ld: ID =  %lu | Nowy watek: %ld\n", i, pthread_self(), konsument_th[i]);
        else
        {
            perror("Blad podczas tworzenia klienta.\n");
            exit(0);
        }
    }
    for(unsigned int i=0;i<N;i++)
        pthread_join(producent_th[i],NULL);
    for(unsigned int i=0;i<n;i++)
        pthread_join(konsument_th[i],NULL);
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&muteks);
    return 0;
}
