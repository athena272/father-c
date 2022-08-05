#include <stdio.h>
#include <string.h>

void main()
{
  char str1[15] = "bom ";
  char str2[15] = "dia";
  // strcat(char *destino, char *origem)
  strcat(str1, str2);
  printf("%s", str1);
}