#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *a, int start, int end, int m)
{
    int l[m - start + 1];
    int r[end - m];
    for (int i = 0; i < m - start + 1; i++)
        l[i] = a[start + i];
    for (int i = 0; i < end - m; i++)
        r[i] = a[m + i + 1];
    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    for (; i < m - start + 1 && j < end - m; k++)
    {
        if (l[i] < r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
    }
    while (i < m - start + 1)
        a[k++] = l[i++];
    while (j < end - m)
        a[k++] = r[j++];
}

void merge_sort(int *a, int start, int end)
{
    if (start >= end)
        return;
    int m = (start + end) / 2;
    merge_sort(a, start, m);
    merge_sort(a, m + 1, end);
    merge(a, start, end, m);
}
int main()
{
    int a[11] = {1, 81, 384, 132, 74, 35, 1054, 899, 40, 2000, 300};
    merge_sort(a, 0, 10);
    for (int i = 0; i < 11; i++)
        printf("%d ", a[i]);
    return 0;
}