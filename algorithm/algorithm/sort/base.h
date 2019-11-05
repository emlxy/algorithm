#pragma once
#include <iostream>

void exchange(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "  " << a[i] << "  ";
        std::cout << std::endl;
    }
}
