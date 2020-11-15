/*
candidates数组中有重复元素，但是每个数字只能被选取一次
*/
#include "stdafx.h"
#include <vector>

class Solution040 {
public:
    void test()
    {
        std::vector<int> vec = { 10,1,2,7,6,1,5};
        combinationSum2(vec, 8);
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {

        std::vector<std::vector<int>> res;
        std::vector<int> track;
        backtrack(candidates, res, track, 0, target);
        return res;
    }

    void backtrack(std::vector<int>& candidates, std::vector<std::vector<int>> &res, std::vector<int> &track, int nstart, int target)
    {
        if(target < 0) return;
        if (target == 0)
        {
            res.push_back(track);
            return;
        }
        if(nstart == candidates.size()) return;

        //选取nStart的数字
        track.push_back(candidates[nstart]);
        backtrack(candidates, res, track, nstart+1, target-candidates[nstart]);

        //不选取nStart的数字
        track.pop_back();
        backtrack(candidates, res, track, nstart+1, target);
    }
};