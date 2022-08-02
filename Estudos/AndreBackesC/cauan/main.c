#include <stdio.h>
#include <stdlib.h>

void main() {

    int lista[5] = {3, 18, 2, 51, 45};
    int maior = lista[0];
    for(int i = 1; i < 5; i++){
        if (maior < lista[i])
            maior = lista[i];
    }
    printf("Maior = %d", maior);
    
}