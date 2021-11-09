#include <stdio.h>
#include <string.h>
 
//Variáveis Globais
char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

// imprime cabeçalho 
void boasVindas() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(char chutes[], int* tentativas) {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
 
    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int jaChutou(char letra, char* chutes, int tentativas) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
 
    return achou;
}

void desenhaForca(char* palavraSecreta, char* chutes, int tentativas) {
 
    printf("Você já deu %d chutes\n", tentativas);
    
    for(int i = 0; i < strlen(palavraSecreta); i++) {
 
        if(jaChutou(palavraSecreta[i], chutes, tentativas)) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
 
    }
    printf("\n");
 
}

void escolhePalavra(char* palavraSecreta) {
    sprintf(palavraSecreta, "MELANCIA"); //imprimi em um array de char(palavraSecreta) o valor MELANCIA
}

void main() {

    boasVindas();
    // código continua aqui

    escolhePalavra(palavraSecreta); 
 
    int acertou = 0; //False
    int enforcou = 0; //False
 
    do {
        
        desenhaforca(palavraSecreta, chutes, tentativas);
 
        chuta(chutes, &tentativas);
 
 
    } while (!acertou && !enforcou); //enquanto não acertar ou morrer enforcado, continuar o jogo'
 
}