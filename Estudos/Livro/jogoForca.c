#include <stdio.h>
#include <string.h>
 
int main() {
 
    char palavraSecreta[20];
    sprintf(palavraSecreta, "MELANCIA"); //imprimi em um array de char(palavraSecreta) o valor MELANCIA
 
    int acertou = 0; //False
    int enforcou = 0; //False
 
    char chutes[26];
    int tentativas = 0;
 
    do {
        
        for(int i = 0; i < strlen(palavraSecreta); i++) {
            int achou = 0;
 
            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavraSecreta[i]) {
                    achou = 1;
                    break;
                }
            }
 
            if(achou) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
 
        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);
 
        chutes[tentativas] = chute;
        tentativas++;
 
 
    } while (!acertou && !enforcou); //enquanto não acertar ou morrer enforcado, continuar o jogo'
 
}