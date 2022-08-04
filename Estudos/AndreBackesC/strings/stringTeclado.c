#include <stdio.h>
#include <string.h>

void main()
{
  char str1[20];
  setbuf(stdin, NULL);
  printf("Digite uma palavra: ");
  fgets(str1, sizeof(str1), stdin);

  printf("%s", str1);
}
