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
    REGISTER listReg[MAX];
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

int searchElement(LIST *list, KEYTYPE key)
{
    for (int i = 0; i < list->amountElements; i++)
    {
        if (key == list->listReg[i].key)
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
    if ((list->amountElements >= MAX) || (position < 0) || (position > list->amountElements))
    {
        return false;
    }
    for (int i = list->amountElements; i > position; i--)
    {
        list->listReg[i] = list->listReg[i - 1];
    }
    list->listReg[position] = reg;
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

    initializeList(myList);
    insertElement(myList, registro1, 0);
    insertElement(myList, registro2, 1);
    insertElement(myList, registro3, 2);
    insertElement(myList, registro4, 3);
    showElements(myList);

    printf("%d\n", searchElement(myList, registro4.key));

    deleteElement(myList, registro3.key);
    showElements(myList);

    return 0;
}