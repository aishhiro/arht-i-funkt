#include <stdio.h>
int main(){
int power(int whattt, int counter1 )
{ 
    int result = 1, counter2;
    for (int counter2 = 0; counter2 < counter1; counter2++) 
    {
        result *= whattt;
    }
    return result;
}
    printf("таблица степеней 1-10 1-6.");
    int num = 1, counter1, whattt;
    for(num; num <= 6; num++)
    {
        printf("\n число %d:\n", num);
        if(num == 1)
        {
            printf("1\n");
        }
        else
        {
            for(counter1 = 1; counter1 <= 10; counter1  ++)
            {
                printf("%d^%d = %d\n", num, counter1, power(num, counter1));
            }
        }
    }
    return 0;
}
