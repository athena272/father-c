#include <stdio.h>
#include <string.h>
 
//Variáveis Globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

// lista de funções que aparecerão no arquivo
int enforcou();
void abertura();
void chuta();
int jachutou(char letra);
int ganhou();
void desenhaforca();
void escolhepalavra();

int enforcou() {
 
    int erros = 0;
 
    for(int i = 0; i < chutesDados; i++) {
        
        int existe = 0;
 
        for(int j = 0; j < strlen(palavraSecreta); j++) {
            if(chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }
 
        if(!existe) erros++;
    }
 
    return erros >= 5;
}

// imprime cabeçalho 
void boasVindas() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
 
    chutes[chutesDados] = chute;
    
}

int jaChutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
 
    return achou;
}

int ganhou() {
    for(int i = 0; i < strlen(palavraSecreta); i++) {
        if(!jaChutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}

void desenhaForca() {
 
    printf("Você deu %d chutes até agora\n", chutesDados);
    
    for(int i = 0; i < strlen(palavraSecreta); i++) {
 
        if(jaChutou(palavraSecreta[i])) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
 
    }
    printf("\n");
 
}

void escolhePalavra() {
    sprintf(palavraSecreta, "MELANCIA"); //imprimi em um array de char(palavraSecreta) o valor MELANCIA
}

void main() {

    boasVindas();
    // código continua aqui

    escolhePalavra(); 
 
    do {
        
        desenhaForca();
 
        chuta();

        
 
    } while (!ganhou() && !enforcou()); //enquanto não acertar ou morrer enforcado, continuar o jogo'
 
}