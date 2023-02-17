#include <stdio.h>
#define alturaMaxima 225

typedef struct
{
    int altura; // em centimetros
    int peso;
} Pessoa;

void main()
{
    Pessoa pessoa;
    pessoa.peso = 80;
    pessoa.altura = 226;
    printf("A pessoa tem %dKg e %dcm\n", pessoa.peso, pessoa.altura);

    if (pessoa.altura > alturaMaxima)
    {
        printf("Altura maxima excedida\n");
    }
    else
    {
        printf("Altura ok\n");
    }
}
