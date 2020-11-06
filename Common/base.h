#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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