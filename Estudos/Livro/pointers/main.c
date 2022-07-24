#include <stdio.h>

void main() {
  int c = 10;
  int* ponteiro;
  //ponteiro apontando para o mesmo endereço de c
  ponteiro = &c;

  // imprime o endereço da variável c
  printf("%d %d\n", &c, ponteiro);


  //imprime o conteúdo da variável c
  printf("%d %d\n", c, *ponteiro); 
} 