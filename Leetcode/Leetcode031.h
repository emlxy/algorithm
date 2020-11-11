#include "stdafx.h"
#include <vector>

class Solution031 {
public:
    void test()
    {
        std::vector<int> vec = {1,2,3};
        nextPermutation(vec);
    }
    void exch(std::vector<int> &nums, int i, int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void reverse(std::vector<int> &nums, int left, int right)
    {
        while(left < right)
        {
            exch(nums, left, right);
            left++;
            right--;
        }
    }
    void nextPermutation(std::vector<int>& nums) {
        if(nums.size() <= 1) return;
        for(int i = nums.size()-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                for(int j = nums.size()-1; j>i; j--)
                {
                    if(nums[j] > nums[i])
                    {
                        exch(nums, i, j);
                        reverse(nums, i+1, nums.size()-1);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0, nums.size()-1);
    }
};