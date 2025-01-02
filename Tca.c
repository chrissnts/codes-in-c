#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

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
    char *nome;
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

// COISAS IMPORTANTES!!!!!!!!!!!!!!!!!!!! **************************************************
// ARRUMAR FUNCAO DE RECUPERAR AMIGO;
// ARRUMAR LISTAR POR CATEGORIAS;
// CRIAR OPCAO DE EXCLUIR TODOS DE UMA VEZ; (TALVEZ FAÇA, SO TALVEZ);

void MensagemErro(int erro); // imprime mensagens de erro;

void Menu();                   // imprime menu principal;
void MenuAmigo();              // imprime menu amigo;
void MenuLocal();              // imprime menu local;
void MenuCategoria();          // imprime menu categoria;
void MenuEncontro();           // imprime menu encontro;
void MenuRelatorio();          // imprime menu relatorio;
void MenuModificarAmigo();     // imprime menu para qual o usuario deseja modificar;
void MenuModificarLocais();    // imprime menu para qual o usuario deseja modificar;
void MenuModificarEncontros(); // imprime menu para qual o usuario deseja modificar;

void MenuEncontroAmigo();     // faz a validacao e procede;
void MenuEncontroCategoria(); // faz a validacao e procede;

void MenuRelatorioListarAmigos();     // menu para perguntar se sera listados todos ou especifico por apelido;
void MenuRelatorioListarLocais();     // menu para perguntar se sera listados todos ou especifico;
void MenuRelatorioListarCategorias(); // menu para perguntar se sera listado;
void MenuRelatorioListarEncontros();  // menu para perguntar se sera listado;

void OpcaoMenu();          //   faz a validacao e procede;
void OpcaoMenuAmigo();     //   faz validacao e procede;
void OpcaoMenuLocal();     //   faz validacao e procede;
void OpcaoMenuCategoria(); //   faz validacao e procede;
void OpcaoMenuEncontro();  //   faz validacao e procede;
void OpcaoMenuRelatorio(); //   faz validacao e procede;

void OpcaoMenuRelatorioListarAmigos();     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarLocais();     // recebe a opcao se vai ser todos ou especifico com apelido e procede;
void OpcaoMenuRelatorioListarCategorias(); // recebe a opcao se vai ser todos ou deseja voltar e procede;
void OpcaoMenuRelatorioListarEncontros();  // recebe a opcao se vai ser todos ou especifico e procede;
void QuantidadeRegistros();                // imprimi a quantidade de quantos amigos/locais/categorias/encontros tem cadastrados;
void ListarEncontrosPorCategorias();       // mostrar em qual categoria esta cada encontro (imprimindo os mesmo);

void ImprimirAmigos(Amigo amigos);             // imprime amigos;
void ImprimirLocais(Local locais);             // imprime locais;
void ImprimirCategorias(Categoria categorias); // imprime categorias;
void ImprimirEncontros(Encontro encontros);    // imprime encontros;

void AlterarAmigos(int amigo, int op);                    // modifica os dados do amigo na hora de Alterar;
void AlterarLocais(int local, int op);                    // modifica os dados do local na hora de Alterar;
void AlterarCategorias(int categorias);                   // modifica os dados da categoria na hora de Alterar;
void AlterarEncontros(int encontros, int op);             // modifica os dados do encontro na hora de Alterar;
void AlterarEncontroListarAmigos(Encontro encontros);     // lista os amigos que estao no encontro que o usuario deseja;
void AlterarEncontroListarCategorias(Encontro encontros); // lista as categorias que estao no encontro que o usuario deseja;
void ExcluirAmigos(int amigo);                            // dispara qual amigo o usuario deseja excluir;
void ExcluirLocais(int local);                            // dispara qual local o usuario deseja excluir;
void ExcluirCategorias(int categoria);                    // dispara qual categoria o usuario deseja excluir;
void ExcluirEncontros(int encontro);                      // dispara qual categoria o usuario deseja excluir;

void AdicionarAmigoEncontro(int encontro);     // adiciona um amigo no encontro que o usario quer;
void AdicionarCategoriaEncontro(int encontro); // adiciona uma categoria no encontro que o usuario quer;

void ModificarAmigoEncontro(int encontro);     // modifica um amigo que o usario quer no encontro desejado;
void ModificarCategoriaEncontro(int encontro); // modifica uma categoria que o usuario quer no encontro desejado;
void ModificarLocalEncontro(int encontro);     // modifica o local que o usuario quer no encontro desejado;
void ModificarDataEncontro(int encontro);      // modifica a data que o usuario quer no encontro desejado;
void ModificarHorarioEncontro(int encontro);   // modifica o horario que o usuario quer no encontro desejado;
void ModificarDescricaoEncontro(int encontro); // modifica a descricao que o usuario quer no encontro desejado;

void DeletarAmigoEncontro(int encontro);     // deleta um amigo do encontro desejado;
void DeletarCategoriaEncontro(int encontro); // deleta uma categoria do encontro desejado;

void VoltarMenuPrincipal(); // volta/chama o menu principal e ja le a opcao direto;
void VoltarMenuRelatorio(); // volta/chama o menu de relatorio e ja le a opcao direto;

void LimpaPonteiroAmigo(Amigo *amigo);             // limpa o ponteiro de amigos;
void LimpaPonteiroLocal(Local *local);             // limpa o ponteiro de locais;
void LimpaPonteiroCategoria(Categoria *categoria); // limpa ponteiro de categorias;
void LimpaPonteiroEncontro(Encontro *encontro);    // limpa ponteiro de encontros;

void OrdenarCategorias(); // ordena as categorias por ordem alfabetica;

void Pausar(int pause); // verifica se o pause eh true ou false e pausa;
void LimparBuffer();    // limpa o buffer do teclado;
void LimparTela();      // limpa a tela (criei por conta da miseria do linux);

void SalvarAmigos();        // salva os dados dos amigos que estava na memoria, em um arquivo;
void SalvarLocais();        // salva os dados dos locais que estava na memoria, em um arquivo;
void SalvarCategorias();    // salva os dados das categorias que estava na memoria, em um arquivo;
void SalvarEncontros();     // salva os dados dos encotros que estava na memoria, em um arquivo;
void SalvarArquivos();      // faz a verificacao dos arquivos e salva todos eles;
void RecuperarAmigos();     // recupera os dados dos amigos que estavam no arquivo;
void RecuperarLocais();     // recupera os dados dos locais que estavam no arquivo;
void RecuperarCategorias(); // recupera os dados das categorias que estavam no arquivo;
void RecuperarEncontros();  // recupera os dados dos encontros que estavam no arquivo;
void RecuperarArquivos();

int IncluirAmigos();       // inclui na funcao o amigo criado na funcao "cria amigo";
int IncluirLocais();       // inclui na funcao o local criado na funcao "cria local";
int IncluirCategorias();   // inlcui na funcao o encontro criado na funcao "cria categoria"
int IncluirEncontros();    // inlcui na funcao o encontro criado na funcao "cria encontro"
int ModificarAmigos();     // alterar amigo;
int ModificarLocais();     // alterar local;
int ModificarCategorias(); // alterar categorias;
int ModificarEncontros();  // alterar encontros;
int DeletarAmigos();       // deleta um amigo;
int DeletarLocais();       // deleta um local;
int DeletarCategorias();   // deleta uma categoria;
int DeletarEncontros();    // deleta um encontro;

int ListarAmigos();                    // lista os amigos que ja estao cadastrados;
int ListarAmigosPorApelido();          // faz a logica de listar amigo por apelido;
int ListarLocais();                    // lista os locais que ja estao cadastrados;
int ListarLocaisPorEstado();           // faz a logica de listar locais por estado;
int ListarLocaisPorCidade();           // faz a logica de listar locais por cidade;
int ListarLocaisPorBairro();           // faz a logica de listar locais por bairro;
int ListarCategorias();                // lista as categorias que ja estao cadastradas;
int ListarCategoriasOrdemAlfabetica(); // lista as categorias cadastradas em ordem alfabetica;
int ListarEncontros();                 // lista os encontros que ja estao cadastradao;
int ListarEncontrosPorAmigos();        // busca pelos encontros com esse amigo;

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
    RecuperarArquivos();
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
        printf("\nErro. Encontro invalido ou nao encontrado.\n");
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
        printf("\nEncontro Invalido.");
        break;
    case -24:
        LimparTela();
        printf("\nErro. Categoria ja incluida no encontro.\n");
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
        printf("\nErro. Amigos insuficientes. Inclua mais amigos no sistema");
        break;

    case -30:
        LimparTela();
        printf("\nErro. Amigo qual deseja excluir esta em um encontro. Exclua primeiro o encontro.");
        break;

    case -31:
        LimparTela();
        printf("\nErro. Local qual deseja excluir esta em um encontro. Exclua primeiro o encontro.");
        break;

    case -32:
        LimparTela();
        printf("\nErro. Categoria qual deseja excluir esta em um encontro. Exclua primeiro o encontro.");
        break;

    case -33:
        LimparTela();
        printf("\nErro. Categoria Invalida.");
        break;

    case -34:
        LimparTela();
        printf("\nErro. Local ja incluido no encontro.");
        break;

    case -35:
        LimparTela();
        printf("\nErro. Locais insuficientes. Inlcua mais locais no sistema");
        break;

    case -36:
        LimparTela();
        printf("\nErro. Categorias insuficientes. Inclua mais categorias no sistema");
        break;

    case -37:
        LimparTela();
        printf("\nErro. Categoria invalida.");
        break;

    case -38:
        LimparTela();
        printf("\nErro. Apenas um amigo no encontro. Impossivel excluir. Exclua o encontro.\n");
        break;

    case -39:
        LimparTela();
        printf("\nErro. Apenas uma categoria no encontro. Impossivel excluir. Exclua o encontro.\n");
        break;

    case -40:
        LimparTela();
        printf("\nErro. Nao foi possivel salvar o arquivo de amigos.\n");
        break;

    case -41:
        LimparTela();
        printf("\nErro. Nao foi possivel salvar o arquivo de locais.\n");
        break;

    case -42:
        LimparTela();
        printf("\nErro. Nao foi possivel salvar o arquivo de categorias.\n");
        break;
    case -43:
        LimparTela();
        printf("\nErro. Nao foi possivel salvar o arquivo de encontros.\n");
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
    printf("\n5. Quantidade de Registros Cadastrados\n");
    printf("\n6. Relatorio de Encontros por Categoria\n");
    printf("\n7. Voltar\n");
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
    printf("\n2. Listar em Ordem Alfabetica\n");
    printf("\n3. Voltar\n");
    printf("\n4. Voltar Menu Principal\n");
}

void MenuRelatorioListarEncontros()
{
    LimparTela();
    printf("\n1. Listar Todos\n");
    printf("\n2. Listar por Amigos\n");
    printf("\n3. Voltar\n");
    printf("\n4. Voltar Menu Principal\n");
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

void MenuModificarEncontros()
{
    LimparTela();
    printf("\nModificar:\n");
    printf("\n1. Amigo\n");
    printf("\n2. Local\n");
    printf("\n3. Categoria\n");
    printf("\n4. Data\n");
    printf("\n5. Horario\n");
    printf("\n6. Descricao\n");
}

void MenuEncontroAmigo()
{
    LimparTela();
    printf("\n1 - Adicionar amigo\n");
    printf("\n2 - Modificar amigo\n");
    printf("\n3 - Excluir amigo\n");
}

void MenuEncontroCategoria()
{
    LimparTela();
    printf("\n1 - Adicionar categoria\n");
    printf("\n2 - Modificar categoria\n");
    printf("\n3 - Excluir categoria\n");
}

void OpcaoMenu()
{
    int op = 0;

    do
    {

        Menu();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 6)
        {
            MensagemErro(0);
            Pausar(1);
            Menu();
            scanf("%i", &op);
            LimparBuffer();
        }

        if (op == 1)
        {
            OpcaoMenuAmigo();
        }
        else if (op == 2)
        {
            OpcaoMenuLocal();
        }
        else if (op == 3)
        {
            OpcaoMenuCategoria();
        }
        else if (op == 4)
        {
            OpcaoMenuEncontro();
        }
        else if (op == 5)
        {
            VoltarMenuRelatorio();
        }
        // salva os arquivos (se tiver algo para salvar, e sai do programa);
        else if (op == 6)
        {
            LimparTela();
            SalvarArquivos();
            exit(0);
        }

    } while (op != 6);
}

Amigo CriaAmigo()
{

    Amigo amigo;

    int erro = -1;
    int i;
    char strAux[100];

    LimparTela();
    printf("\nNome:\n");
    LimparBuffer();
    gets(strAux);
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
        OpcaoMenuAmigo();
    }

    LimparTela();
    printf("\nApelido:\n");
    LimparBuffer();
    gets(strAux);
    amigo.apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.apelido, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nEmail:\n");
    LimparBuffer();
    gets(strAux);
    amigo.email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.email, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nTelefone:\n");
    LimparBuffer();
    gets(strAux);
    amigo.telefone = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(amigo.telefone, strAux);
    LimparBuffer();

    while (erro < 0)
    {
        LimparTela(); // força o usuario digitar data de nascimento seguindo os parametros de data
        printf("\nData de nascimento [dd/mm/yy]:\n");
        scanf("%i%i%i", &amigo.datanasc.dia, &amigo.datanasc.mes, &amigo.datanasc.ano);
        LimparBuffer();
        erro = ValidarData(amigo.datanasc.dia, amigo.datanasc.mes, amigo.datanasc.ano);

        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
            continue;
        }
    }
    return amigo;
}

Local CriaLocal()
{
    Local local;
    int i;
    char strAux[100];

    LimparTela();
    printf("\nNome do Local:\n");
    LimparBuffer();
    gets(strAux);
    local.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.nome, strAux);
    LimparBuffer();

    int localcriado = 0;
    for (i = 0; i < NumLocais; i++)
    {
        if (strcmp(Locais[i].nome, local.nome) == 0)
        {
            localcriado = 1;
            break;
        }
    }

    if (localcriado)
    {
        MensagemErro(-26);
        Pausar(1);
        OpcaoMenuLocal();
    }

    LimparTela();
    printf("\nEstado:\n");
    LimparBuffer();
    gets(strAux);
    local.endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.estado, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nCidade:\n");
    LimparBuffer();
    gets(strAux);
    local.endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.cidade, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nBairro:\n");
    LimparBuffer();
    gets(strAux);
    local.endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(local.endereco.bairro, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nLogradouro:\n");
    LimparBuffer();
    gets(strAux);
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

    LimparTela();
    printf("\nCategoria:\n");
    LimparBuffer();
    gets(strAux);
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
        OpcaoMenuCategoria();
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
            continue;
        }
        else
        {
            // verifica se ja existe um amigo com o mesmo nome;
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
                MensagemErro(-24);
                Pausar(1);
                continue;
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
                    LimparTela();
                    printf("\nAmigo incluido com sucesso.\n");
                    encontro.numamigos++;
                    Pausar(1);
                }
                else
                {
                    MensagemErro(-7);
                    exit(0);
                }

                if (NumAmigos == 1)
                {
                    incluir = 0;
                    break;
                }
                op = 'x';
                while (op != 's' && op != 'n')
                {
                    // caso o numero de amigos incluidos seja menor = nao tem amigos suficientes para adicionar, ent so pula;
                    if (NumAmigos <= encontro.numamigos)
                    {
                        incluir = 0;
                        break;
                    }
                    LimparTela();
                    printf("\nDeseja incluir mais algum amigo no encontro? (s) (n)\n");
                    scanf("%c", &op);
                    LimparBuffer();
                    op = tolower(op);

                    // verifica se pode adicionar mais um amigo ou nao (se o tanto de amigos nao ultrapassa o tanto do encontros);
                    if (op == 's')
                    {
                        continue;
                    }
                    else if (op == 'n')
                    {
                        incluir = 0;
                    }
                    else
                    {
                        MensagemErro(0);
                        Pausar(1);
                        continue;
                    }
                }
            }
        }
    }

    erro = -1;
    while (erro < 0)
    {
        LimparTela();
        printf("\n--- Locais ---\n");
        for (i = 0; i < NumLocais; i++)
        {
            printf("\n%i. %s\n", i + 1, Locais[i].nome);
        }

        printf("\nDigite o local que deseja ir com o amigo:\n");
        scanf("%i", &local);
        LimparBuffer();
        local--;
        if (local < 0 || local >= NumLocais)
        {
            erro = -11;
            MensagemErro(erro);
            Pausar(1);
            continue;
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
                encontro.locais[encontro.numlocais].nome = (char *)malloc((strlen(Locais[local].nome) + 1) * sizeof(char));
                strcpy(encontro.locais[encontro.numlocais].nome, Locais[local].nome);
                LimparTela();
                printf("\nLocal incluido com sucesso.\n");
                encontro.numlocais++;
                Pausar(1);
                erro = 1;
            }
            else
            {
                MensagemErro(-7);
                exit(0);
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
            MensagemErro(-33);
            Pausar(1);
            continue;
        }
        else
        {
            // verifica se ja existe um amigo com o mesmo nome;
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
                continue;
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
                    Pausar(1);
                }
                else
                {
                    MensagemErro(-7);
                    exit(0);
                }

                if (NumCategorias == 1)
                {
                    incluir = 0;
                    break;
                }
                op = 'x';
                while (op != 's' && op != 'n')
                {
                    // caso o numero de categorias incluidos seja menor = nao tem categorias suficientes para adicionar, ent so pula;
                    if (NumCategorias <= encontro.numcategorias)
                    {
                        incluir = 0;
                        break;
                    }
                    LimparTela();
                    printf("\nDeseja incluir mais alguma categoria no encontro? (s) (n)\n");
                    scanf("%c", &op);
                    LimparBuffer();
                    op = tolower(op);

                    // verifica se pode adicionar mais uma categoria ou nao (se o tanto de categorias nao ultrapassa o tanto do encontros);
                    if (op == 's')
                    {
                        continue;
                    }
                    else if (op == 'n')
                    {
                        incluir = 0;
                    }
                    else
                    {
                        MensagemErro(0);
                        Pausar(1);
                        continue;
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
            continue;
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
            continue;
        }
    }

    printf("\nDescricao do encontro:\n");
    LimparBuffer();
    gets(strAux);
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

    if (NumAmigos <= 0)
    {
        return -2;
    }
    else if (NumLocais <= 0)
    {
        return -5;
    }
    else if (NumCategorias <= 0)
    {
        return -14;
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
    printf("\nNome: %s", amigos.nome);
    printf("\nApelido: %s", amigos.apelido);
    printf("\nEmail: %s", amigos.email);
    printf("\nTelefone: %s", amigos.telefone);
    printf("\nData Nascimento: [%02i/%02i/%i]\n", amigos.datanasc.dia, amigos.datanasc.mes, amigos.datanasc.ano);
}

void ImprimirLocais(Local locais)
{
    printf("\nNome do Local: %s", locais.nome);
    printf("\nEstado: %s", locais.endereco.estado);
    printf("\nCidade: %s", locais.endereco.cidade);
    printf("\nBairro: %s", locais.endereco.bairro);
    printf("\nLogradouro: %s", locais.endereco.logradouro);
    printf("\nNumero: %i\n", locais.endereco.numero);
}

void ImprimirCategorias(Categoria categorias)
{
    printf("\nCategoria: %s", categorias.nome);
}

void ImprimirEncontros(Encontro encontros)
{
    if (encontros.numamigos == 1)
    {
        printf("\nAmigo: %s", encontros.amigos->nome);
    }
    else
    {
        printf("\nAmigos: ");
        for (int i = 0; i < encontros.numamigos; i++)
        {
            if (i < encontros.numamigos - 1)
            {
                printf("%s ", encontros.amigos[i].nome);
            }
            else
            {
                printf("%s ", encontros.amigos[i].nome);
            }
        }
    }
    printf("\nLocal: %s", encontros.locais->nome);
    if (encontros.numcategorias == 1)
    {
        printf("\nCategoria: %s", encontros.categorias->nome);
    }
    else
    {
        printf("\nCategorias: ");
        for (int j = 0; j < encontros.numcategorias; j++)
        {
            if (j < encontros.numcategorias - 1)
            {
                printf("%s ", encontros.categorias[j].nome);
            }
            else
            {
                printf("%s ", encontros.categorias[j].nome);
            }
        }
    }
    printf("\nData: [%02i/%02i/%i]\n", encontros.data.dia, encontros.data.mes, encontros.data.ano);
    printf("\nHorario: [%02ih:%02im]\n", encontros.horario.hora, encontros.horario.minuto);
    printf("\nDescricao: %s\n", encontros.descricao);
}

void OpcaoMenuAmigo()
{
    int erro = 0;
    int op = 0;

    do
    {
        MenuAmigo();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuAmigo();
            scanf("%i", &op);
            LimparBuffer();
        }
        switch (op)
        {
        case 1:
            erro = IncluirAmigos();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 2:
            erro = ModificarAmigos();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 3:
            erro = DeletarAmigos();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 4:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (op != 4);
}

void OpcaoMenuLocal()
{
    int erro = 1;
    int op = 0;

    do
    {
        MenuLocal();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuLocal();
            scanf("%i", &op);
            LimparBuffer();
        }

        switch (op)
        {
        case 1:
            erro = IncluirLocais();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 2:
            erro = ModificarLocais();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 3:
            erro = DeletarLocais();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 4:
            VoltarMenuPrincipal();
            break;
        default:
            printf("\nErro\n.");
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (op != 4);
}

void OpcaoMenuCategoria()
{
    int erro = 1;
    int op = 0;

    do
    {
        MenuCategoria();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuCategoria();
            scanf("%i", &op);
            LimparBuffer();
        }

        switch (op)
        {
        case 1:
            erro = IncluirCategorias();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 2:
            erro = ModificarCategorias();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 3:
            erro = DeletarCategorias();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 4:
            VoltarMenuPrincipal();
            break;
        default:
            printf("\nErro\n.");
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (op != 4);
}

void OpcaoMenuEncontro()
{
    int erro = 1;
    int op = 0;

    do
    {
        MenuEncontro();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuEncontro();
            scanf("%i", &op);
            LimparBuffer();
        }

        switch (op)
        {

        case 1:
            erro = IncluirEncontros();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 2:
            erro = ModificarEncontros();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 3:
            erro = DeletarEncontros();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 4:
            VoltarMenuPrincipal();
            break;

        default:
            printf("\nErro\n.");
            Pausar(1);
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (op != 4);
}

void OpcaoMenuRelatorio()
{
    int erro = 1;
    int op = 0;

    do
    {
        MenuRelatorio();
        scanf("%i", &op);
        LimparBuffer();

        while (op < 1 || op > 7)
        {
            MensagemErro(0);
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
                OpcaoMenuRelatorioListarAmigos();
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
                OpcaoMenuRelatorioListarLocais();
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
                OpcaoMenuRelatorioListarCategorias();
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
                OpcaoMenuRelatorioListarEncontros();
                return;
            }
            break;

        case 5:
            QuantidadeRegistros();
            break;

        case 6:
            if (NumEncontros <= 0)
            {
                erro = -16;
            }
            else
            {
                ListarEncontrosPorCategorias();
                Pausar(1);
            }
            break;

        case 7:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (op != 7 || op != 5);
}

void OpcaoMenuRelatorioListarAmigos()
{
    int erro = 1;
    int opr = 0;

    do
    {
        MenuRelatorioListarAmigos();
        scanf("%i", &opr);
        LimparBuffer();

        while (opr < 1 || opr > 4)
        {
            MensagemErro(0);
            MenuRelatorioListarAmigos();
            scanf("%i", &opr);
            LimparBuffer();
        }

        switch (opr)
        {
        case 1:
            erro = ListarAmigos();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 2:
            erro = ListarAmigosPorApelido();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 3:
            VoltarMenuRelatorio();
            break;
        case 4:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (opr != 3 || opr != 4);
}

void OpcaoMenuRelatorioListarLocais()
{
    int erro = 1;
    int opr = 0;

    do
    {
        MenuRelatorioListarLocais();
        scanf("%i", &opr);
        LimparBuffer();

        while (opr < 1 || opr > 6)
        {
            MensagemErro(0);
            Pausar(1);
            MenuRelatorioListarLocais();
            scanf("%i", &opr);
            LimparBuffer();
        }

        switch (opr)
        {

        case 1:
            erro = ListarLocais();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 2:
            erro = ListarLocaisPorEstado();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 3:
            erro = ListarLocaisPorCidade();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 4:
            erro = ListarLocaisPorBairro();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 5:
            VoltarMenuRelatorio();
            break;

        case 6:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (opr != 5 || opr != 6);
}

void OpcaoMenuRelatorioListarCategorias()
{
    int erro = 1;
    int opr = 0;

    do
    {
        MenuRelatorioListarCategorias();
        scanf("%i", &opr);
        LimparBuffer();

        while (opr < 1 || opr > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuRelatorioListarCategorias();
            scanf("%i", &opr);
            LimparBuffer();
        }

        switch (opr)
        {
        case 1:
            erro = ListarCategorias();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 2:
            erro = ListarCategoriasOrdemAlfabetica();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;

        case 3:
            VoltarMenuRelatorio();
            break;

        case 4:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (opr != 3 || opr != 4);
}

void OpcaoMenuRelatorioListarEncontros()
{
    int erro = 1;
    int opr = 0;

    do
    {
        MenuRelatorioListarEncontros();
        scanf("%i", &opr);
        LimparBuffer();

        while (opr < 1 || opr > 4)
        {
            MensagemErro(0);
            Pausar(1);
            MenuRelatorioListarEncontros();
            scanf("%i", &opr);
            LimparBuffer();
        }

        switch (opr)
        {
        case 1:
            erro = ListarEncontros();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 2:
            erro = ListarEncontrosPorAmigos();
            if (erro > 0)
            {
                Pausar(1);
            }
            break;
        case 3:
            VoltarMenuRelatorio();
            break;
        case 4:
            VoltarMenuPrincipal();
            break;
        }

        if (erro <= 0)
        {
            MensagemErro(erro);
            Pausar(1);
        }

    } while (opr != 3 || opr != 4);
}

int ListarAmigos()
{
    if (NumAmigos <= 0)
    {
        return -2;
    }

    LimparTela();
    for (int i = 0; i < NumAmigos; i++)
    {
        printf("\n");
        printf("\n-- Amigo [%i] --\n", i + 1);
        ImprimirAmigos(Amigos[i]);
        printf("\n");
    }

    return 1;
}

int ListarAmigosPorApelido()
{
    char apelido[50];
    int encontrado = 0;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    LimparTela();
    printf("\nDigite o apelido do amigo: \n");
    LimparBuffer();
    gets(apelido);
    LimparBuffer();

    LimparTela();
    for (int i = 0; i < NumAmigos; i++)
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
    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    for (int i = 0; i < NumLocais; i++)
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
    int encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o estado: \n");
    gets(estado);
    LimparBuffer();

    LimparTela();
    for (int i = 0; i < NumLocais; i++)
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
    int encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o cidade: \n");
    gets(cidade);
    LimparBuffer();

    LimparTela();
    for (int i = 0; i < NumLocais; i++)
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
    int encontrado = 0;

    if (NumLocais <= 0)
    {
        return -5;
    }

    LimparTela();
    printf("\nDigite o bairro: \n");
    gets(bairro);
    LimparBuffer();

    LimparTela();
    for (int i = 0; i < NumLocais; i++)
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
    if (NumCategorias <= 0)
    {
        return -14;
    }

    LimparTela();
    for (int i = 0; i < NumCategorias; i++)
    {
        printf("\n");
        printf("\n-- Categoria  [%i] --\n", i + 1);
        ImprimirCategorias(Categorias[i]);
    }

    return 1;
}

int ListarCategoriasOrdemAlfabetica()
{
    if (NumCategorias <= 0)
    {
        return -14;
    }

    // ordenas as categorias em ordem alfabetica (usando bubble sort);
    OrdenarCategorias();

    LimparTela();
    for (int i = 0; i < NumCategorias; i++)
    {
        printf("\n");
        printf("\n-- Categoria  [%i] --\n", i + 1);
        ImprimirCategorias(Categorias[i]);
    }

    return 1;
}

int ListarEncontros()
{
    if (NumEncontros <= 0)
    {
        return -16;
    }

    LimparTela();
    for (int i = 0; i < NumEncontros; i++)
    {
        printf("\n");
        printf("\n-- Encontro  [%i] --\n", i + 1);
        ImprimirEncontros(Encontros[i]);
    }

    return 1;
}

int ListarEncontrosPorAmigos()
{
    char nome[100];
    int encontrado = 0;

    if (NumEncontros <= 0)
    {
        return -16;
    }

    LimparTela();
    printf("\nDigite o nome do amigo: \n");
    LimparBuffer();
    gets(nome);
    LimparBuffer();

    LimparTela();
    for (int i = 0; i < NumEncontros; i++)
    {
        for (int j = 0; j < Encontros[i].numamigos; j++)
        {
            if (strcmp(Encontros[i].amigos[j].nome, nome) == 0)
            {
                printf("\n");
                printf("\n-- Encontro  [%i] --\n", i + 1);
                ImprimirEncontros(Encontros[i]);
                encontrado = 1;
            }
        }
    }

    if (!encontrado)
    {
        return -19;
    }

    return 1;
}

void QuantidadeRegistros()
{
    LimparTela();
    printf("\n-- Total de Registros --\n");
    printf("\nAmigos: %i\n", NumAmigos);
    printf("\nLocais: %i\n", NumLocais);
    printf("\nCategorias: %i\n", NumCategorias);
    printf("\nEncontros: %i\n", NumEncontros);
    Pausar(1);
}

// ARRUMAR !!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!
void ListarEncontrosPorCategorias()
{

    LimparTela();
    for (int i = 0; i < NumEncontros; i++)
    {
        for (int j = 0; j < Encontros[i].numcategorias; j++)
        {
            printf("\n-- Categoria: %s --\n", Encontros[i].categorias[j].nome);

            for (int k = 0; k < NumCategorias; k++)
            {

                if (strcmp(Encontros[i].categorias[j].nome, Categorias[k].nome) == 0)
                {
                    if (Encontros[i].numamigos == 1)
                    {
                        printf("\nAmigo: %s", Encontros[i].amigos->nome);
                    }
                    else
                    {
                        printf("\nAmigos: ");
                        for (int l = 0; l < Encontros[i].numamigos; l++)
                        {
                            if (l < Encontros[i].numamigos - 1)
                            {
                                printf("%s ", Encontros[i].amigos[l].nome);
                            }
                            else
                            {
                                printf("%s ", Encontros[i].amigos[l].nome);
                            }
                        }
                    }
                    printf("\nLocal: %s", Encontros[i].locais->nome);
                    printf("\nData: [%02i/%02i/%i]\n", Encontros[i].data.dia, Encontros[i].data.mes, Encontros[i].data.ano);
                    printf("\nHorario: [%02ih:%02im]\n", Encontros[i].horario.hora, Encontros[i].horario.minuto);
                    printf("\nDescricao: %s\n", Encontros[i].descricao);
                }
            }
        }
    }
}

void AlterarAmigos(int amigo, int op)
{
    int erro = -1;
    char strAux[100];

    if (op == 1)
    {

        LimparTela();
        printf("\nNovo nome:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();

        // verificando se tem o amigo desejado dentro de algum encontro, para pode modificar tambem;
        for (int i = 0; i < NumEncontros; i++)
        {
            for (int j = 0; j < Encontros[i].numamigos; j++)
            {
                if (strcmp(Encontros[i].amigos[j].nome, Amigos[amigo].nome) == 0)
                {
                    if (Encontros[i].amigos[j].nome != NULL)
                    {
                        free(Encontros[i].amigos[j].nome);
                    }
                    Encontros[i].amigos[j].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    if (Encontros[i].amigos[j].nome == NULL)
                    {
                        MensagemErro(-7);
                        exit(0);
                    }
                    strcpy(Encontros[i].amigos[j].nome, strAux);
                    LimparBuffer();
                }
            }
        }

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
        printf("\nNovo apelido:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();

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
        printf("\nNovo email:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();

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
        printf("\nNovo telefone:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();

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
            printf("\nNova data de nascimento [dd/mm/yy]:\n");
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
        printf("\nNovo nome do Local:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();

        // verificando se tem o local desejado dentro de algum encontro, para pode modificar tambem;
        for (int i = 0; i < NumEncontros; i++)
        {
            for (int j = 0; j < Encontros[i].numlocais; j++)
            {
                if (strcmp(Encontros[i].amigos[j].nome, Locais[local].nome) == 0)
                {
                    if (Encontros[i].locais[j].nome != NULL)
                    {
                        free(Encontros[i].locais[j].nome);
                    }
                    Encontros[i].locais[j].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    if (Encontros[i].locais[j].nome == NULL)
                    {
                        MensagemErro(-7);
                        exit(0);
                    }
                    strcpy(Encontros[i].locais[j].nome, strAux);
                    LimparBuffer();
                }
            }
        }

        if (Locais[local].nome != NULL)
        {
            free(Locais[local].nome);
        }
        Locais[local].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        if (Locais[local].nome == NULL)
        {
            MensagemErro(-7);
            exit(0);
        }
        strcpy(Locais[local].nome, strAux);
        LimparBuffer();
    }
    else if (op == 2)
    {
        LimparTela();
        printf("\nNovo estado:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();
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
        printf("\nNova cidade:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();
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
        printf("\nNovo bairro:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();
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
        printf("\nNovo logradouro:\n");
        LimparBuffer();
        gets(strAux);
        LimparBuffer();
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
        printf("\nNovo numero:\n");
        scanf("%i", &Locais[local].endereco.numero);
        LimparBuffer();
    }
}

void AlterarCategorias(int categoria)
{
    char strAux[100];

    LimparTela();
    printf("\nNova categoria:\n");
    LimparBuffer();
    gets(strAux);
    LimparBuffer();

    // verificando se tem a categoria desejada dentro de algum encontro, para pode modificar tambem;
    for (int i = 0; i < NumEncontros; i++)
    {
        for (int j = 0; j < Encontros[i].numcategorias; j++)
        {
            if (strcmp(Encontros[i].categorias[j].nome, Categorias[categoria].nome) == 0)
            {
                if (Encontros[i].categorias[j].nome != NULL)
                {
                    free(Encontros[i].locais[j].nome);
                }
                Encontros[i].categorias[j].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                if (Encontros[i].categorias[j].nome == NULL)
                {
                    MensagemErro(-7);
                    exit(0);
                }
                strcpy(Encontros[i].categorias[j].nome, strAux);
                LimparBuffer();
            }
        }
    }

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

void AlterarEncontros(int encontro, int op)
{
    int opaux;

    if (op == 1)
    {
        while (1)
        {
            MenuEncontroAmigo();
            scanf("%i", &opaux);
            LimparBuffer();
            if (opaux < 1 || opaux > 3)
            {
                MensagemErro(0);
                Pausar(1);
                continue;
            }
            else
            {
                break;
            }
        }

        switch (opaux)
        {

        case 1:
            AdicionarAmigoEncontro(encontro);
            break;

        case 2:
            ModificarAmigoEncontro(encontro);
            break;

        case 3:
            DeletarAmigoEncontro(encontro);
            break;
        }
    }
    else if (op == 2)
    {
        ModificarLocalEncontro(encontro);
    }
    else if (op == 3)
    {
        while (1)
        {
            MenuEncontroCategoria();
            scanf("%i", &opaux);
            LimparBuffer();
            if (opaux < 1 || opaux > 3)
            {
                MensagemErro(0);
                Pausar(1);
                continue;
            }
            else
            {
                break;
            }
        }

        switch (opaux)
        {

        case 1:
            AdicionarCategoriaEncontro(encontro);
            break;

        case 2:
            ModificarCategoriaEncontro(encontro);
            break;

        case 3:
            DeletarCategoriaEncontro(encontro);
            break;
        }
    }
    else if (op == 4)
    {
        ModificarDataEncontro(encontro);
    }
    else if (op == 5)
    {
        ModificarHorarioEncontro(encontro);
    }
    else if (op == 6)
    {
        ModificarDescricaoEncontro(encontro);
    }
}

void AdicionarAmigoEncontro(int encontro)
{
    int incluir = 1;
    int amigo;

    // caso nao tenha amigos suficientes para adicionar;
    if (NumAmigos <= Encontros[encontro].numamigos)
    {
        MensagemErro(-28);
    }
    else
    {
        while (incluir)
        {
            LimparTela();
            printf("\n--- Amigos ---\n");
            for (int i = 0; i < NumAmigos; i++)
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
                continue;
            }
            else
            {
                // verifica se ja existe um amigo com o mesmo nome;
                int amigonoencontro = 0;

                for (int i = 0; i < Encontros[encontro].numamigos; i++)
                {
                    if (strcmp(Amigos[amigo].nome, Encontros[encontro].amigos[i].nome) == 0)
                    {
                        amigonoencontro = 1;
                        break;
                    }
                }

                if (amigonoencontro)
                {
                    MensagemErro(-22);
                    Pausar(1);
                    continue;
                }
                else
                {
                    Encontros[encontro].amigos = (Amigo *)realloc(Encontros[encontro].amigos, (Encontros[encontro].numamigos + 1) * sizeof(Amigo));

                    if (Encontros[encontro].amigos != NULL)
                    {
                        Encontros[encontro].amigos[Encontros[encontro].numamigos].nome = (char *)malloc((strlen(Amigos[amigo].nome) + 1) * sizeof(char));
                        strcpy(Encontros[encontro].amigos[Encontros[encontro].numamigos].nome, Amigos[amigo].nome);
                        LimparTela();
                        printf("\nAmigo incluido com sucesso.\n");
                        Encontros[encontro].numamigos++;
                        break;
                    }
                    else
                    {
                        MensagemErro(-7);
                        exit(0);
                    }
                }
            }
        }
    }
}

void AdicionarCategoriaEncontro(int encontro)
{
    int incluir = 1;
    int categoria;

    // caso nao tenha categorias suficientes para adicionar;
    if (NumCategorias <= Encontros[encontro].numcategorias)
    {
        MensagemErro(-28);
        Pausar(1);
    }
    else
    {
        while (incluir)
        {
            LimparTela();
            printf("\n--- Categorias ---\n");
            for (int i = 0; i < NumCategorias; i++)
            {
                printf("\n%i. %s\n", i + 1, Categorias[i].nome);
            }

            printf("\nDigite a categoria que deseja incluir no encontro:\n");
            scanf("%i", &categoria);
            LimparBuffer();
            categoria--;
            if (categoria < 0 || categoria >= NumCategorias)
            {
                MensagemErro(-33);
                Pausar(1);
                continue;
            }
            else
            {
                // verifica se ja existe uma categoria;
                int categorianoencontro = 0;

                for (int i = 0; i < Encontros[encontro].numcategorias; i++)
                {
                    if (strcmp(Categorias[categoria].nome, Encontros[encontro].categorias[i].nome) == 0)
                    {
                        categorianoencontro = 1;
                        break;
                    }
                }

                if (categorianoencontro)
                {
                    MensagemErro(-22);
                    Pausar(1);
                    continue;
                }
                else
                {
                    Encontros[encontro].categorias = (Categoria *)realloc(Encontros[encontro].categorias, (Encontros[encontro].numcategorias + 1) * sizeof(Categoria));

                    if (Encontros[encontro].categorias != NULL)
                    {
                        Encontros[encontro].categorias[Encontros[encontro].numcategorias].nome = (char *)malloc((strlen(Categorias[categoria].nome) + 1) * sizeof(char));
                        strcpy(Encontros[encontro].categorias[Encontros[encontro].numcategorias].nome, Categorias[categoria].nome);
                        LimparTela();
                        printf("\nCategoria incluida com sucesso.\n");
                        Encontros[encontro].numcategorias++;
                        break;
                    }
                    else
                    {
                        MensagemErro(-7);
                        exit(0);
                    }
                }
            }
        }
    }
}

void ModificarAmigoEncontro(int encontro)
{
    int incluir = 1;
    int amigo, amigoaux;

    if (NumAmigos <= Encontros[encontro].numamigos)
    {
        MensagemErro(-36);
    }

    while (incluir)
    {
        AlterarEncontroListarAmigos(Encontros[encontro]);
        printf("\nDigite o amigo que sera substituido do encontro:\n");
        scanf("%i", &amigoaux);
        LimparBuffer();
        amigoaux--;
        if (amigoaux < 0 || amigoaux >= NumAmigos)
        {
            MensagemErro(-3);
            Pausar(1);
            continue;
        }
        else
        {
            while (1)
            {
                LimparTela();
                printf("\n--- Amigos ---\n");
                for (int i = 0; i < NumAmigos; i++)
                {
                    printf("\n%i. %s\n", i + 1, Amigos[i].nome);
                }
                printf("\nDigite o novo amigo que deseja substituir no encontro:\n");
                scanf("%i", &amigo);
                LimparBuffer();
                amigo--;
                if (amigo < 0 || amigo >= NumAmigos)
                {
                    MensagemErro(-3);
                    Pausar(1);
                    continue;
                }
                else
                {
                    // verifica se ja existe um amigo com o mesmo nome;
                    int amigonoencontro = 0;
                    for (int i = 0; i < Encontros[encontro].numamigos; i++)
                    {
                        if (strcmp(Amigos[amigo].nome, Encontros[encontro].amigos[i].nome) == 0)
                        {
                            amigonoencontro = 1;
                            break;
                        }
                    }

                    if (amigonoencontro)
                    {
                        MensagemErro(-22);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        if (Encontros[encontro].amigos[amigoaux].nome != NULL)
                        {
                            free(Encontros[encontro].amigos[amigoaux].nome);
                        }
                        Encontros[encontro].amigos[amigoaux].nome = (char *)malloc((strlen(Amigos[amigo].nome) + 1) * sizeof(char));
                        strcpy(Encontros[encontro].amigos[amigoaux].nome, Amigos[amigo].nome);
                        if (Encontros[encontro].amigos[amigoaux].nome == NULL)
                        {
                            MensagemErro(-7);
                            exit(0);
                        }
                        LimparTela();
                        printf("\nModificado com sucesso.\n");
                        break;
                    }
                }
            }
        }
        break;
    }
}

void ModificarCategoriaEncontro(int encontro)
{
    int incluir = 1;
    int categoria, cateaux;

    if (NumCategorias <= Encontros[encontro].numcategorias)
    {
        MensagemErro(-36);
    }
    while (incluir)
    {
        AlterarEncontroListarCategorias(Encontros[encontro]);
        printf("\nDigite a categoria que deseja substituir no encontro:\n");
        scanf("%i", &cateaux);
        LimparBuffer();
        cateaux--;
        if (cateaux < 0 || cateaux >= NumAmigos)
        {
            MensagemErro(-37);
            Pausar(1);
            continue;
        }
        else
        {
            while (1)
            {
                LimparTela();
                printf("\n--- Categorias ---\n");
                for (int i = 0; i < NumCategorias; i++)
                {
                    printf("\n%i. %s\n", i + 1, Categorias[i].nome);
                }
                printf("\nDigite a nova categoria que deseja substituir no encontro:\n");
                scanf("%i", &categoria);
                LimparBuffer();
                categoria--;
                if (categoria < 0 || categoria >= NumCategorias)
                {
                    MensagemErro(-37);
                    Pausar(1);
                    continue;
                }
                else
                {
                    // verifica se ja existe uma categoria com o mesmo nome;
                    int categorianoencontro = 0;
                    for (int i = 0; i < Encontros[encontro].numcategorias; i++)
                    {
                        if (strcmp(Categorias[categoria].nome, Encontros[encontro].categorias[i].nome) == 0)
                        {
                            categorianoencontro = 1;
                            break;
                        }
                    }

                    if (categorianoencontro)
                    {
                        MensagemErro(-24);
                        Pausar(1);
                        continue;
                    }
                    else
                    {

                        if (Encontros[encontro].categorias[cateaux].nome != NULL)
                        {
                            free(Encontros[encontro].categorias[cateaux].nome);
                        }
                        Encontros[encontro].categorias[cateaux].nome = (char *)malloc((strlen(Categorias[categoria].nome) + 1) * sizeof(char));
                        strcpy(Encontros[encontro].categorias[cateaux].nome, Categorias[categoria].nome);
                        if (Encontros[encontro].categorias[cateaux].nome == NULL)
                        {
                            MensagemErro(-7);
                            exit(0);
                        }
                        LimparTela();
                        printf("\nModificado com sucesso.\n");
                        break;
                    }
                }
            }
        }
        break;
    }
}

void ModificarLocalEncontro(int encontro)
{
    int local;

    // caso nao tenha informacoes suficientes para modificar;
    if (NumLocais <= Encontros[encontro].numlocais)
    {
        MensagemErro(-35);
    }
    while (1)
    {
        LimparTela();
        printf("\n--- Locais ---\n");
        for (int i = 0; i < NumLocais; i++)
        {
            printf("\n%i. %s\n", i + 1, Locais[i].nome);
        }
        printf("\nDigite o novo local que deseja substituir no encontro:\n");
        scanf("%i", &local);
        LimparBuffer();
        local--;
        if (local < 0 || local >= NumLocais)
        {
            MensagemErro(-6);
            Pausar(1);
            continue;
        }
        else
        {
            // verifica se ja existe um local com o mesmo nome;
            int localnoencontro = 0;
            for (int i = 0; i < Encontros[encontro].numlocais; i++)
            {
                if (strcmp(Locais[local].nome, Encontros[encontro].locais[i].nome) == 0)
                {
                    localnoencontro = 1;
                    break;
                }
            }

            if (localnoencontro)
            {
                MensagemErro(-34);
                Pausar(1);
                continue;
            }
            else
            {

                if (Encontros[encontro].locais->nome != NULL)
                {
                    free(Encontros[encontro].locais->nome);
                }
                Encontros[encontro].locais->nome = (char *)malloc((strlen(Locais[local].nome) + 1) * sizeof(char));
                strcpy(Encontros[encontro].locais->nome, Locais[local].nome);
                if (Encontros[encontro].locais->nome == NULL)
                {
                    MensagemErro(-7);
                    exit(0);
                }
                LimparTela();
                printf("\nModificado com sucesso.\n");
                break;
            }
        }
        break;
    }
}

void ModificarDataEncontro(int encontro)
{
    int erro = -1;
    while (erro < 0)
    {
        LimparTela();
        printf("\nNova data do encontro [dd/mm/yy]:\n");
        scanf("%i%i%i", &Encontros[encontro].data.dia, &Encontros[encontro].data.mes, &Encontros[encontro].data.ano);
        LimparBuffer();
        erro = ValidarData(Encontros[encontro].data.dia, Encontros[encontro].data.mes, Encontros[encontro].data.ano);

        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
            continue;
        }
    }
    LimparTela();
    printf("\nModificado com sucesso.\n");
}

void ModificarHorarioEncontro(int encontro)
{
    int erro = -1;
    while (erro < 0)
    {
        LimparTela();
        printf("\nNovo horario do encontro [hora : min]:\n");
        scanf("%i%i", &Encontros[encontro].horario.hora, &Encontros[encontro].horario.minuto);
        LimparBuffer();
        erro = ValidarHorario(Encontros[encontro].horario.hora, Encontros[encontro].horario.minuto);
        if (erro < 0)
        {
            MensagemErro(erro);
            Pausar(1);
            continue;
        }
    }
    LimparTela();
    printf("\nModificado com sucesso.\n");
}

void ModificarDescricaoEncontro(int encontro)
{
    char strAux[100];
    LimparTela();
    printf("\nNova descricao do encontro:\n");
    LimparBuffer();
    gets(strAux);
    LimparBuffer();
    Encontros[encontro].descricao = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(Encontros[encontro].descricao, strAux);
    LimparBuffer();

    LimparTela();
    printf("\nModificado com sucesso.\n");
}

void DeletarAmigoEncontro(int encontro)
{
    int amigo;
    char op;

    // caso tenha apenas 1 amigo no encontro, nao deixar excluir;
    if (Encontros[encontro].numamigos <= 1)
    {
        MensagemErro(-38);
    }
    while (1)
    {

        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {

            AlterarEncontroListarAmigos(Encontros[encontro]);
            printf("\nDigite o amigo que deseja deletar do encontro:\n");
            scanf("%i", &amigo);
            LimparBuffer();
            amigo--;
            if (amigo < 0 || amigo > Encontros[encontro].numamigos)
            {
                MensagemErro(-3);
                Pausar(1);
                continue;
            }
            else
            {
                // limpa a memoria do amigo que estava no encontro;
                if (Encontros[encontro].amigos[amigo].nome != NULL)
                {
                    free(Encontros[encontro].amigos[amigo].nome);
                    Encontros[encontro].amigos[amigo].nome = NULL;
                }

                // reorganiza a lista de amigos no encontro;
                Encontros[encontro].amigos[amigo] = Encontros[encontro].amigos[Encontros[encontro].numamigos - 1];

                Encontros[encontro].numamigos--;

                LimparTela();
                printf("\nDeletado com sucesso.\n");
                break;
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuEncontro();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        break;
    }
}

void DeletarCategoriaEncontro(int encontro)
{
    int categoria;
    char op;

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            // caso tenha apenas 1 categoria no encontro, nao deixar excluir;
            if (Encontros[encontro].numcategorias <= 1)
            {
                MensagemErro(-39);
                Pausar(1);
            }
            else
            {
                AlterarEncontroListarCategorias(Encontros[encontro]);
                printf("\nDigite a categoria que deseja deletar do encontro:\n");
                scanf("%i", &categoria);
                LimparBuffer();
                categoria--;
                if (categoria < 0 || categoria > Encontros[encontro].numcategorias)
                {
                    MensagemErro(-3);
                    Pausar(1);
                    continue;
                }
                else
                {
                    // limpa a memoria da categoria que estava no encontro;
                    if (Encontros[encontro].categorias[categoria].nome != NULL)
                    {
                        free(Encontros[encontro].categorias[categoria].nome);
                        Encontros[encontro].categorias[categoria].nome = NULL;
                    }

                    // reorganiza a lista de categoria no encontro;
                    Encontros[encontro].categorias[categoria] = Encontros[encontro].categorias[Encontros[encontro].numcategorias - 1];

                    Encontros[encontro].numcategorias--;

                    LimparTela();
                    printf("\nDeletado com sucesso.\n");
                    break;
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuEncontro();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        break;
    }
}

int ModificarAmigos()
{
    int amigo;
    char op;
    int opm = 1;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
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
                while (1)
                {
                    ListarAmigos();
                    printf("\nSelecione o amigo que deseja modificar: [ %i - %i]: ", 1, NumAmigos);
                    scanf("%i", &amigo);
                    LimparBuffer();
                    amigo--;

                    if (amigo < 0 || amigo >= NumAmigos)
                    {
                        MensagemErro(-3);
                        Pausar(1);
                        continue;
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
                            else
                            {
                                break;
                            }
                        }
                    }

                    AlterarAmigos(amigo, opm);
                    break;
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuAmigo();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nModificado com sucesso.\n");
        break;
    }
    return 1;
}

int ModificarLocais()
{

    int local;
    char op;
    int opm;

    if (NumLocais <= 0)
    {
        return -5;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
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
                while (1)
                {
                    ListarLocais();
                    printf("\nSelecione o local que deseja modificar: [ %i - %i]: ", 1, NumLocais);
                    scanf("%i", &local);
                    LimparBuffer();
                    local--;

                    if (local < 0 || local >= NumLocais)
                    {
                        MensagemErro(-6);
                        Pausar(1);
                        continue;
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
                            else
                            {
                                break;
                            }
                        }
                    }

                    AlterarLocais(local, opm);
                    break;
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuLocal();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nModificado com sucesso.\n");
        break;
    }
    return 1;
}

int ModificarCategorias()
{

    int categoria = -1;
    char op;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
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
                while (1)
                {
                    ListarCategorias();
                    printf("\nSelecione o categoria que deseja modificar: [ %i - %i]: ", 1, NumCategorias);
                    scanf("%i", &categoria);
                    LimparBuffer();
                    categoria--;

                    if (categoria < 0 || categoria >= NumCategorias)
                    {
                        MensagemErro(-15);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                AlterarCategorias(categoria);
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuCategoria();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nModificado com sucesso.\n");
        break;
    }

    return 1;
}

int ModificarEncontros()
{

    int encontro;
    char op;
    int opm;

    if (NumEncontros <= 0)
    {
        return -16;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            if (NumEncontros == 1)
            {
                while (1)
                {
                    LimparTela();
                    MenuModificarEncontros();
                    scanf("%i", &opm);
                    LimparBuffer();
                    if (opm < 1 || opm > 6)
                    {
                        MensagemErro(0);
                        Pausar(1);
                        continue;
                    }

                    AlterarEncontros(0, opm);
                    break;
                }
            }
            else
            {
                while (1)
                {
                    ListarEncontros();
                    printf("\nSelecione o encontro que deseja modificar: [ %i - %i]: ", 1, NumEncontros);
                    scanf("%i", &encontro);
                    LimparBuffer();
                    encontro--;

                    if (encontro < 0 || encontro >= NumEncontros)
                    {
                        MensagemErro(-17);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        while (1)
                        {
                            LimparTela();
                            MenuModificarEncontros();
                            scanf("%i", &opm);
                            LimparBuffer();
                            if (opm < 1 || opm > 6)
                            {
                                MensagemErro(0);
                                Pausar(1);
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    AlterarEncontros(encontro, opm);
                    break;
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuEncontro();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }
        break;
    }
    return 1;
}

void AlterarEncontroListarAmigos(Encontro encontros)
{
    LimparTela();
    printf("\nAmigos no encontro atual:\n");
    for (int i = 0; i < encontros.numamigos; i++)
    {
        if (i < encontros.numamigos - 1)
        {
            printf("\n%i. %s ", i + 1, encontros.amigos[i].nome);
        }
        else
        {
            printf("\n%i. %s ", i + 1, encontros.amigos[i].nome);
        }
    }
}

void AlterarEncontroListarCategorias(Encontro encontros)
{
    LimparTela();
    printf("\nCategorias no encontro desejado:\n");
    for (int i = 0; i < encontros.numcategorias; i++)
    {
        if (i < encontros.numcategorias - 1)
        {
            printf("\n%i. %s ", i + 1, encontros.categorias[i].nome);
        }
        else
        {
            printf("\n%i. %s ", i + 1, encontros.categorias[i].nome);
        }
    }
}

int DeletarAmigos()
{
    int amigo;
    char op;

    if (NumAmigos <= 0)
    {
        return -2;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            // verifica se o amigo esta em algum encontro, se tiver nao deixa excluir;
            if (NumAmigos == 1)
            {
                for (int i = 0; i < NumEncontros; i++)
                {
                    for (int j = 0; j < Encontros[i].numamigos; j++)
                    {
                        if (strcmp(Amigos[0].nome, Encontros[i].amigos[j].nome) == 0)
                        {
                            return -30;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                ExcluirAmigos(0);
            }
            else
            {
                while (1)
                {
                    ListarAmigos();
                    printf("\nSelecione o amigo que deseja deletar: [ %i - %i]: ", 1, NumAmigos);
                    scanf("%i", &amigo);
                    LimparBuffer();
                    amigo--;

                    if (amigo < 0 || amigo >= NumAmigos)
                    {
                        MensagemErro(-3);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        for (int i = 0; i < NumEncontros; i++)
                        {

                            for (int j = 0; j < Encontros[i].numamigos; j++)
                            {
                                if (strcmp(Encontros[i].amigos[j].nome, Amigos[amigo].nome) == 0)
                                {
                                    return -30;
                                }
                                else
                                {

                                    break;
                                }
                            }
                        }

                        ExcluirAmigos(amigo);
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuAmigo();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nExclusao bem sucedida.\n");
        break;
    }

    return 1;
}

int DeletarLocais()
{

    int local;
    char op;

    if (NumLocais <= 0)
    {
        return -5;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            // verifica se o local esta em algum encontro, se tiver nao deixa excluir;
            if (NumLocais == 1)
            {
                for (int i = 0; i < NumEncontros; i++)
                {
                    for (int j = 0; j < Encontros[i].numlocais; j++)
                    {
                        if (strcmp(Locais[0].nome, Encontros[i].locais[j].nome) == 0)
                        {
                            return -31;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                ExcluirLocais(0);
            }
            else
            {
                while (1)
                {
                    ListarLocais();
                    printf("\nSelecione o local que deseja deletar: [ %i - %i]: ", 1, NumLocais);
                    scanf("%i", &local);
                    LimparBuffer();
                    local--;

                    if (local < 0 || local >= NumLocais)
                    {
                        MensagemErro(-6);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        for (int i = 0; i < NumEncontros; i++)
                        {
                            for (int j = 0; j < Encontros[i].numlocais; j++)
                            {
                                if (strcmp(Locais[local].nome, Encontros[i].locais[j].nome) == 0)
                                {
                                    return -31;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        ExcluirLocais(local);
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuLocal();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nExclusao bem sucedida.\n");
        break;
    }

    return 1;
}

int DeletarCategorias()
{
    int categoria;
    char op;

    if (NumCategorias <= 0)
    {
        return -14;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            // verifica se a categoria esta em algum encontro, se tiver nao deixa excluir;
            if (NumCategorias == 1)
            {
                for (int i = 0; i < NumEncontros; i++)
                {
                    for (int j = 0; j < Encontros[i].numcategorias; j++)
                    {
                        if (strcmp(Categorias[0].nome, Encontros[i].categorias[j].nome) == 0)
                        {
                            return -32;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                ExcluirCategorias(0);
            }
            else
            {
                while (1)
                {
                    ListarCategorias();
                    printf("\nSelecione a categoria que deseja deletar: [ %i - %i]: ", 1, NumCategorias);
                    scanf("%i", &categoria);
                    LimparBuffer();
                    categoria--;

                    if (categoria < 0 || categoria >= NumCategorias)
                    {
                        MensagemErro(-33);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        for (int i = 0; i < NumEncontros; i++)
                        {
                            for (int j = 0; j < Encontros[i].numcategorias; j++)
                            {
                                if (strcmp(Categorias[categoria].nome, Encontros[i].categorias[j].nome) == 0)
                                {
                                    return -32;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        ExcluirCategorias(categoria);
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuCategoria();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nExclusao bem sucedida.\n");
        break;
    }

    return 1;
}

int DeletarEncontros()
{
    int encontro;
    char op;

    if (NumEncontros <= 0)
    {
        return -16;
    }

    while (1)
    {
        LimparTela();
        printf("\nRealmente deseja prosseguir? (s) (n)\n");
        scanf(" %c", &op);
        LimparBuffer();
        op = tolower(op);

        if (op == 's')
        {
            if (NumEncontros == 1)
            {

                ExcluirEncontros(0);
            }
            else
            {
                while (1)
                {
                    ListarEncontros();
                    printf("\nSelecione o encontro que deseja deletar: [ %i - %i]: ", 1, NumEncontros);
                    scanf("%i", &encontro);
                    LimparBuffer();
                    encontro--;

                    if (encontro < 0 || encontro >= NumEncontros)
                    {
                        MensagemErro(-23);
                        Pausar(1);
                        continue;
                    }
                    else
                    {
                        ExcluirEncontros(encontro);
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            OpcaoMenuEncontro();
        }
        else
        {
            MensagemErro(0);
            Pausar(1);
            continue;
        }

        LimparTela();
        printf("\nExclusao bem sucedida.\n");
        break;
    }

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
    if (NumEncontros <= 0 || encontro < 0 || encontro >= NumEncontros)
    {
        return;
    }

    // libera memoria do encontro que quer ser removida
    LimpaPonteiroEncontro(&Encontros[encontro]);

    // sobrescreve o elemento a ser removido com o último elemento (basicamente reorganiza);
    Encontros[encontro] = Encontros[NumEncontros - 1];
    NumEncontros--;
}

void VoltarMenuPrincipal()
{
    OpcaoMenu();
}

void VoltarMenuRelatorio()
{
    OpcaoMenuRelatorio();
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
    free(local->nome);
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
    free(encontro->locais->nome);
    free(encontro->locais->endereco.estado);
    free(encontro->locais->endereco.cidade);
    free(encontro->locais->endereco.bairro);
    free(encontro->locais->endereco.logradouro);
    free(encontro->categorias->nome);
    free(encontro->descricao);
    encontro->numamigos = 0;
    encontro->numlocais = 0;
    encontro->numcategorias = 0;
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

void OrdenarCategorias()
{
    for (int i = 0; i < NumCategorias - 1; i++)
    {
        for (int j = 0; j < NumCategorias - i - 1; j++)
        {
            // compara os nomes das categorias
            if (strcmp(Categorias[j].nome, Categorias[j + 1].nome) > 0)
            {
                Categoria aux = Categorias[j];
                Categorias[j] = Categorias[j + 1];
                Categorias[j + 1] = aux;
            }
        }
    }
}

void SalvarAmigos()
{
    FILE *ArqAmigos;

    ArqAmigos = fopen("Amigos.txt", "w");

    if (ArqAmigos == NULL)
    {
        MensagemErro(-40);
        Pausar(1);
        exit(0);
    }

    for (int i = 0; i < NumAmigos; i++)
    {
        fprintf(ArqAmigos, "%s;", Amigos[i].nome);
        fprintf(ArqAmigos, "%s;", Amigos[i].apelido);
        fprintf(ArqAmigos, "%s;", Amigos[i].email);
        fprintf(ArqAmigos, "%i;", Amigos[i].datanasc.dia);
        fprintf(ArqAmigos, "%i;", Amigos[i].datanasc.mes);
        fprintf(ArqAmigos, "%i;", Amigos[i].datanasc.ano);
        fprintf(ArqAmigos, "%s;", Amigos[i].telefone);
        fprintf(ArqAmigos, "%c", '\n');
    }

    fclose(ArqAmigos);
}

void SalvarLocais()
{
    FILE *ArqLocais;

    ArqLocais = fopen("Locais.txt", "w");

    if (ArqLocais == NULL)
    {
        MensagemErro(-41);
        Pausar(1);
        exit(0);
    }

    for (int i = 0; i < NumLocais; i++)
    {
        fprintf(ArqLocais, "%s@", Locais[i].nome);
        fprintf(ArqLocais, "%s@", Locais[i].endereco.estado);
        fprintf(ArqLocais, "%s@", Locais[i].endereco.cidade);
        fprintf(ArqLocais, "%s@", Locais[i].endereco.bairro);
        fprintf(ArqLocais, "%s@", Locais[i].endereco.logradouro);
        fprintf(ArqLocais, "%i@", Locais[i].endereco.numero);
        fprintf(ArqLocais, "%c", '\n');
    }

    fclose(ArqLocais);
}

void SalvarCategorias()
{
    FILE *ArqCategorias;

    ArqCategorias = fopen("Categorias.txt", "w");

    if (ArqCategorias == NULL)
    {
        MensagemErro(-42);
        Pausar(1);
        exit(0);
    }

    for (int i = 0; i < NumCategorias; i++)
    {
        fprintf(ArqCategorias, "%s$", Categorias[i].nome);
        fprintf(ArqCategorias, "%c", '\n');
    }

    fclose(ArqCategorias);
}

void SalvarEncontros()
{
    FILE *ArqEncontros;

    ArqEncontros = fopen("Encontros.txt", "w");

    if (ArqEncontros == NULL)
    {
        MensagemErro(-43);
        Pausar(1);
        exit(0);
    }

    for (int i = 0; i < NumEncontros; i++)
    {
        fprintf(ArqEncontros, "%s#", Encontros[i].amigos->nome);
        fprintf(ArqEncontros, "%s#", Encontros[i].locais->nome);
        fprintf(ArqEncontros, "%s#", Encontros[i].categorias->nome);
        fprintf(ArqEncontros, "%i#", Encontros[i].data.dia);
        fprintf(ArqEncontros, "%i#", Encontros[i].data.mes);
        fprintf(ArqEncontros, "%i#", Encontros[i].data.ano);
        fprintf(ArqEncontros, "%i#", Encontros[i].horario.hora);
        fprintf(ArqEncontros, "%i#", Encontros[i].horario.minuto);
        fprintf(ArqEncontros, "%s#", Encontros[i].descricao);
        fprintf(ArqEncontros, "%c", '\n');
    }

    fclose(ArqEncontros);
}

void SalvarArquivos()
{
    if (NumAmigos > 0)
    {
        SalvarAmigos();
    }
    if (NumLocais > 0)
    {
        SalvarLocais();
    }
    if (NumCategorias > 0)
    {
        SalvarCategorias();
    }
    if (NumEncontros > 0)
    {
        SalvarEncontros();
    }
}

void RecuperarAmigos()
{
    int i = 0, sep = 0;
    char str[100], c;

    FILE *ArqAmigos = fopen("Amigos.txt", "r");

    while (1)
    {   
        // se o caracter for o end of file;
        if ((c = fgetc(ArqAmigos)) == EOF)
        {
            break;
        }

        // monta a string;
        if (c != '\n' && c != ';')
        {
            str[i] = c;
            i++;
        }
        else
        {
            // finaliza a string;
            str[i] = '\0';
            i = 0;

            switch (sep)
            {
            
            //nome;
            case 0: 
                if (NumAmigos == 0)
                {
                    Amigos = (Amigo *)malloc(1 * sizeof(Amigo));
                }
                else
                {
                    Amigos = (Amigo *)realloc(Amigos, (NumAmigos + 1) * sizeof(Amigo));
                }

                Amigos[NumAmigos].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Amigos[NumAmigos].nome, str);
                break;
            
            // apelido;
            case 1: 
                Amigos[NumAmigos].apelido = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Amigos[NumAmigos].apelido, str);
                break;

            // email;
            case 2: 
                Amigos[NumAmigos].email = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Amigos[NumAmigos].email, str);
                break;

            // data de nascimento (dia);
            case 3: 
                Amigos[NumAmigos].datanasc.dia = atoi(str);
                break;

            // data de nascimento (mes);
            case 4:
                Amigos[NumAmigos].datanasc.mes = atoi(str);
                break;

            // data de nascimento (ano);
            case 5: 
                Amigos[NumAmigos].datanasc.ano = atoi(str);
                break;

            // telefone;
            case 6:
                Amigos[NumAmigos].telefone = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Amigos[NumAmigos].telefone, str);

                // passa para o proximo amigo;
                sep = 0; 
                NumAmigos++;
                break;
            }

            sep++;
        }
    }

    fclose(ArqAmigos);
}

void RecuperarLocais()
{
    int i = 0, sep = 0;
    char str[100], c;

    FILE *ArqLocais = fopen("Locais.txt", "r");

    while (1)
    {   
        // se o caracter for o end of file;
        if ((c = fgetc(ArqLocais)) == EOF)
        {
            break;
        }

        // monta a string;
        if (c != '\n' && c != '@')
        {
            str[i] = c;
            i++;
        }
        else
        {
            // finaliza a string;
            str[i] = '\0';
            i = 0;

            switch (sep)
            {
            
            //nome;
            case 0: 
                if (NumLocais == 0)
                {
                    Locais = (Local *)malloc(1 * sizeof(Local));
                }
                else
                {
                    Locais = (Local *)realloc(Locais, (NumLocais + 1) * sizeof(Local));
                }

                Locais[NumLocais].nome = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Locais[NumLocais].nome, str);
                break;
            
            // estado;
            case 1: 
                Locais[NumLocais].endereco.estado = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Locais[NumLocais].endereco.estado, str);
                break;

            // cidade;
            case 2: 
                Locais[NumLocais].endereco.cidade = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Locais[NumLocais].endereco.cidade, str);
                break;

            // bairro
            case 3: 
                Locais[NumLocais].endereco.bairro = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Locais[NumLocais].endereco.bairro, str);
                break;

            // logradouro
            case 4: 
                Locais[NumLocais].endereco.logradouro = (char *)malloc((strlen(str) + 1) * sizeof(char));
                strcpy(Locais[NumLocais].endereco.logradouro, str);
                break;

            // numero;
            case 5: 
                Locais[NumLocais].endereco.numero = atoi(str);
                sep = 0; 
                NumLocais++;
                break;
            }

            sep++;
        }
    }

    fclose(ArqLocais);
}

void RecuperarArquivos()
{
    RecuperarAmigos();
    RecuperarLocais();
}

void Pausar(int pause)
{
    printf("\nPressione Qualquer Tecla para Continuar..\n");
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
#endif
}

void LimparTela()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}
