#include <stdio.h>
#include <math.h>

void imprimeLog(float num)
{
  if(num <= 0) return;
  printf("Log = %f\n", log(num));
}

void main()
{
  float num;
  printf("Digite um valor: ");
  scanf("%f", &num);

  imprimeLog(num);
}