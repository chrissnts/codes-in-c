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
int numPessoa = 0, numLivro = 0;

void Menu(); // mostra menu;
void MensagemErro(int erro); //mostrar erros;
int OpcaoMenu(int op); // pega a opcao do usuario;
int IncluirPessoa(); // inclui pessoa;
int IncluirLivro(); // inclui livro;
void ImprimirPessoa(Pessoa p); // imprime pessoa;
void ImprimirLivro(Livro l); // imprime livro;

Pessoa InclusaoP(); // criar pessoa;
Livro InclusaoL(); // criar livro;

int main()
{
    cliente = (Pessoa *)malloc(MAXPESSOA * sizeof(Pessoa));
    livro = (Livro *)malloc(MAXLIVRO * sizeof(Livro));

    int op;
    do
    {
        Menu();
        scanf("%i", &op);
        fflush(stdin);
        OpcaoMenu(op);
        system("pause");

    } while (op != 6);

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
        printf("\nErro. Empty list.\n");
        break;
    case -5:
        printf("\nErro. Enter a valid minute.\n");
        break;
    case -6:
        printf("\nErro. Enter a valid second.\n");
        break;
    case -7:
        printf("\nErro. Enter a valid minute and second.\n");
        break;
    case -8:
        printf("\nErro. Invalid track.\n");
        break;

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

int Incluir()
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
    livro[numLivro] = Inclusao();
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