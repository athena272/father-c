#include <stdio.h>
#include <stdlib.h>
# include <time.h>

void main() {
    //Imprimi mensagem bonita de boas-vindas
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int numeroChute; //guarda o valor do chute
    int acertou; //guarda o valor 1 caso acerte, e 0 caso erre
    int nivel; //guarda o nivel escolhido (1) Fácil (2) Médio (3) Difícil
    int totalTentativas; //Fácil 20 chances, Medio 15 chances, Difícil 6 chances
    float pontos = 1000; //O jogador começa com 1000 pontos

    //Gerar número randomico
    int segundos = time(0); //pegar o numero de segundos de 1970 até hoje
    srand(segundos); //fazer a funcao rand usar esses segundos
    int numeroAleatorio = rand(); //numero aleatorio muito grande
    int numeroSecreto = numeroAleatorio % 100; //pegar o resto da divisao para manter o numero muito grande entre 0 e 99
    
    printf("Qual o nível de dificuldade\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Sua escolha: ");
    scanf("%d", &nivel);

    //Defini o numero de chances com base no nivel escolhido
    if(nivel == 1) {
        totalTentativas = 20;
    } else if (nivel == 2) {
        totalTentativas = 15;
    } else {
        totalTentativas = 6;
    }


    for (int i = 1; i <= totalTentativas; i++)    
    {
        printf("\n%d° tentativa de %d\n", i, totalTentativas);

        printf("\nQual o número secreto?: ");
        scanf("%d", &numeroChute);

        //Caso o número seja negativo
        if (numeroChute < 0) 
        {
            printf("\nVocê não pode digitar números negativos\n");
            i--;
            continue;
        }

        printf("\nVocê chutou o número %d!\n\n", numeroChute);

        // imprimirá 0 quando a condição for falsa,
        // e 1 quando ela for verdadeira.
        acertou = (numeroSecreto == numeroChute); //Verificando se o numeroSecreto foi acertado    
        int chuteMaior = (numeroChute > numeroSecreto); //Verificando se o chute foi maior que o 
        
        if (acertou) //Verificando se o numero esta certo
        {
            break; //Sair do laço caso acerte o valor
        } else if(chuteMaior) {
               
                printf("Seu %d° chute foi maior do que o número secreto!\n", i);
                printf("Não desamine, tente novamente!\n\n");
        } else{
                printf("Seu %d° chute foi menor do que o número secreto!\n", i);
                printf("Não desamine, tente novamente!\n\n");
        }    

        //funcao abs transforma o numero em positivo
        double pontosPerdidos = abs((numeroChute - numeroSecreto) / 2.0); //Verificando quantos pontos foram perdidos
        pontos -= pontosPerdidos; //Caso errre, perde pontos

    }
    if (acertou)
    {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns você acertou o número secreto!!!");
        printf("\nVocê fez: %.2f pontos\n", pontos);
        printf("Você é um ótimo jogador!\n");
    }
    else
    {
        printf("\nFim do Jogo, o número secreto é: %d\n\n", numeroSecreto);
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nVocê perdeu! Tente novamente!\n\n");
    }    
}

