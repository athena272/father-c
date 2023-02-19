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
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // Outros campos...
} REGISTRO;

typedef struct
{
    REGISTRO lista[MAX];
    int qtdElements;
} LISTA;

void main()
{
}