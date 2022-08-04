#include <stdio.h>
#include <stdlib.h> //usado malloc
#include <string.h> //usado strcpy 
#include <ctype.h> //usado toupper

int main(){

 struct tipo{
	  char Palavra[20];
	  void *Prox; 
  };
  typedef struct tipo TIPO;
  
  TIPO *Inicio, *Fim, *Auxiliar, *Atual, *Anterior;
  char P[20],R='S';

  Inicio=NULL;
  while (R=='S'){
    system("cls");
    printf("\n > > > ORDENA PALAVRAS < < < \n");
    printf("\n Entrada atual:");
    Auxiliar=Inicio; 
    while (Auxiliar!=NULL){
      printf(" %s ",Auxiliar->Palavra);
      Auxiliar= Auxiliar->Prox;} 
    printf("\n\n Qual palavra deseja inserir? ");
    scanf(" %s",P);    
    Auxiliar=(TIPO *) malloc(sizeof(TIPO));
    strcpy(Auxiliar->Palavra,P);
    Auxiliar->Prox = NULL;
    if (Inicio == NULL){ //primeiro elemento da estrutura
      Auxiliar->Prox=NULL;
      Inicio = Auxiliar;
      Fim = Auxiliar;}
    else
      if (strcmp(P,Inicio->Palavra)<=0){ //insere no inicio
		Auxiliar->Prox = Inicio;
		Inicio = Auxiliar;}
	  else
	    if (strcmp(P,Fim->Palavra)>=0){ //insere no fim
		  Fim->Prox = Auxiliar;
		  Fim = Auxiliar;}
		else{ //insere no meio - antes do primeiro maior
		  Atual = Inicio->Prox;
		  Anterior = Inicio;
		  while (strcmp(Atual->Palavra,Auxiliar->Palavra)<0){
		    Anterior = Atual;
		    Atual = Atual->Prox;}
		  Anterior->Prox = Auxiliar;
		  Auxiliar->Prox = Atual;}
    system("cls");
    printf("\n > > > ORDENA PALAVRAS < < < \n");
    printf("\n Palavras ordenadas: "); 
    Auxiliar=Inicio; 
    while (Auxiliar!=NULL){
      printf(" %s ",Auxiliar->Palavra);
      Auxiliar= Auxiliar->Prox; }
    printf("\n\n Digite S se deseja continuar: ");
    scanf(" %c",&R);
    R = toupper(R); }
   return 0;
}
