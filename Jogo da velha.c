#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define CARACTER '_'
#define EMPATE 'E'

int main()
{

    /*
        [0] [1] [2]
    [0]  1   2   3
    [1]  4   5   6
    [2]  7   8   9

    */

    int lin, col;
    int cont_jogadas = 0;
    int jogada;
    char jogo[TAM][TAM];
    char jogador_atual = JOGADOR_X;
    char ganhador = EMPATE;

    // Criando tabuleiro;
    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            jogo[lin][col] = CARACTER;
        }
    }
    // Laço de jogadas;
    while (1)
    {
        // Apresentando tabuleiro;

        for (lin = 0; lin < TAM; lin++)
        {
            for (col = 0; col < TAM; col++)
            {
                printf("%c ", jogo[lin][col]);
            }
            printf("\n");
        }

        // Lendo jogada do jogador atual;
        printf("\nJogador %c, faca sua jogada:\n", jogador_atual);
        scanf("%i", &jogada);

        // Verificando se jogada é valida;
        if (!(jogada >= 1 && jogada <= 9))
        {
            printf("\nPosicao invalida, digite novamente.\n");
            continue;
        }

        // Condicoes de jogadas, jogador x;
        if (jogada >= 1 && jogada <= 3)
        {
            if (jogo[0][jogada - 1] != CARACTER)
            {
                printf("\nPosicao ja preenchida, digite novamente.\n");
                continue;
            }

            jogo[0][jogada - 1] = jogador_atual;
        }
        else if (jogada >= 4 && jogada <= 6)
        {
            if (jogo[1][jogada - 4] != CARACTER)
            {
                printf("\nPosicao ja preenchida, digite novamente.\n");
                continue;
            }

            jogo[1][jogada - 4] = jogador_atual;
        }
        else if (jogada >= 7 && jogada <= 9)
        {
            if (jogo[2][jogada - 7] != CARACTER)
            {
                printf("\nPosicao ja preenchida, digite novamente.\n");
                continue;
            }

            jogo[2][jogada - 7] = jogador_atual;
        }

        // Verifica se as linhas foram preenchidas e jogador X ganhou;
        for (lin = 0; lin < TAM; lin++)
        {
            if (jogo[lin][0] == jogador_atual && jogo[lin][1] == jogador_atual && jogo[lin][2] == jogador_atual)
            {
                ganhador = jogador_atual;
                break;
            }
        }

        // Verifica se as colunas foram preenchidas e jogador X ganhou;
        for (col = 0; col < TAM; col++)
        {
            if (jogo[0][col] == jogador_atual && jogo[1][col] == jogador_atual && jogo[2][col] == jogador_atual)
            {
                ganhador = jogador_atual;
                break;
            }
        }
        // Verifica se as diagonais foram preenchidas e jogador X ganhou;
        if (jogo[0][0] == JOGADOR_X && jogo[1][1] == JOGADOR_X && jogo[2][2] == JOGADOR_X)
        {
            ganhador = JOGADOR_X;
        }
        else if (jogo[0][2] == JOGADOR_X && jogo[1][1] == JOGADOR_X && jogo[2][0] == JOGADOR_X)
        {
            ganhador = JOGADOR_X;
        }

        // Se houver ganhador ou todas as casas estiverem preenchidas
        if (ganhador != EMPATE)
        {
            break;
        }

        cont_jogadas++;

        // Verificando se a jogada sera do X ou O;
        if (jogador_atual == JOGADOR_X)
        {
            jogador_atual = JOGADOR_O;
        }
        else
        {
            jogador_atual = JOGADOR_X;
        }

        // Se houver ganhador ou todas as casas estiverem preenchidas
        if (ganhador != EMPATE || cont_jogadas == 9)
        {
            break;
        }
    }
    // Apresentando o resultado final;
    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            printf("%c ", jogo[lin][col]);
        }
        printf("\n");
    }
    if (ganhador != EMPATE)
    {
        printf("\nJogador %c venceu!\n", ganhador);
    }
    else
    {
        printf("\nEmpate!\n");
    }
}