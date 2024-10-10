#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
#define FI "FIAT"
#define VO "VOLKS"
#define TO "TOYOTA"
#define FO "FORD"
#define JE "JEEP"

typedef struct
{
    char *marca;
    char *modelo;
    char *placa;
    char *cambio;
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
void excluir();
void excluir_veiculo(char *placa);
void converter_para_maiusculas(char str[8]);

int main()
{
    int op;
    do
    {
        menu();
        __fpurge(stdin);
        scanf("%i", &op);
        opcao_menu(op);
    } while (op != 4);

    return 0;
}

void menu()
{
    printf("\n1- Adicionar veiculo\n");
    printf("\n2 - Visualizar veiculo\n");
    printf("\n3 - Excluir veiculo\n");
    printf("\n4 - Sair\n");
}
void opcao_menu(int op)
{
    int opm;
    char *placa = malloc(7 * sizeof(char));

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
        __fpurge(stdin);
        scanf("%i", &opm);
        visualizar_veiculo(opm);
    }
    else if (op == 3)
    {
        if (ja_adicionado <= 0)
        {
            messageError(2);
            return;
        }
        excluir();
        __fpurge(stdin);
        scanf("%s", placa);
        verificacao_placa(placa);
        converter_para_maiusculas(placa);
        excluir_veiculo(placa);
    }
}

void adicionar_veiculo()
{
    system("clear");
    if (ja_adicionado >= 200)
    {
        messageError(1);
        return;
    }

    carro[ja_adicionado].marca = malloc(20 * sizeof(char));
    carro[ja_adicionado].modelo = malloc(20 * sizeof(char));
    carro[ja_adicionado].placa = malloc(7 * sizeof(char));
    carro[ja_adicionado].cambio = malloc(10 * sizeof(char));

    printf("\nDigite a marca do veiculo: (Fiat, Volks, Ford, Toyota, Jeep)\n");
    __fpurge(stdin);
    scanf("%s", carro[ja_adicionado].marca);
    converter_para_maiusculas(carro[ja_adicionado].marca);

    printf("Digite o modelo do veiculo: (Polo, Argo, Corolla, Ranger, Renegade)\n");
    __fpurge(stdin);
    scanf("%s", carro[ja_adicionado].modelo);
    converter_para_maiusculas(carro[ja_adicionado].modelo);

    printf("Digite a placa do veiculo: (AAA0000, BBB1234)\n");
    __fpurge(stdin);
    scanf("%s", carro[ja_adicionado].placa);
    converter_para_maiusculas(carro[ja_adicionado].placa);

    printf("Digite o tipo de cambio do veiculo: (Manual, Automatico)\n");
    __fpurge(stdin);
    scanf("%s", carro[ja_adicionado].cambio);
    converter_para_maiusculas(carro[ja_adicionado].cambio);

    printf("Digite o motor do veiculo: (1.0, 1.4, 1.6, 1.8, 2.0)\n");
    __fpurge(stdin);
    scanf("%f", &carro[ja_adicionado].motor);

    ja_adicionado++;

    system("clear");
    printf("\nVeiculo adicionado com sucesso!\n");
}

void menu_visualizar_veiculo()
{
    system("clear");
    printf("\n1- Verificar todos\n");
    printf("\n2- Verificar por marca\n");
    printf("\n3- Verificar por modelo\n");
}
void visualizar_veiculo(int opm)
{
    char marca[20];
    char modelo[20];

    if (ja_adicionado <= 0)
    {
        messageError(1);
        return;
    }
    else if (opm == 1)
    {

        for (int i = 0; i < ja_adicionado; i++)
        {
            printf("\nMarca do veiculo %i: %s\n", i + 1, carro[i].marca);
            printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
            printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
            printf("\nMotor do veiculo %i: %.1f\n", i + 1, carro[i].motor);
            printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
        }
    }
    else if (opm == 2)
    {
        printf("\nDigite a marca:\n");
        __fpurge(stdin);
        scanf("%s", marca);
        converter_para_maiusculas(marca);

        for (int i = 0; i < ja_adicionado; i++)
        {
            if (strcmp(carro[i].marca, marca) == 0)
            {
                printf("\nInformacoes do veiculo %i com marca %s:\n", i + 1, carro[i].marca);
                printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
                printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
                printf("\nMotor do veiculo %i: %.1f\n", i + 1, carro[i].motor);
                printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
            }
        }
    }
    else if (opm == 3)
    {
        printf("\nDigite o modelo:\n");
        __fpurge(stdin);
        scanf("%s", modelo);
        converter_para_maiusculas(modelo);

        for (int i = 0; i < ja_adicionado; i++)
        {
            if (strcmp(carro[i].modelo, modelo) == 0)
            {
                printf("\nInformacoes do veiculo %i com modelo %s:", i + 1, carro[i].modelo);
                printf("\nMarca do veiculo %i: %s\n", i + 1, carro[i].marca);
                printf("\nModelo do veiculo %i: %s\n", i + 1, carro[i].modelo);
                printf("\nCambio do veiculo %i: %s\n", i + 1, carro[i].cambio);
                printf("\nMotor do veiculo %i: %.1f\n", i + 1, carro[i].motor);
                printf("\nPlaca do veiculo %i: %s\n", i + 1, carro[i].placa);
            }
        }
    }
}
void excluir_veiculo(char *placa)
{

    int encontrado = 0;

    for (int i = 0; i < ja_adicionado; i++)
    {
        if (strcmp(carro[i].placa, placa) == 0)
        {
            encontrado = 1;

            free(carro[i].marca);
            free(carro[i].cambio);
            free(carro[i].placa);
            free(carro[i].modelo);

            for (int j = i; j < ja_adicionado - 1; j++)
            {
                carro[j] = carro[j + 1];
            }

            ja_adicionado--;

            printf("\nVeiculo excluido com sucesso.\n");

            break;
        }
    }

    if (!encontrado)
    {
        messageError(3);
    }
}
void excluir()
{
    system("clear");
    printf("\nDigite a placa do veiculo:\n");
}
void converter_para_maiusculas(char str[8])
{
    for (int i = 0; i <= 8; i++)
    {
        str[i] = toupper(str[i]);
    }
}


void messageError(int erro)
{
    switch (erro)
    {
    case 0:
        system("clear");
        printf("\nErro. Opcao invalida.\n");
        break;
    case 1:
        system("clear");
        printf("\nLimite de veiculos atingido.\n");
        break;

    case 2:
        system("clear");
        printf("\nErro. Nenhum veiculo adicionado.\n");
        break;
    case 3:
        system("clear");
        printf("\nErro. Placa nao encontrada.\n");
        break;
    case 4:
        system("clear");
        printf("\nErro. Marca invalida.\n");
        break;
    case 5:
        system("clear");
        printf("\nErro. Placa invalida. Falta ou excede o tamanho de caracteres.\n");
        break;

    default:
        system("clear");
        printf("\nErro.\n");
        break;
    }
}
