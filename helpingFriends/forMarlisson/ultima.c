#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{

    // Primeiro pais input
    char pais1[50];
    scanf("%s", pais1);
    for (int i = 0; pais1[i]; i++) {
        pais1[i] = tolower(pais1[i]);
    }

    // Input dos primeiros jogos
    int pontost1[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &pontost1[i]);
    }

    //Segundo pais input
    char pais2[50];
    scanf("%s", pais2);
    for (int i = 0; pais2[i]; i++) {
        pais2[i] = tolower(pais2[i]);
    }

    // Input dos segundos jogos
    int pontost2[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &pontost2[i]);
    }

    // Loop final
    char saidaFinal[50] = "EMPATE";
    for (int i = 0; i < 3; i++)
    {
        if (pontost1[i] > pontost2[i])
        {
            //Substitui a string final pelo nome do país
            strcpy(saidaFinal, pais1);
            break;
        }
        else if (pontost2[i] > pontost1[i])
        {
            //Substitui a string final pelo nome do país
            strcpy(saidaFinal, pais2);
            break;
        }
    }

    printf("%s\n", saidaFinal);
}