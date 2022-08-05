#include <stdio.h>

int menu()
{
  
  int choise;
  do
  {
    printf("[1] Trancar \n");
    printf("[2] Desistir \n");
    printf("[3] Suicidio \n");
    printf("Escolha uma opcao: ");
   
    scanf("%d", &choise);
  } while (choise < 1 || choise > 3);
  
  return choise;
}

void main()
{
  int escolha = menu();
  printf("Voce escolheu a opcao %d\n", escolha); 
}