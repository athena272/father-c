#include <stdio.h>

struct vetor
{
  int v[5];
};

struct vetor retornaArray()
{
  struct vetor v = {1, 2, 3, 4, 5};
  return v;
}

void main()
{
  struct vetor vet = retornaArray();
  for (int i = 0; i < 5; i++)
  {
    printf("Valores: %d\n", vet.v[i]);
  }
}