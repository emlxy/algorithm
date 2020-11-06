#include "stdafx.h"
#include <vector>
#include <map>

class Solution001 {
public:
    void test()
    {
        
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> _map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (_map.count(target - nums[i]) > 0)
                return{ _map[target - nums[i]], i};
            _map[nums[i]] = i;
        }
        return {};
    }
};