// algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "sort/bubble.h"
#include "sort/quick.h"

int _tmain(int argc, _TCHAR* argv[])
{
    int a[10] = {2,5,3,21,8456,234,13,1,42,324};

    //bubblesort(a, 10);  //冒泡

    quicksort(a, 0, 9);   //快排


    printArray(a, 10);

    system("pause");
	return 0;
}

