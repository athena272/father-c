#include <stdio.h>

void imprime(int *vetor, int qtdElements)
{
  for(int i = 0; i < qtdElements; i++)
  {
    printf("%d \n", vetor[i]);
  }
}

void main()
{
  int vet[5] = {1, 2, 3, 4, 5};
  imprime(vet, 5);
}