#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int CN, UN;
    int step = 0;

    srand((unsigned int)time(NULL));
    CN = rand() % 1000 + 1;
    
    printf("hidden number ;)!\n");
    printf("use a dichotomous number search.\n");
    while (1)
    {
        printf(" enter a number:\n");
        while(scanf("%d", &UN) != 1)
        {
            printf("type number again \n");
            while(getchar() != '\n');
        }
        if(UN > CN)
        {
            printf("GT+\n"); // +
            ++step;
        }
        else if(UN < CN)
        {
            printf("LT-\n"); // -
            ++step;
        }
        else if(UN == CN)
        {
            printf("EQ=\n"); // =
            ++step;
            break;
        }
    }

    printf("guessed a number\n");
    printf(" done %d to search hidden number \n", step);
    return 0;
}
