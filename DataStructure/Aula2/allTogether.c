#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 255

typedef struct
{
    int peso;
    int altura; // em centimetros
} Pessoa;

void main()
{
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    pessoa->peso = 80;
    pessoa->altura = 185;

    printf("%d\n", &pessoa);
    printf("A pessoa tem %dKg e %dcm\n", pessoa->peso, pessoa->altura);
    // printf("A pessoa tem %dKg e %dcm\n", pessoa.peso, pessoa.altura);
}