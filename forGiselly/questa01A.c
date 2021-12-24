#include <stdio.h>

void repeat (char meuCaractere , int numeroVezes)
{
    for (int i = 0; i < numeroVezes; i++){
        printf("%c", meuCaractere);
    }
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        repeat('*', i);
        printf("\n");
    }
    
}