#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu();
void Comprar();
void Erros(int erro);
int OpcaoMenu(int op);
int OpcaoComprar(int op);

int main()
{
    int op = -1;

    FILE *file, *file2;

    file = fopen("Vendas.txt", "a+");
    file2 = fopen("Compras.txt", "a+");

    if (file == NULL || file2 == NULL)
    {
        printf("\nError opening file.\n");
    }

    do
    {
        system("clear");
        Menu();
        scanf("%i", &op);
        OpcaoMenu(op);

    } while (op != 0);

    if (op == 0)
    {
        Erros(0);
    }

    fclose(file);
    fclose(file2);

    return 0;
}

void Menu()
{
    printf("\n********************************\n");
    printf("1 - Comprar Produtos\n");
}
int OpcaoMenu(int op)
{
    if (op < 0 || op > 5)
    {
        return -1;
    }
    if (op == 1)
    {
        Comprar();
    }
}

void Comprar()
{
    int op = 1;
    system("clear");
    printf("\n********************************\n");
    printf("\nQual produto deseja?\n");
    printf("\n1 - Agua\n");
    printf("\n2 - Suco\n");
    printf("\n3 - Refri\n");
    scanf("%d", &op);
    OpcaoComprar(op);
}
int OpcaoComprar(int op)
{
    if (op < 1 || op > 3)
    {
        return -1;
    }
}
void Erros(int erro)
{
    switch (erro)
    {
    case 0:
        printf("\nBye.\n");
        return;
    case -1:
        printf("\nInvalido.\n");
        return;
    }
}
