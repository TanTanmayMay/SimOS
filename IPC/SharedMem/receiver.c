// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define ll  int

int main()
{
    void* shared_memory_addr;
    char inp[200];

    ll shmid = shmget((key_t)1, 4096, 0777);
    shared_memory_addr = shmat(shmid, NULL, 0);
    printf("Shared memory attached to address : %p\n", shared_memory_addr);

    strcpy(inp, shared_memory_addr);
    printf("Message Read by Receiver : ");

    ll i;
    for(i = 0; i < strlen(inp); i++)
    {
        printf("%c", inp[i]);
    }
    printf("\n");

    return 0;
}