/*
+++ podczas kompilacji trzeab zlinkować -lpthread
+++ Program dodaje/usuwa elementy z listy jednokierunkowej nasladujacej strukture LIFO.
+++ Operacje push i pop obslugiwane sa przez funkcje push_back oraz pop_front,
	funkcje te sa typu int aby mozna bylo zwrocic wartosci na ktorych pracuja oraz zabezpieczyc program przed wyjsciem poza wyznaczony zakres listy (MAX_ELEMS)
+++ praca producenta oraz konsumenta znajduje sie w funkcjach z odpowiadajacymi im nazwami
+++ W sekcjach krytycznych zabezpieczonych mutexem znajduja sie zmienne warunkowe ktore odpowiednio sugnalizuja watki w przypadkach proby przekroczenia zakresu listy
+++ po wyjsciu z mutexa watki spia aby lepiej zobrazowac dzialanie programu
*/
#include <stdio.h> //printf
#include <stdlib.h> //rand,free,malloc
#include <unistd.h> //sleep
#include <pthread.h> //watki

#define MAX_ELEMS 10 //maksuymalna liczba elementow na stosie
#define N 5 //liczba producentow
#define M 5 //liczba konsumentow
#define ILOSC_WYKONAN 20 //ilosc przejsc petli while
#define SLEEP_P 500000 //dlugosc snu producenta - dlugosci roznia sie aby czasami lista sie zapelnila lub zostala oczyszczona
#define SLEEP_K 400000 //dlugosc snu konsumenta

typedef struct List
{
    int value;
    struct List* next;
}List;

unsigned short warunek_p = 0, warunek_k = 0;
List *head = NULL; //inicjalizacja oryginalnej glowy listy
unsigned int iterator = 0; /* sprawdza ilosc elementow na liscie za przy kazdym wywolaniu funkcji push_back,
w przypadku gdyby funkcja dodawania na liste wykonala sie N razy (rozmiar listy),
wtedy nastepny element nie zostanie stworzony ani dodany.
iterator jest zerowany w funkcji pop_front,
poniewaz lista nigdy nie bedzie pelna jezeli zostanie z niej cos zdjete. */
pthread_mutex_t muteks;
pthread_cond_t pusty, pelny;

int push_back(List **node, int a) //funkcja dodajaca element na koniec listy
{
    if(iterator <= MAX_ELEMS)
   {
        struct List *tmp = malloc(sizeof(List)); //wskaznik pomocniczny
        tmp->next = NULL;
        tmp->value = a;
        struct List *pom = *node; //przypisanie glowy listy do tymczasowego wskaznika
        if(*node == NULL) //jesli glowa jest pusta przypisz do niej nowy element
        {
            *node = tmp;
            iterator++;
        }
        else
        {
    	   while(pom->next) //przewiniecie listy do konca
            {
            	pom = pom->next;
                iterator++;
            }
                pom->next = tmp; //wrzucenie elementu na koniec listy 
        }
        return tmp->value;
   }
   else
        return -1;
}

int pop_front(List **node) //funkcja usuwajaca pierwszy element z listy
{
    if((*node) == NULL) //jesli lista pusta zwroc -1
    {
        return -1;
    }
    else
    {
        struct List *tmp = *node; //przypisanie glowy listy do tymczasowego wskaznika
        int pop_value = tmp->value;
        *node = (*node)->next; //zmiana glowy na element wskazywany przez obecna glowe
        free(tmp); //usuniecie starej glowy poprzez tymczasowy wskaznik
        iterator = 0;
        return pop_value;
    }
}

void *producent(void *arg)
{
    while(warunek_p <= ILOSC_WYKONAN)
    {
        int wartosc = rand()%30;
        pthread_mutex_lock(&muteks); //poczatek sekcji krytycznej
          int value = push_back(&head,wartosc);
         if(value != -1) //JESLI nie wystapi - negatywny wynik if z push_back, TO wypisz ktory watek co wrzucil, po czym zasygnalizuj to za pomoca zmiennej warunkowej
           {
            printf("Watek %ld wrzucilem na liste element: %d\n", pthread_self(), value);
            pthread_cond_signal(&pusty);
          }
          else
          {
              printf("Watek %ld: lista jest przepełniona\n", pthread_self());
              pthread_cond_wait(&pelny,&muteks);
          }
        pthread_mutex_unlock(&muteks); //koniec sekcji krytycznej
        usleep(SLEEP_P);
        warunek_p++;
    }
    pthread_exit(NULL);
}

void *konsument(void *arg)
{
    while(warunek_k < ILOSC_WYKONAN)
    {
        pthread_mutex_lock(&muteks); //poczatek sekcji krytycznej
            int value = pop_front(&head);
            if(value != -1) //JESLI nie wystapi - negatywny wynik if z pop_front, TO wypisz ktory watek co zdjal, po czym zasygnalizuj to za pomoca zmiennej warunkowej
            {
                printf("Watek %ld: zdjalem z listy element: %d\n", pthread_self(), value);
                pthread_cond_signal(&pelny);
            }
            else
            {
                printf("Watek %ld: lista pusta\n", pthread_self());
				pthread_cond_wait(&pusty,&muteks);
            }
        pthread_mutex_unlock(&muteks); //koniec sekcji krytycznej
        usleep(SLEEP_K);
        warunek_k++;
    }
    pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    pthread_t producent_th[N];
    pthread_t konsument_th[M];

    if(pthread_mutex_init(&muteks,0)!=0)
    {
        perror("Nie moge utworzyc mutexa");
        exit(0);
    }
    if(pthread_cond_init(&pusty,0)!=0)
    {
        perror("Nie moge utworzyc cond var");
        exit(0);
    }

	if(pthread_cond_init(&pelny,0)!=0)
    {
        perror("Nie moge utworzyc cond var");
        exit(0);
    }

    printf("START PRODUCENTOW\n");
    for(unsigned int i=0;i<N;i++)
    {
        if(pthread_create(&producent_th[i],NULL,producent,NULL)==0)
            printf("Stworzony producent %ld: ID =  %lu | Nowy watek: %ld\n", i, pthread_self(), producent_th[i]); //przedstawienie tworzonych watkow i ich numerow id
        else
        {
            perror("Blad podczas tworzenia producenta.\n");
            exit(0);
        }
    }

    printf("START KONSUMENTOW\n");
    for(unsigned int i=0;i<M;i++)
    {
        if(pthread_create(&konsument_th[i],NULL,konsument,NULL) == 0)
            printf("Stworzony konsument %ld: ID =  %lu | Nowy watek: %ld\n", i, pthread_self(), konsument_th[i]); //przedstawienie tworzonych watkow i ich numerow id
        else
        {
            perror("Blad podczas tworzenia klienta.\n");
            exit(0);
        }
    }
    for(unsigned int i=0;i<N;i++)
        pthread_join(konsument_th[i],NULL);
    for(unsigned int i=0;i<N;i++)
        pthread_join(producent_th[i],NULL);
    

    pthread_cond_destroy(&pusty);
    pthread_cond_destroy(&pelny);
    pthread_mutex_destroy(&muteks);
    return 0;
}
