#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

void swap(char str1[TAM], char str2[TAM])
{
    char temp[TAM];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main()
{
    char word[TAM], word2[TAM], word3[TAM];

    printf("\nEnter a word:\n");
    fgets(word, TAM, stdin);
    word[strcspn(word, "\n")] = 0;

    printf("\nEnter a word 2:\n");
    fgets(word2, TAM, stdin);
    word2[strcspn(word2, "\n")] = 0;

    printf("\nEnter a word 3:\n");
    fgets(word3, TAM, stdin);
    word3[strcspn(word3, "\n")] = 0;

    if (strlen(word) > strlen(word2))
    {
        swap(word, word2);
    }

    if (strlen(word2) > strlen(word3))
    {
        swap(word2, word3);
    }

    if (strlen(word) > strlen(word2))
    {
        swap(word, word2);
    }

    printf("\n%s - %s - %s\n", word, word2, word3);

    return 0;
}
