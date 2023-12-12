// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define ll int 

void bsort(ll inp[], ll n)
{
    ll i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if(inp[i] > inp[j])
            {
                inp[i] ^= inp[j];
                inp[j] ^= inp[i];
                inp[i] ^= inp[j];
            }
        }
    }
}

int main(ll argc, char *argv[])
{
    ll inp[30], n, i;
    char str[30], *args[30];

    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("\n");
    printf(" : Enter the elements : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &inp[i]);
    }

    printf(" : Now Sorting the given input : \n");
    bsort(inp, n);

    printf(" : Sorting Complete -> Following Result : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", inp[i]);
    }
    printf("\n");

    printf(" : Converting Integer numbers to String and then put them into Arg List : \n");
    for (i = 0; i < n; i++)
    {
        sprintf(str, "%d", inp[i]);
        args[i] = malloc(sizeof(str));
        strcpy(args[i], str);
    }
    args[i] = NULL;
    printf("\nConversion Completed \n Now continuing 2nd Program\n");
    execv("./prog2Exe", args);

    printf("Back to Program 1\n");

    return 0;
}