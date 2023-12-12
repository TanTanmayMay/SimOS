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

    ll shmid = shmget((key_t)1, 4096, 0777 | IPC_CREAT);
    shared_memory_addr = shmat(shmid, NULL, 0);
    printf("Shared memory attached to address : %p\n", shared_memory_addr);

    printf("Enter Message you want to Send : ");
    fgets(inp, sizeof(inp), stdin);

    strcpy(shared_memory_addr, inp);
    printf("Message written into shared memory successfully");
    return 0;
}