// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define ll int

int main()
{
    char inp[200];

    ll fileDesc1, fileDesc2;
    fileDesc1 = open("fifo1", O_RDONLY);
    fileDesc2 = open("fifo2", O_WRONLY);

    read(fileDesc1, inp, sizeof(inp));
    printf("Message Received Client (FIFO1) : %s\n", inp);

    ll charCnt = 0, wrdCnt = 0, i = 0;
    for(i=0; i < strlen(inp); i++)
    {
        charCnt++;
        if(inp[i] == ' ')
        {
            wrdCnt++;
        }
    }

    sprintf(inp, "No. of Char : %d\n No. of Words : %d\n", charCnt, (wrdCnt + 1));
    write(fileDesc2, inp, sizeof(inp));

    close(fileDesc1);
    close(fileDesc2);

    return 0;
}