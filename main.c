#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //char str[30];
    char *str= (char*)malloc(sizeof(char) * 100);
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]) != 0)
        {
            if (str[i] < 'a')
            {
                str[i] = str[i] + 32;
            }
        }
        else
        {
            while (isalpha(str[i]) == 0)
            {
                i ++;
            }
        }
        printf("%c", str[i]);
    }

    char *pInizio = &str[0];
    char *pFine = &str[sizeof(str)-1];

    for (int i  = 0; pInizio < pFine; i++)
    {
        if (pInizio[i] != pFine[sizeof(str)-1-i])
        {
            printf("Non palindromo");
            free(str);
            str = NULL;
            return 0;
        }
        pInizio++;
        pFine--;
    }

    printf("Palindromo");
    free(str);
    str = NULL;
    return 0;
}
