#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    FILE * fp;

    // [w] = abre/cria e apaga o conteudo;
    // [r] = so abre arquivo se existir e mantem o conteudo;
    // [a+] = abre/cria o arquivo e mantem o conteudo;
    fp = fopen ("Teste.txt", "a+");

    if (fp == NULL)
    {
        printf("\nErro. Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    fclose (fp);
}