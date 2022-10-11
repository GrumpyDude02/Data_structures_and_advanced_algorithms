#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reallocate(int **tab, size_t old_size, size_t new_size)
{
    int *new_tab = (int *)calloc(sizeof(int), new_size);
    memcpy(new_tab, *tab, sizeof(int) * old_size);
    int *temp = *tab;
    *tab = new_tab;
    free(temp);
}

int main()
{
    int *tableau = (int *)calloc(sizeof(int), 5);
    for (int i = 0; i < 5; i++)
    {
        tableau[i] = rand();
        printf("%d\n", tableau[i]);
    }
    reallocate(&tableau, 5, 10);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", tableau[i]);
    }
}