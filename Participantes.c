#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int grupo[3];
    // talvez participante prescise ser matriz;
    char participante[6];
    int i, cont = 0;

    for (i = 0; i < 6; i++)
    {
        scanf("%c", &participante[i]);
        if (participante[i] == 'v' || participante[i] == 'V')
        {
            cont++;
        }
    }
    
    for ( i = 0; i < 3; i++)
    {
        if (cont == 5 || cont == 6)
        {   
            // pq se o participante for matriz, aqui eu posso colocar qual o participante foi, com a quantidade de jogos ganho;
            grupo[i] = participante[i];
        }
    }

    printf("\n%i\n", cont);
}