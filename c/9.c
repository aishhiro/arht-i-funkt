#include <stdio.h>
int reverse(char *str)
{
    char *first, *last, storage;
    first = str;
    last = str;

    while (*last != 0)
    {
        last++;
    }
    last--;

    while(first < last)
    {
        if(*first != *last)
        {
            return 0;
            break;
        }
        first++;
        last--;
    }
    return 1;
}

int main()
{
    char str[BUFSIZ];
    int is_palenrdome = 0;
    printf("строка на проверку палиндроме\n");
    scanf("%s", str);
    if (reverse(str) == 1)
    {
        printf("да\n");
    }
    else
    {
        printf("нет\n");
    }
    return 0;
}
