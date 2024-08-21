#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define JOGADOR_X 'X'
#define JOGADOR_O 'O'

void mostrar_tabuleiro()
{
    char tabuleiro[TAM][TAM];
    int lin, col;

    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            tabuleiro[lin][col] = '_';
        }
    }

    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            printf("%c", tabuleiro[lin][col]);
        }
        printf("\n");
    }
}

int main()
{

    int lin, col;
    int cont_jogadas = 0;
    int jogada;
    char jogo[TAM][TAM];

    mostrar_tabuleiro();

    // Criando tabuleiro;
    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            jogo[lin][col] = '_';
        }
    }

    while (1)
    {
        if (cont_jogadas % 2 == 0)
        {
            printf("\nJogador %c, faça sua jogada:\n", JOGADOR_X);
            scanf("%i", &jogada);
            cont_jogadas++;

            // Condicoes de jogadas, jogador A;
            if (jogada == 1)
            {
                if (jogo[0][0] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][0] = JOGADOR_X;
                }
            }
            else if (jogada == 2)
            {
                if (jogo[0][1] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][1] = JOGADOR_X;
                }
            }
            else if (jogada == 3)
            {
                if (jogo[0][2] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][2] = JOGADOR_X;
                }
            }
            else if (jogada == 4)
            {
                if (jogo[1][0] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][0] = JOGADOR_X;
                }
            }
            else if (jogada == 5)
            {
                if (jogo[1][1] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][1] = JOGADOR_X;
                }
            }
            else if (jogada == 6)
            {
                if (jogo[1][2] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][2] = JOGADOR_X;
                }
            }
            else if (jogada == 7)
            {
                if (jogo[2][0] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][0] = JOGADOR_X;
                }
            }
            else if (jogada == 8)
            {
                if (jogo[2][1] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][1] = JOGADOR_X;
                }
            }
            else if (jogada == 9)
            {
                if (jogo[2][2] == JOGADOR_O)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][2] = JOGADOR_X;
                }
            }
        }
        else if (cont_jogadas % 2 != 0)
        {
            printf("\nJogador %c, faça sua jogada:\n", JOGADOR_O);
            scanf("%i", &jogada);
            cont_jogadas++;

            // Condicoes de jogadas, jogador O;
            if (jogada == 1)
            {
                if (jogo[0][0] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][0] = JOGADOR_O;
                }
            }
            else if (jogada == 2)
            {
                if (jogo[0][1] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][1] = JOGADOR_O;
                }
            }
            else if (jogada == 3)
            {
                if (jogo[0][2] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[0][2] = JOGADOR_O;
                }
            }
            else if (jogada == 4)
            {
                if (jogo[1][0] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][0] = JOGADOR_O;
                }
            }
            else if (jogada == 5)
            {
                if (jogo[1][1] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][1] = JOGADOR_O;
                }
            }
            else if (jogada == 6)
            {
                if (jogo[1][2] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[1][2] = JOGADOR_O;
                }
            }
            else if (jogada == 7)
            {
                if (jogo[2][0] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][0] = JOGADOR_O;
                }
            }
            else if (jogada == 8)
            {
                if (jogo[2][1] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][1] = JOGADOR_O;
                }
            }
            else if (jogada == 9)
            {
                if (jogo[2][2] == JOGADOR_X)
                {
                    printf("Posicao invalida, tente novamente.\n");
                    cont_jogadas--;
                    continue;
                }
                else
                {
                    jogo[2][2] = JOGADOR_O;
                }
            }

            // Mostrando o tabuleiro com X e O;
            for (lin = 0; lin < TAM; lin++)
            {
                for (col = 0; col < TAM; col++)
                {
                    printf("%c", jogo[lin][col]);
                }
                printf("\n");
            }
        }

        
    }
}
