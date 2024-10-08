#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

typedef struct
{
    char marca[20];
    char modelo[20];
    char placa[7];
    char cambio[10];
    float motor;

} veiculo;

veiculo carro[200];
int ja_adicionado = 0;

void menu();
void opcao_menu(int op);
void messageError(int erro);
void adicionar_veiculo();
void menu_visualizar_veiculo();
void visualizar_veiculo(int opm);

int main()
{
    int op;
    do
    {
        menu();
        fflush(stdin);
        scanf("%i", &op);
        opcao_menu(op);
    } while (op != 4);

    return 0;
}

void menu()
{
    system("cls");
    printf("\n1- Adicionar veiculo\n");
    printf("\n2 - Visualizar veiculo\n");
    printf("\n3 - Excluir veiculo\n");
    printf("\n4 - Sair\n");
}
void opcao_menu(int op)
{
    int opm;

    if (op > 4 || op < 1)
    {
        messageError(0);
    }
    else if (op == 1)
    {
        adicionar_veiculo();
    }
    else if (op == 2)
    {
        menu_visualizar_veiculo();
        fflush(stdin);
        scanf("%i", &opm);
        visualizar_veiculo(opm);
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
void adicionar_veiculo()
{
    system("cls");
    if (ja_adicionado >= 200)
    {
        printf("Limite de veiculos atingido.\n");
        return;
    }

    printf("\nDigite a marca do veiculo: (Fiat, Volks, Ford, Toyota, Jeep)\n");
    fflush(stdin);
    gets(carro[ja_adicionado].marca);
    printf("\nDigite o modelo do veiculo: (Polo, Argo, Corolla, Ranger, Renegade)\n");
    fflush(stdin);
    gets(carro[ja_adicionado].modelo);
    printf("\nDigite a placa do veiculo: (AAA0000, BBB1234)\n");
    fflush(stdin);
    gets(carro[ja_adicionado].placa);
    printf("\nDigite o tipo de cambio do veiculo: (Manual, Automatico)\n");
    fflush(stdin);
    gets(carro[ja_adicionado].cambio);
    printf("\nDigite o motor do veiculo: (1.0, 1.4, 1.6, 1.8, 2.0)\n");
    fflush(stdin);
    scanf("%f", &carro[ja_adicionado].motor);
    ja_adicionado++;

    printf("\nVeiculo adicionado com sucesso!\n");
}
void menu_visualizar_veiculo()
{
    system("cls");
    printf("\n1- Verificar todos\n");
    printf("\n2- Verificar por marca\n");
    printf("\n3- Verificar por modelo\n");
}
void visualizar_veiculo(int opm)
{
    char marca[20];
    char modelo[20];

    if (opm == 1)
    {
        system("cls");
        for (int i = 0; i < ja_adicionado; i++)
        {
            printf("\nMarca do veiculo %i: %s\n", i + 1, carro[i].marca);
            printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
            printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
            printf("\nMotor do veiculo %i: %.2f\n", i + 1, carro[i].motor);
            printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
        }
    }
    else if (opm == 2)
    {
        printf("\nDigite a marca:\n");
        fflush(stdin);
        gets(marca);
        system("cls");
        for (int i = 0; i < ja_adicionado; i++)
        {
            if (strcmp(carro[i].marca, marca) == 0)
            {
                printf("\nInformacoes do veiculo %i com marca %s:", i + 1, carro[i].marca);
                printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
                printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
                printf("\nMotor do veiculo %i: %.2f\n", i + 1, carro[i].motor);
                printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
            }
        }
    }
    else if (opm == 3)
    {
        printf("\nDigite o modelo:\n");
        fflush(stdin);
        gets(modelo);
        system("cls");
        for (int i = 0; i < ja_adicionado; i++)
        {
            if (strcmp(carro[i].modelo, modelo) == 0)
            {
                printf("\nInformacoes do veiculo %i com modelo %s:", i + 1, carro[i].modelo);
                printf("\nMarca do veiculo %i: %s\n", i + 1, carro[i].marca);
                printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
                printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
                printf("\nMotor do veiculo %i: %.2f\n", i + 1, carro[i].motor);
                printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
            }
        }
    }
}