#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAXLOCAL 100
#define MAXAMIGO 100
#define MAXCATEGORIA 100
#define MAXENCONTRO 100

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
    char *nome_local;
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
    Amigo *amigos;
    Categoria *categorias;
    Local *locais;
    char *descricao;
    int numamigos;
    int numcategorias;
    int numlocais;

} Encontro;

// COISAS IMPORTANTES!!
// NAO DEIXAR O USUARIO EXCLUIR UM AMIGO SE ELE ESTIVER EM UM ENCONTRO (OU PERGUNTAR SE O USUARIO REALMENTE QUER, SE ELE QUISER ENTAO DELETAR O ENCONTRO);
// EXCLUIR AS INFORMACOES DO ENCONTRO SE AS INFORMACOES FOREM EXCLUIDAS NORMALMENTE;
// USARA TOKEN QUANDO FOR MANIPULAR ARQUIVO (MAIS FACIL);

void MensagemErro(int erro); // imprime mensagens de erro;

void Menu();                // imprime menu principal;
void MenuAmigo();           // imprime menu amigo;
void MenuLocal();           // imprime menu local;
void MenuCategoria();       // imprime menu categoria;
void MenuEncontro();        // imprime menu encontro;
void MenuRelatorio();       // imprime menu relatorio;
void MenuModificarAmigo();  // imprime menu para qual o usuario deseja modificar;
void MenuModificarLocais(); // imprime menu para qual o usuario deseja modificar;

void MenuRelatorioListarAmigos();                // menu para perguntar se sera listados todos ou especifico por apelido;
void MenuRelatorioListarLocais();                // menu para perguntar se sera listados todos ou especifico;
void MenuRelatorioListarCategorias();            // menu para perguntar se sera listado;
void MenuRelatorioListarEncontros();             // menu para perguntar se sera listado;
void MenuRelatorioListarEncontrosPorCategoria(); // menu para perguntar por qual categoria quer que liste;

void OpcaoMenu(int op);          // recebe opcao do menu, faz a validacao e procede;
void OpcaoMenuAmigo(int op);     // recebe opcao do menu de amigos, faz validacao e procede;
void OpcaoMenuLocal(int op);     // recebe opcao do menu de local, faz validacao e procede;
void OpcaoMenuCategoria(int op); // recebe opcao do menu de categoria, faz validacao e procede;
void OpcaoMenuEncontro(int op);  // recebe opcao do menu de encontro, faz validacao e procede;
void OpcaoMenuRelatorio(int op); // recebe opcao do menu de relatorios, faz validacao e procede;

void OpcaoMenuRelatorioListarAmigos(int opr);     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarLocais(int opr);     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarCategorias(int opr); // recebe a opcao se vai ser todos ou deseja voltar e procede;
void OpcaoMenuRelatorioListarEncontros(int opr);  // recebe a opcao se vai ser todos ou especifico e procede;

void ImprimirAmigos(Amigo amigos);             // imprime amigos;
void ImprimirLocais(Local locais);             // imprime locais;
void ImprimirCategorias(Categoria categorias); // imprime categorias;
void ImprimirEncontros(Encontro encontros);    // imprime encontros; -

void AlterarAmigos(int amigo, int op);        // modifica os dados do amigo na hora de Alterar;
void AlterarLocais(int local, int op);        // modifica os dados do local na hora de Alterar;
void AlterarCategorias(int categorias);       // modifica os dados da categoria na hora de Alterar;
void AlterarEncontros(int encontros, int op); // modifica os dados do encontro na hora de Alterar;
void ExcluirAmigos(int amigo);                // dispara qual amigo o usuario deseja excluir;
void ExcluirLocais(int local);                // dispara qual local o usuario deseja excluir;
void ExcluirCategorias(int categoria);        // dispara qual categoria o usuario deseja excluir;
void ExcluirEncontros(int encontro);          // dispara qual categoria o usuario deseja excluir;

void VoltarMenuPrincipal(); // volta/chama o menu principal e ja le a opcao direto;
void VoltarMenuRelatorio(); // volta/chama o menu de relatorio e ja le a opcao direto;

void LimpaPonteiroAmigo(Amigo *amigo);             // limpa o ponteiro de amigos;
void LimpaPonteiroLocal(Local *local);             // limpa o ponteiro de locais;
void LimpaPonteiroCategoria(Categoria *categoria); // limpa ponteiro de categorias;
void LimpaPonteiroEncontro(Encontro *encontro);    // limpa ponteiro de encontros; ---------

void Pausar(int pause); // verifica se o pause eh true ou false e pausa;
void LimparBuffer();    // limpa o buffer do teclado;
void LimparTela();      // limpa a tela (criei por conta da miseria do linux);

int IncluirAmigos();       // inclui na funcao o amigo criado na funcao "cria amigo";
int IncluirLocais();       // inclui na funcao o local criado na funcao "cria local";
int IncluirCategorias();   // inlcui na funcao o encontro criado na funcao "cria categoria"
int IncluirEncontros();    // inlcui na funcao o encontro criado na funcao "cria encontro" ---------------
int ModificarAmigos();     // alterar amigo;
int ModificarLocais();     // alterar local;
int ModificarCategorias(); // alterar categorias;
int ModificarEncontros();  // alterar encontros; --------------
int DeletarAmigos();       // deleta um amigo;
int DeletarLocais();       // deleta um local;
int DeletarCategorias();   // deleta uma categoria;
int DeletarEncontros();    // deleta um encontro; --------

int ListarAmigos();           // lista os amigos que ja estao cadastrados;
int ListarAmigosPorApelido(); // faz a logica de listar amigo por apelido;
int ListarLocais();           // lista os locais que ja estao cadastrados;
int ListarLocaisPorEstado();  // faz a logica de listar locais por estado;
int ListarLocaisPorCidade();  // faz a logica de listar locais por cidade;
int ListarLocaisPorBairro();  // faz a logica de listar locais por bairro;
int ListarCategorias();       // lista as categorias que ja estao cadastradas;
int ListarEncontros();        // lista os encontros que ja estao cadastradao; ---------

int ValidarData(int dia, int mes, int ano); // valida data que o usuario digitar;
int Bissexto(int ano);                      // verifica se o ano eh bissexto para poder arrumar dias e mes
int ValidarHorario(int hora, int min);

Amigo CriaAmigo();         // funcao para criar um amigo;
Local CriaLocal();         // funcao para criar um local;
Categoria CriaCategoria(); // funcao para criar uma categoria;
Encontro CriaEncontro();   // funcao para criar um encontro;

Amigo *Amigos;
Local *Locais;
Categoria *Categorias;
Encontro *Encontros;

int NumAmigos = 0, NumLocais = 0, NumCategorias = 0, NumEncontros = 0;

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
        printf("\nErro. Categoria Invalida ou nao encontrada.\n");
        break;

    case -16:
        LimparTela();
        printf("\nErro. Encontros Vazios.\n");
        break;

    case -17:
        LimparTela();
        printf("\nErro. Encontro invalido.\n");
        break;

    case -18:
        LimparTela();
        printf("\nErro. Quantidade de encontros cheia.\n");
        break;

    case -19:
        LimparTela();
        printf("\nErro. Amigos, Locais ou Categorias vazias, inclua todos.\n");
        break;

    case -20:
        LimparTela();
        printf("\nErro. Hora invalida.\n");
        break;

    case -21:
        LimparTela();
        printf("\nErro. Minuto invalido.\n");
        break;

    case -22:
        LimparTela();
        printf("\nErro. Amigo ja incluido no encontro.\n");
        break;

    case -23:
        LimparTela();
        printf("\nErro. Local ja incluido no encontro.\n");
        break;

    case -24:
        LimparTela();
        printf("\nErro. Categoria ja incluido no encontro.\n");
        break;

    case -25:
        LimparTela();
        printf("\nErro. Amigo ja existe. Nao pode haver amigos com o mesmo nome.\n");
        break;

    case -26:
        LimparTela();
        printf("\nErro. Local ja existe. Nao pode haver local com o mesmo nome.\n");
        break;

    case -27:
        LimparTela();
        printf("\nErro. Categoria ja existe. Nao pode haver categorias com o mesmo nome.\n");
        break;
    case -28:
        LimparTela();
        printf("\nTodos os amigos ja adicionados. Indo para locais...");
        break;
    case -29:
        LimparTela();
        printf("\nTodos os locais ja adicionados. Indo para categoria...");
        break;
    case -30:
        LimparTela();
        printf("\nTodos os categorias ja adicionadas. Indo para data...");
        break;
    case -31:
        LimparTela();
        printf("\nErro. Amigo qual deseja excluir esta em um encontro. Impossivel exclui-lo.");
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

void MenuRelatorioListarEncontros()
{
    LimparTela();
    printf("\n1. Listar Todos\n");
    printf("\n2. Listar por Amigos\n");
    printf("\n3. Listar por Locais\n");
    printf("\n4. Voltar\n");
    printf("\n5. Voltar Menu Principal\n");
}

// ARRUMAR, VOU FICAR MALUCO!!!!!!!!!!!!!!!!!!!!!!!!!!!
void MenuRelatorioListarEncontrosPorCategoria()
{
    int i, j;
    LimparTela();
    printf("\n--- Categorias ---\n");

    for (i = 0; i < Encontros->numcategorias; i++)
    {
        printf("\n- %s -\n", Encontros[i].categorias->nome);

        for (j = 0; j < NumEncontros; j++)
        {
            if (strcmp(Encontros[j].categorias->nome, Categorias[i].nome) == 0)
            {
                printf("\nAmigo: %s\n", Encontros[j].amigos->nome);
                printf("\nLocal: %s\n", Encontros[j].categorias->nome);
                printf("\nData: [%02i/%02i/%i]\n", Encontros[j].data.dia, Encontros[j].data.mes, Encontros[j].data.ano);
                printf("\nHorario: [%02ih:%02im]\n", Encontros[j].horario.hora, Encontros[j].horario.minuto);
                printf("\nDescricao: %s \n", Encontros[j].descricao);
                printf("\n");
            }

        }
    }
}

void MenuModificarAmigo()
{
    LimparTela();
    printf("\nModificar:\n");
    printf("\n1. Nome\n");
    printf("\n2. Apelido\n");
    printf("\n3. Email\n");
    printf("\n4. Telefone\n");
    printf("\n5. Data de nascimento\n");
}

void MenuModificarLocais()
{
    LimparTela();
    printf("\nModificar:\n");
    printf("\n1. Nome do local\n");
    printf("\n2. Estado\n");
    printf("\n3. Cidade\n");
    printf("\n4. Bairro\n");
    printf("\n5. Logradouro\n");
    printf("\n6. Numero\n");
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
        OpcaoMenuEncontro(opm);
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
    int i;
    char strAux[100];
    int op;

    LimparTela();
    printf("\nNome:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    amigo.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.nome, strAux);
    LimparBuffer();

    int amigojacriado = 0;
    for (i = 0; i < NumAmigos; i++)
    {
        if (strcmp(Amigos[i].nome, amigo.nome) == 0)
        {
            amigojacriado = 1;
            break;
        }
    }

    if (amigojacriado)
    {
        MensagemErro(-25);
        Pausar(1);
        MenuAmigo();
        scanf("%i", &op);
        LimparBuffer();
        OpcaoMenuAmigo(op);
    }

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
    int i;
    char strAux[100];
    int op;

    LimparTela();
    printf("\nNome do Local:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    local.nome_local = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.nome_local, strAux);
    LimparBuffer();

    int localcriado = 0;
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].nome_local, local.nome_local) == 0)
        {
            localcriado = 1;
            break;
        }
    }

    if (localcriado)
    {
        MensagemErro(-26);
        Pausar(1);
        MenuLocal();
        scanf("%i", &op);
        LimparBuffer();
        OpcaoMenuLocal(op);
    }

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
    int i;
    char strAux[100];
    int op;

    LimparTela();
    printf("\nCategoria:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    categoria.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(categoria.nome, strAux);
    LimparBuffer();

    int categoriacriada = 0;
    for (i = 0; i < NumCategorias; i++)
    {
        if (strcmp(Categorias[i].nome, categoria.nome) == 0)
        {
            categoriacriada = 1;
            break;
        }
    }

    if (categoriacriada)
    {
        MensagemErro(-27);
        Pausar(1);
        MenuCategoria();
        scanf("%i", &op);
        LimparBuffer();
        OpcaoMenuCategoria(op);
    }

    return categoria;
}

Encontro CriaEncontro()
{

    Encontro encontro;
    int i;
    int amigo, categoria, local;
    int incluir = 1, erro;
    char op;
    char strAux[100];

    encontro.amigos = 0;
    encontro.categorias = 0;
    encontro.locais = 0;
    encontro.numamigos = 0;
    encontro.numlocais = 0;
    encontro.numcategorias = 0;

    while (incluir)
    {
        LimparTela();
        printf("\n--- Amigos ---\n");
        for (i = 0; i < NumAmigos; i++)
        {
            printf("\n%i. %s\n", i + 1, Amigos[i].nome);
        }

        printf("\nDigite o amigo que deseja incluir no encontro:\n");
        scanf("%i", &amigo);
        LimparBuffer();
        amigo--;
        if (amigo < 0 || amigo >= NumAmigos)
        {
            MensagemErro(-3);
            Pausar(1);
        }
        else
        {
            int amigonoencontro = 0;

            for (i = 0; i < encontro.numamigos; i++)
            {
                if (strcmp(Amigos[amigo].nome, encontro.amigos[i].nome) == 0)
                {
                    amigonoencontro = 1;
                    break;
                }
            }

            if (amigonoencontro)
            {
                MensagemErro(-22);
                Pausar(1);
            }
            else
            {

                if (encontro.amigos == 0)
                {
                    encontro.amigos = (Amigo *)malloc(1 * sizeof(Amigo));
                }
                else
                {
                    encontro.amigos = (Amigo *)realloc(encontro.amigos, (encontro.numamigos + 1) * sizeof(Amigo));
                }

                if (encontro.amigos != NULL)
                {
                    encontro.amigos[encontro.numamigos].nome = (char *)malloc((strlen(Amigos[amigo].nome) + 1) * sizeof(char));
                    strcpy(encontro.amigos[encontro.numamigos].nome, Amigos[amigo].nome);
                    /*encontro.amigos[encontro.numamigos].apelido = (char *)malloc((strlen(Amigos[amigo].apelido) + 1) * sizeof(char));
                    strcpy(encontro.amigos[encontro.numamigos].apelido, Amigos[amigo].apelido);
                    encontro.amigos[encontro.numamigos].email = (char *)malloc((strlen(Amigos[amigo].email) + 1) * sizeof(char));
                    strcpy(encontro.amigos[encontro.numamigos].email, Amigos[amigo].email);
                    encontro.amigos[encontro.numamigos].telefone = (char *)malloc((strlen(Amigos[amigo].telefone) + 1) * sizeof(char));
                    strcpy(encontro.amigos[encontro.numamigos].telefone, Amigos[amigo].telefone);
                    encontro.amigos[encontro.numamigos].datanasc.dia = Amigos[amigo].datanasc.dia;
                    encontro.amigos[encontro.numamigos].datanasc.mes = Amigos[amigo].datanasc.mes;
                    encontro.amigos[encontro.numamigos].datanasc.ano = Amigos[amigo].datanasc.ano;
                    */
                    LimparTela();
                    printf("\nAmigo incluido com sucesso.\n");
                    encontro.numamigos++;
                    Encontros->numamigos++;
                    Pausar(1);
                }
                else
                {
                    MensagemErro(-7);
                    exit(0);
                }

                op = 'x';
                while (op != 's' && op != 'n')
                {
                    LimparTela();
                    printf("\nDeseja incluir mais algum amigo? (s) (n)\n");
                    scanf("%c", &op);
                    LimparBuffer();
                    op = tolower(op);
                    if (op == 's')
                    {
                        if (NumAmigos <= encontro.numamigos)
                        {
                            MensagemErro(-28);
                            Sleep(1000);
                            incluir = 0;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if (op == 'n')
                    {
                        incluir = 0;
                    }
                    else
                    {
                        MensagemErro(0);
                        Pausar(1);
                    }
                }
            }
        }
    }

    incluir = 1;
    while (incluir)
    {
        LimparTela();
        printf("\n--- Locais ---\n");
        for (i = 0; i < NumLocais; i++)
        {
            printf("\n%i. %s\n", i + 1, Locais[i].nome_local);
        }

        printf("\nDigite o local que deseja ir com o amigo:\n");
        scanf("%i", &local);
        LimparBuffer();
        local--;
        if (local < 0 || local >= NumLocais)
        {
            MensagemErro(-11);
            Pausar(1);
        }
        else
        {
            int localnoencontro = 0;

            for (i = 0; i < encontro.numlocais; i++)
            {
                if (strcmp(Locais[local].nome_local, encontro.locais[i].nome_local) == 0)
                {
                    localnoencontro = 1;
                    break;
                }
            }

            if (localnoencontro)
            {
                MensagemErro(-23);
                Pausar(1);
            }
            else
            {

                if (encontro.locais == 0)
                {
                    encontro.locais = (Local *)malloc(1 * sizeof(Local));
                }
                else
                {
                    encontro.locais = (Local *)realloc(encontro.locais, (encontro.numlocais + 1) * sizeof(Local));
                }

                if (encontro.locais != NULL)
                {
                    encontro.locais[encontro.numlocais].nome_local = (char *)malloc((strlen(Locais[local].nome_local) + 1) * sizeof(char));
                    strcpy(encontro.locais[encontro.numlocais].nome_local, Locais[local].nome_local);
                    LimparTela();
                    printf("\nLocal incluido com sucesso.\n");
                    encontro.numlocais++;
                    Encontros->numlocais++;
                    Pausar(1);
                }
                else
                {
                    MensagemErro(-7);
                    exit(0);
                }

                op = 'x';
                while (op != 's' && op != 'n')
                {
                    LimparTela();
                    printf("\nDeseja incluir mais algum local? (s) (n)\n");
                    scanf("%c", &op);
                    LimparBuffer();
                    op = tolower(op);
                    if (op == 's')
                    {
                        if (NumLocais <= encontro.numlocais)
                        {
                            MensagemErro(-29);
                            Sleep(1000);
                            incluir = 0;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if (op == 'n')
                    {
                        incluir = 0;
                    }
                    else
                    {
                        MensagemErro(0);
                        Pausar(1);
                    }
                }
            }
        }
    }

    incluir = 1;
    while (incluir)
    {
        LimparTela();
        printf("\n--- Categorias ---\n");
        for (i = 0; i < NumCategorias; i++)
        {
            printf("\n%i. %s\n", i + 1, Categorias[i].nome);
        }

        printf("\nDigite a categoria que deseja incluir no encontro:\n");
        scanf("%i", &categoria);
        LimparBuffer();
        categoria--;
        if (categoria < 0 || categoria >= NumCategorias)
        {
            MensagemErro(-15);
            Pausar(1);
        }
        else
        {
            int categorianoencontro = 0;

            for (i = 0; i < encontro.numcategorias; i++)
            {
                if (strcmp(Categorias[categoria].nome, encontro.categorias[i].nome) == 0)
                {
                    categorianoencontro = 1;
                    break;
                }
            }

            if (categorianoencontro)
            {
                MensagemErro(-24);
                Pausar(1);
            }
            else
            {

                if (encontro.categorias == 0)
                {
                    encontro.categorias = (Categoria *)malloc(1 * sizeof(Categoria));
                }
                else
                {
                    encontro.categorias = (Categoria *)realloc(encontro.categorias, (encontro.numcategorias + 1) * sizeof(Categoria));
                }

                if (encontro.categorias != NULL)
                {
                    encontro.categorias[encontro.numcategorias].nome = (char *)malloc((strlen(Categorias[categoria].nome) + 1) * sizeof(char));
                    strcpy(encontro.categorias[encontro.numcategorias].nome, Categorias[categoria].nome);
                    LimparTela();
                    printf("\nCategoria incluida com sucesso.\n");
                    encontro.numcategorias++;
                    Encontros->numcategorias++;
                    Pausar(1);
                }
                else
                {
                    MensagemErro(-7);
                    exit(0);
                }

                op = 'x';
                while (op != 's' && op != 'n')
                {
                    LimparTela();
                    printf("\nDeseja incluir mais alguma categoria? (s) (n)\n");
                    scanf("%c", &op);
                    LimparBuffer();
                    op = tolower(op);
                    if (op == 's')
                    {
                        if (NumCategorias <= encontro.numcategorias)
                        {
                            MensagemErro(-30);
                            Sleep(1000);
                            incluir = 0;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if (op == 'n')
                    {
                        incluir = 0;
                    }
                    else
                    {
                        MensagemErro(0);
                        Pausar(1);
                    }
                }
            }
        }
    }

    erro = -1;
    while (erro < 0)
    {
        LimparTela();
        printf("\nData do encontro [dd/mm/yy]:\n");
        scanf("%i%i%i", &encontro.data.dia, &encontro.data.mes, &encontro.data.ano);
        LimparBuffer();
        erro = ValidarData(encontro.data.dia, encontro.data.mes, encontro.data.ano);

        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }
    }

    erro = -1;
    while (erro < 0)
    {
        LimparTela();
        printf("\nHorario do encontro [hora : min]:\n");
        scanf("%i%i", &encontro.horario.hora, &encontro.horario.minuto);
        LimparBuffer();
        erro = ValidarHorario(encontro.horario.hora, encontro.horario.minuto);
        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }
    }

    printf("\nDescricao do encontro:\n");
    fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
    strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
    encontro.descricao = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(encontro.descricao, strAux);
    LimparBuffer();

    return encontro;
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
        exit(0);
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
        exit(0);
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
        exit(0);
    }

    Categorias[NumCategorias] = CriaCategoria();
    LimparTela();
    ImprimirCategorias(Categorias[NumCategorias]);
    NumCategorias++;

    return 1;
}

int IncluirEncontros()
{
    if (NumEncontros >= MAXENCONTRO)
    {
        return -18;
    }

    if (NumAmigos <= 0 || NumLocais <= 0 || NumCategorias <= 0)
    {
        return -19;
    }

    if (NumEncontros == 0)
    {
        Encontros = (Encontro *)malloc(1 * sizeof(Encontro));
    }
    else
    {
        Encontros = (Encontro *)realloc(Encontros, (NumEncontros + 1) * sizeof(Encontro));
    }

    if (!Encontros)
    {
        return -7;
        exit(0);
    }

    Encontros[NumEncontros] = CriaEncontro();
    LimparTela();
    ImprimirEncontros(Encontros[NumEncontros]);
    NumEncontros++;

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
    printf("\nNome do Local: %s\n", locais.nome_local);
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

void ImprimirEncontros(Encontro encontros)
{
    printf("\nAmigo: %s\n", encontros.amigos->nome);
    printf("\nCategoria: %s\n", encontros.categorias->nome);
    printf("\nLocal: %s\n", encontros.categorias->nome);
    printf("\nData: [%02i/%02i/%i]\n", encontros.data.dia, encontros.data.mes, encontros.data.ano);
    printf("\nHorario: [%02ih:%02im]\n", encontros.horario.hora, encontros.horario.minuto);
    printf("\nDescricao: %s \n", encontros.descricao);
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

void OpcaoMenuEncontro(int op)
{
    int erro = 1;
    int opm;

    while (op < 1 || op > 4)
    {
        MensagemErro(0);
        Pausar(1);
        MenuEncontro();
        scanf("%i", &op);
        LimparBuffer();
    }

    if (op == 1)
    {
        erro = IncluirEncontros(); //------------ FAZER ESSA PARTE E DAR CONTINUIDADE;
    }
    else if (op == 2)
    {
        // erro = ModificarEncontros();  ------------ FAZER ESSA PARTE E DAR CONTINUIDADE;
    }
    else if (op == 3)
    {
        // erro = DeletarEncontros();  ------------ FAZER ESSA PARTE E DAR CONTINUIDADE;
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
    MenuEncontro();
    scanf("%i", &opm);
    LimparBuffer();
    OpcaoMenuEncontro(opm);
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
        if (NumEncontros <= 0)
        {
            erro = -16;
        }
        else
        {
            MenuRelatorioListarEncontros();
            scanf("%i", &opr);
            LimparBuffer();
            OpcaoMenuRelatorioListarEncontros(opr);
            return;
        }
        break;

    case 5:
        if (NumEncontros <= 0)
        {
            erro = -16;
        }
        else
        {
            MenuRelatorioListarEncontrosPorCategoria();
            // testar;
        }
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

    while (opr < 1 || opr > 3)
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

void OpcaoMenuRelatorioListarEncontros(int opr)
{
    int erro = 1;
    int aux;

    while (opr < 1 || opr > 5)
    {
        MensagemErro(0);
        Pausar(1);
        MenuRelatorioListarEncontros();
        scanf("%i", &opr);
        LimparBuffer();
    }

    if (opr == 1)
    {
        erro = ListarEncontros();
    }
    else if (opr == 2)
    {
        // Fazer essa funcao ainda;
        // erro = ListarEncontrosAmigos();
    }
    else if (opr == 3)
    {
        // Fazer essa funcao ainda;
        // erro = ListarEncontrosLocais();
    }

    else if (opr == 4)
    {
        VoltarMenuRelatorio();
    }
    else if (opr == 5)
    {
        VoltarMenuPrincipal();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }

    Pausar(1);
    MenuRelatorioListarEncontros();
    scanf("%i", &aux);
    LimparBuffer();
    OpcaoMenuRelatorioListarEncontros(aux);
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
        printf("\n-- Amigo [%i] --\n", i + 1);
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
            printf("\n-- Amigo [%i] --\n", i + 1);
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
        printf("\n-- Local  [%i] --\n", i + 1);
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
            printf("\n-- Local  [%i] --\n", i + 1);
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
            printf("\n-- Local  [%i] --\n", i + 1);
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
            printf("\n-- Local  [%i] --\n", i + 1);
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
        printf("\n-- Categoria  [%i] --\n", i + 1);
        ImprimirCategorias(Categorias[i]);
    }

    return 1;
}

int ListarEncontros()
{
    int i;

    if (NumEncontros <= 0)
    {
        return -16;
    }

    LimparTela();
    for (i = 0; i < NumEncontros; i++)
    {
        printf("\n");
        printf("\n-- Encontro  [%i] --\n", i + 1);
        ImprimirEncontros(Encontros[i]);
    }

    return 1;
}

void AlterarAmigos(int amigo, int op)
{
    int erro = -1;
    char strAux[100];

    if (op == 1)
    {

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
            exit(0);
        }
        strcpy(Amigos[amigo].nome, strAux);
        LimparBuffer();
    }
    else if (op == 2)
    {
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
            exit(0);
        }
        strcpy(Amigos[amigo].apelido, strAux);
        LimparBuffer();
    }
    else if (op == 3)
    {
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
            exit(0);
        }
        strcpy(Amigos[amigo].email, strAux);
        LimparBuffer();
    }
    else if (op == 4)
    {
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
            exit(0);
        }
        strcpy(Amigos[amigo].telefone, strAux);
        LimparBuffer();
    }
    else if (op == 5)
    {
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
                Pausar(1);
            }
        }
    }
}

void AlterarLocais(int local, int op)
{
    char strAux[100];

    if (op == 1)
    {
        LimparTela();
        printf("\nNome do Local:\n");
        fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
        strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
        if (Locais[local].nome_local != NULL)
        {
            free(Locais[local].nome_local);
        }

        Locais[local].nome_local = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

        if (Locais[local].nome_local == NULL)
        {
            MensagemErro(-7);
            exit(0);
        }
        strcpy(Locais[local].nome_local, strAux);
    }
    else if (op == 2)
    {
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
            exit(0);
        }
        strcpy(Locais[local].endereco.estado, strAux);
    }
    else if (op == 3)
    {
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
            exit(0);
        }
        strcpy(Locais[local].endereco.cidade, strAux);
        LimparBuffer();
    }
    else if (op == 4)
    {
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
            exit(0);
        }
        strcpy(Locais[local].endereco.bairro, strAux);
        LimparBuffer();
    }
    else if (op == 5)
    {
        LimparTela();
        printf("\nLogradouro:\n");
        fgets(strAux, sizeof(strAux), stdin); // Usando fgets em vez de gets()
        strAux[strcspn(strAux, "\n")] = '\0'; // Remover a nova linha caso presente
        if (Locais[local].endereco.logradouro != NULL)
        {
            free(Locais[local].endereco.logradouro);
        }

        Locais[local].endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

        if (Locais[local].endereco.logradouro == NULL)
        {
            MensagemErro(-7);
            exit(0);
        }
        strcpy(Locais[local].endereco.logradouro, strAux);
        LimparBuffer();
    }
    else if (op == 6)
    {
        LimparTela();
        printf("\nNumero:\n");
        scanf("%i", &Locais[local].endereco.numero);
        LimparBuffer();
    }
}

void AlterarCategorias(int categoria)
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
        exit(0);
    }
    strcpy(Categorias[categoria].nome, strAux);
    LimparBuffer();
}

int ModificarAmigos()
{
    int amigo;
    int aux;
    char op;
    int opm = 1;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumAmigos == 1)
        {
            while (1)
            {
                LimparTela();
                MenuModificarAmigo();
                scanf("%i", &opm);
                LimparBuffer();
                if (opm < 1 || opm > 5)
                {
                    MensagemErro(0);
                    Pausar(1);
                    continue;
                }

                AlterarAmigos(0, opm);
                break;
            }
        }
        else
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
                while (1)
                {
                    LimparTela();
                    MenuModificarAmigo();
                    scanf("%i", &opm);
                    LimparBuffer();
                    if (opm < 1 || opm > 5)
                    {
                        MensagemErro(0);
                        Pausar(1);
                        continue;
                    }

                    AlterarAmigos(amigo, opm);
                    break;
                }
            }
        }
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuAmigo();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuAmigo(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nModificado com sucesso.\n");

    return 1;
}

int ModificarLocais()
{

    int local;
    char op;
    int aux;
    int opm;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumLocais == 1)
        {

            while (1)
            {
                LimparTela();
                MenuModificarLocais();
                scanf("%i", &opm);
                LimparBuffer();
                if (opm < 1 || opm > 6)
                {
                    MensagemErro(0);
                    Pausar(1);
                    continue;
                }

                AlterarLocais(0, opm);
                break;
            }
        }
        else
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
                while (1)
                {
                    LimparTela();
                    MenuModificarLocais();
                    scanf("%i", &opm);
                    LimparBuffer();
                    if (opm < 1 || opm > 6)
                    {
                        MensagemErro(0);
                        Pausar(1);
                        continue;
                    }

                    AlterarLocais(local, opm);
                    break;
                }
            }
        }
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuLocal();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuLocal(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nModificado com sucesso.\n");

    return 1;
}

int ModificarCategorias()
{

    int categoria = -1;
    int aux;
    char op;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumCategorias == 1)
        {
            LimparTela();
            AlterarCategorias(0);
        }
        else
        {
            ListarCategorias();
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
                AlterarCategorias(categoria);
            }
        }
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuCategoria();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuCategoria(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nModificado com sucesso.\n");

    return 1;
}

int DeletarAmigos()
{
    int amigo;
    int aux;
    char op;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumAmigos == 1)
        {
            for (int i = 0; i < Encontros->numamigos; i++)
            {
                if (strcmp(Amigos[0].nome, Encontros[i].amigos[i].nome) == 0)
                {
                    return -31;
                    break;
                }
                ExcluirAmigos(0);
            }
        }
        else
        {
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
                // COM ERRO!!!!!!!! ARRUMARRR
                for (int i = 0; i < Encontros->numamigos; i++)
                {
                    if (strcmp(Amigos[amigo].nome, Encontros[i].amigos[i].nome) == 0)
                    {
                        return -31;
                        break;
                    }
                    ExcluirAmigos(amigo);
                }
            }
        }
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuAmigo();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuAmigo(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nExclusao Sucedida.\n");
    return 1;
}

int DeletarLocais()
{

    int local;
    char op;
    int aux;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumLocais == 1)
        {
            ExcluirLocais(0);
        }
        else
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
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuLocal();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuLocal(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nExclusao bem sucedida.\n");
    return 1;
}

int DeletarCategorias()
{
    int categoria;
    int aux;
    char op;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    LimparTela();
    printf("\nRealmente deseja proseguir? (s) (n)\n");
    scanf(" %c", &op);
    LimparBuffer();
    op = tolower(op);

    if (op == 's')
    {
        if (NumCategorias == 1)
        {
            ExcluirCategorias(0);
        }
        else
        {
            ListarCategorias();
            printf("\nSelecione o categoria que deseja deletar: [ %i - %i]: ", 1, NumCategorias);
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
        }
    }
    else if (op == 'n')
    {
        LimparTela();
        MenuCategoria();
        scanf("%i", &aux);
        LimparBuffer();
        OpcaoMenuCategoria(aux);
    }
    else if (op != 's' || op != 'n')
    {
        return 0;
    }

    LimparTela();
    printf("\nExclusao Sucedida.\n");
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

    NumCategorias--;
}

void ExcluirEncontros(int encontro)
{
    // Fazer Funcao para excluir encontros!!!!!!!!!!!!
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
    free(local->nome_local);
    free(local->endereco.logradouro);
    free(local->endereco.bairro);
    free(local->endereco.cidade);
    free(local->endereco.estado);
}

void LimpaPonteiroCategoria(Categoria *categoria)
{
    free(categoria->nome);
}

void LimpaPonteiroEncontro(Encontro *encontro)
{

    free(encontro->amigos->nome);
    free(encontro->amigos->apelido);
    free(encontro->amigos->email);
    free(encontro->amigos->telefone);
    free(encontro->locais->nome_local);
    free(encontro->locais->endereco.estado);
    free(encontro->locais->endereco.cidade);
    free(encontro->locais->endereco.bairro);
    free(encontro->locais->endereco.logradouro);
    free(encontro->categorias->nome);
    free(encontro->descricao);
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

int ValidarHorario(int hora, int min)
{
    if (hora < 1 || hora > 24)
    {
        return -20;
    }
    else if (min < 1 || min > 60)
    {
        return -21;
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
#ifdef _WIN32
    fflush(stdin);
#elif __linux__
    __fpurge(stdin);
#else
#error "Sistema operacional não suportado."
#endif
}

void LimparTela()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear")
#else
#error "Sistema operacional não suportado."
#endif
}
