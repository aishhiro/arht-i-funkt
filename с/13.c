#include <stdio.h>
#include <ctype.h>

int ivalid(char str_num[], int sys_num)
{
    char *p = str_num;
    int value;
    while (*p)
    {
        if (isdigit(*p)){value = *p - '0';}
        else if (isalpha(*p)) {value = toupper(*p) - 'A' + 10;}
        else {return 0;}
        if (value >= sys_num){return 0;}
        p++;
    }
    return 1;
}


void converter(char str_num[], int sys_num, int *result) 
{
    char *p = str_num;
    while (*p) 
    {
        *result = *result * sys_num + (isalpha(*p) ? *p - 'A' + 10 : *p - '0');
        p++;
    }
}

int main()
{
    char str_num[BUFSIZ];
    int sys_num, result = 0;
    printf("основание системы счиасления(2-36)\n");
    scanf("%s", str_num);
    printf("число\n");
    scanf("%d", &sys_num);    
    
    if (!ivalid(str_num, sys_num))
    {
        printf("ошибка '%s' несущесвует %d.\n", str_num, sys_num);
        return 1;
    }

    converter(str_num, sys_num, &result);
    printf("десятичное значение %d \n", result);
    return 0;
} 
