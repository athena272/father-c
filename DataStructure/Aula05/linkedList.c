#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#define MAX 50

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

int main()
{
    return 0;
}
