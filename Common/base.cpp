#include "stdafx.h"
#include "base.h"

void exch(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "  " << a[i] << "  ";
        std::cout << std::endl;
    }
}