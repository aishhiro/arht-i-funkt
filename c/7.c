#include <stdio.h>
#include <math.h>
#include <ctype.h> // новый заг фаил классификация символов
int prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0;
    return 1;
}

// проверка 
int vowel(char const letter)
{
    if (letter == 'a' || letter == 'A'){return 1;}
    if (letter == 'e' || letter == 'E'){return 1;}
    if (letter == 'i' || letter == 'I'){return 1;}
    if (letter == 'o' || letter == 'O'){return 1;}
    if (letter == 'u' || letter == 'U'){return 1;}
    return 0;
}

void transform(char string[])    
{
    for (int i = 0; string[i] != '\0'; i++) 
    {
        int posision = i + 1;
        char letter = string[i];
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            if (vowel(letter) && posision % 2 == 0) 
            {
                if (letter >= 'a' && letter <= 'z')
                    string[i] = toupper(letter); 
            }

            else if (!vowel(letter) && prime(posision)) 
            {
                if (letter >= 'A' && letter <= 'Z')
                    string[i] = tolower(letter);
            }
        }
    }
}

int main()
{
    char string[256];
    printf("введите строку для конвенвертации\n");
    fgets(string, 256, stdin);
    transform(string);
    printf("%s\n", string);
    return 0;
} 
