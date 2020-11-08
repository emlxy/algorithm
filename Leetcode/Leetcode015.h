#include "stdafx.h"
#include <vector>
#include <map>

/*
3数之和题解：
1、对所有数排序，这样可以避免相同的答案
2、排序。可以双指针法向正确答案逼近
*/

class Solution015 {
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
        sort(_vec, lo, key-1);
        sort(_vec, key+1, hi);
    }
    /*******/
    void test()
    {
        std::vector<int> _vec = { -1,0,1,2,-1,-4 };
        threeSum(_vec);
    }
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int lo, int target) {
        std::vector<std::vector<int>> res;
        int left = lo, right = nums.size() - 1;
        int lnum = nums[left];
        int rnum = nums[right];
        while(left < right)
        {
            lnum = nums[left];
            rnum = nums[right];

            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                res.push_back({ nums[left], nums[right] });
                while (left < right && nums[left] == lnum) left++;
                while (left < right && nums[right] == rnum) right--;
            }
            else if (sum < target)
            {
                while (left < right && nums[left] == lnum) left++;
            }
            else if (sum > target)
            {
                while (left < right && nums[right] == rnum) right--;
            }
        }
        return res;
    }
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.size() <= 2) return res;

        sort(nums, 0, nums.size()-1);
        int left = 0;
        for(int i = 0; i < nums.size()-1;i++)  //i的右边界可以优化，因为最右边的2个值不会是第一个
        {
            left = nums[i];
            std::vector<std::vector<int>> vectemp;
            vectemp = twoSum(nums, i + 1, 0 - nums[i]);
            for (int j = 0; j < vectemp.size(); j++)
            {
                vectemp[j].push_back(nums[i]);
            }
            while (i < nums.size()-1 && nums[i+1] == left) i++;

            for (int j = 0; j < vectemp.size(); j++)
            {
                res.push_back(vectemp[j]);
            }
        }
        return res;
    }
};


//之前的另一次提交
class Solution015_1 {
public:
    void exchange(std::vector<int>&nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    int partition(std::vector<int>& nums, int low, int high)
    {
        int key = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= key) high--;
            exchange(nums, low, high);

            while (low < high && nums[low] <= key) low++;
            exchange(nums, low, high);
        }
        return low;
    }

    void quickSort(std::vector<int>& nums, int low, int high)
    {
        if (low < high)
        {
            int n = partition(nums, low, high);
            quickSort(nums, low, n - 1);
            quickSort(nums, n + 1, high);
        }
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int size = nums.size();
        quickSort(nums, 0, size - 1);  //快速排序
        for (int i = 0; i < size - 2; i++)
        {
            if (nums[i] > 0) break;    //排序之后，第一个为正数的，3个数之和肯定为正数，不为0
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = size - 1;
            while (j < k)
            {
                int total = nums[i] + nums[j] + nums[k];
                if (total == 0)
                {
                    result.push_back({ nums[i], nums[j], nums[k] });
                    while (j < k && nums[j + 1] == nums[j])
                        j++;
                    j++;
                    while (j < k && nums[k - 1] == nums[k])
                        k--;
                    k--;
                }
                else if (total > 0)
                {
                    --k;
                }
                else if (total < 0)
                {
                    ++j;
                }
            }
        }
        return result;
    }
};