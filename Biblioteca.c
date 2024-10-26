#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPESSOA 10
#define MAXLIVRO 100

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

typedef struct
{
    char *titulo;
    char *autor;
    char *isbn;
    int anopubli;
} Livro;

typedef struct
{
    Livro livro_emprestado;
    Pessoa pessoa_que_pegou;
    char *data_emprestimo;
    char *data_devolucao;
} Emprestimo;

Pessoa *cliente;
Livro *livro;
Emprestimo **emprestimo;
int numPessoa = 0, numLivro = 0, numEmprestimo = 0;

void Menu();                   // mostra menu;
void MensagemErro(int erro);   // mostrar erros;
int OpcaoMenu(int op);         // pega a opcao do usuario;
int IncluirPessoa();           // inclui pessoa;
int IncluirLivro();            // inclui livro;
int RegistrarEmprestimo();     // registra um emprestimo;
int VerificarEmprestimo();     // verifica se o livro esta sendo emprestado por alguem;
int BuscarPeloCPF();           // buscar pessoa pelo CPF e ver livros emprestados;
int Listar();                  // Listar todos os emprestimos em aberto;
void ImprimirPessoa(Pessoa p); // imprime pessoa;
void ImprimirLivro(Livro l);   // imprime livro;
void LiberarMemoria();         // libera as memorias;

Pessoa InclusaoP(); // criar pessoa;
Livro InclusaoL();  // criar livro;

int main()
{
    cliente = (Pessoa *)malloc(MAXPESSOA * sizeof(Pessoa));
    livro = (Livro *)malloc(MAXLIVRO * sizeof(Livro));
    emprestimo = NULL;

    int op;
    do
    {
        Menu();
        scanf("%i", &op);
        fflush(stdin);
        if (op < 1 || op > 6)
        {
            MensagemErro(0);
        }
        else
        {
            OpcaoMenu(op);
            system("pause");
        }

    } while (op != 6);

    LiberarMemoria();

    return 0;
}

void MensagemErro(int erro)
{
    switch (erro)
    {
    case 0:
        printf("\nErro. Opcao invalida\n");
        break;
    case -1:
        printf("\nErro. Lista cheia.\n");
        break;
    case -2:
        printf("\nErro. Nao ha pessoas ou livros cadastrados.\n");
        break;
    case -3:
        printf("\nErro. Esse livro ja foi emprestado.\n");
        break;
    case -4:
        printf("\nErro. CPF invalido ou nao encontrado.\n");
    default:
        printf("\nErro.\n");
        break;
    }
}

void Menu()
{
    system("cls");
    printf("\n - (1) Incluir pessoa\n");
    printf("\n - (2) Incluir livro\n");
    printf("\n - (3) Registrar emprestimo\n");
    printf("\n - (4) Listar todos os emprestimos em aberto\n");
    printf("\n - (5) Buscar pessoa pelo CPF e ver livros emprestados\n");
    printf("\n - (6) Sair\n");
}

int OpcaoMenu(int op)
{
    int erro;

    if (op < 1 || op > 6)
    {
        MensagemErro(0);
    }
    if (op == 1)
    {
        erro = IncluirPessoa();
    }
    else if (op == 2)
    {
        erro = IncluirLivro();
    }
    else if (op == 3)
    {
        erro = RegistrarEmprestimo();
    }
    else if (op == 4)
    {
        erro = Listar();
    }
    else if (op == 5)
    {
        erro = BuscarPeloCPF();
    }

    if (erro <= 0)
    {
        MensagemErro(erro);
    }
}

Pessoa InclusaoP()
{
    Pessoa p;

    p.nome = (char *)malloc(50 * sizeof(char));
    p.endereco.estado = (char *)malloc(20 * sizeof(char));
    p.endereco.cidade = (char *)malloc(20 * sizeof(char));
    p.endereco.rua = (char *)malloc(20 * sizeof(char));
    p.cpf = (char *)malloc(12 * sizeof(char));

    system("cls");
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

int IncluirPessoa()
{
    if (numPessoa >= MAXPESSOA)
    {
        return -1;
    }
    cliente[numPessoa] = InclusaoP();
    system("cls");
    ImprimirPessoa(cliente[numPessoa++]);

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

Livro InclusaoL()
{
    Livro l;

    l.titulo = (char *)malloc(20 * sizeof(char));
    l.autor = (char *)malloc(20 * sizeof(char));
    l.isbn = (char *)malloc(20 * sizeof(char));

    system("cls");
    printf("\nTitulo:\n");
    gets(l.titulo);
    fflush(stdin);

    printf("\nAno Publicado:\n");
    scanf("%i", &l.anopubli);
    fflush(stdin);

    printf("\nAutor:\n");
    gets(l.autor);
    fflush(stdin);

    printf("\nIsbn:\n");
    gets(l.isbn);
    fflush(stdin);

    return l;
}

int IncluirLivro()
{
    if (numLivro >= MAXLIVRO)
    {
        return -1;
    }
    livro[numLivro] = InclusaoL();
    system("cls");
    ImprimirLivro(livro[numLivro++]);

    return 1;
}

void ImprimirLivro(Livro l)
{
    printf("\n- Titulo: %s\n", l.titulo);
    printf("\n- Ano publicado: %i\n", l.anopubli);
    printf("\n- Autor: %s\n", l.autor);
    printf("\n- Isbn: %s\n", l.isbn);
}

int RegistrarEmprestimo()
{
    int erro;
    if (numPessoa == 0 || numLivro == 0)
    {
        return -2;
    }

    int pessoaIndex, livroIndex;
    char dataEmp[11], dataDev[11];

    system("cls");
    printf("\nEscolha a pessoa pelo numero (0 a %i):\n", numPessoa - 1);
    for (int i = 0; i < numPessoa; i++)
    {
        printf("%i. %s\n", i, cliente[i].nome);
    }
    scanf("%i", &pessoaIndex);
    fflush(stdin);

    system("cls");
    printf("\nEscolha o livro pelo numero (0 a %i):\n", numLivro - 1);
    for (int i = 0; i < numLivro; i++)
    {
        printf("%i. %s\n", i, livro[i].titulo);
    }
    scanf("%i", &livroIndex);
    fflush(stdin);

    erro = VerificarEmprestimo(livroIndex);
    if (erro == -3)
    {
        return erro;
    }

    emprestimo = (Emprestimo **)realloc(emprestimo, (numEmprestimo + 1) * sizeof(Emprestimo *));
    emprestimo[numEmprestimo] = (Emprestimo *)malloc(sizeof(Emprestimo));

    emprestimo[numEmprestimo]->pessoa_que_pegou = cliente[pessoaIndex];
    emprestimo[numEmprestimo]->livro_emprestado = livro[livroIndex];

    system("cls");
    printf("\nDigite a data do emprestimo (dd/mm/aaaa):\n");
    gets(dataEmp);
    fflush(stdin);
    emprestimo[numEmprestimo]->data_emprestimo = (char *)malloc((strlen(dataEmp) + 1) * sizeof(char));
    strcpy(emprestimo[numEmprestimo]->data_emprestimo, dataEmp);

    system("cls");
    printf("\nDigite a data prevista para devolucao (dd/mm/aaaa):\n");
    gets(dataDev);
    fflush(stdin);
    emprestimo[numEmprestimo]->data_devolucao = (char *)malloc((strlen(dataDev) + 1) * sizeof(char));
    strcpy(emprestimo[numEmprestimo]->data_devolucao, dataDev);

    system("cls");
    printf("\nEmprestimo registrado com sucesso!\n");

    numEmprestimo++;

    return 1;
}

int VerificarEmprestimo(int livroIndex)
{
    for (int i = 0; i < numEmprestimo; i++)
    {

        if (strcmp(emprestimo[i]->livro_emprestado.isbn, livro[livroIndex].isbn) == 0)
        {
            return -3;
        }
    }
    return 1;
}

int BuscarPeloCPF()
{
    char cpf[12];
    int i,j;

    system("cls");
    printf("\nDigite o CPF da pessoa para busca:\n");
    gets(cpf);
    fflush(stdin);

    if (strlen(cpf) != 11)
    {
        return -4;
    }

    for ( i = 0; i < numPessoa; i++)
    {
        if (strcmp(cpf, cliente[i].cpf) == 0)
        {
            ImprimirPessoa(cliente[i]);
            
            for ( j = 0; j < numEmprestimo; j++)
            {
                if (strcmp(cliente[i].cpf, emprestimo[j]->pessoa_que_pegou.cpf) == 0)
                {
                    printf("\nEmprestimo ativo:\n");
                    ImprimirLivro(emprestimo[j]->livro_emprestado);
                    printf("\nData Emprestimo: %s", emprestimo[j]->data_emprestimo);
                    printf("\nData Devolucao: %s\n", emprestimo[j]->data_devolucao);
                }
            }
            return 1;
        }
    }

    return -4;
}
Listar()
{
    int i;

    if (numPessoa == 0 || numLivro == 0)
    {
        return -2;
    }
    for (i = 0; i < numPessoa; i++)
    {
        system("cls");
        printf("\nPessoa [%i]", i + 1);
        ImprimirPessoa(cliente[i]);
        printf("\n");
        printf("\nLivro [%i] da pessoa [%i]", i + 1, i + 1);
        ImprimirLivro(livro[i]);
    }

    return 1;
}
void LiberarMemoria()
{
    for (int i = 0; i < numPessoa; i++)
    {
        free(cliente[i].nome);
        free(cliente[i].cpf);
        free(cliente[i].endereco.rua);
        free(cliente[i].endereco.cidade);
        free(cliente[i].endereco.estado);
    }
    free(cliente);

    for (int i = 0; i < numLivro; i++)
    {
        free(livro[i].titulo);
        free(livro[i].autor);
        free(livro[i].isbn);
    }
    free(livro);

    for (int i = 0; i < numEmprestimo; i++)
    {
        free(emprestimo[i]->data_emprestimo);
        free(emprestimo[i]->data_devolucao);
        free(emprestimo[i]);
    }
    free(emprestimo);
}
