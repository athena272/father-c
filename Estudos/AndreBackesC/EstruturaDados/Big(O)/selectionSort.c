#include <stdio.h>
#include <string.h>

void selectionSort(int *Vector, int size)
{
  int me, troca;
  for (int i = 0; i < size - 1; i++)
  {
    me = i;
    for (int j = i + 1; j < size; j++)
    {
      if (Vector[j] < Vector[me])
      {
        me = j;
      }
    }
    if (me != i)
    {
      troca = Vector[i];
      Vector[i] = Vector[me];
      Vector[me] = troca;
    }
  }
}

void main()
{
  int vetor[] = {1, 7, 8,-4, 4, -21, 3, 10, 42};
  selectionSort(vetor, 6);
  int size = sizeof(vetor)/sizeof(vetor[0]);

  for (int i = 0; i < size; i++)
  {
    printf("%d ",vetor[i]);
  }
  printf("\n");
}