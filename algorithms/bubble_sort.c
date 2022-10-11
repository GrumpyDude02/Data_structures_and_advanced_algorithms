#include <stdio.h>
#include <stdlib.h>

void print(int *list, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", list[i]);
}

void bubble_sort(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                int *temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int l[10];
    for (int i = 0; i < 10; i++)
    {
        l[i] = rand();
    }
    print(l, 10);
    printf("\n");
    bubble_sort(l, 10);
    print(l, 10);
    return 0;
}