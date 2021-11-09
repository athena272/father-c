# include <stdio.h>
void joga(int tentativas) {

    printf("joga %d\n", tentativas);
    tentativas++;
    printf("joga %d\n", tentativas);
}

void main() {
    int tentativas = 0;

    printf("main %d\n", tentativas);
    tentativas++;

    printf("main %d\n", tentativas);
    tentativas++;
    
    printf("main %d\n", tentativas);
    
    joga(tentativas);
    
    printf("main %d\n", tentativas);

}
