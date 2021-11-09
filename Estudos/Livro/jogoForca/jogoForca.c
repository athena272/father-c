#include <stdio.h>
#include <string.h>
# include <stdlib.h>
#include <time.h>
#include "forca.h" 

//Variáveis Globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

int letraExiste(char letra) {
 
    for(int j = 0; j < strlen(palavraSecreta); j++) {
        if(letra == palavraSecreta[j]) {
            return 1;
        }
    }
 
    return 0;
}

int chutesErrados() {
    int erros = 0;
 
    for(int i = 0; i < chutesDados; i++) {
        
        if(!letraExiste(chutes[i])) {
            erros++;
        }
    }
 
    return erros;
}

int ganhou() {
    for(int i = 0; i < strlen(palavraSecreta); i++) {
        if(!jaChutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int enforcou() {
    return chutesErrados() >= 5;
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
 
    if(letraExiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }
 
    chutes[chutesDados] = chute;
    chutesDados++;
    
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

void desenhaForca() {
 
    printf("Você deu %d chutes até agora\n", chutesDados);
    
   int erros = chutesErrados();
 
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
 
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
    
   FILE* f;
 
    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }
 
    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);
 
    srand(time(0));
    int randomico = rand() % qtdPalavras;
 
    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavraSecreta);
    }
 
    fclose(f);

}

void adicionaPalavra() {
    char quer;
 
    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);
 
    if(quer == 'S') {
        char novaPalavra[TAMANHO_PALAVRA];
 
        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novaPalavra);
 
        FILE* f;
 
        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }
 
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);
 
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);
 
        fclose(f);
 
    }
 
}

void main() {

    boasVindas();
    // código continua aqui

    escolhePalavra(); 
 
    do {
        
        desenhaForca();
 
        chuta();

    } while (!ganhou() && !enforcou()); //enquanto não acertar ou morrer enforcado, continuar o jogo

    if(ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");
 
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
 
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);
 
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
 
    adicionaPalavra();
 
}