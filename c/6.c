 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h> 

 int main() 
{
    int numbers[BUFSIZ], i;
    srand(time(NULL)); 
    for(i = 0; i < BUFSIZ; i++)
    {
        numbers[i] = rand() % 20001 - 10000; 
    }


    int num_max = numbers[0], num_min = numbers[0], index_max = 0, index_min = 0;


    for(i = 0; i < BUFSIZ; i++)
    {
        if(numbers[i] > num_max)
        {
            num_max = numbers[i];
            index_max = i;
        }
        if(numbers[i] < num_min)
        {
            num_min = numbers[i];
            index_min = i;
        }
    }
    printf("макс %d - %d\n", num_max, index_max);
    printf("мин %d - %d\n", num_min, index_min);
    return 0;
}
