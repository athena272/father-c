#include <stdio.h>

int main() {

    printf("Imprimindo a soma dos números inteiros de 1 até 10: ");
    
    int num = 1; //essa variavel vai comecar com 1 e terminar com 10
    int somaInt = 0; //essa variavel vai guardando a soma

    while (num <= 10) {

        somaInt = somaInt  + num ;

        num++;
    }

    printf("%d\n", somaInt);

    return 0;
}