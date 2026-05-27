#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

int fib(int n) 
{
    if(n < 0){ return -1;}
    if (n == 0) 
    {
        return 0;
    } 
    else if (n == 1) 
    {
        return 1;
    } 
    else 
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int fib_seq(int *DA, int n)
{
    if(DA == NULL){ return -1;}
    if(n < 0){ return -2; }
    int i;
    int fib_result;
    for(i = 0; i <= n; i++)
        {
            fib_result = fib(i);
            DA[i] = fib_result;
        }321
    return 0;
}
int main()
{
    int *dyn_array;
    int n;
    int i;
    printf("how much numbers need\n");
    while(scanf("%d", &n) != 1)
    {
       printf("Error! :[ \ntype numbers again\n");
        while(getchar() != '\n');
    }
    if((dyn_array = (int *)malloc(sizeof(int) * (size_t)n)) == NULL)
    {
        printf("memmory error\n");
        return 1;
    }
    switch (fib_seq(dyn_array, n))
    {
    case -1:
        printf("error\n");
        return -2;
        break;
    case -2:
        printf("invalid argument\n");
        return -3;
        break;
    case 0:
        for(i = 0; i < n; ++i)
        {
            printf("%d\n", dyn_array[i]);
        }

        free(dyn_array);
        break;
    }

    return 0;
}
