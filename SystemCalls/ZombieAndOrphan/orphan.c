// @author : Tanmay Kokate

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define ll  int

int main()
{
    pid_t fVal;
    fVal = fork();
    if(fVal == 0)
    {
        sleep(2);
        printf("I am Child with id : %d\n", getpid());
        printf("My parent is with id : %d\n", getppid());
    }
    else
    {
        printf("I am Parent with id : %d\n", getpid());
        printf("My child has id : %d\n", fVal);
    }

    return 0;
}