#include <stdio.h>
#include <string.h>

void main()
{
  char str1[100], str2[100];
  printf("Digite um texto: ");
  fgets(str1, 100, stdin);
  strcpy(str2, str1);
  fputs(str2, stdout);
}