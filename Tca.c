#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 20

typedef struct
{
    char *nome;
} Pessoa;

void MessagemErro(int erro);
void Menu();
void OpcaoMenu(int op);
Pessoa CriarAmigo();

int main()
{
    int op = 1;

    while (op != 5)
    {

        Menu();
        scanf("%i", &op);
        fflush(stdin);
        OpcaoMenu(op);
        system("pause");
    }

    return 0;
}

void MessagemErro(int erro)
{
    switch (erro)
    {
    case 0:
        system("cls");
        printf("\nErro. Opcao invalida.\n");
        break;
    default:
        system("cls");
        printf("\nErro.\n");
        break;
    }
}

void Menu()
{
    system("cls");
    printf("\n1. Incluir Amigo\n");
    printf("\n\nDigite uma opcao:\n");
}
void OpcaoMenu(int op)
{
    int erro;

    if (op < 1 || op > 5)
    {
        MessagemErro(0);
    }
    else if (op < 5)
    {

        if (op == 1)
        {
        }
        else if (op == 2)
        {
        }
        else if (op == 3)
        {
        }
        else if (op == 4)
        {
        }

        if (erro <= 0)
        {
            MessagemErro(erro);
        }
    }
}
Pessoa CriarAmigo()
{
    Pessoa amigo;
    amigo.nome = (char *)malloc(TAMMAX * sizeof(char));

    printf("\nNome do amigo:\n");
    gets(amigo.nome);
    fflush(stdin);

    return amigo;
}