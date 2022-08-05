#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cadastro
{
  char nome[50];
  int idade;
  char rua[50];
  int numero;
};

struct aluno
{
  char nome[50];
  int matricula;
  float nota1, nota2, nota3;
};

void main()
{
  struct cadastro c[4];

  for (int i = 0; i < 4; i++)
  {
    printf("\nInforme o nome da pessoa: ");
    fgets(c[i].nome, sizeof(c[i].nome), stdin);

    printf("Informe o nome da rua: ");
    fgets(c[i].rua, sizeof(c[i].rua), stdin);

    printf("Informe a idade da pessoa: ");
    scanf(" %d", &c[i].idade);

    printf("Informe o numero da rua: ");
    scanf(" %d", &c[i].numero);

    printf("#==##==##==##==##= Cadastro numero %d =##==##==##==##==#\n", i + 1);
    printf("Nome: %s", c[i].nome);
    printf("Idade: %d\n", c[i].idade);
    printf("Rua: %s", c[i].rua);
    printf("Numero da rua: %d\n", c[i].numero);
  }
}