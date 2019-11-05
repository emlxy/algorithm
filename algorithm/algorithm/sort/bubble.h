#include "base.h"

void bubblesort(int a[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
                exchange(a, i, j);
        }
}