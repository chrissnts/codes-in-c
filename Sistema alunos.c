#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TURMAS 2
#define ALUNOS 2
#define CONCEITOS 2
#define NOME_DOSMELIANTES 50

int data_dia()
{
    int dia = 0;
    do
    {
       
        printf("Digite o dia (1-31): ");
        scanf("%d", &dia);

        if (dia < 1 || dia > 31)
        {
            printf("Dia invalido seu chupeta. Insira um valor entre 1 e 31.\n");
            
            continue;
        }
    } while (dia < 1 || dia > 31);

    return dia;
}

int data_mes()
{
    int mes = 0;
    do
    { 
       
        printf("Digite o mes (1-12): ");
        scanf("%d", &mes);

        if (mes < 1 || mes > 12)
        {
            printf("Mes invalido seu chupeta. Insira um valor entre 1 e 12.\n");
           
            continue;
        }
    } while (mes < 1 || mes > 12);

    return mes;
}

int data_ano()
{
    int ano = 0;
    do
    {
       
        printf("Digite o ano (maior que 1900): ");
        scanf("%d", &ano);

        if (ano <= 1900)
        {
            printf("Ano invalido seu chupeta. Insira um valor maior que 1900.\n");
            continue;
        }
    } while (ano <= 1900);

    return ano;
}

int main()
{
    char alunos[ALUNOS][NOME_DOSMELIANTES];
    char conceitos[ALUNOS][CONCEITOS];
    int dias[TURMAS][ALUNOS];
    int meses[TURMAS][ALUNOS];
    int anos[TURMAS][ALUNOS];
    float coeficientes[TURMAS][ALUNOS];
    float media[TURMAS] = {0};

    float soma_total = 0;
    float maior_coeficiente = -1;
    char aluno_maior_coeficiente[NOME_DOSMELIANTES];

    for (int i = 0; i < TURMAS; i++)
    {
        for (int j = 0; j < ALUNOS; j++)
        {
            printf("Digite o nome do aluno(a): ");
            fgets(alunos[j], NOME_DOSMELIANTES, stdin);
            alunos[j][strcspn(alunos[j], "\n")] = '\0';

            for (int k = 0; k < CONCEITOS; k++)
            {
                do
                {
                    printf("Digite o conceito %d (A, B, C ou D) para o aluno (a) %s: ", k + 1, alunos[j]);
                    scanf(" %c", &conceitos[j][k]);
                    conceitos[j][k] = toupper(conceitos[j][k]);
                } while (conceitos[j][k] < 'A' || conceitos[j][k] > 'D');
            }

            printf("Digite a data de nascimento do aluno (a) %s:\n", alunos[j]);
            dias[i][j] = data_dia();  
            meses[i][j] = data_mes(); 
            anos[i][j] = data_ano();  

            do
            {
                printf("Digite o coeficiente de rendimento (0 a 10) do aluno (a) %s: ", alunos[j]);
                scanf("%f", &coeficientes[i][j]);
            } while (coeficientes[i][j] < 0 || coeficientes[i][j] > 10);
            getchar();
        }
    }

    for (int i = 0; i < TURMAS; i++)
    {
        printf("\nTurma %d:\n", i + 1);

        for (int j = 0; j < ALUNOS; j++)
        {
            printf("\nAluno: %s\n", alunos[j]);
            printf("Conceitos: ");
            for (int k = 0; k < CONCEITOS; k++)
            {
                printf("%c", conceitos[j][k]);
            }

            printf("\nData de Nascimento: %02d/%02d/%04d\n", dias[i][j], meses[i][j], anos[i][j]);
            printf("Coeficiente: %.2f\n", coeficientes[i][j]);

            media[i] += coeficientes[i][j];
            soma_total += coeficientes[i][j];

            if (coeficientes[i][j] > maior_coeficiente)
            {
                maior_coeficiente = coeficientes[i][j];
                strcpy(aluno_maior_coeficiente, alunos[j]);
            }
        }
        media[i] /= ALUNOS;
        printf("\nCoeficiente medio da turma %d: %.2f\n", i + 1, media[i]);
    }

    printf("Coeficiente medio total: %.2f\n", soma_total / (TURMAS * ALUNOS));
    printf("Aluno (a) com o maior coeficiente: %s (%.2f)\n", aluno_maior_coeficiente, maior_coeficiente);

    return 0;
}
