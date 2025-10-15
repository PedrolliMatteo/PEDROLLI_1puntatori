#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define n 100

int main(void)
{
    char *str= (char*)malloc(sizeof(char) * n);
    fgets(str, n, stdin);

    char arrayPulito[n];
    char *pInizio = &str[0];
    char *pFine = &str[n-1];

    for (int i = 0; *pInizio != '\0'; )
    {
        if (isalpha(*pInizio) != 0)
        {
            if (*pInizio < 'a')
            {
                *pInizio += 32;
            }
            arrayPulito[i] = *pInizio;
            i ++;

        }
        pInizio++;
    }
    printf("%s", arrayPulito);
    //fino a qui funziona e ritorna una stringa pulita



        for (int i  = 0; pInizio < pFine; i++)
        {
            if (pInizio[i] != pFine[n-1-i])
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