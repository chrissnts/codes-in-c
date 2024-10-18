#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *rua;
    char *estado;
    char *cidade;
    int numero;
} Endereco;

typedef struct
{
    char *nome;
    int idade;
    char *cpf;
    Endereco endereco;
} Pessoa;

Pessoa *pessoa;
int numPessoas = 0;

void Menu();
void OpcaoMenu(int op);
int InlcuirPessoa();
void ImprimirPessoa(Pessoa p);
void ListarTodasPessoas();
void ListarCPF();
Pessoa CriaPessoa();

int main()
{
    pessoa = (Pessoa *)malloc(sizeof(Pessoa) * 5);
    int op;

    do
    {
        Menu();
        scanf("%i", &op);
        fflush(stdin);
        OpcaoMenu(op);
        system("pause");

    } while (op != 4);

    return 0;
}

void Menu()
{
    system("cls");
    printf("\n - (1) Incluir pessoa\n");
    printf("\n - (2) Lista todas pessoas\n");
    printf("\n - (3) Listar por CPF\n");
    printf("\n - (4) Sair\n");
}
void OpcaoMenu(int op)
{
    if (op < 4 || op > 1)
    {
        if (op == 1)
        {
            InlcuirPessoa();
        }
        else if (op == 2)
        {
            ListarTodasPessoas();
        }
        else if (op == 3)
        {
            ListarCPF();
        }
    }
}
Pessoa CriaPessoa()
{
    Pessoa p;

    p.nome = (char *)malloc(50 * sizeof(char));
    p.endereco.estado = (char *)malloc(20 * sizeof(char));
    p.endereco.cidade = (char *)malloc(20 * sizeof(char));
    p.endereco.rua = (char *)malloc(20 * sizeof(char));
    p.cpf = (char *)malloc(12 * sizeof(char));

    printf("\nNome da pessoa:\n");
    gets(p.nome);
    fflush(stdin);

    printf("\nIdade:\n");
    scanf("%i", &p.idade);
    fflush(stdin);

    printf("\nCPF:\n");
    gets(p.cpf);
    fflush(stdin);

    printf("\nEstado:\n");
    gets(p.endereco.estado);

    printf("\nCidade:\n");
    gets(p.endereco.cidade);

    printf("\nRua:\n");
    gets(p.endereco.rua);

    printf("\nNumero:\n");
    scanf("%i", &p.endereco.numero);

    return p;
}
int InlcuirPessoa()
{

    pessoa[numPessoas] = CriaPessoa();
    system("cls");
    ImprimirPessoa(pessoa[numPessoas++]);

    return 1;
}
void ImprimirPessoa(Pessoa pessoa)
{
    printf("\n- Nome: %s\n", pessoa.nome);
    printf("\n- Idade: %i\n", pessoa.idade);
    printf("\n- CPF: %s\n", pessoa.cpf);
    printf("\n- Estado: %s\n", pessoa.endereco.estado);
    printf("\n- Cidade: %s\n", pessoa.endereco.cidade);
    printf("\n- Rua: %s\n", pessoa.endereco.rua);
    printf("\n- Numero: %i\n", pessoa.endereco.numero);
}
void ListarTodasPessoas()
{
    int i;

    for (i = 0; i < numPessoas; i++)
    {
        printf("\n--- PESSOA [%i] ---\n", i + 1);
        ImprimirPessoa(pessoa[i]);
    }
}
void ListarCPF()
{
    char *cpf;
    int i;
    cpf = (char *)malloc(12 * sizeof(char));

    printf("\nDigite o CPF que deseja buscar:\n");
    gets(cpf);
    fflush(stdin);
    for ( i = 0; i < numPessoas; i++)
    {
        if (strcmp(pessoa[i].cpf, cpf) == 0)
        {
            ImprimirPessoa(pessoa[i]);
            return;
        }
        else
        {   
            system("cls");
            printf("\nCPF nao encontrado.\n");
            system("pause");
        }
    }
}
