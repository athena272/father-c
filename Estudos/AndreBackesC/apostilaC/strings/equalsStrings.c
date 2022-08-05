#include <stdio.h>
#include <string.h>

void main()
{
  char str1[100], str2[100];
  printf("Informe um palavra: ");
  fgets(str1, 100, stdin);
  printf("Informe outra palavra: ");
  fgets(str2, 100, stdin);

  if(strcmp(str1, str2) == 0)
  {
    printf("Strings iguais\n");
  }
  else
  {
    printf("Strings diferentes\n");
  }
}