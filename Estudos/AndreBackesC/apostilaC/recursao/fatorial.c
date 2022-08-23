#include <stdio.h>

int calcFatorial(int num) 
{
  if (num == 0)
  {
    return 1;
  }
  return num * calcFatorial(num - 1);

}

void main()
{
  int fatorial = calcFatorial(5);
  printf("%d\n", fatorial);
}