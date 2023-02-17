#include <stdio.h>

/*
    Em C há uma distinção bastante explícita entre um tipo(ou uma estrutura) e um endereçp
    int x; significa que x é uma variável do tipo inteiro
    int* y; significa que y é uma variável do tipo endereço para inteiro
*/

void main()
{
    int x = 25;
    int* y = &x;
    // va no endereço y e coloque 30
    *y = 30;

    printf("O valor atual de X eh: %d\n", x);

}

/*
    A variável x é inicializada com 25
    A variável y recebe o endereço onde está a variável x
    Coloca-se o valor 30 na posição de memória referenciada(apontada) pelo endereço armezanado em y
*/