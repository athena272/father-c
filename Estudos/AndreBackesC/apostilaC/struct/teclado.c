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
  struct cadastro C;
  
  printf("Informe o nome da pessoa: ");
  fgets(C.nome, sizeof(C.nome), stdin);

  printf("Informe o nome da rua: ");
  fgets(C.rua, sizeof(C.rua), stdin);

  printf("Informe a idade da pessoa: ");
  scanf("%d", &C.idade);

  printf("Informe o numero da rua: ");
  scanf("%d", &C.numero);

  printf("#==##==##==##==##==##==##==##==##==#\n");
  printf("Nome: %s", C.nome);
  printf("Idade: %d\n", C.idade);
  printf("Rua: %s", C.rua);
  printf("Numero da rua: %d\n", C.numero);
}