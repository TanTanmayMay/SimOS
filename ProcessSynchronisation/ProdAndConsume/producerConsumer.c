// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 6
#define total_items 25
#define ll int

int offset[MAX];
int inPtr = 0, outPtr = 0, proCnt = 0, conCnt = 0, curItem = 1;

sem_t m, full, empty;

void* producer(void* arg)
{
    while(proCnt < total_items)
    {
        sem_wait(&empty);
        sem_wait(&m);

        offset[inPtr] = curItem;
        printf("Producer produced item\t -> %d\n", curItem);
        curItem++;
        inPtr = (inPtr + 1) % MAX;
        proCnt++;
        printf("*********Current Buffer State**********\n");
        if(inPtr > outPtr)
        {
            ll i = outPtr;
            for(i = outPtr; i < inPtr; i++)
            {
                printf("%d ", offset[i]);
            }
            printf("\n");
        }
        else
        {
            ll i = outPtr;
            for(i = outPtr; i < MAX; i++)
            {
                printf("%d ", offset[i]);
            }
            for(i = 0; i < inPtr; i++)
            {
                printf("%d ", offset[i]);
            }
            printf("\n");
        }
        printf("\n");

        fflush(stdout);
        sleep(2);

        sem_post(&m);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg)
{
    while(conCnt < total_items)
    {
        sem_wait(&full);
        sem_wait(&m);

        int remItem = offset[outPtr];
        printf("Consumer Consumed item\t -> %d\n", remItem);
        outPtr = (outPtr + 1) % MAX;
        conCnt++;
        printf("*********Current Buffer State**********\n");
        if(inPtr > outPtr)
        {
            ll i = outPtr;
            for(i = outPtr; i < inPtr; i++)
            {
                printf("%d ", offset[i]);
            }
            printf("\n");
        }
        else
        {
            ll i = outPtr;
            for(i = outPtr; i < MAX; i++)
            {
                printf("%d ", offset[i]);
            }
            for(i = 0; i < inPtr; i++)
            {
                printf("%d ", offset[i]);
            }
            printf("\n");
        }
        printf("\n");

        fflush(stdout);
        sleep(2);

        sem_post(&m);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t proThread1, proThread2, conThread;

    sem_init(&m, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX);

    pthread_create(&proThread1, NULL, producer, NULL);
    pthread_create(&proThread2, NULL, producer, NULL);
    pthread_create(&conThread, NULL, consumer, NULL);

    pthread_join(proThread1, NULL);
    pthread_join(proThread2, NULL);
    pthread_join(conThread, NULL);

    sem_destroy(&m);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}