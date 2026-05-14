#include <stdio.h>
int powerf(int num, int power)
{
    int result = 1;
    while(power != 0)
    {
        if(power % 2 == 1)
        {
            result *= num;
        }
        num *= num;
        power /= 2;
    }
    return result;
}

int main()
{
    printf("введите числа\n");
    int num, power;
    if (scanf("%d%d", &num, &power) != 2)
    {
        printf("введено не число\n");
    }
    else
    {
        printf("число %d в %d степени = %d\n", num, power, powerf(num, power));
    }
    return 0;
}
