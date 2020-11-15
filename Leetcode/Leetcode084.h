/*
看了题解才明白。单调栈的应用.

主要还是分析题，空间换时间，空间如何存储数值才能更好的解题。怎样的取值的顺序才能满足需求。

本题具体分析：
1、最重要的还是计算顺序，先计算高的，再计算低的。
2、stack存储的都是index，这样可以方便计算width，也方便取height。
*/
#include "stdafx.h"
#include <vector>
#include <stack>

class Solution084 {
public:
    void test()
    {
        vector<int> vec = { 2,1,5,6,2,3};
        largestRectangleArea(vec);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;

        std::stack<int> stk;
        int maxlen = 0;

        for(int i=0; i<heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int height = heights[stk.top()];
                stk.pop();
                int width = i;
                if(!stk.empty())
                    width = i - stk.top() -1;
                maxlen = max(maxlen, width*height);
            }
            stk.push(i);
        }

        while(!stk.empty())
        {
            int height = heights[stk.top()];
            stk.pop();
            int width = n;
            if(!stk.empty())
                width = n - stk.top() -1;
            maxlen = max(maxlen, width*height);
        }
        return maxlen;
    }
};