#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct Livro{
	char Nome[20];
	float Preco;
	int QtdEstoque;
};
  
typedef struct livro LIVRO;

LIVRO Biblioteca;  
FILE *ArqLivro;