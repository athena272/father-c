#include <stdio.h>
#include <malloc.h>

/*
    Malloc, memory allocation
    -recebe como parâmetro o número de butes que se deseja alocar
    -retorna o endereço inicial do bloco de bytes que foi alocado,
    porém esse retorno tem o tipo void* (ponteiro para void)

    -ha um opereador chamado sizeof que recebe como parâmetro um tipo
    (simples ou composto) e retorna a quantidade de bytes ocupada por
    esse tipo

*/

void main()
{
    int *y = (int *)malloc(sizeof(int));
    *y = 20;
    int z = sizeof(int);

    printf("*y = %d\nz = %d\ny = %d\n", *y, z, y);
}