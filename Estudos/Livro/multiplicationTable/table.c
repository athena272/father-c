#include <stdio.h>

void opening(int mult) {
	printf("Tabuada do %d\n\n", mult);
}

void createTable(int mult) {
    for(int i = 1; i <= 10; i++) {
		printf("%d x %d = %d\n", i, mult,mult * i);
	}
}

void main() {
	
    int multiplicador;
    printf("Digite um numero para fazer a tabuada: ");
    scanf("%d", &multiplicador);

	opening(multiplicador);
    createTable(multiplicador);

	
}