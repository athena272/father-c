/*
    Lista Linear Sequencial.
    Uma lista linear na qual a ordem lógica dos elementos
    (a ordem vista pelo usuario) é a mesma ordem fisica
    (em memoria principal) dos elementos
    Isto eh, elementos vizinhos na lista estarao em posicoes
    vizinhas na memoria
*/
/*
    Inicializar estrutura
    Retornar a quantidade de elementos validos
    Exibir os elementos da estrutura
    Buscar por um elemento na estrutura
    Inserir elementos na estrutura
    Excluir elementos da estrutura
    Reinicializar a estrutura
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 50

// implementation
typedef int KEYTYPE;

typedef struct
{
    KEYTYPE key;
    // Outros campos...
} REGISTER;

typedef struct
{
    REGISTER list[MAX];
    int amountElements;
} LIST;

// void initializeList(LIST list)
// {
//     list.amountElements = 0;
// }

void initializeList(LIST *list)
{
    list->amountElements = 0;
}

int quantityElements(LIST *list)
{
    return list->amountElements;
}

void showElement(LIST *list)
{
    printf("List: \"");
    for (int i = 0; i < list->amountElements; i++)
    {
        printf("%d ", list->list[i].key);
    }
    printf("\"\n");
}

int searchElement(LIST *list, KEYTYPE key)
{
    for (int i = 0; i < list->amountElements; i++)
    {
        if (key == list->list[i].key)
        {
            return i;
        }
    }
    return -1;
}

bool insertElement(LIST *list, REGISTER reg, int position)
{
    // check is valid position
    // if the list is full
    // if the position is negative
    // if the position is bigger than size of the list
    if ((list->amountElements == MAX) || (position < 0) || (position > list->amountElements))
    {
        return false;
    }
    for (int i = list->amountElements; i > position; i--)
    {
        list->list[i] = list->list[i - 1];
    }
    list->list[position] = reg;
    list->amountElements++;
    return true;
}

bool deleteElement(LIST *list, KEYTYPE key)
{
    int position = searchElement(list, key);
    if (position == -1)
    {
        return false;
    }
    for (int i = position; i < (list->amountElements - 1); i--)
    {
        list->list[i] = list->list[i + 1];
    }
    list->amountElements--;
    return true;
}

void restartList(LIST *list)
{
    list->amountElements = 0;
}

int main()
{
    LIST *myList = (LIST *)malloc(sizeof(LIST));
    REGISTER registro1;
    REGISTER registro2;
    registro1.key = 5;    
    registro2.key = 11;    

    initializeList(myList);
    insertElement(myList, registro1, 0);
    insertElement(myList, registro2, 1);
    showElement(myList);

    return 0;
}