#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *charreverse_word(char *word)
{
    char *reversed = (char *)malloc(sizeof(char) * 50);
    int i = 0;
    char temp;
    int mid = strlen(word) / 2;
    while (i < mid)
    {
        temp = word[i];
        word[i] = word[strlen(word) - 1 - i];
        word[strlen(word) - 1 - i] = temp;
        i++;
        for (int j = 0; j < 3; j++)
        {
        }
    }
}

int main()
{
    char *word = (char *)malloc(50 * sizeof(char));
    gets(word);
    puts(word);
    charreverse_word(word);
    puts(word);
}