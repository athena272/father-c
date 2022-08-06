#include <stdio.h>

void somaUm(int num)
{
  num++;
  printf("Dentro da funcao %d\n", num);
}

void main()
{
  int x = 5;
  printf("Antes da funcao %d\n", x);
  somaUm(x);
  printf("Depois da funcao %d\n", x);
}