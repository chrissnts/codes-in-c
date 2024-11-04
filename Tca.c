#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 20

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct
{
    int hora;
    int minuto;

} Hora;

typedef struct
{
    char *logradouro;
    char *bairro;
    char *cidade;
    char *estado;

} Endereco;

typedef struct
{
    char *nome_encontro;
    Endereco endereco;
} Local;

typedef struct
{
    char *nome;
    char *apelido;
    char *email;
    Data datanasc;
    char *telefone;

} Amigo;

typedef struct
{
    char *nome;
} Categoria;

typedef struct
{
    Data data;
    Hora horario;
    Amigo amigos;
    Categoria categoria;
    char *descricao;

} Encontro;

void MenssagemErro(int erro); // imprime mensagens de erro;
void Menu();             // imprime menu principal;
void MenuAmigo();        // imprime menu amigo;
void MenuLocal();        // imprime menu local;
void MenuCategoria();    // imprime menu categoria;
void MenuEncontro();     // imprime menu encontro;
void OpcaoMenu(int op);  // recebe opcao do menu e faz a validacao;

int main()
{
    int op = 1;

    while (op != 6)
    {

        Menu();
        scanf("%i", &op);
        fflush(stdin);
        OpcaoMenu(op);
        system("pause");
    }

    return 0;
}

void MenssagemErro(int erro)
{
    switch (erro)
    {
    case 0:
        system("clear");
        printf("\nErro. Opcao invalida.\n");
        break;
    default:
        system("clear");
        printf("\nErro.\n");
        break;
    }
}

void Menu()
{
    system("clear");
    printf("\n1. Manter amigo\n");
    printf("\n2. Manter local\n");
    printf("\n3. Manter categoria\n");
    printf("\n4. Manter encontro\n");
    printf("\n5. Relatorios\n");
    printf("\n6. Sair\n");
}
void OpcaoMenu(int op)
{
    int erro;
    int opm;

    if (op < 1 || op > 6)
    {
        MenssagemErro(0);
    }
    else if (op < 6)
    {

        if (op == 1)
        {
            MenuAmigo();
            scanf("%i", &opm);
            fflush(stdin);
        }
        else if (op == 2)
        {
            MenuLocal();
            scanf("%i", &opm);
            fflush(stdin);
        }
        else if (op == 3)
        {
            MenuCategoria();
            scanf("%i", &opm);
            fflush(stdin);
        }
        else if (op == 4)
        {
            MenuEncontro();
            scanf("%i", &opm);
            fflush(stdin);
        }
        else if (op == 5)
        {
        }
        else if (op == 6)
        {
            exit(0);
        }

        if (erro <= 0)
        {
            MenssagemErro(erro);
        }
    }
}
void MenuAmigo()
{

    system("clear");
    printf("\n1. Cadastrar Amigo\n");
    printf("\n2. Modificar Amigo\n");
    printf("\n3. Excluir Amigo\n");
}
void MenuLocal()
{

    system("clear");
    printf("\n1. Cadastrar Local\n");
    printf("\n2. Modificar Local\n");
    printf("\n3. Excluir Local\n");
}
void MenuCategoria()
{

    system("clear");
    printf("\n1. Cadastrar Categoria\n");
    printf("\n2. Modificar Categoria\n");
    printf("\n3. Excluir Categoria\n");
}
void MenuEncontro()
{

    system("clear");
    printf("\n1. Cadastrar Encontro\n");
    printf("\n2. Modificar Encontro\n");
    printf("\n3. Excluir Encontro\n");
}
