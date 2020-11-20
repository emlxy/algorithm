#include "stdafx.h"
#include <vector>

class Solution074 {
public:
    void test()
    {
        vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
        searchMatrix(matrix, 13);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();

        int left = 0, right = m*n;
        while(left < right)
        {
            int mid = (right + left) / 2;
            if(matrix[mid/n][mid%n] == target)
                return true;
            else if(matrix[mid/n][mid%n] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return false;
    }
};