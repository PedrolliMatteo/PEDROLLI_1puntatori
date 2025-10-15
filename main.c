#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define n 100

int main(void)
{
    char *str= (char*)malloc(sizeof(char) * n);
    fgets(str, n, stdin);

    char arrayPulito[n-1];
    char *pInizio = &str[0];
    int i = 0;

    for (i = 0; *pInizio != '\0'; )
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
    //printf("%s", arrayPulito);
    //fino a qui funziona e ritorna una stringa pulita

    pInizio = arrayPulito;
    char *pFine = &arrayPulito[i -1];

    for (i = 0; pInizio < pFine; i ++)
    {
        if (*pInizio != *pFine)
        {
            printf("Non palindromo");
            free(str);
            str = NULL;
            return 0;
        }
        pInizio ++;
        pFine --;
    }

    printf("Palindromo");
    free(str);
    str = NULL;
    return 0;
}