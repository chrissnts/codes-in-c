#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TAM 3

void ImprimirTabuleiro();
int PedirJogada(int jogada);
void MensagemErro(int erro);
int FazerJogada(int jogada);

int jogador = 2;
int tabuleiro[TAM][TAM];

int main(){
    int jogada;
    int erro = -1;
    
    while (erro <= 0){ 
        ImprimirTabuleiro();
        scanf("%i", &jogada);
        jogador ++;
        erro = PedirJogada(jogada);
        MensagemErro(erro);
        jogador --;
        Sleep(1000);
        
    }
    
    return 0;
}

void ImprimirTabuleiro()
{   
    system("clear");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            // ARRUMAR!!!
            if (tabuleiro[i][j] != ' _ ' )
            {
                tabuleiro[i][j] = " _ ";
            }
            printf("%i", tabuleiro[i][j]);
        }
        printf("\n");
    } 
    if (jogador % 2 == 0)
    {
        printf("\nDigite jogador X digite uma jogada:\n");
    }
    else
    {
        printf("\nDigite jogador O digite uma jogada:\n");
    }
    
}
int PedirJogada(int jogada)
{
    if (jogada < 1 || jogada > 9)
    {
        return 0;
    }
}
void MensagemErro(int erro)
{
    switch (erro)
    {
        case 0:
            system("clear");
            printf("\nOpcao invalida.\n");
            break;
        case -1:
            system("clear");
            printf("\n.\n");
            break;
    }
}
int FazerJogada(int jogada)
{
    if (jogada == 1 && (jogador % 2 == 0))
    {
        tabuleiro[0][1] = "X";        
    
    } 
    
}
