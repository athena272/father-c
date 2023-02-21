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
#include <string.h>
#include <math.h>

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
    REGISTER listReg[MAX + 1];
    int amountElements;
} LIST;

// void initializeList(LIST list)
// {
//     list.amountElements = 0;
// }

REGISTER createRegister(KEYTYPE key)
{
    REGISTER reg;
    reg.key = key;
    // initialize other fields as needed
    return reg;
}

void initializeList(LIST *list)
{
    list->amountElements = 0;
}

int quantityElements(LIST *list)
{
    return list->amountElements;
}

void showElements(LIST *list)
{
    printf("List: \" ");
    for (int i = 0; i < list->amountElements; i++)
    {
        printf("%d ", list->listReg[i].key);
    }
    printf("\"\n");
}

int sentinelSearch(LIST *list, KEYTYPE key)
{
    int i;
    list->listReg[list->amountElements].key = key;
    for (i = 0; list->listReg[i].key != key; i++)
    {
    }
    if (i == list->amountElements)
    {
        return -1;
    }
    return i;
}

int binarySearch(LIST *list, KEYTYPE key)
{
    int left, right, middle;
    left = 0;
    right = list->amountElements - 1;
    while (left <= right)
    {
        middle = floor((left + right) / 2);
        if (list->listReg[middle].key == key)
        {
            return middle;
        }
        else if (list->listReg[middle].key < key)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

bool insertSortElement(LIST *list, REGISTER reg)
{
    // check is valid position
    // if the list is full
    if ((list->amountElements >= MAX))
    {
        return false;
    }
    int i = list->amountElements;
    for (i; i > 0 && (list->listReg[i - 1].key > reg.key); i--)
    {
        list->listReg[i] = list->listReg[i - 1];
    }
    list->listReg[i] = reg;
    list->amountElements++;
    return true;
}

bool deleteElement(LIST *list, KEYTYPE key)
{
    int position = binarySearch(list, key);
    if (position == -1)
    {
        return false;
    }
    for (int i = position; i < (list->amountElements - 1); i++)
    {
        list->listReg[i] = list->listReg[i + 1];
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
    // This will set all the bytes in the LIST struct to zero, which initializes all the elements to zero as well. Then, when you insert the fourth element, it will be inserted in position 4, and the loop in showElements() will only print the three valid elements, without the extra zero.
    // memset(myList, 0, sizeof(LIST));
    REGISTER registro1 = createRegister(5);
    REGISTER registro2 = createRegister(11);
    REGISTER registro3 = createRegister(17);
    REGISTER registro4 = createRegister(23);
    REGISTER registro5 = createRegister(-2);
    REGISTER registro6 = createRegister(19);

    initializeList(myList);
    insertSortElement(myList, registro1);
    insertSortElement(myList, registro2);
    insertSortElement(myList, registro3);
    insertSortElement(myList, registro4);
    insertSortElement(myList, registro5);
    insertSortElement(myList, registro6);
    showElements(myList);

    printf("%d\n", binarySearch(myList, registro3.key));

    return 0;
}