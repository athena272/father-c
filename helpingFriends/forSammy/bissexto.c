#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int contaDigitos(int ano){
  char string_ano[100];
  sprintf(string_ano, "%d", ano);
  return strlen(string_ano);
}

int ehBissexto(int ano){
  return (ano % 4 == 0) && ((ano % 400 == 0) || (ano % 100 != 0));
}

void Mensagem(int ano){

    if(contaDigitos(ano) == 4){
      // printf("%d\n", ano);

      if(ehBissexto(ano)){

        if(ano == 2020){
          // printf("%d\n", ano);
          printf("O ano %d eh bissexto\n", ano);
        }else if (ano < 2020){
          // printf("%d\n", ano);
          printf("O ano %d foi bissexto\n", ano);
        }else{
          // printf("%d\n", ano);
          printf("O ano %d serah bissexto\n", ano);
        }
      }else{
        // printf("%d\n", ano);
        printf("O ano %d NAO eh bissexto\n", ano);
      }
    }else{
      printf("Ano invalido\n");
    }

}

int main() {
  //Receber datas
  char str[100];
  scanf("%[^\n]s",str);
  
  //Fazer a divisao dela usando strtoke
  char delim[] = " ";

	char *finalString = strtok(str, delim);

	while(finalString != NULL)
	{
      int convertAno = atoi(finalString);
      Mensagem(convertAno);
		  finalString = strtok(NULL, delim);
	}

  return 0;
}