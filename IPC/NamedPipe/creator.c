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
    if(mkfifo("fifo1", 0777) == -1) // 0777 -> Read, write, execute for users, group and others
    {
        if(errno != EEXIST)
        {
            printf("Creating fifo1 Failed :(\n");
            return 1;
        }
    }  
    if(mkfifo("fifo2", 0777) == -1)
    {
        if(errno != EEXIST)
        {
            printf("Creating fifo2 failed :>\n");
            return 2;
        }
    }
    return 0;
}