#include "stdafx.h"
#include <vector>
#include <map>

/*
最接近的3数之和 题解：
1、对所有数排序，这样可以避免相同的答案
2、排序。可以双指针法向正确答案逼近
*/

class Solution016 {
public:
    void exch(std::vector<int> &_vec, int lo, int hi)
    {
        int temp = _vec[lo];
        _vec[lo] = _vec[hi];
        _vec[hi] = temp;
    }
    int partition(std::vector<int> &_vec, int lo, int hi)
    {
        int v = _vec[lo];
        int i = lo, j = hi;
        while (i < j)
        {
            while (i < j && _vec[j] >= v) j--;    //先计算j
            while (i < j && _vec[i] <= v) i++;
            exch(_vec, i, j);
        }
        exch(_vec, lo, i);
        return i;
    }
    void sort(std::vector<int> &_vec, int lo, int hi)
    {
        if (lo >= hi) return;
        int key = partition(_vec, lo, hi);
        sort(_vec, lo, key - 1);
        sort(_vec, key + 1, hi);
    }
    /*******/
    void test()
    {
        std::vector<int> _vec = { -1,0,1,2,-1,-4 };
        threeSumClosest(_vec, 9);
    }

    int threeSumClosest(std::vector<int>& nums, int target) {
        int res = 0;
        if (nums.size() <= 2) return res;
        sort(nums, 0, nums.size() - 1);
        res = nums[0] + nums[1] + nums[2];  //必须正确初始化，用实际的数字的和。不能随便设置0或者其他数字
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (std::abs(target - sum) < std::abs(target - res))
                    res = sum;
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                    return res;
            }
        }
        return res;
    }
};