#include <stdio.h>
void converter(int num, int sys_num, char *result) 
{
    char *p = result + BUFSIZ - 1; 
    *p-- = 0; 
    while (num > 0)
    {
        int r = num % sys_num; 
        *p-- = (r > 9) ? (r - 10 + 'A') : (r + '0');
        num /= sys_num;
    }
    p++;
    for (char *s = result; *p; p++, s++)
    {
        *s = *p;
    }
}

int main()
{
    int num, sys_num;
    char new_num[BUFSIZ];
    printf("введите число\n");
    scanf("%d", &num);
    printf("систему нумерации 2-36\n");
    scanf("%d", &sys_num);    
    
    converter(num, sys_num, new_num);
    printf("число %d в системе счисления %d  %s\n", num, sys_num, new_num);

    return 0;
} 
