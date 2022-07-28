#include <stdio.h>
#include <string.h>

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
	sprintf(palavraSecreta, "MELANCIA");
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

	int acertou = 0; // false

	abertura();
	escolhePalavra(palavraSecreta);

	do
	{

		desenhaForca();

		chuta();

		chutesDados++;

	} while (!acertou && !enforcou());
}