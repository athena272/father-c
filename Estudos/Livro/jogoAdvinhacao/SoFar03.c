#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void main() {
 
    // imprime um cabecalho bonito para o nosso jogo
    printf("******************************************\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("******************************************\n");

    int chute;
    int acertou;
    double pontos = 1000;
    
    //GERAR NUMERO SECRETO
    int segundos = time(0); //gera segundos passados desde de 1 de Janeiro de 1970(Epoch)
    srand(segundos); //define a semente dos numeros aleatorios, e aplica na formula
    int numeroGrande = rand(); //gera um numero aleatório muito grande
    int numeroSecreto = numeroGrande % 100; //limita com que esse numero fique entre 0 à 99

    //DEFINIR O NIVEL DO JOGO
    int nivel;
    int totalTentativas;

    printf("Escolha um nível de dificuldade: \n");
    printf("[1] Fácil (20 tentativas)\n[2] Médio (15 tentativas)\n[3] Difícil (6 tentativas)\n");
    printf("\nQual a sua escolha?: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        totalTentativas = 20;
        break;
    
    case 2: 
        totalTentativas = 15;
        break;

    default:
        totalTentativas = 6;
        break;
    }

    


    for(int i = 1; i <= totalTentativas; i++) {

        printf("%dª Tentativa de %d tentativas\n", i, totalTentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n\n");
            i--;
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou) {
            break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n\n");
            //como a pessoa errou, precisa perder pontos 
        } 
        else {
            printf("Seu chute foi menor que o número secreto\n\n");
        }
        
        //Calcula o numero de pontos perdidos
        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    //MENSAGEM DE VITORIA OU DERROTA
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
        printf("             OOOOOOOOOOOO              \n\n");
        printf("Parabéns! Você acertou em %d tentativas!\n", totalTentativas);
        printf("Você fez %.2f pontos\n", pontos);
        printf("Jogue de novo, você é um bom jogador!\n");
        
    }
    else {
        printf("\n");
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n\n");
        printf("Fim de jogo! O número secreto era %d\n", numeroSecreto);
        printf("Você perdeu! Tente novamente!\n");
        
    }

}