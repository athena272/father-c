#include <stdio.h>
#include <stdlib.h>

void main()
{
  int lista[5] = {3, 51, 18, 2, 45};
  int soma = 0;
  for (int i = 0; i < 5; i++)
  {
    soma += lista[i];
  }
  printf("%d\n", soma);
  system("pause");
}