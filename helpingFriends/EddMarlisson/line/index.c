#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct
{
    ITEM itens[MAX];
    int inicio;
    int fim;
    int tamanho;
} FILA;

// Inicializa a fila deixando-a pronta para ser utilizada.
void inicializar(FILA *f)
{
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Retornar o tamanho da fila
int tamanho(FILA *f)
{
    return f->tamanho;
}

// Estara cheia quando tamanho = MAX
bool cheia(FILA *f)
{
    return tamanho(f) == MAX;
}

// Retorna true se a filha esta vazia (Tamanho = 0)
bool vazia(FILA *f)
{
    return tamanho(f) == 0;
}

/*
  Objetivo: Insere um item no final da fila.
*/
bool inserir(ITEM item, FILA *f)
{
    // Verificar se a lista esta cheia
    if (cheia(f))
    {
        return false;
    }

    // Atualizar o fim da fila e insere o item no final

    //     atualiza o índice do fim da fila. A expressão (f->fim + 1) % MAX incrementa o índice atual em 1 e, em seguida, calcula o resto da divisão por MAX. Isso garante que, quando fim atingir o valor MAX-1, ele voltará ao início da fila, ou seja, à posição 0.

    // Por exemplo, se a fila tem MAX elementos e o índice do fim atual é MAX-1, então (MAX-1 + 1) % MAX resultará em 0, que é a posição do primeiro elemento da fila. Assim, a fila é considerada circular, onde o último elemento está conectado ao primeiro, permitindo que novos elementos sejam adicionados à fila sem deslocar todos os elementos existentes para a direita.

    f->fim = (f->fim + 1) % MAX;

    f->itens[f->fim] = item;

    // Aumenta o tamanho da fila
    f->tamanho++;

    return true;
}

/*
  Objetivo: Acessa a frente da Fila e atribui ao parâmetro item, sem afetar
            o estado da Fila. Retorna true quando algum item foi obtido.
*/
bool frente(ITEM *item, FILA *f)
{

    if (vazia(f))
    {
        return false;
    }

    // Atualiza o primeiro item com base no parâmetro
    *item = f->itens[f->inicio];

    return true;
}

/*
  Objetivo: Retira um Item do inicio da Fila (frente) e atribui
            ao parametro item.
            Retorna true quando algum item foi retornado.
*/
bool retirar(ITEM *item, FILA *f)
{

    if (vazia(f))
    {
        return false;
    }

    //     A variável f->inicio indica a posição do primeiro item na fila. Para retirar o item, é necessário atualizar essa posição para apontar para o próximo item na fila. Isso é feito somando 1 à posição atual de f->inicio e aplicando o operador % MAX para garantir que a posição fique dentro dos limites do vetor itens. Isso significa que, caso f->inicio seja igual a MAX-1 (última posição do vetor), a próxima posição será a posição 0.

    // Portanto, o trecho f->inicio = (f->inicio + 1) % MAX atualiza o início da fila para apontar para o próximo item, garantindo que a posição fique dentro dos limites do vetor itens.

    // Retiramos o topo da fila e aualizamos o inicio
    *item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;

    f->tamanho--;

    return true;
}

// Exibicao da fila
void exibir(FILA *f)
{
    int pos = f->inicio;

    for (int i = 0; i < tamanho(f); i++)
    {
        printf("(%d,%s)", f->itens[pos].chave, f->itens[pos].valor);
        pos = (pos + 1) % MAX;
    }
}

// Liberacao das variaveis dinamicas dos nos da lista, iniciando da cabeca
void destruir(FILA *f)
{
    f->inicio = 0; // ajusta o inicio da lista (vazia)
    f->fim = 0;    // ajusta o fim da lista (vazia)
    f->tamanho = 0;
}

//////////////////////////////////////////////////////////////

void lerItens(FILA *f)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        if (!inserir(item, f))
            printf("Nao inseriu na fila (%d,%s)\n", item.chave, item.valor);
    }
}

void retirarItens(FILA *f, int n)
{
    ITEM item;
    for (int i = 0; i < n; i++)
        if (retirar(&item, f))
            printf("Retirado (%d,%s)\n", item.chave, item.valor);
        else
            printf("Nao retirou\n");
}

void imprimir(FILA *f)
{
    printf("Tamanho = %d\n", tamanho(f));
    exibir(f);
    printf("\n");
}

/////////////////////////////////////////////////////

int main()
{

    FILA f;
    ITEM item;
    int n;
    inicializar(&f);

    // Obtem os itens iniciais e mostra
    lerItens(&f);
    imprimir(&f);

    // Le a quantidade de itens a serem retirados e retira da fila
    scanf("%d", &n);
    retirarItens(&f, n);
    imprimir(&f);

    // Mostra a frente da fila, se existir
    if (frente(&item, &f))
        printf("Frente (%d,%s)\n", item.chave, item.valor);
    else
        printf("Nao tem frente\n");

    // Obtem mais itens e imprime a situacao
    lerItens(&f);
    imprimir(&f);

    // Continua com a retirada de mais itens
    scanf("%d", &n);
    retirarItens(&f, n);
    imprimir(&f);

    destruir(&f);
    return 0;
}