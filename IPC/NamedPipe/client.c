// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define ll int

int main()
{
    char inp[200];
    printf("Message that you want to Send and Process : ");
    fgets(inp, sizeof(inp), stdin);

    ll fileDesc1, fileDesc2;
    fileDesc1 = open("fifo1", O_WRONLY);
    fileDesc2 = open("fifo2", O_RDONLY);

    write(fileDesc1, inp, sizeof(inp));
    read(fileDesc2, inp, sizeof(inp));

    printf("========= Result received from Server(FIFO2) =========\n%s", inp);

    close(fileDesc1);
    close(fileDesc2);

    return 0;
}