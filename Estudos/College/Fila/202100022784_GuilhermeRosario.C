#include <stdio.h>
#include <stdlib.h> //usado system
#include <ctype.h>  //usado toupper
#include <string.h> //usado strcmp

typedef char Str20[20];
int L[] = {1, 2, 3, 4, 5, 6, 7, 8};
struct Reg
{
  Str20 Taxista; // nome
  void *Proximo;
};

typedef struct Reg TpReg;
Str20 T;

TpReg *InicioTaxista, *FimTaxista = NULL;
TpReg *AuxiliarTaxista;

TpReg *InicioCliente, *FimCliente = NULL;
TpReg *AuxiliarCliente;

int Opcao;

void EmFilarTaxistas(Str20 S)
{
  AuxiliarTaxista = (TpReg *)malloc(sizeof(TpReg));
  strcpy(AuxiliarTaxista->Taxista, S);
  AuxiliarTaxista->Proximo = NULL;
  if ((InicioTaxista == NULL) && (FimTaxista == NULL))
  {
    InicioTaxista = AuxiliarTaxista;
    FimTaxista = AuxiliarTaxista;
  }
  else
  {
    FimTaxista->Proximo = AuxiliarTaxista;
    FimTaxista = AuxiliarTaxista;
  }
}

void EmFilarCliente(Str20 S)
{
  AuxiliarCliente = (TpReg *)malloc(sizeof(TpReg));
  strcpy(AuxiliarCliente->Taxista, S);
  AuxiliarCliente->Proximo = NULL;
  if ((InicioCliente == NULL) && (FimCliente == NULL))
  {
    InicioCliente = AuxiliarCliente;
    FimCliente = AuxiliarCliente;
  }
  else
  {
    FimCliente->Proximo = AuxiliarCliente;
    FimCliente = AuxiliarCliente;
  }
}

// Para incluir taxista.
void Incluir()
{
  char Resposta;
  do
  {
    system("cls");
    printf("*** Chegada de Taxista ***\n\n");
    printf("Taxista: ");
    scanf("%[^\n]s", T);
    fflush(stdin);
    if (!((InicioCliente == NULL) && (FimCliente == NULL)))
    {
      printf("Tirando cliente da lista de espera\n\n");
      AuxiliarCliente = InicioCliente;
      InicioCliente = InicioCliente->Proximo;
      free(AuxiliarCliente);
      if (InicioCliente == NULL)
        FimCliente = NULL;
    }
    else
    {
      printf("Adicionando taxista na fila...\n\n");
      EmFilarTaxistas(T);
      
    }

    // inclusao da taxista na fila

    printf("\nOutro taxista? S/N ");
    scanf("%c", &Resposta);
    fflush(stdin);
    Resposta = toupper(Resposta);
  } while (Resposta != 'N');
  return;
}

// Para atender chamada
void Remover(Str20 Titulo)
{
  char Resposta;
  do
  {
    system("cls");
    printf("%s \n\n", Titulo);

    // remover da fila de taxistas
    if ((InicioTaxista == NULL) && (FimTaxista == NULL))
    {
      printf("Lista de Taxistas Vazia\n\n");
      int contador = 0;
      if (!((InicioCliente == NULL) && (FimCliente == NULL)))
      {
        AuxiliarCliente = InicioCliente;

        while (AuxiliarCliente != NULL)
        {
          AuxiliarCliente = AuxiliarCliente->Proximo;
          contador ++;
        }
      }

      if (contador >= 4)
      {
        printf("A fila de cliente se encontra cheia no momento tente novamente mais tarde\n\n");
        Resposta = 'N';
        system("pause");
      }
      else
      {
        printf("Digite seu nome para entrar na fila:\n\n");
        printf("Quantidade de clientes na fila: %d \n\n", contador);
        printf("Cliente: ");
        scanf("%[^\n]s", T);
        fflush(stdin);
        EmFilarCliente(T);

        printf("Deseja chamar outro cliente? S/N ");
        scanf("%c", &Resposta);
        fflush(stdin);
        Resposta = toupper(Resposta);
      }
    }
    else
    {
      printf("Taxista: ");
      printf("%s \n\n", InicioTaxista->Taxista);
      AuxiliarTaxista = InicioTaxista;
      InicioTaxista = InicioTaxista->Proximo;
      free(AuxiliarTaxista);
      if (InicioTaxista == NULL)
        FimTaxista = NULL;

      printf("Efetuar novo atendimento? S/N ");
      scanf("%c", &Resposta);
      fflush(stdin);
      Resposta = toupper(Resposta);
    }
  } while (Resposta != 'N');
  return;
}

void ListarTodos(int K[])
{
  system("cls");
  printf("***Fila de Taxistas***\n\n ");
  if (InicioTaxista != NULL)
  {
    AuxiliarTaxista = InicioTaxista;
    do
    {
      printf("%s\n", AuxiliarTaxista->Taxista);
      AuxiliarTaxista = AuxiliarTaxista->Proximo;
    } while (AuxiliarTaxista != NULL);
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
    if (InicioTaxista != NULL)
    {
      AuxiliarTaxista = InicioTaxista;
      do
      {
        printf("%s ", AuxiliarTaxista->Taxista);
        AuxiliarTaxista = AuxiliarTaxista->Proximo;
      } while (AuxiliarTaxista != NULL);
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
      ListarTodos(L);
      break;
    }
  } while (Opcao != 4);
  return 0;
}