#include <stdio.h>

void main()
{
  printf("************************************\n");
  printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
  printf("************************************\n");

  int numeroSecreto = 42;
  int chute;
  printf("Qual eh o seu chute?: ");
  scanf("%d", &chute);
  printf("Seu chute foi %d\n", chute);
}
