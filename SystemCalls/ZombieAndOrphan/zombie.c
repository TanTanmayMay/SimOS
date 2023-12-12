// @author : Tanmay Kokate

#include <stdio.h>

int main()
{
    int pid, forkVal;

    pid = getpid();

    printf("Current ParentProcess ID :  %d\n\n", pid);
    printf("********FORKING CHILD PROCESS*******\n\n");

    forkVal = fork();

    printf("FORK VALUE : %d\n\n", forkVal);

    if(forkVal > 0)
    {
        // sleep(3);
        printf("********CONTROL IS WITH PARENT PROCESS********\n\n");
        printf("Parent Process ID : %d\n\n", getpid());
        printf("***********SLEEPING PARENT -> CONTROL WITH CHILD PROCESS**********\n\n");
        sleep(1);
        printf("********CONTROL IS WITH PARENT PROCESS 2nd Time********\n\n");
        while(1)
        {
            /*
                Infinite Loop That Keeps Parent Running
            */
        }
        printf("Parent Process ID : %d\n\n Completing and Exiting Parent \n\n", getpid());
        exit(1);
    }
    else
    {
        printf("********CONTROL IS WITH CHILD PROCESS********\n\n");
        printf("Child Process ID : %d\n\n", getpid());
        printf("Parent Process ID : %d\n\n", getppid());
        printf("CHILD PROCESS COMPLETED AND EXITING....\n\n");
        exit(0);                                                              
    }
    return 0;
}