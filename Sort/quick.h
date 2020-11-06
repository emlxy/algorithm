#include "base.h"

int partition(int a[], int low, int high)
{
    int key = a[low];
    int i = low;
    int j = high + 1;
    while (true)
    {
        while (a[--j] >= key)
            if (j == low) break;

        while (a[++low] <= key)
            if (i == high) break;

        if (i >= j) break;

        exch(a, i, j);
    }

    exch(a, low, j);

    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int key = partition(a, low, high);
        quicksort(a, low, key - 1);
        quicksort(a, key + 1, high);
    }
}