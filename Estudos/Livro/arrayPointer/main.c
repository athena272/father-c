#include <stdio.h>

void main()
{
  int numeros[3];

  // declarando um ponteiro que aponta para o
  // mesmo lugar que o array/ponteiro numeros
  int* ponteiro = numeros;
  numeros[0] = 10;
  numeros[1] = 20;
  numeros[2] = 30;
  
  for(int i = 0; i < 3; i++){
    printf("%d ", numeros[0]);
  
    // repare na soma que fazemos com o ponteiro
    printf("%d", *(ponteiro + i));

    printf("\n");
  }

  // printf("%d %d %d\n", &numeros[0], &numeros[1], &numeros[2] );

}