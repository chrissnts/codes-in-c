#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct
{
    char marca[20];
    char modelo[20];
    char placa[7];
    float motor;
    char cambio[10];

} veiculo;

veiculo carro[200];

void menu();
void opcao_menu(int op);
void messageError(int erro);
void adicionar_veiculo();

int main()
{
    int op;

    menu();
    scanf("%i", &op);
    opcao_menu(op);

    return 0;
}

void menu()
{
    system("cls");
    printf("\n1- Adicionar veiculo\n");
    printf("\n2 - Vizualizar veiculo\n");
    printf("\n3 - Excluir veiculo\n");
    printf("\n4 - Sair\n");
}
void opcao_menu(int op)
{
    if (op > 4 || op < 1)
    {

        messageError(0);
    }

    if (op == 1)
    {
        adicionar_veiculo();
    }
}
void messageError(int erro)
{
    switch (erro)
    {
    case 0:
        system("cls");
        printf("\nInvalido.\n");
    }
}
void adicionar_veiculo(int *ja_adicionado)
{

    system("cls");
    for (int i = *ja_adicionado + 1; i < *ja_adicionado; i++)
    {
        printf("\nDigite a marca do veiculo:\n");
        gets(carro.marca[i]);
    }
}
