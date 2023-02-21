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

REGISTER createRegister(KEYTYPE key)
{
    REGISTER reg;
    reg.key = key;
    // initialize other fields as needed
    return reg;
}

void inicializeList(LIST *list)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        list->listElem[i].next = i + 1;
    }
    list->listElem[MAX - 1].next = INVALID;
    list->start = INVALID;
    list->available = 0;
}

int main()
{
    return 0;
}
