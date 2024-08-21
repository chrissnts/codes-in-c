#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define CARACTER '_'

int main()
{

    int lin, col;
    int cont_jogadas = 0;
    int jogada;
    char jogo[TAM][TAM];

    // Criando o "menu";
    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            jogo[lin][col] = CARACTER;
        }
    }

    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            printf("%c", jogo[lin][col]);
        }
        printf("\n");
    }

    // Laço de jogadas;
    while (1)
    {
        if (cont_jogadas % 2 == 0)
        {
            printf("\nJogador %c, faça sua jogada:\n", JOGADOR_X);
            scanf("%i", &jogada);

            // Verificando se jogada é valida;
            if (!(jogada >= 1 && jogada <= 9))
            {
                printf("Posicao invalida, digite novamente.\n");
                continue;
            }

            // Condicoes de jogadas, jogador A;
            if (jogada >= 1 && jogada <= 3)
            {
                if (jogo[0][jogada - 1] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[0][jogada - 1] = JOGADOR_X;
            }
            else if (jogada >= 4 && jogada <= 6)
            {
                if (jogo[1][jogada - 4] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[1][jogada - 4] = JOGADOR_X;
            }
            else if (jogada >= 7 && jogada <= 9)
            {
                 if (jogo[2][jogada - 7] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[2][jogada - 7] = JOGADOR_X;
            }

            cont_jogadas++;
        }
        else 
        {
            printf("\nJogador %c, faça sua jogada:\n", JOGADOR_O);
            scanf("%i", &jogada);

            // Verificando se jogada é valida;
            if (!(jogada >= 1 && jogada <= 9))
            {
                printf("Posicao invalida, digite novamente.\n");
                continue;
            }

            // Condicoes de jogadas, jogador A;
            if (jogada >= 1 && jogada <= 3)
            {
                if (jogo[0][jogada - 1] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[0][jogada - 1] = JOGADOR_O;
            }
            else if (jogada >= 4 && jogada <= 6)
            {
                if (jogo[1][jogada - 4] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[1][jogada - 4] = JOGADOR_O;
            }
            else if (jogada >= 7 && jogada <= 9)
            {
                if (jogo[2][jogada - 7] != CARACTER)
                {
                    printf("Posicao ja preenchida, digite novamente.");
                    continue;
                }

                jogo[2][jogada - 7] = JOGADOR_O;
            }
        }
     
    }
}
