
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        scanf("%i", &op);
        fflush(stdin);
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
        scanf("%i", &opm);
        fflush(stdin);
        visualizar_veiculo(opm);
    }
}

void messageError(int erro)
{
    switch (erro)
    {
    case 0:
        system("cls");
        printf("\nErro. Invalido.\n");
    case 1:
        system("cls");
        printf("\nErro. Nenhum veiculo adicionado.\n");
    case 2:
        system("cls");
        printf("\nErro. Limite de veiculos atingidos.\n");
    }
}
void adicionar_veiculo()
{

    system("cls");
    if (ja_adicionado >= 200)
    {
        messageError(2);
        return;
    }

    printf("\nDigite a marca do veiculo: (Fiat, Volks, Ford, Toyota, Jeep)\n");
    gets(carro[ja_adicionado].marca);
    fflush(stdin);

    printf("\nDigite o modelo do veiculo: (Polo, Argo, Corolla, Ranger, Renegade)\n");
    gets(carro[ja_adicionado].modelo);
    fflush(stdin);

    printf("\nDigite a placa do veiculo: (AAA0000, BBB1234)\n");
    gets(carro[ja_adicionado].placa);
    fflush(stdin);

    printf("\nDigite o tipo de cambio do veiculo: (Manual, Automatico)\n");
    gets(carro[ja_adicionado].cambio);
    fflush(stdin);

    printf("\nDigite o motor do veiculo: (1.0, 1.4, 1.6, 1.8, 2.0)\n");
    scanf("%f", &carro[ja_adicionado].motor);
    fflush(stdin);

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
    int i;

    if (ja_adicionado <= 0)
    {
        messageError(1);
    }
    else
    {
        if (opm == 1)
        {
            system("cls");
            for (i = 0; i < ja_adicionado; i++)
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
            gets(marca);
            fflush(stdin);
            system("cls");
            for (i = 0; i < ja_adicionado; i++)
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
            gets(modelo);
            fflush(stdin);
            system("cls");
            for (i = 0; i < ja_adicionado; i++)
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
}