#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLOCAL 100
#define MAXAMIGO 100

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
    int numero;

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

// COISAS QUE TALVEZ MODIFIQUE.
// 1- COLOCAR UM MENU PARA DELETAR 1 OU TODOS (SE FOR 1, TALVEZ POR APELIDO.)
// 2- ADICIONAR MENU PARA MODIFICAR TUDO OU APENAS UMA PARTE, TEREI QUE FAZER UMA OPCAO PARA CADA PROVAVELMENTE.

void MenssagemErro(int erro);                 // imprime mensagens de erro;
void Menu();                                  // imprime menu principal;
void MenuAmigo();                             // imprime menu amigo;
void MenuLocal();                             // imprime menu local;
void MenuCategoria();                         // imprime menu categoria;
void MenuEncontro();                          // imprime menu encontro;
void MenuRelatorio();                         // imprime menu relatorio;
void MenuRelatorioListarAmigos();             // menu para perguntar se sera listados todos ou especifico por apelido;
void MenuRelatorioListarLocais();             // menu para perguntar se sera listados todos ou especifico;
void OpcaoMenu(int op);                       // recebe opcao do menu e faz a validacao e procede;
void OpcaoMenuAmigo(int op);                  // recebe opcao do menu de amigos e faz validacao e procede;
void OpcaoMenuLocal(int op);                  // recebe opcao do menu de local e faz validacao e procede;
void OpcaoMenuRelatorio(int op);               // recebe opcao do menu de relatorios e faz validacao e procede;
void OpcaoMenuRelatorioListarAmigos(int opr); // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarLocais(int opr); // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void ImprimirAmigos(Amigo amigos);            // imprime amigos;
void ImprimirLocais(Local locais);            // imprime locais;
void AlternarAmigos(int amigo);               // modifica os dados do amigo na hora de alternar;
void ExcluirAmigos(int amigo);                // dispara qual amigo o usuario deseja excluir;
void ReorganizarAmigos(int amigo);            // reorganiza todos os amigos com base no amigo excluido;
void LimpaPonteiroAmigo (Amigo *amigo);       // limpa o ponteiro de amigos; 
void LimpaPonteiroLocal (Local *local);       // limpa o ponteiro de locais;

int IncluirAmigos();                        // inclui na funcao o amigo criado na funcao "cria amigo";
int IncluirLocal();                         // inclui na funcao o local criado na funcao "cria local";
int ValidarData(int dia, int mes, int ano); // valida data que o usuario digitar;
int ListarAmigos();                         // lista os amigos que ja estao cadastrados;
int ListarLocais();                         // lista os locais que ja estao cadastrados;
int ListarAmigosPorApelido();               // faz a logica de listar amigo por apelido;
int ModificarAmigos();                      // alterar amigo;
int Bissexto(int ano);                      // verifica se o ano eh bissexto para poder arrumar dias e mes

Amigo CriaAmigo(); // funcao para criar um amigo;
Local CriaLocal(); // funcao para criar um local;

Amigo *Amigos;
Local *Locais;
int NumAmigos = 0, NumLocais = 0;

int main()
{

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
    case -5:
        system("cls");
        printf("\nErro. Quantidade de locais cheia.\n");
        break;
    case -6:
        system("cls");
        printf("\nErro. Locais vazio.\n");
        break;
    case -10:
        system("cls");
        printf("\nErro. Alocacao de memoria fracassada.\n");
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
            OpcaoMenuLocal(opm);
        }
        else if (op == 3)
        {
            // categoria;
        }
        else if (op == 4)
        {
            // encontro;
        }
        else if (op == 5)
        {
            MenuRelatorio();
            scanf("%i", &opm);
            fflush(stdin);
            OpcaoMenuRelatorio(opm);
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
void MenuRelatorioListarLocais()
{
    system("cls");
    printf("\n1. Listar todos\n");
    printf("\n2. Listar por estado\n");
    printf("\n3. Listar por cidade\n");
    printf("\n4. Listar por bairro\n");
}
Amigo CriaAmigo()
{

    Amigo amigo;

    int erro = -1;
    char strAux[100];

    printf("\nNome:\n");
    gets(strAux);
    amigo.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.nome, strAux);
    fflush(stdin);

    printf("\nApelido:\n");
    gets(strAux);
    amigo.apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.apelido, strAux);
    fflush(stdin);

    printf("\nEmail:\n");
    gets(strAux);
    amigo.email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.email, strAux);
    fflush(stdin);

    printf("\nTelefone:\n");
    gets(strAux);
    amigo.telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.telefone, strAux);
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
Local CriaLocal()
{
    Local local;
    char strAux[100];

    printf("\nNome do encontro:\n");
    gets(strAux);
    local.nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.nome_encontro, strAux);
    fflush(stdin);

    printf("\nEstado:\n");
    gets(strAux);
    local.endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.estado, strAux);
    fflush(stdin);

    printf("\nCidade:\n");
    gets(strAux);
    local.endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.cidade, strAux);
    fflush(stdin);

    printf("\nBairro:\n");
    gets(strAux);
    local.endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.bairro, strAux);
    fflush(stdin);

    printf("\nLogradouro:\n");
    gets(strAux);
    local.endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.logradouro, strAux);
    fflush(stdin);

    printf("\nNumero:\n");
    scanf("%i", &local.endereco.numero);
    fflush(stdin);

    return local;
}
int IncluirAmigos()
{
    if (NumAmigos >= MAXAMIGO)
    {
        return -1;
    }

    if (NumAmigos == 0)
    {
        Amigos = (Amigo *)malloc(1 * sizeof(Amigo));
    }
    else
    {
        Amigos = (Amigo *)realloc(Amigos, (NumAmigos + 1) * sizeof(Amigo));
    }

    if (!Amigos)
    {
        return -10;
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
int IncluirLocal()
{
    if (NumLocais >= MAXLOCAL)
    {
        return -5;
    }

    if (NumLocais == 0)
    {
        Locais = (Local *)malloc(1 * sizeof(Local));
    }
    else
    {
        Locais = (Local *)realloc(Locais, (NumLocais + 1) * sizeof(Local));
    }

    if (!Locais)
    {
        return -10;
    }

    Locais[NumLocais] = CriaLocal();
    system("cls");
    ImprimirLocais(Locais[NumLocais]);
    NumLocais++;

    return 1;
}
void OpcaoMenuAmigo(int op)
{
    int erro = -1;

    // TEM QUE ARRUMA PARA DAR UM JEITO DE VOLTAR PARA O MENU DE AMIGOS CASO OPCAO SEJA INVALIDA!!!!!!!
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
            erro = ModificarAmigos();
        }
        else if (op == 3)
        {
            erro = DeletarAmigos();
        }

        if (erro <= 0)
        {
            MenssagemErro(erro);
        }
    }
    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}
void OpcaoMenuLocal(int op)
{
    int erro;

    // TEM QUE ARRUMA PARA DAR UM JEITO DE VOLTAR PARA O MENU DE LOCAL CASO OPCAO SEJA INVALIDA!!!!!!!
    if (op < 1 || op > 3)
    {
        MenssagemErro(0);
    }
    else if (op <= 3)
    {
        if (op == 1)
        {
            erro = IncluirLocal();
        }
        else if (op == 2)
        {
            // modificar local;
        }
        else if (op == 3)
        {
            // deletar local;
        }

        if (erro <= 0)
        {
            MenssagemErro(erro);
        }
    }
}
void OpcaoMenuRelatorio(int op)
{
    int opr;
    int erro;

    // TEM QUE ARRUMA PARA DAR UM JEITO DE VOLTAR PARA O MENU DE RELATORIO CASO OPCAO SEJA INVALIDA (IGUAL NO DE AMIGOS)!!!!!!!
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
            if (NumAmigos <= 0)
            {
                erro = -3;
                // TESTAR RETURN ;
                return;
                
            }
            OpcaoMenuRelatorioListarAmigos(opr);
        }
        else if (op == 2)
        {
            MenuRelatorioListarLocais();
            scanf("%i", &opr);
            fflush(stdin);
            if (NumLocais <= 0)
            {
                erro = -6;
                // TESTAR RETURN;
                return;
                
            }    
            OpcaoMenuRelatorioListarLocais(opr);
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
        if (erro <= 0)
        {
            MenssagemErro(erro);
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
        erro = ListarAmigosPorApelido();
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}
void OpcaoMenuRelatorioListarLocais(int opr)
{
    int erro;

    if (opr < 1 || opr > 2)
    {
        MenssagemErro(0);
    }

    if (opr == 1)
    {
        // lista todos;
        erro = ListarLocais();
    }
    else if (opr == 2)
    {
        // lista por estado;
    }
    else if (opr == 3)
    {
        // lista por cidade;
    }
    else if (opr == 4)
    {
        // listar por bairro;
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}

void ImprimirLocais(Local locais)
{
    printf("\nNome do encontro: %s\n", locais.nome_encontro);
    printf("\nEstado: %s \n", locais.endereco.estado);
    printf("\nCidade: %s\n", locais.endereco.cidade);
    printf("\nBairro: %s\n", locais.endereco.bairro);
    printf("\nLogradouro: %s\n", locais.endereco.logradouro);
    printf("\nNumero: %i\n", locais.endereco.numero);
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
int ListarLocais()
{
    int i;

    if (NumLocais <= 0)
    {
        return -6;
    }

    system("cls");
    for (i = 0; i < NumLocais; i++)
    {
        printf("\n");
        printf("\n-- Local [Numero %i] --\n", i + 1);
        ImprimirLocais(Locais[i]);
    }

    return 1;
}

// ARRUMAR CODIGO!!!!!!!! TODA VEZ QUE COLOCA APELIDO INVALIDO RETORNA -4, MAS TAMBEM RETORNA 0 LOGO DEPOIS!!
int ListarAmigosPorApelido()
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

void AlternarAmigos(int amigo)
{
    int erro = -1;
    char strAux[100];

    // Modifica o amigo que o usuario escolheu, no caso na mesma posicao que estava o anterior;

    printf("\nNome:\n");
    gets(strAux);
    if (Amigos[amigo].nome != NULL) 
    {
        free(Amigos[amigo].nome);
    }

    Amigos[amigo].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].nome == NULL) 
    {
        MenssagemErro(-10);
        return; 
    }
    strcpy(Amigos[amigo].nome, strAux);
    fflush(stdin);

    printf("\nApelido:\n");
    gets(strAux);
    if (Amigos[amigo].apelido != NULL) 
    {
        free(Amigos[amigo].apelido);
    }

    Amigos[amigo].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].apelido == NULL) 
    {
        MenssagemErro(-10);
        return; 
    }
    strcpy(Amigos[amigo].apelido, strAux);
    fflush(stdin);

    printf("\nEmail:\n");
    if (Amigos[amigo].email != NULL) 
    {
        free(Amigos[amigo].email);
    }

    Amigos[amigo].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].email == NULL) 
    {
        MenssagemErro(-10);
        return; 
    }
    strcpy(Amigos[amigo].email, strAux);
    fflush(stdin);

    printf("\nTelefone:\n");
    gets(strAux);
    if (Amigos[amigo].telefone != NULL) 
    {
        free(Amigos[amigo].telefone);
    }

    Amigos[amigo].telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].telefone == NULL) 
    {
        MenssagemErro(-10);
        return; 
    }
    strcpy(Amigos[amigo].telefone, strAux);
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
int ModificarAmigos()
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
            return -4;
        }
        else
        {
            AlternarAmigos(amigo);
        }
    }
    system("cls");
    ImprimirAmigos(Amigos[amigo]);

    return 1;
}

int DeletarAmigos()
{
    int amigo = -1;

    if (NumAmigos <= 0)
    {
        return -3;
    }
    ListarAmigos();
    printf("\nSelecione o amigo que deseja deletar: [ %i - %i]:", 1, NumAmigos);
    scanf("%i", &amigo);
    fflush(stdin);
    amigo--;

    if (amigo < 0 || amigo >= NumAmigos)
    {
       return -4;
    }
    else
    {
        ExcluirAmigos(amigo);
    }
    system("cls");
    printf("\nExclusao bem sucedida.\n");

    return 1;
}
void ExcluirAmigos(int amigo)
{
    // exclui um unico amigo que tiver
    if (NumAmigos == 1)
    {
        LimpaPonteiroAmigo(&Amigos[amigo]);
        NumAmigos--;
    } 
    else if (amigo >= 0 && amigo < NumAmigos)
    {
        // exclui e reorganiza se houver mais de um amigo
        LimpaPonteiroAmigo(&Amigos[amigo]);
        ReorganizarAmigos(amigo);
    }
   
}
void ReorganizarAmigos(int amigo)
{
    int i;

    for (i = amigo; i < NumAmigos - 1; i++)
    {
        Amigos[i] = Amigos[i + 1];
    }
    NumAmigos--;
}
void LimpaPonteiroAmigo(Amigo *amigo) 
{
    free(amigo->nome);
    free(amigo->apelido);
    free(amigo->email);
    free(amigo->telefone);
}

void LimpaPonteiroLocal(Local *local) 
{
    free(local->nome_encontro);
    free(local->endereco.logradouro);
    free(local->endereco.bairro);
    free(local->endereco.cidade);
    free(local->endereco.estado);
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
