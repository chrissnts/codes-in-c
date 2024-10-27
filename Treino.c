#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char str[50];

    // [w] = abre/cria e apaga o conteudo;
    // [r] = so abre arquivo se existir e mantem o conteudo;
    // [a+] = abre/cria o arquivo e mantem o conteudo;
    //[fgetc] = le um caracter por vez de uma linha;
    //[fgetc] com laço de repetição = (do c = fgect(fp) printf("%c", c)while (c!= '\n') )= vai mostrar uma linha;
    //[fgetc] com laço de repetição = (do c = fgect(fp) printf("%c", c)while (c!= EOF) )= vai mostrar todas as linhas;
    // [fputc] = insere na proxima linha (fputc('\n', fp) um caracter no arquivo);
    // [fputc] = insere na proxima linha (com laço de repetição for (i = 0; str[i] != '\0; i ++) ) uma string no arquivo);
    //[fgets] = faz o que o fputc faz com o laço for, pega ate o '\n';
    // [fgets] = para pegar todo o conteudo do arquivo ( while (fgets(Str, 50, fp != NULL printf("%s", str) ) );
    // [fputs] = insere uma frase ou texto no arquivo usando o gets normal dps apenas dando fputs(str, fp) fputs("\n", fp);

    fp = fopen("Teste.txt", "a+");

    if (fp == NULL)
    {
        printf("\nErro. Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    printf("\nDigite seu nome:\n");
    gets(str);
    fputs(str, fp); 
    fputs("\n", fp);
    

    fclose(fp);
}