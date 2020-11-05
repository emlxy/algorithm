#pragma once
#include <iostream>

void exch(int a[], int i, int j);

void printArray(int a[], int size);

template<class T>
T const &min(T const &a, T const &b)
{
    return a < b ? a : b;
}

template<class T>
T const &max(T const &a, T const &b)
{
    return a > b ? a : b;
}