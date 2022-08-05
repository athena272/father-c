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
  //Atribui a string "Carlos" para o campo nome
  strcpy(C.nome, "Carlos"); 

  //Atribui o valor 18 para o campo idade
  C.idade = 18;

  //Atribui a string "Avenida Brasil" para o campo rua
  strcpy(C.rua, "Avenida Brasil");

  //Atribui o valor 1082 para o campo numero
  C.numero = 1082;

  
}