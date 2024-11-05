#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 20
#define MAXAMIGO 100
#define TAMEMAIL 50

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

void MenssagemErro(int erro);               // imprime mensagens de erro;
void Menu();                                // imprime menu principal;
void MenuAmigo();                           // imprime menu amigo;
void MenuLocal();                           // imprime menu local;
void MenuCategoria();                       // imprime menu categoria;
void MenuEncontro();                        // imprime menu encontro;
void MenuRelatorio();                       // imprime menu relatorio;
void OpcaoMenu(int op);                     // recebe opcao do menu e faz a validacao e procede;
void OpcaoMenuAmigo(int op);                // recebe opcao do menu de amigos e faz validacao e procede;
void ImprimirAmigos(Amigo amigos);          // imprime amigos;
int IncluirAmigo();                         // inclui na funcao o amigo criado na funcao "cria amigo";
int ValidarData(int dia, int mes, int ano); // valida data que o usuario digitar;
int Bissexto(int ano);                      // verifica se o ano eh bissexto para poder arrumar dias e mes

Amigo CriaAmigo(); // funcao para criar um amigo;

Amigo *Amigos;
int num_amigos = 0;

int main()
{
    Amigos = (Amigo *)malloc(MAXAMIGO * sizeof(Amigo));

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
        system("cls");
        printf("\nErro. Opcao invalida.\n");
        break;
    case -1:
        system("cls");
        printf("\nErro. Quantidade de amigos cheia.\n");
        break;
    case -2:
        system("cls");
        printf("\nErro. Dia, Mes ou ano invalido.\n");
        break;

    default:
        system("cls");
        printf("\nErro.\n");
        break;
    }
}

void Menu()
{
    system("cls");
    printf("\n1. Manter amigo\n");
    printf("\n2. Manter local\n");
    printf("\n3. Manter categoria\n");
    printf("\n4. Manter encontro\n");
    printf("\n5. Relatorios\n");
    printf("\n6. Sair\n");
}
void OpcaoMenu(int op)
{
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
            OpcaoMenuAmigo(opm);
        }
        else if (op == 2)
        {
            MenuLocal();
            scanf("%i", &opm);
        }
        else if (op == 3)
        {
            MenuCategoria();
            scanf("%i", &opm);
        }
        else if (op == 4)
        {
            MenuEncontro();
            scanf("%i", &opm);
        }
        else if (op == 5)
        {
        }
        else if (op == 6)
        {
            exit(0);
        }
    }
}
void MenuAmigo()
{

    system("cls");
    printf("\n1. Cadastrar Amigo\n");
    printf("\n2. Modificar Amigo\n");
    printf("\n3. Excluir Amigo\n");
}
void MenuLocal()
{

    system("cls");
    printf("\n1. Cadastrar Local\n");
    printf("\n2. Modificar Local\n");
    printf("\n3. Excluir Local\n");
}
void MenuCategoria()
{

    system("cls");
    printf("\n1. Cadastrar Categoria\n");
    printf("\n2. Modificar Categoria\n");
    printf("\n3. Excluir Categoria\n");
}
void MenuEncontro()
{

    system("cls");
    printf("\n1. Cadastrar Encontro\n");
    printf("\n2. Modificar Encontro\n");
    printf("\n3. Excluir Encontro\n");
}
void MenuRelatorio()
{
    system("cls");
    printf("\n1. Listar Amigos\n");
    printf("\n2. Listar Locais\n");
    printf("\n3. Listar Categorias\n");
    printf("\n3. Listar Encontros\n");
    printf("\n3. Relatorio por Categoria\n");
}
void OpcaoMenuAmigo(int op)
{
    int erro;

    // DAR UM JEITO DE VOLTAR PARA O MENU DE AMIGOS!!!!!!!
    if (op < 1 || op > 3)
    {
        MenssagemErro(0);
        
    }
    else if (op <= 3)
    {
        if (op == 1)
        {
            erro = IncluirAmigo();
        }
        else if (op == 2)
        {
        }
        else if (op == 3)
        {
        }

        if (erro <= 0)
        {
            MenssagemErro(erro);
        }
    }
}

Amigo CriaAmigo()
{
    Amigo amigo;

    int erro = -1;

    amigo.nome = (char *)malloc(TAMMAX * sizeof(char));
    amigo.apelido = (char *)malloc(TAMMAX * sizeof(char));
    amigo.telefone = (char *)malloc(TAMMAX * sizeof(char));
    amigo.email = (char *)malloc(TAMEMAIL * sizeof(char));

    printf("\nNome:\n");
    gets(amigo.nome);
    fflush(stdin);

    printf("\nApelido:\n");
    gets(amigo.apelido);
    fflush(stdin);

    printf("\nEmail:\n");
    gets(amigo.email);
    fflush(stdin);

    printf("\nTelefone:\n");
    gets(amigo.telefone);
    fflush(stdin);

    while (erro < 0)
    {

        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &amigo.datanasc.dia, &amigo.datanasc.mes, &amigo.datanasc.ano);
        fflush(stdin);
        erro = ValidarData(amigo.datanasc.dia, amigo.datanasc.mes, amigo.datanasc.ano);

        if (erro < 0)
        {
            MenssagemErro(erro);
        }
    }

    return amigo;
}
int IncluirAmigo()
{
    if (num_amigos >= MAXAMIGO)
    {
        return -1;
    }

    Amigos[num_amigos] = CriaAmigo();
    system("cls");
    ImprimirAmigos(Amigos[num_amigos++]);

    return 1;
}
void ImprimirAmigos(Amigo amigos)
{
    system("cls");
    printf("\n- Nome: %s\n", amigos.nome);
    printf("\n- Apelido: %s\n", amigos.apelido);
    printf("\n- Email: %s\n", amigos.email);
    printf("\n- Telefone: %s\n", amigos.telefone);
    printf("\n- Data Nascimento: [%i/%i/%i]\n", amigos.datanasc.dia, amigos.datanasc.mes, amigos.datanasc.ano);
}

int Bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int ValidarData(int dia, int mes, int ano)
{

    if (ano < 1980)
    {
        return -2;
    }

    if (mes < 1 || mes > 12)
    {
        return -2;
    }

    // Número de dias em cada mês
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajusta para anos bissextos
    if (Bissexto(ano))
    {
        diasNoMes[2] = 29; // fevereiro tem 29 dias em ano bissexto
    }

    if (dia < 1 || dia > diasNoMes[mes])
    {
        return -2;
    }

    return 1;
}