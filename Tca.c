#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLOCAL 100
#define MAXAMIGO 100
#define MAXCATEGORIA 100

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
// 1- COLOCAR UM MENU PARA DELETAR 1 OU TODOS (SE FOR 1, VAI SER POR UMA CARACTERISTICA.)
// 2- ADICIONAR MENU PARA MODIFICAR TUDO OU APENAS UMA PARTE, TEREI QUE FAZER UMA OPCAO PARA CADA PROVAVELMENTE.
// 3- FAZER ALTERAÇÕES DO PAUSE, POR EXEMPLO, CRIAR UMA FUNCAO PARA VERIFICAR SE O PAUSE EH TRUE OU FALSE, SE FOR PAUSAR SE NAO FOR PASSAR DIRETO. ----
// 4- FAZER UMA VERIFICACAO SE AMIGO, E ETC JA EXISTE NA HORA DE CRIAR, E SO CRIAR SE NAO EXISTIR.
// 5- NAO DEIXAR O USUARIO EXCLUIR UM AMIGO SE ELE ESTIVER EM UM ENCONTRO;
// 6- 

void MensagemErro(int erro); // imprime mensagens de erro;

void Menu();                          // imprime menu principal;
void MenuAmigo();                     // imprime menu amigo;
void MenuLocal();                     // imprime menu local;
void MenuCategoria();                 // imprime menu categoria;
void MenuEncontro();                  // imprime menu encontro;
void MenuRelatorio();                 // imprime menu relatorio;
void MenuRelatorioListarAmigos();     // menu para perguntar se sera listados todos ou especifico por apelido;
void MenuRelatorioListarLocais();     // menu para perguntar se sera listados todos ou especifico;
void MenuRelatorioListarCategorias(); // menu para perguntar se sera listado;

void OpcaoMenu(int op);                           // recebe opcao do menu e faz a validacao e procede;
void OpcaoMenuAmigo(int op);                      // recebe opcao do menu de amigos e faz validacao e procede;
void OpcaoMenuLocal(int op);                      // recebe opcao do menu de local e faz validacao e procede;
void OpcaoMenuCategoria(int op);                  // recebe opcao do menu de categoria e faz validacao e procede;
void OpcaoMenuRelatorio(int op);                  // recebe opcao do menu de relatorios e faz validacao e procede;
void OpcaoMenuRelatorioListarAmigos(int opr);     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarLocais(int opr);     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarCategorias(int opr); // recebe a opca se vai ser todos ou deseja voltar e procede;

void ImprimirAmigos(Amigo amigos);             // imprime amigos;
void ImprimirLocais(Local locais);             // imprime locais;
void ImprimirCategorias(Categoria categorias); // imprime categorias;

void AlternarAmigos(int amigo);          // modifica os dados do amigo na hora de alternar;
void AlternarLocais(int local);          // modifica os dados do local na hora de alternar;
void AlternarCategorias(int categorias); // modifica os dados da categoria na hora de alternar;
void ExcluirAmigos(int amigo);           // dispara qual amigo o usuario deseja excluir;
void ExcluirLocais(int local);           // dispara qual local o usuario deseja excluir;
void ExcluirCategorias(int categoria);   // dispara qual categoria o usuario deseja excluir;

void VoltarMenuPrincipal(); // volta/chama o menu principal e ja le a opcao direto;
void VoltarMenuRelatorio(); // volta/chama o menu de relatorio e ja le a opcao direto;

void LimpaPonteiroAmigo(Amigo *amigo);              // limpa o ponteiro de amigos;
void LimpaPonteiroLocal(Local *local);              // limpa o ponteiro de locais;
void LimpaPonteiroCategoria(Categoria *categoria); // limpa ponteiro de categorias;

void Pausar(int pause); // verifica se o pause eh true ou false e pausa;
void LimparBuffer();    // limpa o buffer do teclado;
void LimparTela();      // limpa a tela (criei por conta da miseria do linux);

int IncluirAmigos();       // inclui na funcao o amigo criado na funcao "cria amigo";
int IncluirLocais();       // inclui na funcao o local criado na funcao "cria local";
int IncluirCategorias();   // inlcui na funcao o amigo criado na funcao "cria ategoria"
int ModificarAmigos();     // alterar amigo;
int ModificarLocais();     // alterar local;
int ModificarCategorias(); // alterar categorias;
int DeletarAmigos();       // deleta um amigo;
int DeletarLocais();       // deleta um local;
int DeletarCategorias();   // deleta uma categoria;

int ListarAmigos();           // lista os amigos que ja estao cadastrados;
int ListarAmigosPorApelido(); // faz a logica de listar amigo por apelido;
int ListarLocais();           // lista os locais que ja estao cadastrados;
int ListarLocaisPorEstado();  // faz a logica de listar locais por estado;
int ListarLocaisPorCidade();  // faz a logica de listar locais por cidade;
int ListarLocaisPorBairro();  // faz a logica de listar locais por bairro;
int ListarCategorias();       // lista as categorias que ja estao cadastradas;

int ValidarData(int dia, int mes, int ano); // valida data que o usuario digitar;
int Bissexto(int ano);                      // verifica se o ano eh bissexto para poder arrumar dias e mes

Amigo CriaAmigo();         // funcao para criar um amigo;
Local CriaLocal();         // funcao para criar um local;
Categoria CriaCategoria(); // funcao para criar uma categoria;

Amigo *Amigos;
Local *Locais;
Categoria *Categorias;

int NumAmigos = 0, NumLocais = 0, NumCategorias = 0;

int main()
{

    int op = 0;

    while (op != 6)
    {
        VoltarMenuPrincipal();
    }

    return 0;
}

void MensagemErro(int erro)
{
    switch (erro)
    {
    case 0:
        LimparTela();
        printf("\nErro. Opcao invalida.\n");
        break;
    case -1:
        LimparTela();
        printf("\nErro. Quantidade de amigos cheia.\n");
        break;

    case -2:
        LimparTela();
        printf("\nErro. Amigos Vazios.\n");
        break;
    case -3:
        LimparTela();
        printf("\nErro. Amigo invalido.\n");
        break;
    case -4:
        LimparTela();
        printf("\nErro. Quantidade de locais cheia.\n");
        break;
    case -5:
        LimparTela();
        printf("\nErro. Locais vazio.\n");
        break;
    case -6:
        LimparTela();
        printf("\nErro. Local invalido.\n");
        break;
    case -7:
        LimparTela();
        printf("\nErro. Alocacao de memoria fracassada.\n");
        break;
    case -8:
        LimparTela();
        printf("\nErro. Ano invalido.\n");
        break;
    case -9:
        LimparTela();
        printf("\nErro. Mes invalido.\n");
        break;
    case -10:
        LimparTela();
        printf("\nErro. Dia invalido.\n");
        break;
    case -11:
        LimparTela();
        printf("\nErro. Local invalido ou nao encontrado.\n");
        break;
    case -12:
        LimparTela();
        printf("\nErro. Amigo invalido ou nao encontrado.\n");
        break;
    case -13:
        LimparTela();
        printf("\nErro. Quantidade de categorias cheia.\n");
        break;
    case -14:
        LimparTela();
        printf("\nErro. Categorias Vazias.\n");
        break;

    case -15:
        LimparTela();
        printf("\nErro. Categoria Invalida.\n");
        break;
    

    default:
        LimparTela();
        printf("\nErro.\n");
        break;
    }
}

void Menu()
{
    LimparTela();
    printf("\n1. Manter amigo\n");
    printf("\n2. Manter local\n");
    printf("\n3. Manter categoria\n");
    printf("\n4. Manter encontro\n");
    printf("\n5. Relatorios\n");
    printf("\n6. Sair\n");
}

void MenuAmigo()
{

    LimparTela();
    printf("\n1. Cadastrar Amigo\n");
    printf("\n2. Modificar Amigo\n");
    printf("\n3. Excluir Amigo\n");
    printf("\n4. Voltar\n");
}

void MenuLocal()
{

    LimparTela();
    printf("\n1. Cadastrar Local\n");
    printf("\n2. Modificar Local\n");
    printf("\n3. Excluir Local\n");
    printf("\n4. Voltar\n");
}

void MenuCategoria()
{

    LimparTela();
    printf("\n1. Cadastrar Categoria\n");
    printf("\n2. Modificar Categoria\n");
    printf("\n3. Excluir Categoria\n");
    printf("\n4. Voltar\n");
}

void MenuEncontro()
{

    LimparTela();
    printf("\n1. Cadastrar Encontro\n");
    printf("\n2. Modificar Encontro\n");
    printf("\n3. Excluir Encontro\n");
    printf("\n4. Voltar\n");
}

void MenuRelatorio()
{
    LimparTela();
    printf("\n1. Listar Amigos\n");
    printf("\n2. Listar Locais\n");
    printf("\n3. Listar Categorias\n");
    printf("\n4. Listar Encontros\n");
    printf("\n5. Relatorio por Categoria\n");
    printf("\n6. Voltar\n");
}

void MenuRelatorioListarAmigos()
{
    LimparTela();
    printf("\n1. Listar todos\n");
    printf("\n2. Buscar por apelido\n");
    printf("\n3. Voltar\n");
    printf("\n4. Voltar Menu Principal\n");
}

void MenuRelatorioListarLocais()
{
    LimparTela();
    printf("\n1. Listar todos\n");
    printf("\n2. Listar por estado\n");
    printf("\n3. Listar por cidade\n");
    printf("\n4. Listar por bairro\n");
    printf("\n5. Voltar\n");
    printf("\n6. Voltar Menu Principal\n");
}

void MenuRelatorioListarCategorias()
{
    LimparTela();
    printf("\n1. Listar Todas\n");
    printf("\n2. Voltar\n");
    printf("\n3. Voltar Menu Principal\n");
}

void OpcaoMenu(int op)
{
    int opm;

    while (op < 1 || op > 6)
    {
        MensagemErro(0);
        Pausar(1);
        VoltarMenuPrincipal();
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
        OpcaoMenuCategoria(opm);
    }
    else if (op == 4)
    {
        MenuEncontro();
        scanf("%i", &opm);
        LimparBuffer();
        // TERMINAR ENCONTRO;
    }
    else if (op == 5)
    {
        VoltarMenuRelatorio();
    }
    else if (op == 6)
    {
        LimparTela();
        printf("\nBye Bye..\n");
        exit(0);
    }
}

Amigo CriaAmigo()
{

    Amigo amigo;

    int erro = -1;
    char strAux[100];

    LimparTela();

    printf("\nNome:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.nome, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nApelido:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.apelido, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nEmail:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.email, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nTelefone:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.telefone, strAux);
    LimparBuffer();

    while (erro < 0)
    {
        LimparTela(); // força o usuario digitar data de nascimento seguindo os parametros de data
        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &amigo.datanasc.dia, &amigo.datanasc.mes, &amigo.datanasc.ano);
        LimparBuffer();
        erro = ValidarData(amigo.datanasc.dia, amigo.datanasc.mes, amigo.datanasc.ano);

        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }
    }
    return amigo;
}

Local CriaLocal()
{
    Local local;
    char strAux[100];

    LimparTela();
    printf("\nNome do encontro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.nome_encontro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.nome_encontro, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nEstado:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.estado, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nCidade:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.cidade, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nBairro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.bairro, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nLogradouro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.logradouro, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nNumero:\n");
    scanf("%i", &local.endereco.numero);
    LimparBuffer();

    return local;
}

Categoria CriaCategoria()
{
    Categoria categoria;
    char strAux[100];

    LimparTela();
    printf("\nCategoria:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    categoria.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(categoria.nome, strAux);
    LimparBuffer();

    return categoria;
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
    LimparTela();
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
    LimparTela();
    ImprimirLocais(Locais[NumLocais]);
    NumLocais++;

    return 1;
}

int IncluirCategorias()
{
    if (NumCategorias >= MAXCATEGORIA)
    {
        return -13;
    }

    if (NumCategorias == 0)
    {
        Categorias = (Categoria *)malloc(1 * sizeof(Categoria));
    }
    else
    {
        Categorias = (Categoria *)realloc(Categorias, (NumCategorias + 1) * sizeof(Categoria));
    }

    if (!Categorias)
    {
        return -7;
    }

    Categorias[NumCategorias] = CriaCategoria();
    LimparTela();
    ImprimirCategorias(Categorias[NumCategorias]);
    NumCategorias++;

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

void ImprimirCategorias(Categoria categorias)
{
    printf("\nTipo de Categoria: %s\n", categorias.nome);
}

void OpcaoMenuAmigo(int op)
{

    int erro = 1;
    int opm;

    while (op < 1 || op > 4)
    {
        MensagemErro(0);
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
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
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
        MensagemErro(0);
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
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    MenuLocal();
    scanf("%i", &opm);
    LimparBuffer();
    OpcaoMenuLocal(opm);
}

void OpcaoMenuCategoria(int op)
{
    int erro = 1;
    int opm;

    while (op < 1 || op > 4)
    {
        MensagemErro(0);
        Pausar(1);
        MenuCategoria();
        scanf("%i", &op);
        LimparBuffer();
    }

    if (op == 1)
    {
        erro = IncluirCategorias();
    }
    else if (op == 2)
    {
        erro = ModificarCategorias();
    }
    else if (op == 3)
    {
        erro = DeletarCategorias();
    }
    else if (op == 4)
    {
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    MenuCategoria();
    scanf("%i", &opm);
    LimparBuffer();
    OpcaoMenuCategoria(opm);
}

void OpcaoMenuRelatorio(int op)
{
    int opr;
    int erro = 1;

    while (op < 1 || op > 6)
    {
        MensagemErro(0);
        Pausar(1);
        VoltarMenuRelatorio();
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
        if (NumCategorias <= 0)
        {
            erro = -14;
        }
        else
        {
            MenuRelatorioListarCategorias();
            scanf("%i", &opr);
            LimparBuffer();
            OpcaoMenuRelatorioListarCategorias(opr);
            return;
        }
        break;

    case 4:

        // LOGICA PARA LISTAR ENCONTROS;
        break;

    case 5:

        // LOGICA PARA RELATORIO DE CATEGORIA;
        break;

    case 6:
    {
        VoltarMenuPrincipal();
    }
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    VoltarMenuRelatorio();
}

void OpcaoMenuRelatorioListarAmigos(int opr)
{
    int erro = 1;
    int aux;

    while (opr < 1 || opr > 4)
    {
        MensagemErro(0);
        MenuRelatorioListarAmigos();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarAmigos();
    }
    else if (opr == 2)
    {
        erro = ListarAmigosPorApelido();
    }
    else if (opr == 3)
    {
        VoltarMenuRelatorio();
    }
    else if (opr == 4)
    {
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
        Pausar(1);
    }

    Pausar(1);
    MenuRelatorioListarAmigos();
    scanf("%i", &aux);
    LimparBuffer();
    OpcaoMenuRelatorioListarAmigos(aux);
}

void OpcaoMenuRelatorioListarLocais(int opr)
{
    int erro = 1;
    int aux;

    while (opr < 1 || opr > 6)
    {
        MensagemErro(0);
        Pausar(1);
        MenuRelatorioListarLocais();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarLocais();
    }
    else if (opr == 2)
    {
        erro = ListarLocaisPorEstado();
    }
    else if (opr == 3)
    {
        erro = ListarLocaisPorCidade();
    }
    else if (opr == 4)
    {
        erro = ListarLocaisPorBairro();
    }
    else if (opr == 5)
    {
        VoltarMenuRelatorio();
    }
    else if (opr == 6)
    {
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    MenuRelatorioListarLocais();
    scanf("%i", &aux);
    LimparBuffer();
    OpcaoMenuRelatorioListarLocais(aux);
}

void OpcaoMenuRelatorioListarCategorias(int opr)
{
    int erro = 1;
    int aux;

    while (opr < 1 || opr > 6)
    {
        MensagemErro(0);
        Pausar(1);
        MenuRelatorioListarCategorias();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarCategorias();
    }
    else if (opr == 2)
    {
        VoltarMenuRelatorio();
    }
    else if (opr == 3)
    {
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    MenuRelatorioListarCategorias();
    scanf("%i", &aux);
    LimparBuffer();
    OpcaoMenuRelatorioListarCategorias(aux);
}

int ListarAmigos()
{
    int i;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    LimparTela();
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

    LimparTela();
    printf("\nDigite o apelido do amigo: \n");
    fgets(apelido, sizeof(apelido), stdin); // Usando fgets em vez de gets()
    apelido[strcspn(apelido, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    LimparTela();
    for (i = 0; i < NumAmigos; i++)
    {
        if (strcmp(Amigos[i].apelido, apelido) == 0)
        {
            printf("\n");
            printf("\n-- Amigo Numero [%i] --\n", i + 1);
            ImprimirAmigos(Amigos[i]);
            encontrado = 1;
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

    LimparTela();
    for (i = 0; i < NumLocais; i++)
    {
        printf("\n");
        printf("\n-- Local Numero [%i] --\n", i + 1);
        ImprimirLocais(Locais[i]);
    }

    return 1;
}

int ListarLocaisPorEstado()
{
    char estado[50];
    int i, encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o estado: \n");
    fgets(estado, sizeof(estado), stdin); // Usando fgets em vez de gets()
    estado[strcspn(estado, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    LimparTela();
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].endereco.estado, estado) == 0)
        {
            printf("\n");
            printf("\n-- Local Numero [%i] --\n", i + 1);
            ImprimirLocais(Locais[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        return -11;
    }
    return 1;
}

int ListarLocaisPorCidade()
{
    char cidade[50];
    int i, encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o cidade: \n");
    fgets(cidade, sizeof(cidade), stdin); // Usando fgets em vez de gets()
    cidade[strcspn(cidade, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    LimparTela();
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].endereco.cidade, cidade) == 0)
        {
            printf("\n");
            printf("\n-- Local Numero [%i] --\n", i + 1);
            ImprimirLocais(Locais[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        return -11;
    }

    return 1;
}

int ListarLocaisPorBairro()
{
    char bairro[50];
    int i, encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o bairro: \n");
    fgets(bairro, sizeof(bairro), stdin); // Usando fgets em vez de gets()
    bairro[strcspn(bairro, "\n")] = '\0'; // Remover a nova linha caso presente
    LimparBuffer();

    LimparTela();
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].endereco.bairro, bairro) == 0)
        {
            printf("\n");
            printf("\n-- Local Numero [%i] --\n", i + 1);
            ImprimirLocais(Locais[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        return -11;
    }

    return 1;
}

int ListarCategorias()
{
    int i;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    LimparTela();
    for (i = 0; i < NumCategorias; i++)
    {
        printf("\n");
        printf("\n-- Categoria Numero [%i] --\n", i + 1);
        ImprimirCategorias(Categorias[i]);
    }

    return 1;
}

void AlternarAmigos(int amigo)
{
    int erro = -1;
    char strAux[100];

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].nome, strAux);
    LimparBuffer();

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].apelido, strAux);
    LimparBuffer();

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].email, strAux);
    LimparBuffer();

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Amigos[amigo].telefone, strAux);
    LimparBuffer();

    while (erro < 0)
    {
        LimparTela();
        printf("\nData Nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &Amigos[amigo].datanasc.dia, &Amigos[amigo].datanasc.mes, &Amigos[amigo].datanasc.ano);
        LimparBuffer();
        erro = ValidarData(Amigos[amigo].datanasc.dia, Amigos[amigo].datanasc.mes, Amigos[amigo].datanasc.ano);

        if (erro < 0)
        {
            MensagemErro(erro);
        }
    }
}

void AlternarLocais(int local)
{
    char strAux[100];

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Locais[local].nome_encontro, strAux);

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Locais[local].endereco.estado, strAux);

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Locais[local].endereco.cidade, strAux);
    LimparBuffer();

    LimparTela();
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
        MensagemErro(-7);
        return;
    }
    strcpy(Locais[local].endereco.bairro, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nNumero:\n");
    scanf("%i", &Locais[local].endereco.numero);
}

void AlternarCategorias(int categoria)
{
    char strAux[100];

    LimparTela();
    printf("\nTipo da categoria:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    if (Categorias[categoria].nome != NULL)
    {
        free(Categorias[categoria].nome);
    }

    Categorias[categoria].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    if (Categorias[categoria].nome == NULL)
    {
        MensagemErro(-7);
        return;
    }
    strcpy(Categorias[categoria].nome, strAux);
    LimparBuffer();
    
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
        printf("\n");
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

    LimparTela();
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
        printf("\n");
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

    LimparTela();
    ImprimirLocais(Locais[local]);

    return 1;
}

int ModificarCategorias()
{
    // Modifica a categoria que o usuario escolheu, no caso na mesma posicao que estava o anterior;

    int categoria = -1;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    while (categoria < 0 || categoria >= NumCategorias)
    {
        ListarCategorias();
        printf("\n");
        printf("\nSelecione o categoria que deseja modificar: [ %i - %i]: ", 1, NumCategorias);
        scanf("%i", &categoria);
        LimparBuffer();
        categoria--;

        if (categoria < 0 || categoria >= NumCategorias)
        {
            return -15;
        }
        else
        {
            AlternarCategorias(categoria);
        }
    }

    LimparTela();
    ImprimirCategorias(Categorias[categoria]);

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
    printf("\n");
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

    LimparTela();
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
        printf("\n");
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

    LimparTela();
    printf("\nExclusao bem sucedida.\n");

    return 1;
}

int DeletarCategorias()
{
    int categoria = -1;

    if (NumCategorias <= 0)
    {
        return -14;
    }
    ListarCategorias();
    printf("\n");
    printf("\nSelecione a categoria que deseja deletar: [ %i - %i]: ", 1, NumCategorias);
    scanf("%i", &categoria);
    LimparBuffer();
    categoria--;

    if (categoria < 0 || categoria >= NumCategorias)
    {
        return -15;
    }
    else
    {
        ExcluirCategorias(categoria);
    }

    LimparTela();
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

void ExcluirCategorias(int categoria)
{
   if (NumCategorias <= 0 || categoria < 0 || categoria >= NumCategorias)
    {
        return;
    }

    // libera memoria do categoria que quer ser removida
    LimpaPonteiroCategoria(&Categorias[categoria]);

    // sobrescreve o elemento a ser removido com o último elemento (basicamente reorganiza);
    Categorias[categoria] = Categorias[NumCategorias - 1];

    NumLocais--;
}

void VoltarMenuPrincipal()
{
    int op;
    Menu();
    scanf("%i", &op);
    LimparBuffer();
    OpcaoMenu(op);
}

void VoltarMenuRelatorio()
{
    int op;
    MenuRelatorio();
    scanf("%i", &op);
    LimparBuffer();
    OpcaoMenuRelatorio(op);
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

void LimpaPonteiroCategoria(Categoria *categoria)
{
    free(categoria->nome);
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
void LimparTela()
{
    system("clear");
}