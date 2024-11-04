#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MessagemErro(int erro);
void Menu();
void OpcaoMenu(int op);

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
        printf("\nErro. Opcao invalida.\n");
    default:
        printf("\nErro.\n");
    }
}

void Menu()
{
    system("clear");
    printf("\n");
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
            erro = ;
        }
        else if (op == 2)
        {
            erro = ;
        }
        else if (op == 3)
        {
            erro = ;
        }
        else if (op == 4)
        {
            erro = ;
        }

        if (erro <= 0)
        {
            MessagemErro(erro);
        }
    }
}