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
// 3- FAZER ALTERAÇÕES DO PAUSE, POR EXEMPLO, CRIAR UMA FUNCAO PARA VERIFICAR SE O PAUSE EH TRUE OU FALSE, SE FOR PAUSAR SE NAO FOR PASSAR DIRETO.
// 4- FAZER UMA VERIFICACAO SE AMIGO, E ETC JA EXISTE NA HORA DE CRIAR, E SO CRIAR SE NAO EXISTIR.

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
void OpcaoMenuRelatorio(int op);              // recebe opcao do menu de relatorios e faz validacao e procede;
void OpcaoMenuRelatorioListarAmigos(int opr); // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarLocais(int opr); // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void ImprimirAmigos(Amigo amigos);            // imprime amigos;
void ImprimirLocais(Local locais);            // imprime locais;
void AlternarAmigos(int amigo);               // modifica os dados do amigo na hora de alternar;
void AlternarLocais(int local);               // modifica os dados do local na hora de alternar;
void ExcluirAmigos(int amigo);                // dispara qual amigo o usuario deseja excluir;
void ExcluirLocais(int local);                // dispara qual local o usuario deseja excluir;
void LimpaPonteiroAmigo(Amigo *amigo);        // limpa o ponteiro de amigos;
void LimpaPonteiroLocal(Local *local);        // limpa o ponteiro de locais;
void Pausar(int pause);                       // verifica se o pause eh true ou false e pausa;
void LimparBuffer();                          // limpa o buffer do teclado;

int IncluirAmigos();                          // inclui na funcao o amigo criado na funcao "cria amigo";
int ModificarAmigos();                        // alterar amigo;
int DeletarAmigos();                          // deleta um amigo;
int IncluirLocais();                          // inclui na funcao o local criado na funcao "cria local";
int ModificarLocais();                        // alterar local;
int DeletarLocais();                          // deleta um local;
int ValidarData(int dia, int mes, int ano);   // valida data que o usuario digitar;
int ListarAmigos();                           // lista os amigos que ja estao cadastrados;
int ListarLocais();                           // lista os locais que ja estao cadastrados;
int ListarAmigosPorApelido();                 // faz a logica de listar amigo por apelido;
int ListarLocaisPorEstado();                  // faz a logica de listar locais por estado;
int Bissexto(int ano);                        // verifica se o ano eh bissexto para poder arrumar dias e mes

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
        LimparBuffer();
        OpcaoMenu(op);
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
    case -1:
        system("clear");
        printf("\nErro. Quantidade de amigos cheia.\n");
        break;

    case -2:
        system("clear");
        printf("\nErro. Amigos Vazios.\n");
        break;
    case -3:
        system("clear");
        printf("\nErro. Amigo invalido.\n");
        break;
    case -4:
        system("clear");
        printf("\nErro. Quantidade de locais cheia.\n");
        break;
    case -5:
        system("clear");
        printf("\nErro. Locais vazio.\n");
        break;
    case -6:
        system("clear");
        printf("\nErro. Local invalido.\n");
        break;
    case -7:
        system("clear");
        printf("\nErro. Alocacao de memoria fracassada.\n");
        break;
    case -8:
        system("clear");
        printf("\nErro. Ano invalido.\n");
        break;
    case -9:
        system("clear");
        printf("\nErro. Mes invalido.\n");
        break;
    case -10:
        system("clear");
        printf("\nErro. Dia invalido.\n");
        break;
    case -11:
        system("clear");
        printf("\nErro. Local invalido ou nao encontrado.\n");
        break;
    case -12:
        system("clear");
        printf("\nErro. Amigo invalido ou nao encontrado.\n");
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

void MenuAmigo()
{

    system("clear");
    printf("\n1. Cadastrar Amigo\n");
    printf("\n2. Modificar Amigo\n");
    printf("\n3. Excluir Amigo\n");
    printf("\n4. Voltar\n");
}

void MenuLocal()
{

    system("clear");
    printf("\n1. Cadastrar Local\n");
    printf("\n2. Modificar Local\n");
    printf("\n3. Excluir Local\n");
    printf("\n4. Voltar\n");
}

void MenuCategoria()
{

    system("clear");
    printf("\n1. Cadastrar Categoria\n");
    printf("\n2. Modificar Categoria\n");
    printf("\n3. Excluir Categoria\n");
    printf("\n4. Voltar\n");
}

void MenuEncontro()
{

    system("clear");
    printf("\n1. Cadastrar Encontro\n");
    printf("\n2. Modificar Encontro\n");
    printf("\n3. Excluir Encontro\n");
    printf("\n4. Voltar\n");
}

void MenuRelatorio()
{
    system("clear");
    printf("\n1. Listar Amigos\n");
    printf("\n2. Listar Locais\n");
    printf("\n3. Listar Categorias\n");
    printf("\n4. Listar Encontros\n");
    printf("\n5. Relatorio por Categoria\n");
    printf("\n6. Voltar\n");
}

void MenuRelatorioListarAmigos()
{
    system("clear");
    printf("\n1. Listar todos\n");
    printf("\n2. Buscar por apelido\n");
    printf("\n3. Voltar\n");
}

void MenuRelatorioListarLocais()
{
    system("clear");
    printf("\n1. Listar todos\n");
    printf("\n2. Listar por estado\n");
    printf("\n3. Listar por cidade\n");
    printf("\n4. Listar por bairro\n");
    printf("\n5. Voltar\n");
}

void OpcaoMenu(int op)
{
    int opm;

    while (op < 1 || op > 6)
    {
        MenssagemErro(0);
        Pausar(1);
        Menu();
        scanf("%i", &op);
        LimparBuffer();
    }

    if (op == 1)
    {
        MenuAmigo();
        scanf("%i", &opm);
        LimparBuffer();
        OpcaoMenuAmigo(opm);
    }
    else if (op == 2)
    {
        MenuLocal();
        scanf("%i", &opm);
        LimparBuffer();
        OpcaoMenuLocal(opm);
    }
    else if (op == 3)
    {
        MenuCategoria();
        scanf("%i", &opm);
        LimparBuffer();
        //TERMINAR CATEGORIA;
    }
    else if (op == 4)
    {
        MenuEncontro();
        scanf("%i", &opm);
        LimparBuffer();
        //TERMINAR ENCONTRO;
    }
    else if (op == 5)
    {
        MenuRelatorio();
        scanf("%i", &opm);
        LimparBuffer();
        OpcaoMenuRelatorio(opm);
    }
    else if (op == 6)
    {
        exit(0);
    }
}

Amigo CriaAmigo()
{

    Amigo amigo;

    int erro = -1;
    char strAux[100];

    system("clear");

    printf("\nNome:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.nome, strAux);
    LimparBuffer();

    system("clear");
    printf("\nApelido:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.apelido, strAux);
    LimparBuffer();

    system("clear");
    printf("\nEmail:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.email, strAux);
    LimparBuffer();

    system("clear");
    printf("\nTelefone:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.telefone, strAux);
    LimparBuffer();

    while (erro < 0)
    {
        system("clear"); // força o usuario digitar data de nascimento seguindo os parametros de data
        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &amigo.datanasc.dia, &amigo.datanasc.mes, &amigo.datanasc.ano);
        LimparBuffer();
        erro = ValidarData(amigo.datanasc.dia, amigo.datanasc.mes, amigo.datanasc.ano);

        if (erro < 0)
        {
            MenssagemErro(erro);
            Pausar(1);
        }
    }
    return amigo;
}

Local CriaLocal()
{
    Local local;
    char strAux[100];

    system("clear");
    printf("\nNome do encontro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.nome_encontro, strAux);
    LimparBuffer();

    system("clear");
    printf("\nEstado:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.estado, strAux);
    LimparBuffer();

    system("clear");
    printf("\nCidade:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.cidade, strAux);
    LimparBuffer();

    system("clear");
    printf("\nBairro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.bairro, strAux);
    LimparBuffer();

    system("clear");
    printf("\nLogradouro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.logradouro, strAux);
    LimparBuffer();

    system("clear");
    printf("\nNumero:\n");
    scanf("%i", &local.endereco.numero);
    LimparBuffer();

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
        return -7;
    }

    Amigos[NumAmigos] = CriaAmigo();
    system("clear");
    ImprimirAmigos(Amigos[NumAmigos]);
    NumAmigos++;

    return 1;
}

int IncluirLocais()
{
    if (NumLocais >= MAXLOCAL)
    {
        return -4;
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
        return -7;
    }

    Locais[NumLocais] = CriaLocal();
    system("clear");
    ImprimirLocais(Locais[NumLocais]);
    NumLocais++;

    return 1;
}

void ImprimirAmigos(Amigo amigos)
{
    printf("\n- Nome: %s\n", amigos.nome);
    printf("\n- Apelido: %s\n", amigos.apelido);
    printf("\n- Email: %s\n", amigos.email);
    printf("\n- Telefone: %s\n", amigos.telefone);
    printf("\n- Data Nascimento: [%02i/%02i/%i]\n", amigos.datanasc.dia, amigos.datanasc.mes, amigos.datanasc.ano);
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

void OpcaoMenuAmigo(int op)
{

    int erro = 1;
    int opm;

    while (op < 1 || op > 4)
    {
        MenssagemErro(0);
        Pausar(1);
        MenuAmigo();
        scanf("%i", &op);
        LimparBuffer();
    }

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
    else if (op == 4)
    {
        return;
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }

    Pausar(1);
    MenuAmigo();
    scanf("%i", &opm);
    LimparBuffer();
    OpcaoMenuAmigo(opm);
}

void OpcaoMenuLocal(int op)
{
    int erro = 1;
    int opm;

    while (op < 1 || op > 4)
    {
        MenssagemErro(0);
        Pausar(1);
        MenuLocal();
        scanf("%i", &op);
        LimparBuffer();
    }

    if (op == 1)
    {
        erro = IncluirLocais();
    }
    else if (op == 2)
    {
        erro = ModificarLocais();
    }
    else if (op == 3)
    {
        erro = DeletarLocais();
    }
    else if (op == 4)
    {
        return;
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }

    Pausar(1);
    MenuLocal();
    scanf("%i", &opm);
    LimparBuffer();
    OpcaoMenuLocal(opm);
}

void OpcaoMenuRelatorio(int op)
{
    int opr;
    int erro = 1;

    while (op < 1 || op > 6)
    {
        MenssagemErro(0);
        Pausar(1);
        MenuRelatorio();
        scanf("%i", &op);
        LimparBuffer();
    }

    switch (op)
    {
    case 1:
        if (NumAmigos <= 0)
        {
            erro = -2;
        }
        else
        {
            MenuRelatorioListarAmigos();
            scanf("%i", &opr);
            LimparBuffer();
            OpcaoMenuRelatorioListarAmigos(opr);
            return;
        }
        break;

    case 2:
        if (NumLocais <= 0)
        {
            erro = -5;
        }
        else
        {
            MenuRelatorioListarLocais();
            scanf("%i", &opr);
            LimparBuffer();
            OpcaoMenuRelatorioListarLocais(opr);
            return;
        }
        break;

    case 3:

        // LOGICA PARA LISTAR CATEGORIAS;
        break;

    case 4:

        // LOGICA PARA LISTAR ENCONTROS;
        break;

    case 5:

        // LOGICA PARA RELATORIO DE CATEGORIA;
        break;

    case 6:
    {
        return;
    }
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }

    Pausar(1);
    MenuRelatorio();
    scanf("%i", &opr);
    LimparBuffer();
    OpcaoMenuRelatorio(opr);
}

void OpcaoMenuRelatorioListarAmigos(int opr)
{
    int erro = 1;
    int op;

    while (opr < 1 || opr > 3)
    {
        MenssagemErro(0);
        Pausar(1);
        MenuRelatorioListarAmigos();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarAmigos();
        Pausar(1);
    }
    else if (opr == 2)
    {
        erro = ListarAmigosPorApelido();
        Pausar(1);
    }
    else if (opr == 3)
    {
        MenuRelatorio();
        scanf("%i", &op);
        LimparBuffer();
        OpcaoMenuRelatorio(op);
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}

void OpcaoMenuRelatorioListarLocais(int opr)
{
    int erro = 1;
    int op;

    while (opr < 1 || opr > 5)
    {
        MenssagemErro(0);
        Pausar(1);
        MenuRelatorioListarLocais();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarLocais();
        Pausar(1);
    }
    else if (opr == 2)
    {
        erro = ListarLocaisPorEstado();
        Pausar(1);
    }
    else if (opr == 3)
    {
        // lista por cidade;
    }
    else if (opr == 4)
    {
        // listar por bairro;
    }
    else if (opr == 5)
    {
        MenuRelatorio();
        scanf("%i", &op);
        LimparBuffer();
        OpcaoMenuRelatorio(op);
    }

    if (erro <= 0)
    {
        MenssagemErro(erro);
    }
}

int ListarAmigos()
{
    int i;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    system("clear");
    for (i = 0; i < NumAmigos; i++)
    {
        printf("\n");
        printf("\n-- Amigo Numero [%i] --\n", i + 1);
        ImprimirAmigos(Amigos[i]);
    }

    return 1;
}

int ListarAmigosPorApelido()
{
    char apelido[50];
    int i, encontrado = 0;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    system("clear");
    printf("\nDigite o apelido do amigo: ");
    fgets(apelido, sizeof(apelido), stdin); // Usando fgets em vez de gets()
    apelido[strcspn(apelido, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    system("clear");
    for (i = 0; i < NumAmigos; i++)
    {
        if (strcmp(Amigos[i].apelido, apelido) == 0)
        {   
            printf("\n-- Amigo Numero [%i] --\n", i + 1);
            ImprimirAmigos(Amigos[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        return -12;
    }

    return 1;
}

int ListarLocais()
{
    int i;

    if (NumLocais <= 0)
    {
        return -5;
    }

    system("clear");
    for (i = 0; i < NumLocais; i++)
    {
        printf("\n");
        printf("\n-- Local Numero [%i] --\n", i + 1);
        ImprimirLocais(Locais[i]);
    }

    return 1;
}
    // ARRUMAR !!!!!!!!!!!!!!!!!!!!!, TA COM ALGUM PROBLEMA DE NAO TA RETORNANDO MAIS QUE 1!!!!!!!!!!!!!!!!!!!!!! (talvez tenha que criar um contador dentro da struct, but i ain't sure bout tha shee)
int ListarLocaisPorEstado()
{
    char estado[50];
    int i, encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    system("clear");
    printf("\nDigite o estado: ");
    fgets(estado, sizeof(estado), stdin); // Usando fgets em vez de gets()
    estado[strcspn(estado, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    system("clear");
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].endereco.estado, estado) == 0)
        {   
            printf("\n-- Local Numero [%i] --\n", i + 1);
            ImprimirLocais(Locais[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        return -11;
    }

    return 1;
}
void AlternarAmigos(int amigo)
{
    int erro = -1;
    char strAux[100];

    system("clear");
    printf("\nNome:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente

    if (Amigos[amigo].nome != NULL)
    {
        free(Amigos[amigo].nome);
    }

    Amigos[amigo].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].nome == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].nome, strAux);
    LimparBuffer();

    system("clear");
    printf("\nApelido:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente

    if (Amigos[amigo].apelido != NULL)
    {
        free(Amigos[amigo].apelido);
    }

    Amigos[amigo].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].apelido == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].apelido, strAux);
    LimparBuffer();

    system("clear");
    printf("\nEmail:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente

    if (Amigos[amigo].email != NULL)
    {
        free(Amigos[amigo].email);
    }

    Amigos[amigo].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].email == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].email, strAux);
    LimparBuffer();

    system("clear");
    printf("\nTelefone:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente

    if (Amigos[amigo].telefone != NULL)
    {
        free(Amigos[amigo].telefone);
    }

    Amigos[amigo].telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Amigos[amigo].telefone == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].telefone, strAux);
    LimparBuffer();

    while (erro < 0)
    {
        system("clear");
        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &Amigos[amigo].datanasc.dia, &Amigos[amigo].datanasc.mes, &Amigos[amigo].datanasc.ano);
        LimparBuffer();
        erro = ValidarData(Amigos[amigo].datanasc.dia, Amigos[amigo].datanasc.mes, Amigos[amigo].datanasc.ano);

        if (erro < 0)
        {
            MenssagemErro(erro);
        }
    }
}

void AlternarLocais(int local)
{
    char strAux[100];

    system("clear");
    printf("\nNome do encontro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    if (Locais[local].nome_encontro != NULL)
    {
        free(Locais[local].nome_encontro);
    }

    Locais[local].nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Locais[local].nome_encontro == NULL)
    {
        MenssagemErro(-7);
        return;
    }

    system("clear");
    printf("\nEstado:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    if (Locais[local].endereco.estado != NULL)
    {
        free(Locais[local].endereco.estado);
    }

    Locais[local].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Locais[local].endereco.estado == NULL)
    {
        MenssagemErro(-7);
        return;
    }

    system("clear");
    printf("\nCidade:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    if (Locais[local].endereco.cidade != NULL)
    {
        free(Locais[local].endereco.cidade);
    }

    Locais[local].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Locais[local].endereco.cidade == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Locais[local].endereco.cidade, strAux);
    LimparBuffer();

    system("clear");
    printf("\nBairro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    if (Locais[local].endereco.bairro != NULL)
    {
        free(Locais[local].endereco.bairro);
    }

    Locais[local].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Locais[local].endereco.bairro == NULL)
    {
        MenssagemErro(-7);
        return;
    }
    strcpy(Locais[local].endereco.estado, strAux);
    LimparBuffer();

    system("clear");
    printf("\nNumero:\n");
    scanf("%i", &Locais[local].endereco.numero);
}

int ModificarAmigos()
{
    // Modifica o amigo que o usuario escolheu, no caso na mesma posicao que estava o anterior;

    int amigo = -1;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    while (amigo < 0 || amigo >= NumAmigos)
    {
        ListarAmigos();
        printf("\nSelecione o amigo que deseja modificar: [ %i - %i]: ", 1, NumAmigos);
        scanf("%i", &amigo);
        LimparBuffer();
        amigo--;

        if (amigo < 0 || amigo >= NumAmigos)
        {
            return -3;
        }
        else
        {
            AlternarAmigos(amigo);
        }
    }

    system("clear");
    ImprimirAmigos(Amigos[amigo]);

    return 1;
}

int ModificarLocais()
{

    // Modifica o local que o usuario escolheu, no caso na mesma posicao que estava o anterior;

    int local = -1;

    if (NumLocais <= 0)
    {
        return -5;
    }

    while (local < 0 || local >= NumLocais)
    {
        ListarLocais();
        printf("\nSelecione o local que deseja modificar: [ %i - %i]: ", 1, NumLocais);
        scanf("%i", &local);
        LimparBuffer();
        local--;

        if (local < 0 || local >= NumLocais)
        {
            return -6;
        }
        else
        {
            AlternarLocais(local);
        }
    }

    system("clear");
    ImprimirLocais(Locais[local]);

    return 1;
}

int DeletarAmigos()
{
    int amigo = -1;

    if (NumAmigos <= 0)
    {
        return -2;
    }
    ListarAmigos();
    printf("\nSelecione o amigo que deseja deletar: [ %i - %i]: ", 1, NumAmigos);
    scanf("%i", &amigo);
    LimparBuffer();
    amigo--;

    if (amigo < 0 || amigo >= NumAmigos)
    {
        return -3;
    }
    else
    {
        ExcluirAmigos(amigo);
    }

    system("clear");
    printf("\nExclusao bem sucedida.\n");

    return 1;
}

int DeletarLocais()
{

    int local = -1;

    if (NumLocais <= 0)
    {
        return -5;
    }

    while (local < 0 || local >= NumLocais)
    {
        ListarLocais();
        printf("\nSelecione o local que deseja deletar: [ %i - %i]: ", 1, NumLocais);
        scanf("%i", &local);
        LimparBuffer();
        local--;

        if (local < 0 || local >= NumLocais)
        {
            return -6;
        }
        else
        {
            ExcluirLocais(local);
        }
    }

    system("clear");
    printf("\nExclusao bem sucedida.\n");

    return 1;
}

void ExcluirAmigos(int amigo)
{
    if (NumAmigos <= 0 || amigo < 0 || amigo >= NumAmigos)
    {
        return;
    }

    // libera memoria do amigo que quer ser removido
    LimpaPonteiroAmigo(&Amigos[amigo]);

    // sobrescreve o elemento a ser removido com o último elemento (basicamente reorganiza);
    Amigos[amigo] = Amigos[NumAmigos - 1];

    NumAmigos--;
}

void ExcluirLocais(int local)
{
    if (NumLocais <= 0 || local < 0 || local >= NumLocais)
    {
        return;
    }

    // libera memoria do local que quer ser removido
    LimpaPonteiroLocal(&Locais[local]);

    // sobrescreve o elemento a ser removido com o último elemento (basicamente reorganiza);
    Locais[local] = Locais[NumLocais - 1];

    NumLocais--;
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

    if (ano < 1980 || ano > 2024)
    {
        return -8;
    }

    if (mes < 1 || mes > 12)
    {
        return -9;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (Bissexto(ano))
    {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes])
    {
        return -10;
    }
    return 1;
}

void Pausar(int pause)
{
    if (pause)
    {
        getchar();
    }
}
void LimparBuffer()
{
    __fpurge(stdin);
}