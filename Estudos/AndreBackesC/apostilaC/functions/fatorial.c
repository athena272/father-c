#include <stdio.h>

int fatorial (int num)
{
  int fat = 1;
  for (int i = 1; i <= num; i++)
  {
    fat = fat * i;
  }

  return fat;
}

void main()
{
  int num;
  
  printf("Digite um numero para calcular fatorial: ");
  scanf("%d", &num);

  int fat = fatorial(num);
  printf("O fatorial de %d eh %d\n", num, fat);
}