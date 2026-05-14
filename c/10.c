#include <stdio.h>
#include <string.h>

void mstrcat(char *str1, char const *str2) 
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main()
{
    char str1[BUFSIZ], str2[BUFSIZ];
    printf("две строки дляя комбинации \n");
    printf("ввести первую строку\n");
    scanf("%s", str1);
    printf("вторую строку \n");
    scanf("%s", str2);

    mstrcat(str1, str2);
    printf("результат %s\n", str1);
    return 0;
}
