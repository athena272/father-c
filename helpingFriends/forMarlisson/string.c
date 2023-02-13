#include <stdio.h>

int main()
{
    int qntd;
    int menor;
    scanf("%i", &qntd);

    // Add numeros na lista
    int numero[50];
    for (int i = 0; i < qntd; i++)
    {
        scanf("%d", &numero[i]);
    }

    // Encontrar o menor numero
    int menorNumero = numero[0];
    int menorPos = 0;
    for (int i = 1; i < qntd; i++)
    {
        if (numero[i] < menorNumero)
        {
            menorNumero = numero[i];
            menorPos = i;
        }
    }

    printf("Menor valor: %d", menorNumero);
    printf("Posicao: ", menorPos); 
}
