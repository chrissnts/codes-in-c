#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_NT 4

typedef struct {
    char *nome_disciplina;
    float notas[N_NT];
} disciplina;

typedef struct {
    char *nome;
    disciplina *grade;
    int num_disciplina;
} aluno;

int main() {
    int num_aluno = 0;
    char straux[100];
    int i, j;

    aluno *info23;

    printf("\nDigite o numero de alunos:\n");
    scanf("%i", &num_aluno);
    getchar();  

    if (num_aluno > 0) {
        info23 = (aluno *)malloc(num_aluno * sizeof(aluno));

        for (i = 0; i < num_aluno; i++) 
        {
            printf("\nDigite o nome do aluno:\n");
            fgets(straux, sizeof(straux), stdin);
            straux[strcspn(straux, "\n")] = 0; 

            info23[i].nome = (char*)malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(info23[i].nome, straux);

            printf("\nDigite a quantidade de disciplinas do aluno:\n");
            scanf("%i", &info23[i].num_disciplina);
            getchar();

            
            info23[i].grade = (disciplina*)malloc(info23[i].num_disciplina * sizeof(disciplina));

            for (j = 0; j < info23[i].num_disciplina; j++) 
            {
                printf("\nDigite o nome da disciplina %d:\n", j + 1);
                fgets(straux, sizeof(straux), stdin);
                straux[strcspn(straux, "\n")] = 0; 

                info23[i].grade[j].nome_disciplina = (char*)malloc((strlen(straux) + 1) * sizeof(char));
                strcpy(info23[i].grade[j].nome_disciplina, straux);

              
                for (int k = 0; k < N_NT; k++) 
                {
                    printf("Digite a nota %d para a disciplina %s:\n", k + 1, straux);
                    scanf("%f", &info23[i].grade[j].notas[k]);
                }
                getchar();                                                       
            }
        }

    }

    return 0;
}
