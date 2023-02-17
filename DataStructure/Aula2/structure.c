#include <stdio.h>

typedef struct
{
    int altura; // em centimetros
    int peso;
} Pessoa;

void main()
{
    Pessoa pessoa;
    pessoa.peso = 80;
    pessoa.altura = 180;
    printf("A pessoa tem %dKg e %dcm\n", pessoa.peso, pessoa.altura);
}