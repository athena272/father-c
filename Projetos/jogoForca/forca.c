#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "forca.h"

// variaveis globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

void abertura()
{
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta()
{
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[chutesDados] = chute;
	// (chutesDados)++;
}

int jaChutou(char letra)
{

	int achou = 0; // false

	for (int j = 0; j < chutesDados; j++)
	{
		if (chutes[j] == letra)
		{
			achou = 1;
			break;
		}
	}

	return achou;
}

int ganhou()
{
	for (int i = 0; i < strlen(palavraSecreta); i++)
	{
		if (!jaChutou(palavraSecreta[i]))
		{
			return 0;
		}
	}
	return 1;
}

void desenhaForca()
{

	printf("Voce ja deu %d chutes\n", chutesDados);

	for (int i = 0; i < strlen(palavraSecreta); i++)
	{
		int achou = 0;

		if (jaChutou(palavraSecreta[i]))
		{
			printf("%c ", palavraSecreta[i]);
		}
		else
		{
			printf("_ ");
		}
	}
	printf("\n");
}

void escolhePalavra()
{
	FILE *f;

	f = fopen("palavras.txt", "r");
	if (f == 0)
	{
		printf("Banco de palavras nao disponivel\n\n");
		exit(1);
	}
	int qtdPalavras;
	fscanf(f, "%d", &qtdPalavras);

	srand(time(0));
	int randomico = rand() % qtdPalavras;

	for (int i = 0; i <= randomico; i++)
	{
		fscanf(f, "%s", palavraSecreta);
	}
	fclose(f);
}

void adicionaPalavra()
{
	char quer;
	print("Voce deseja adicionar uma nova palavra no jogo?[S/N]: ");
	scanf(" %c", &quer);

	if (quer == 'S' || quer == 's')
	{
		char novaPalavra[20];

		printf("Digite a nova palavra, em letras maisculas: ");
		scanf(" %s", novaPalavra);

		// agora falta salvar no arquvio
		FILE *f;
		// abre arquivo
		f = fopen("palavras.txt", "a");
		if (f == 0)
		{
			printf("Banco de palavras não disponível\n\n");
			exit(1);
		}
		// escreve a palavra nele
		fprintf(f, "%s", novaPalavra);
		// fecha
		fclose(f);
	}
}

int enforcou()
{
	int erros = 0; // false
	// vamos fazer o loop em todos os chutes dados
	for (int i = 0; i < chutesDados; i++)
	{
		int existe = 0;
		// agora vamos olhar letra a letra da palavra secreta
		// e ver se encontramos o chute aqui
		for (int j = 0; j < strlen(palavraSecreta); j++)
		{
			if (chutes[i] == palavraSecreta[j])
			{
				// encontramos, vamos quebrar o loop
				existe = 1;
				break;
			}
		}
		// se não encontrou, soma um na quantidade de erros
		if (!existe)
			erros++;
	}
	// se tivermos mais do que 5 erros, retornamos 1
	// caso contrário, retornamos 0.
	return erros >= 5;
}

void main()
{
	abertura();
	escolhePalavra(palavraSecreta);

	do
	{

		desenhaForca();

		chuta();

		chutesDados++;

	} while (!ganhou() && !enforcou());
}