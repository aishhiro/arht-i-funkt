#include <stdio.h>

int mstrcmp(char const *str1, char const *str2) 
{
    for(int i = 0; str1[i] != 0 || str2[i] != 0; i++)
     {
        if(str1[i] > str2[i])
        {
            return 1;
            break;
        }
        else if(str1[i] < str2[i])
        {
            return -1;
            break;
        }
     }   
     return 0;
}

int main()
{
    char str1[BUFSIZ], str2[BUFSIZ];
    printf("введите 2 строки для проверки на идентичность\n");
    printf("первая\n");
    scanf("%s", str1);
    printf("вторая\n");
    scanf("%s", str2);

    if (mstrcmp(str1, str2) == 0)
    {
        printf("идентичны\n");
    }
    else
    {
        printf("неидентичны.\n");
    }
    return 0;
}
