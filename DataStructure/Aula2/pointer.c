#include <stdio.h>

void main()
{
    int x = 25;
    int* y = &x;
    // va no endereço y e coloque 30
    *y = 30;

    printf("O valor atual de X eh: %d\n", x);

}