#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu()
{
    printf("\nTry to guess the position of one of the 1 values in the 20 position array.\n");
    printf("\n|00|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|");
    printf("\n----------------------------------------------------\n");
    printf("|??|??|??|??|??|??|??|??|??|??|??|??|??|??|??|??|??|\n");
}

int main()
{
    srand(time(NULL));
    int vet[20];
    int i, posicion, guess;
    ;

    // Chamando a função menu;
    menu();

    // Preenchendo o vetor com 0;
    for (i = 0; i < 17; i++)
    {
        vet[i] = 0;
    }

    // Preenchendo o restante do vetor com 3 uns aleatoriamente;
    for (i = 0; i < 3;)
    {
        posicion = rand() % 20;
        if (vet[posicion] == 0)
        {
            vet[posicion] = 1;
            i++;
        }
    }

    // Laço para acertar o valor;
    while (1) 
    {
        printf("\nEnter a posicion of (0 on 19): ");
        scanf("%d", &guess);

        if (guess < 0 || guess >= 20) 
        {
            printf("\nThats not possible! Try it again.\n");
        } 
        else if (vet[guess] == 1) 
        {
            printf("\nNice, you got it in the posicion %d.\n", guess);
            break;
        } 
        else 
        {
            printf("\nThere is no value 1 in the posicion %d. Try again.\n", guess);
        }
    }

    return 0;
}
