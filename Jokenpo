#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    // PEDRA = 1;
    // TESOURA = 0;
    // PAPEL = 2;
    int jogada, cpu;

    srand(time(NULL));

    printf("\n-----------------------------------");
    printf("\nPEDRA = 1\nTESOURA = 0\nPAPEL = 2");
    printf("\n-----------------------------------");
    printf("\nDigite uma jogada:");
    scanf("%i", &jogada);

    cpu = rand() % 3;

    // Caso jogada = 0;
    if (jogada == 0 && cpu == 0)
    {
        printf("\nHouve empate.");
    }
    else if (jogada == 0 && cpu == 1)
    {
        printf("\nCPU ganhou com PEDRA, JOGADOR perdeu com TESOURA.");
    }
    else if (jogada == 0 && cpu == 2)
    {
        printf("\nJOGADOR ganhou com TESOURA, CPU perdeu com PAPEL.");
    }

    // Caso jogada = 1;
    if (jogada == 1 && cpu == 1)
    {
        printf("\nHouve empate.");
    }
    else if (jogada == 1 && cpu == 0)
    {
        printf("\nJOGADOR ganhou com PEDRA, CPU perdeu com TESOURA.");
    }
    else if (jogada == 1 && cpu == 2)
    {
        printf("\nCPU ganhou com PAPEL, JOGADOR perdeu com PEDRA");
    }

    // Caso jogada = 2;
    if (jogada == 2 && cpu == 2)
    {
        printf("\nHouve empate.");
    }
    else if (jogada == 2 && cpu == 1)
    {
        printf("\nCPU ganhou com PEDRA, JOGADOR perdeu com PAPEL.");
    }
    else if (jogada == 2 && cpu == 0)
    {
        printf("\nCPU ganhou com Tesoura, JOGADOR perdeu com PAPEL");
    }

    return 0;
}
