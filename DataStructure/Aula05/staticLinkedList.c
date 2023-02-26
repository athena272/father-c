#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#define MAX 50
#define INVALID -1

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

typedef struct
{
    REGISTER reg;
    int next;
} ELEMENT;

typedef struct
{
    ELEMENT listElem[MAX];
    int start;
    int available;
} LIST;

ELEMENT createElement(KEYTYPE key, int next)
{
    ELEMENT element;
    element.reg.key = key;
    element.next = next;
}

int sizeOfList(LIST *list)
{
    int i = list->start;
    int size = 0;
    while (i != INVALID)
    {
        size++;
        i = list->listElem[i].next;
    }
    return size;
}

void inicializeList(LIST *list)
{
    // Colocar todos os elementos na lista de disponiveis
    for (int i = 0; i < MAX - 1; i++)
    {
        list->listElem[i].next = i + 1;
    }
    list->listElem[MAX - 1].next = INVALID;
    list->start = INVALID;
    list->available = 0;
}

void showList(LIST *list)
{
    int current = list->start;
    printf("Lista: \" ");
    while (current != INVALID)
    {
        printf("%d ", list->listElem[current].reg.key);
        current = list->listElem[current].next;
    }

    printf("\"\n");
}

int ordSequencialSearch(LIST *list, KEYTYPE key)
{
    int current = list->start;
    while (current != INVALID && list->listElem[current].reg.key < key)
    {
        current = list->listElem[current].next;
    }
    if (current != INVALID && list->listElem[current].reg.key == key)
    {
        return current;
    }
    return INVALID;
}

int getNode(LIST *list)
{
    int postion = list->available;
    if (list->available != INVALID)
    {
        list->available = list->listElem[list->available].next;
    }
    return postion;
}

bool insertElement(LIST *list, REGISTER reg)
{
    if (list->available == INVALID)
    {
        return false;
    }
    int previous = INVALID;
    int current = list->start;
    KEYTYPE key = reg.key;
    while ((current != INVALID) && (list->listElem[current].reg.key < key))
    {
        previous = current;
        current = list->listElem[current].next;
    }
    if (current != INVALID && list->listElem[current].reg.key == key)
    {
        return false;
    }
    // Se passou por tudo isso e não deu false, da para inserir
    current = getNode(list);
    list->listElem[current].reg = reg;

    // So falta saber onde inserir
    if (previous != INVALID)
    {
        list->listElem[current].next = list->start;
        list->start = current;
    }
    else
    {
        list->listElem[current].next = list->listElem[previous].next;
        list->listElem[previous].next = current;
    }

    return true;
}

int main()
{
    ELEMENT element0 = createElement(4, 1);

    return 0;
}
