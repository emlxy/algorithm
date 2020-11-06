#include "stdafx.h"
#include <vector>

class Solution011 {
public:
    void test()
    {
        vector<int> v = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        int res = maxArea(v);
    }
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                res = max(res, height[left] * (right - left));
                left++;
            }
            else
            {
                res = max(res, height[right] * (right - left));
                right--;
            }
        }
        return res;
    }
};