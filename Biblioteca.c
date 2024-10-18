#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu();

int main()
{
    int op;
    do
    {
        Menu();
        scanf("%i",&op);

    } while (op != 6);

    return 0;
}

void Menu()
{
    system("cls");
    printf("\n - (1) Incluir pessoa\n");
    printf("\n - (2) Incluir livro\n");
    printf("\n - (3) Registrar emprestimo\n");
    printf("\n - (4) Listar todos os emprestimos em aberto\n");
    printf("\n - (5) Buscar pessoa pelo CPF e ver livros emprestados\n");
    printf("\n - (6) Sair\n");
}