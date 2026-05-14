#include <stdio.h>
#include <math.h>
int main() {
    printf("введиче число");
    int num, i, iprime = 1; 
    if (scanf("%d", &num) != 1 || num <= 0) 
    {
        printf("ошибка. вы ввели не число или число <0\n");
    }
        else
    {
        if(num == 1)
        {
            printf("\n");
        }
        else
        {
            for(i = 2; i <= (int)sqrt(num); i++) //sqrt корень к целому
           {
                if(num % i == 0)
                {
                    iprime = 0;
                    break;
                }

            }
            if (iprime == 0)               
            {
                printf("%d составное\n", num);
            }
            else
            {
                printf("%d простое\n", num);
            }
        }
    }    
    return 0;  
}
