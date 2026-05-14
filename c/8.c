#include <stdio.h>
void reverse(char *str) 
{
    char *first, *last, temporal_storage;
    first = str;
    last = str;
    while (*last != 0)
    {
        last++;
    }
    last--;
    
    while(first < last)
    {
        temporal_storage = *first;
        *first = *last;
        *last = temporal_storage;
        first++;
        last--;
    }

}

int main()
{
    char str[BUFSIZ];
    printf("строка для реверса\n");
    scanf("%s", str);
    reverse(str);
    printf("реверснутая : %s\n", str);
    return 0;
}
