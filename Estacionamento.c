#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 200

typedef struct
{
    char marca[20];
    char modelo[20];
    float motor;
    char cambio[10];
    char placa[7];

} veiculo;

veiculo carros[TAM];

void menu();
void opcao_menu(int op);
void mensagemError(int codigoErro);
void adicionar_veiculo();
int verificar_veiculo();
void vizualiar_veiculo(int aux, int ja_adicionado);

int main()
{

    int op = -1, i, aux;
    int ja_adicionado = 0;
    char modelo[20];

    while (op != 4)
    {
        menu();
        scanf("%i", &op);
        fflush(stdin);
        system("cls");
        opcao_menu(op);

        if (op == 1)
        {

            adicionar_veiculo(&ja_adicionado);
        }
        else if (op == 2)
        {
            // Verificar veiculos (e escolher a verificação)
            aux = verificar_veiculo();
            vizualiar_veiculo(aux, ja_adicionado);
        }
        else if (op == 3)
        {
            // Comparar as duas strings
            printf("\nDigite o modelo que deseja ver as informacoes:\n");
            fflush(stdin);
            gets(modelo);
            for (i = 0; i < ja_adicionado; i++)
            {
                if (strcmp(carros[i].modelo, modelo) == 0)
                {
                    // Exibir dados do veículo pelo modelo
                }
            }
        }
    
    }

    return 0;
}

void menu()
{
    system("cls");
    printf("\n");
    printf("1 - Adicionar carro\n");
    printf("2 - Visualizar veiculos\n");
    printf("3 - Remocao do veiculo\n");
    printf("4 - Sair\n");
}
void opcao_menu(int op)
{
    if (op < 1 || op > 4)
    {
        mensagemError(0);
    }
}
void adicionar_veiculo(int *ja_adicionado)
{
    int i;
    for (i = *ja_adicionado + 1; i < *ja_adicionado; i++) 
    {
        printf("\nDigite a marca do carro (Fiat, Volks, Ford, Toyota, Jeep):\n");
        scanf("%s", carros[i].marca);
        printf("\nDigite o modelo do carro (Polo, Argo, Corolla, Ranger, Renegade):\n");
        scanf("%s", carros[i].modelo);
        printf("\nDigite o motor (1.0, 1.4, 1.6, 1.8, 2.0):\n");
        scanf("%f", &carros[i].motor);
        printf("\nDigite o cambio (Manual, Automatico):\n");
        scanf("%s", carros[i].cambio);
        printf("\nDigite a placa do veiculo (AAA0000):\n");
        scanf("%s", carros[i].placa);
    }
}
int verificar_veiculo()
{
    int aux;
    system("cls");
    printf("\n");
    printf("\nEscolha uma das opcoes abaixo:\n");
    printf("1 - Vizualizar todos os veiculos\n");
    printf("2 - Visualizar veiculos por marca\n");
    printf("3 - Visualizar veiculos por modelo\n");
    scanf("%i", &aux);
    return aux;
}
void vizualiar_veiculo(int aux, int ja_adicionado)
{
    char marca[20];

    if (aux == 1)
    {
        for (int i = 0; i < ja_adicionado; i++)
        {
            printf("\nMarca do carro %i: %s\n", i + 1, carros[i].marca);
            printf("Modelo do carro %i: %s\n", i + 1, carros[i].modelo);
            printf("Cambio do carro %i: %s\n", i + 1, carros[i].cambio);
            printf("Placa do carro %i: %s\n", i + 1, carros[i].placa);
            printf("Motor do carro %i: %.2f\n", i + 1, carros[i].motor);
        }
    }
    else if (aux == 2)
    {
        // Comparar as duas strings
        printf("\nDigite a marca que deseja ver as informacoes:\n");
        fflush(stdin);
        scanf("%s", marca);

        int encontrou = 0; 

        for (int i = 0; i < ja_adicionado; i++)
        {    
            // Comparar strings 
            if (strcmp(carros[i].marca, marca) == 0)
            {
                // Exibir dados do veículo pela marca
                printf("\nMarca do carro %i: %s\n", i + 1, carros[i].marca);
                printf("\nModelo do carro %i: %s\n", i + 1, carros[i].modelo);
                printf("\nCambio do carro %i: %s\n", i + 1, carros[i].cambio);
                printf("\nPlaca do carro %i: %s\n", i + 1, carros[i].placa);
                printf("\nMotor do carro %i: %.2f\n", i + 1, carros[i].motor);

                // Marca encontrada
                encontrou = 1; 
            }
        }

        if (!encontrou)
        {
            // Exibir mensagem de erro se a marca não foi encontrada
            mensagemError(1);
        }
    }
}


void mensagemError(int codigoErro)
{
    switch (codigoErro)
    {
    case 0:
        printf("ERRO: Opcao Invalida!!!\n");
        break;

    case 1:
        printf("ERRO: Marca invalida!!\n");

    default:
        printf("ERRO!!!\n");
        break;
    }
}
