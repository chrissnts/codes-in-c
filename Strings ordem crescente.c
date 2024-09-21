#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 100

int main ()
{
    char word[TAM], word2[TAM], word3[TAM];
    int result;

    printf("\nEnter a word:\n");
    fflush(stdin);
    gets(word);

    printf("\nEnter a word 2:\n");
    fflush(stdin);
    gets(word2);

    printf("\nEnter a word 3:\n");
    fflush(stdin);
    gets(word3);

    result = strncmp(word, word2, 1);
    if (result > 0)
    {
        result = strncmp(word, word3, 1);
        if (result > 0)
        {
            result = strncmp(word2, word3, 1);
            if (result > 0)
            {
                strcat(word3, " - ");
                strcat(word3, word2);
                strcat(word3, " - ");
                strcat(word3, word);
                printf("\n%s\n", word3);
            }
            else
            {
                strcat(word2, " - ");
                strcat(word2, word3);
                strcat(word2, " - ");
                strcat(word2, word);
                printf("\n%s\n", word2);
            }
        }
        else
        {
            strcat(word2, " - ");
            strcat(word2, word);
            strcat(word2, " - ");
            strcat(word2, word3);
            printf("\n%s\n", word2);
        }
    }
    else
    {
        result = strncmp(word, word3, 1);
        if (result > 0)
        {
            strcat(word3, " - ");
            strcat(word3, word);
            strcat(word3, " - ");
            strcat(word3, word2);
            printf("\n%s\n", word3);
        }
        else
        {
            result = strncmp(word2, word3, 1);
            if (result > 0)
            {
                strcat(word, " - ");
                strcat(word, word3);
                strcat(word, " - ");
                strcat(word, word2);
                printf("\n%s\n", word);
            }
            else
            {
                strcat(word, " - ");
                strcat(word, word2);
                strcat(word, " - ");
                strcat(word, word3);
                printf("\n%s\n", word);
            }
        }
    }

    return 0;
}
