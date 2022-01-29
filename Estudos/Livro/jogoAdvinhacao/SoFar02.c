#include <stdio.h>
 
void main() {
 
// imprime cabecalho do nosso jogo
printf("******************************************\n");
printf("* Bem vindo ao nosso jogo de adivinhação *\n");
printf("******************************************\n");

double pontos = 1000;
int numeroSecreto = 42;

int chute;
int tentativas = 1;

while(1) {

    printf("Tentativa %d\n", tentativas);
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
        printf("Parabéns! Você acertou!\n");
        printf("Jogue de novo, você é um bom jogador!\n");
     
        break;
    }

    

    else if(maior) {
        printf("Seu chute foi maior que o número secreto\n");
        //como a pessoa errou, precisa perder pontos
    double pontosPerdidos = abs(chute - numeroSecreto) / 2;
    pontos = pontos - pontosPerdidos;
    } 

    else {
        printf("Seu chute foi menor que o número secreto\n");
    }

    tentativas++;
}

printf("Fim de jogo!\n");
printf("Você fez %.2f pontos", pontos);
printf("Você acertou em %d tentativas!\n", tentativas);

}