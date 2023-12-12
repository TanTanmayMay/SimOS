// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define ll int

pthread_t readThreads[100], writeThreads[100];
sem_t m, wrt;
ll rc = 0;

void* reader(void* par)
{
    sem_wait(&m);
    rc++;
    if(rc == 1)
    {
        sem_wait(&wrt);
    }
    sem_post(&m);
    printf("%d -> Readers reading Critical section\n", rc);
    usleep(3);
    sem_wait(&m);
    rc--;
    if(rc == 0)
    {
        sem_post(&wrt);
    }
    sem_post(&m);
    printf("%d Reader is leaving\n",(rc + 1));
    return NULL;
}

void* writer(void* par)
{
    printf("Writer trying to enter the critical section\n");
    sem_wait(&wrt);
    printf("Writer performing the write operation\n");
    sem_post(&wrt);
    printf("Writer is leaving\n");
    return NULL;
}

int main()
{
    ll n, i;
    printf("Enter Number of Readers : ");
    scanf("%d", &n);
    sem_init(&m, 0, 1);
    sem_init(&wrt, 0, 1);

    for(i=0; i<n; i++)
    {
        pthread_create(&writeThreads[i], NULL, reader, NULL);
        pthread_create(&readThreads[i], NULL, writer, NULL);
    }

    for(i=0; i<n; i++)
    {
        pthread_join(writeThreads[i], NULL);
        pthread_join(readThreads[i], NULL);
    }

    return 0;
}