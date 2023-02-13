#include <string.h>
#include <stdio.h>


int contaDigitos(int ano){
  char string_ano[100];
  sprintf(string_ano, "%d", ano);
  return strlen(string_ano);
}

int ehBissexto(int ano){
  return (ano % 4 == 0) && ((ano % 400 == 0) || (ano % 100 != 0));
}

void Mensagem(int ano, char *saida){

    if(contaDigitos(ano) == 4){

      if(ehBissexto(ano)){

        if(ano == 2020){
          sprintf(saida, "O ano %d eh bissexto", ano);
        }else if (ano < 2020){
          sprintf(saida, "O ano %d foi bissexto", ano);
        }else{
          sprintf(saida,"O ano %d serah bissexto", ano);
        }
      }else{
        sprintf(saida,"O ano %d NAO eh bissexto", ano);
      }
    }else{
      sprintf(saida,"Ano invalido");
    }

}

int main() {

  int tamanho_entrada = 0;
  int entrada[128] = { 0 };
  while(scanf("%d", &entrada[tamanho_entrada])==1) tamanho_entrada++;
  
  for(int i = 0; i < tamanho_entrada; ++i){

    char mensagem[40];

    Mensagem(entrada[i], mensagem);
    printf("%s\n", mensagem);

  }

  return 0;
}