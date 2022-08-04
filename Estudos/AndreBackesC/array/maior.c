#include <stdlib.h>
#include <stdio.h>

void main()
{
  int lista[6] = {3, 51, 18, 2, 45, 147};
  int maior = lista[0];
  for (int i = 1; i < 6; i++)
  {
    if(lista[i] > maior)
    {
      maior = lista[i];
    }
  }
  printf("O maior numero eh %d\n", maior);
}