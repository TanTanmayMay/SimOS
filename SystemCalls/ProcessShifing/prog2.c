// @author : Tanmay Kokate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define ll int 

void bssearch(ll inp[], ll n, ll key)
{
    ll l = 0, r = n;
    while(r > (l + 1))
    {
        ll m = (l + r) >> 1;
        if(inp[m] > key)
        {
            r = m;
        }
        else if(inp[m] < key)
        {
            l = m;
        }
        else
        {
            printf(" : Found Key in the Array : \n");
            return;
        }
    }
    printf(" : Key Not Present : \n");
    return;
}

int main(ll argc, char *argv[])
{
    ll inp[30], n, i;

    for (i = 0; i < argc; i++)
    {
        inp[i] = atoi(argv[i]);
    }

    printf("Reverse Printing in 2nd Program\n");
    for (i = (argc - 1); i >= 0; i--)
    {
        printf("%d ", inp[i]);
    }
    printf("\n");

    // while(1)
    // {
    //     ll choice;
    //     printf("Do you want to search an Element ? (1/0) : ");
    //     scanf("%d", &choice);
    //     if (!choice)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         ll key;
    //         printf("Enter Key to be searched : ");
    //         scanf("%d", key);
    //         bssearch(inp, argc, key);
    //     }
    // }

    return 0;
}