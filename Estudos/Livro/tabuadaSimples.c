#include <stdio.h>
 
void menuBonito(int m) {
    printf("Tabuada do %d\n\n", m);
}

int numeroTabu() {
    int multiplicador;
 
    printf("Informe um número para fazermos sua tabuada: ");
    scanf("%d", &multiplicador );

    return multiplicador;
}
 
int main() {
    
    int numTabu = numeroTabu();

    menuBonito(numTabu);
 
    for(int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numTabu, i, numTabu * i);
    }
}