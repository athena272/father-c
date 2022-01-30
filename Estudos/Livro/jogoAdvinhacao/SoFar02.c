#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void main() {
 
    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int chute;
    int acertou = 0;
    int tentativas = 1;
    double pontos = 1000;
    
    //GERAR NUMERO SECRETO
    int segundos = time(0); //gera segundos passados desde de 1 de Janeiro de 1970(Epoch)
    srand(segundos); //define a semente dos numeros aleatorios, e aplica na formula
    int numeroGrande = rand(); //gera um numero aleatório muito grande
    int numeroSecreto = numeroGrande % 100; //limita com que esse numero fique entre 0 à 99

    


    while(!acertou) {

        printf("%dª Tentativa\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou) {
            printf("\nParabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
        
            break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n\n");
            //como a pessoa errou, precisa perder pontos
            
        } 
        else {
            printf("Seu chute foi menor que o número secreto\n\n");
        }

        tentativas++;

        //Calcula o numero de pontos perdidos
        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de jogo!\n");
    printf("Você fez %.2f pontos\n", pontos);
    printf("Você acertou em %d tentativas!\n", tentativas);
    printf("Obrigado por jogar!!!\n");

}