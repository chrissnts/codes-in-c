#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int main()
{

    char *name1, *name2;
    int tam;
    int tam1, tam2;

    printf("\nDigite um tamanho:\n");
    scanf("%d", &tam);

    name1 = malloc (tam*sizeof(char));
    name2 = malloc (tam*sizeof(char));

    printf("\nDigite 2 nomes:\n");
    fflush(stdin);
    gets(name1);
    gets(name2);

    tam1 = strlen (name1);
    tam2 = strlen (name2);

    printf("\n %i + %i = %i\n", tam1, tam2, tam1+tam2);

    //https://youtu.be/pQHtnygAeu0?si=dau5FRao785IWx2l

    
    return 0;
}
