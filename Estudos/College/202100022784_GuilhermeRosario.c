#include <stdio.h>
#include <stdlib.h> //usado malloc
#include <string.h> //usado strcpy
#include <ctype.h>  //usado toupper

int main()
{

  struct tipo
  {
    char Palavra[20];
    void *Prox;
  };
  typedef struct tipo TIPO;

  TIPO *Inicio, *Fim, *Auxiliar, *Atual, *Anterior, *auxilairDisordered, *inicioDisordered, *fimDisordered;
  char P[20], R = 'S';

  Inicio = NULL;
  inicioDisordered = NULL;
  while (R == 'S')
  {
    system("cls");
    printf("\n > > > ORDENA PALAVRAS < < < \n");
    printf("\n Entrada atual:");

    //Loop ordenado
    Auxiliar = Inicio;
    while (Auxiliar != NULL)
    {
      printf(" %s ", Auxiliar->Palavra);
      Auxiliar = Auxiliar->Prox;
    }
    
    printf("\n\n Qual palavra deseja inserir? ");
    scanf(" %s", P);

    Auxiliar = (TIPO *)malloc(sizeof(TIPO));
    auxilairDisordered = (TIPO *)malloc(sizeof(TIPO));

    strcpy(Auxiliar->Palavra, P);
    Auxiliar->Prox = NULL;

    strcpy(auxilairDisordered->Palavra, P);
    auxilairDisordered->Prox = NULL;

    if (Inicio == NULL)
    { // primeiro elemento da estrutura
      //condicao com ordem
      Auxiliar->Prox = NULL;
      Inicio = Auxiliar;
      Fim = Auxiliar;

      //condicao sem ordem
      auxilairDisordered->Prox = NULL;
      inicioDisordered = auxilairDisordered;
      fimDisordered = auxilairDisordered;
    }
    else if (strcmp(P, Inicio->Palavra) <= 0)
    { // insere no inicio
      Auxiliar->Prox = Inicio;
      Inicio = Auxiliar;

      fimDisordered->Prox = auxilairDisordered;
      fimDisordered = auxilairDisordered;
    }
    else if (strcmp(P, Fim->Palavra) >= 0)
    { // insere no fim
      Fim->Prox = Auxiliar;
      Fim = Auxiliar;

      fimDisordered->Prox = auxilairDisordered;
      fimDisordered = auxilairDisordered;
    }
    else
    { // insere no meio - antes do primeiro maior
      Atual = Inicio->Prox;
      Anterior = Inicio;
      while (strcmp(Atual->Palavra, Auxiliar->Palavra) < 0)
      {
        Anterior = Atual;
        Atual = Atual->Prox;
      }
      Anterior->Prox = Auxiliar;
      Auxiliar->Prox = Atual;

      fimDisordered->Prox = auxilairDisordered;
      fimDisordered = auxilairDisordered;
    }
    system("cls");
    printf("\n > > > ORDENA PALAVRAS < < < \n");
    printf("\n Palavras ordenadas: ");
    Auxiliar = Inicio;
    auxilairDisordered = inicioDisordered;
    
    while (Auxiliar != NULL)
    {
      printf(" %s ", Auxiliar->Palavra);
      Auxiliar = Auxiliar->Prox;
    }

    printf("\n Palavras desordenadas: ");
    while (auxilairDisordered != NULL)
    {
      printf(" %s ", auxilairDisordered->Palavra);
      auxilairDisordered = auxilairDisordered->Prox;
    }

    printf("\n\n Digite S se deseja continuar: ");
    scanf(" %c", &R);
    R = toupper(R);
  }
  return 0;
}
