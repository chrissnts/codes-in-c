#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 20
#define MAXAMIGO 100
#define TAMEMAIL 50
#define TAMTELE 10

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

void MenssagemErro(int erro);                 // imprime mensagens de erro;
void Menu();                                  // imprime menu principal;
void MenuAmigo();                             // imprime menu amigo;
void MenuLocal();                             // imprime menu local;
void MenuCategoria();                         // imprime menu categoria;
void MenuEncontro();                          // imprime menu encontro;
void MenuRelatorio();                         // imprime menu relatorio;
void MenuRelatorioListarAmigos();             // menu para perguntar se sera listados todos ou especifico por apelido;
void OpcaoMenu(int op);                       // recebe opcao do menu e faz a validacao e procede;
void OpcaoMenuAmigo(int op);                  // recebe opcao do menu de amigos e faz validacao e procede;
int OpcaoMenuRelatorio(int op);               // recebe opcao do menu de relatorios e faz validacao e procede;
void OpcaoMenuRelatorioListarAmigos(int opr); // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void ImprimirAmigos(Amigo amigos);            // imprime amigos;
void ModificarAmigos(int amigo);              // modifica os dados do amigo na hora de alternar;
int IncluirAmigos();                          // inclui na funcao o amigo criado na funcao "cria amigo";
int ValidarData(int dia, int mes, int ano);   // valida data que o usuario digitar;
int ListarAmigos();                           // lista os amigos que ja estao cadastrados;
int ListarAmigoPorApelido();                  // faz a logica de listar amigo por apelido;
int AlternarAmigos();                         // alterar amigo;

int Bissexto(int ano); // verifica se o ano eh bissexto para poder arrumar dias e mes

Amigo CriaAmigo(); // funcao para criar um amigo;

Amigo *Amigos;
int NumAmigos = 0;

int main()
{
    Amigos = (Amigo *)malloc(MAXAMIGO * sizeof(Amigo));

    int op = 0;

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
        // system("cls");
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
    case -3:
        system("cls");
        printf("\nErro. Amigos Vazios.\n");
        break;
    case -4:
        system("cls");
        printf("\nErro. Amigo invalido.\n");
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
    int erro;

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
            OpcaoMenuAmigo(opm);
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
            MenuRelatorio();
            scanf("%i", &opm);
            fflush(stdin);
            erro = OpcaoMenuRelatorio(opm);
        }
        if (erro <= 0)
        {
            MenssagemErro(erro);
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
    printf("\n4. Listar Encontros\n");
    printf("\n5. Relatorio por Categoria\n");
    printf("\n6. Voltar\n");
}
void MenuRelatorioListarAmigos()
{
    system("cls");
    printf("\n1. Listar todos\n");
    printf("\n2. Buscar por apelido\n");
}
void OpcaoMenuAmigo(int op)
{
    int erro;

    // TEM QUE ARRUMA PARA DAR UM JEITO DE VOLTAR PARA O MENU DE AMIGOS CASO OPCOA SEJA INVALIDA!!!!!!!
    if (op < 1 || op > 3)
    {
        MenssagemErro(0);
    }
    else if (op <= 3)
    {
        if (op == 1)
        {
            erro = IncluirAmigos();
        }
        else if (op == 2)
        {
            erro = AlternarAmigos();
        }
        else if (op == 3)
        {
            //FAZER A LOGICA PARA DELETAR AMIGOSS;
        }

        if (erro <= 0)
        {
            MenssagemErro(erro);
        }
    }
}
int OpcaoMenuRelatorio(int op)
{
    int opr;

    if (NumAmigos <= 0)
    {
        return -3;
    }

    // TEM QUE ARRUMA PARA DAR UM JEITO DE VOLTAR PARA O MENU DE RELATORIO CASO OPCOA SEJA INVALIDA (IGUAL NO DE AMIGOS)!!!!!!!
    if (op < 1 || op > 2)
    {
        MenssagemErro(0);
    }
    else if (op <= 2)
    {
        if (op == 1)
        {
            MenuRelatorioListarAmigos();
            scanf("%i", &opr);
            fflush(stdin);
            OpcaoMenuRelatorioListarAmigos(opr);
        }
        else if (op == 2)
        {
            // LOGICA PARA LISTAR LOCAIS;
        }
        else if (op == 3)
        {
            // LOGICA PARA LISTAR CATEGORIAS;
        }
        else if (op == 4)
        {
            // LOGICA PARA LISTAR ENCONTROS;
        }
        else if (op == 5)
        {
            // LOGICA PARA RELATORIO DE CATEGORIA;
        }
        else if (op == 6)
        {
            // LOGICA PARA SAIR;
        }
    }
}

void OpcaoMenuRelatorioListarAmigos(int opr)
{
    int erro;

    if (opr < 1 || opr > 2)
    {
        MenssagemErro(0);
    }

   
    if (opr == 1)
    {   
        // lista todos;
        erro = ListarAmigos();
    }
    else if (opr == 2)
    {
        // lista por apelido que o usuario digitar;
        erro = ListarAmigoPorApelido();
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}

Amigo CriaAmigo()
{
    Amigo amigo;

    int erro = -1;

    amigo.nome = (char *)malloc(TAMMAX * sizeof(char));
    amigo.apelido = (char *)malloc(TAMMAX * sizeof(char));
    amigo.telefone = (char *)malloc(TAMTELE * sizeof(char));
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
        // força o usuario digitar data de nascimento seguindo os parametros de data
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
int IncluirAmigos()
{
    if (NumAmigos >= MAXAMIGO)
    {
        return -1;
    }

    Amigos[NumAmigos] = CriaAmigo();
    system("cls");
    ImprimirAmigos(Amigos[NumAmigos]);
    NumAmigos++;

    return 1;
}
void ImprimirAmigos(Amigo amigos)
{
    printf("\n- Nome: %s\n", amigos.nome);
    printf("\n- Apelido: %s\n", amigos.apelido);
    printf("\n- Email: %s\n", amigos.email);
    printf("\n- Telefone: %s\n", amigos.telefone);
    printf("\n- Data Nascimento: [%i/%i/%i]\n", amigos.datanasc.dia, amigos.datanasc.mes, amigos.datanasc.ano);
}

int ListarAmigos()
{
    int i;

    if (NumAmigos <= 0)
    {
        return -3;
    }

    system("cls");
    for (i = 0; i < NumAmigos; i++)
    {
        printf("\n");
        printf("\n-- Amigo [Numero %i] --\n", i + 1);
        ImprimirAmigos(Amigos[i]);
    }

    return 1;
}

// ARRUMAR CODIGO!!!!!!!! TODA VEZ QUE COLOCA APELIDO INVALIDO RETORNA -4, MAS TAMBEM RETORNA 0 LOGO DEPOIS!!
int ListarAmigoPorApelido()
{
    char *apelido;
    int i;
    apelido = (char *)malloc(15 * sizeof(char));

    printf("\nDigite o apelido do amigo:");
    gets(apelido);
    fflush(stdin);

    for (i = 0; i < NumAmigos; i++)
    {
        if (strcmp(Amigos[i].apelido, apelido) == 0)
        {
            ImprimirAmigos(Amigos[i]);
            return 1;
        }
    }
    return -4;
}
void ModificarAmigos(int amigo)
{
    int erro = -1;

    // Modifica o amigo que o usuario escolheu, no caso na mesma posicao que estava o anterior;

    printf("\nNome:\n");
    gets(Amigos[amigo].nome);
    fflush(stdin);

    printf("\nApelido:\n");
    gets(Amigos[amigo].apelido);
    fflush(stdin);

    printf("\nEmail:\n");
    gets(Amigos[amigo].email);
    fflush(stdin);

    printf("\nTelefone:\n");
    gets(Amigos[amigo].telefone);
    fflush(stdin);

    while (erro < 0)
    {
        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &Amigos[amigo].datanasc.dia, &Amigos[amigo].datanasc.mes, &Amigos[amigo].datanasc.ano);
        fflush(stdin);
        erro = ValidarData(Amigos[amigo].datanasc.dia, Amigos[amigo].datanasc.mes, Amigos[amigo].datanasc.ano);

        if (erro < 0)
        {
            MenssagemErro(erro);
        }
    }
}
int AlternarAmigos()
{

    int amigo = -1;

    if (NumAmigos <= 0)
    {
        return -3;
    }

    while (amigo < 0 || amigo >= NumAmigos)
    {
        ListarAmigos();
        printf("\nSelecione o amigo que deseja modificar: [ %i - %i]:", 1, NumAmigos);
        scanf("%i", &amigo);
        fflush(stdin);
        amigo--;

        if (amigo < 0 || amigo >= NumAmigos)
        {
            MenssagemErro(-4);
        }
        else
        {
            ModificarAmigos(amigo);
        }
    }
    system("cls");
    ImprimirAmigos(Amigos[amigo]);

    return 1;
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