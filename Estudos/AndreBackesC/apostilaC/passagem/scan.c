#include <stdio.h>

void main()
{
  int x = 5;
  printf("Antes da funcao scanf: x = %d\n", x);
  printf("Digite um numero: ");
  scanf("%d", &x);
  printf("Depois da funcao scanf: x = %d\n", x);
}