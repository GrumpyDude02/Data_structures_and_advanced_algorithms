#include <stdio.h>

int binary_search(int *tab, int cle, int n)
{
    int trouve = 0;
    int start = 0;
    int end = n - 1;
    int m = (start + end) / 2;
    while (!trouve)
    {
        if (start > end)
        {
            return 0;
        }
        if (tab[m] == cle)
        {
            trouve = 1;
            return trouve;
        }
        else
        {
            if (tab[m] < cle)
            {
                start = m + 1;
                m = (start + end) / 2;
            }
            else
            {
                end = m - 1;
                m = (start + end) / 2;
            }
        }
    }
}

int main()
{
    int tab1[5] = {1, 4, 6, 8, 9};
    if (binary_search(tab1, 6, 5))
        printf("found");
    else
        printf("not found");
}