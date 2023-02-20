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

void insertElement(LIST *list, KEYTYPE key)
{
    
}

int main()
{
    return 0;
}