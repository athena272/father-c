#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef enum
{
    NoEsquerdo,
    NoDireito,
    NoPai,
    NoRaiz
} DIRECAO;

typedef struct
{
    TIPOCHAVE chave;
    //    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *esq;
    struct estrutura *dir;
    struct estrutura *pai;
} ARVORE_BINARIA;

// Inicializa a arvore binaria deixando-a pronta para ser utilizada.
void inicializar(ARVORE_BINARIA *arvore)
{
    arvore = NULL;
}

// Retorna true se a arvore esta vazia (igual a NULL)
bool vazia(ARVORE_BINARIA *arvore)
{
    return arvore == NULL;
}

// Cria um novo no usando o apontador arvore passado contendo o item,
// os apontadores para o pai e para os filhos contendo NULL
void criarNo(ITEM item, ARVORE_BINARIA **arvore)
{
    if (!vazia(*arvore))
    {
        printf("ERRO: O no deve estar vazio para ser criado.");
        exit(EXIT_FAILURE);
    }

    *arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
    (*arvore)->item = item;
    (*arvore)->pai = NULL;
    (*arvore)->esq = NULL;
    (*arvore)->dir = NULL;
}

// Testa se o No indicado por Direcao a partir de arv existe
bool existeNo(DIRECAO direcao, ARVORE_BINARIA *arvore)
{
    if (vazia(arvore))
        return false;

    if (direcao == NoRaiz)
        return true;

    if (direcao == NoPai)
        return !vazia(arvore->pai);

    if (direcao == NoEsquerdo)
        return !vazia(arvore->esq);

    if (direcao == NoDireito)
        return !vazia(arvore->dir);

    return false;
}

// Cria um filho no NO apontado por Arvore na direcao informada
bool adicionarFilho(ITEM item, DIRECAO direcao, ARVORE_BINARIA *arvore)
{
    if (vazia(arvore) || (direcao == NoPai) || (direcao == NoRaiz) || existeNo(direcao, arvore))
        return false; // Criacao ilegal de um filho

    if (direcao == NoEsquerdo)
    {
        criarNo(item, &(arvore->esq));
        arvore->esq->pai = arvore;
    }
    else
    {
        criarNo(item, &(arvore->dir));
        arvore->dir->pai = arvore;
    }
    return true;
}

// Desaloca da memoria toda a arvore
void disposeArvore(ARVORE_BINARIA *arvore)
{
    if (!vazia(arvore))
    {
        disposeArvore(arvore->esq);
        disposeArvore(arvore->dir);
        free(arvore);
    }
}

/*************************************************************/
// Caso precise de alguma funcao auxiliar, criar aqui

// Insere todas as chaves da árvore no vetor de chaves
// A função percorrerArvore recebe um nó de uma árvore binária de busca,
// um vetor de chaves e um inteiro que representa o número de elementos no vetor.
// Ela percorre a árvore de forma recursiva e, a cada nó, insere sua chave no vetor de chaves.
void percorrerArvore(ARVORE_BINARIA *no, TIPOCHAVE *chaves, int *n)
{
    if (no != NULL)
    {
        percorrerArvore(no->esq, chaves, n); // Chama a função recursivamente para o filho esquerdo
        chaves[(*n)++] = no->item.chave;     // Insere a chave do nó atual no vetor de chaves
        percorrerArvore(no->dir, chaves, n); // Chama a função recursivamente para o filho direito
    }
}

// Verifica se há algum valor duplicado no vetor de chaves
// A função verificarDuplicados recebe um vetor de chaves e o número de elementos no vetor.
// Ela verifica se há algum valor duplicado no vetor, comparando todos os elementos entre si.
bool verificarDuplicados(TIPOCHAVE *chaves, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (chaves[i] == chaves[j]) // Compara as chaves dos elementos i e j
            {
                return true; // Retorna verdadeiro se houver valores duplicados
            }
        }
    }
    return false; // Retorna falso se não houver valores duplicados
}

/*************************************************************/

/*
| Objetivos: Percorre a arvore e analisa, para cada NO da arvore apontada
|            pelo parametro arvore, se ha algum outro NO com o mesmo valor
|            de chave. Se houver, retorna true. Caso contrario, retorna false.
*/

// A função haDuplicados recebe um nó de uma árvore binária de busca e a raiz da árvore.
// Ela cria um vetor de chaves, chama a função percorrerArvore para preencher o vetor
// e, em seguida, chama a função verificarDuplicados para verificar se há valores duplicados.
bool haDuplicados(ARVORE_BINARIA *arvore, ARVORE_BINARIA *raiz)
{
    TIPOCHAVE chaves[100];               // Cria um vetor de chaves com tamanho máximo de 100
    int n = 0;                           // Inicializa o número de elementos no vetor como 0
    percorrerArvore(arvore, chaves, &n); // Preenche o vetor de chaves com as chaves da árvore

    return verificarDuplicados(chaves, n); // Retorna verdadeiro se houver valores duplicados e falso caso contrário
}

/////////////////////////////////////////////////////

// Mostra na tela uma linha informando se ha valores duplicados na Arvore
void imprimirSeHaDuplicados(ARVORE_BINARIA *arv)
{
    if (haDuplicados(arv, arv))
        printf("Ha valores duplicados\n");
    else
        printf("Nao ha valores duplicados\n");
}

/////////////////////////////////////////////////////

int main()
{
    ARVORE_BINARIA *arv1 = NULL;
    inicializar(arv1);

    ITEM item;
    item.chave = 1;
    criarNo(item, &arv1); // cria o no Raiz
    imprimirSeHaDuplicados(arv1);

    item.chave = 2;
    adicionarFilho(item, NoEsquerdo, arv1);

    item.chave = 5;
    adicionarFilho(item, NoDireito, arv1);
    /*
                  1
               2     5
    */

    item.chave = 3;
    adicionarFilho(item, NoEsquerdo, arv1->esq);

    item.chave = 4;
    adicionarFilho(item, NoDireito, arv1->esq);

    item.chave = 6;
    adicionarFilho(item, NoEsquerdo, arv1->dir);

    item.chave = 7;
    adicionarFilho(item, NoDireito, arv1->dir->esq);

    /*
                                    1
                                 2     5
                                3 4   6
                                       7
    */
    imprimirSeHaDuplicados(arv1);

    item.chave = 1;
    adicionarFilho(item, NoEsquerdo, arv1->esq->esq);

    imprimirSeHaDuplicados(arv1);

    item.chave = 7;
    adicionarFilho(item, NoDireito, arv1->dir);
    imprimirSeHaDuplicados(arv1);
    /*
                                      1
                                 2         5
                               3   4     6   7
                             1         7
    */

    disposeArvore(arv1);
    return 0;
}
