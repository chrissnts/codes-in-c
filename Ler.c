#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    FILE *fp;

    char name[50], name2[50];

    fp = fopen("Alunos.txt", "a+");

    if (fp == NULL)
    {
        printf("\nErro ao abrir o arquivo.\n");
    }

    printf("\nNome:\n");
    gets(name2);
    fflush(stdin);


    // Fazer exercicio 10;
    while (fgets(name, sizeof(name), fp) != NULL)
    {   
        name[strcspn(name, "\n")] = '\0';

        if (strcmp(name, name2) == 0)
        {
            printf("\nEncontrado\n");
            fclose(fp);
            return 0;
        }
    }

    printf("\nNao encontrado.\n");

    fclose(fp);

    return 0;
}