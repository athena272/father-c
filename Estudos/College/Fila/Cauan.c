#include <stdio.h>
#include <stdlib.h> //usado system
#include <ctype.h>  //usado toupper
#include <string.h> //usado strcmp

typedef char Str20[20];
int L[] = {1, 2, 3, 4, 5, 6, 7, 8};
struct Reg
{
  Str20 Taxista; // nome
  void *Prox;
};

typedef struct Reg TpReg;
Str20 T;

TpReg *InicioT, *FimT = NULL;
TpReg *AuxT;

TpReg *InicioC, *FimC = NULL;
TpReg *AuxC;

int Opcao;

void EmFilaT(Str20 S)
{
  AuxT = (TpReg *)malloc(sizeof(TpReg));
  strcpy(AuxT->Taxista, S);
  AuxT->Prox = NULL;
  if ((InicioT == NULL) && (FimT == NULL))
  {
    InicioT = AuxT;
    FimT = AuxT;
  }
  else
  {
    FimT->Prox = AuxT;
    FimT = AuxT;
  }
}

void EmFilcaC(Str20 S)
{
  AuxC = (TpReg *)malloc(sizeof(TpReg));
  strcpy(AuxC->Taxista, S);
  AuxC->Prox = NULL;
  if ((InicioC == NULL) && (FimC == NULL))
  {
    InicioC = AuxC;
    FimC = AuxC;
  }
  else
  {
    FimC->Prox = AuxC;
    FimC = AuxC;
  }
}

// Para incluir taxista.
void Incluir()
{
  char R;
  do
  {
    system("cls");
    printf("*** Chegada de Taxista ***\n\n");
    printf("Taxista: ");
    scanf("%[^\n]s", T);
    fflush(stdin);
    if (!((InicioC == NULL) && (FimC == NULL)))
    {
      printf("Tirando cliente da lista de espera\n\n");
      AuxC = InicioC;
      InicioC = InicioC->Prox;
      free(AuxC);
      if (InicioC == NULL)
        FimC = NULL;
    }
    else
    {
      printf("Adicionando taxista na fila...\n\n");
      EmFilaT(T);
      
    }

    // inclusao da taxista na fila

    printf("\nOutro taxista? S/N ");
    scanf("%c", &R);
    fflush(stdin);
    R = toupper(R);
  } while (R != 'N');
  return;
}

// Para atender chamada
void Remover(Str20 Titulo)
{
  char R;
  do
  {
    system("cls");
    printf("%s \n\n", Titulo);

    // remover da fila de taxistas
    if ((InicioT == NULL) && (FimT == NULL))
    {
      printf("Lista de Taxistas Vazia\n\n");
      int contador = 0;
      if (!((InicioC == NULL) && (FimC == NULL)))
      {
        AuxC = InicioC;

        while (AuxC != NULL)
        {
          AuxC = AuxC->Prox;
          contador ++;
        }
      }

      if (contador >= 4)
      {
        printf("A fila de cliente se encontra cheia no momento tente novamente mais tarde\n\n");
        R = 'N';
        system("pause");
      }
      else
      {
        printf("Digite seu nome para entrar na fila:\n\n");
        printf("Quantidade de clientes na fila: %d \n\n", contador);
        printf("Cliente: ");
        scanf("%[^\n]s", T);
        fflush(stdin);
        EmFilcaC(T);

        printf("Deseja chamar outro cliente? S/N ");
        scanf("%c", &R);
        fflush(stdin);
        R = toupper(R);
      }
    }
    else
    {
      printf("Taxista: ");
      printf("%s \n\n", InicioT->Taxista);
      AuxT = InicioT;
      InicioT = InicioT->Prox;
      free(AuxT);
      if (InicioT == NULL)
        FimT = NULL;

      printf("Efetuar novo atendimento? S/N ");
      scanf("%c", &R);
      fflush(stdin);
      R = toupper(R);
    }
  } while (R != 'N');
  return;
}

void LTodos(int K[])
{
  system("cls");
  printf("***Fila de Taxistas***\n\n ");
  if (InicioT != NULL)
  {
    AuxT = InicioT;
    do
    {
      printf("%s\n", AuxT->Taxista);
      AuxT = AuxT->Prox;
    } while (AuxT != NULL);
  }
  else
    printf("\nLista de afazeres vazia. Pressione <ENTER>\n");
  system("pause");
}

int main()
{
  do
  {
    system("cls");
    printf("\n\n> > > Charme Taxis < < < \n\n");
    printf("Taxistas disponiveis: ");
    if (InicioT != NULL)
    {
      AuxT = InicioT;
      do
      {
        printf("%s ", AuxT->Taxista);
        AuxT = AuxT->Prox;
      } while (AuxT != NULL);
    }
    printf("\n\nQue deseja fazer? \n\n");
    printf("1 - Chegada de Taxista \n");
    printf("2 - Chamada de Cliente \n"); // taxista é removido da fila
    printf("3 - Listar Todos \n");
    printf("4 - Sair \n\n");
    printf("Opcao: ");
    scanf("%d", &Opcao);
    fflush(stdin);
    switch (Opcao)
    {
    case 1:
      Incluir();
      break;
    case 2:
      Remover("*** Atender Chamada ***");
      break;
    case 3:
      LTodos(L);
      break;
    }
  } while (Opcao != 4);
  return 0;
}