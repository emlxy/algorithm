#include <vector>

class Solution240 {
public:
    void test()
    {
        //vector<vector<int>> _vec = { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 }};
        //searchMatrix(_vec, 5);

        vector<vector<int>> _vec1 = { { 1, 4 }, { 2, 5 } };
        searchMatrix(_vec1, 4);
    }

    bool biFind2(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2)
    {
        int low = 0, high = 0;
        if(x1 == x2)
        {
            low = y1;
            high = y2;
        }
        else if(y1 == y2)
        {
            low = x1;
            high = x2;
        }
        else return false;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int num = 0;
            if(x1 == x2)
                num = matrix[x1][mid];
            else
                num = matrix[mid][y1];
            if(num == target)
                return true;
            else if(num < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    bool searchPart1(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2)
    {
        if(x1 == x2 || y1 == y2)
        {
            return biFind2(matrix, target, x1, y1, x2, y2);
        }
        if(target < matrix[x1][y1] || target > matrix[x2][y2])
            return false;

        int midx = x1+(x2-x1)/2;
        int midy = y1+(y2-y1)/2;

        bool bFind = false;
        if(target < matrix[midx][midy]) //去除右下角
        {
            bFind = searchPart1(matrix, target, x1, y1, midx, midy);
            if(bFind) return true;
            bFind = searchPart1(matrix, target, midx+1, y1, x2, midy-1);
            if(bFind) return true;
            return searchPart1(matrix, target, x1, midy+1, midx-1, y2);
        }
        else if(target > matrix[midx][midy]) //去除左上角
        {
            bFind = searchPart1(matrix, target, midx+1, y1, x2, y2);
            if(bFind) return true;
            return searchPart1(matrix, target, x1, midy+1, midx-1, y2);
        }

        /*if(target < matrix[midx][midy]) //去除右下角
        {
            bFind = searchPart1(matrix, target, x1, y1, x2, midy); //左半边
            if(bFind) return true;
            return searchPart1(matrix, target, x1, midy, midx-1, y2); //右上角
        }
        else  //去除左上角
        {
            bFind = searchPart1(matrix, target, midx, y1, x2, y2);  //下半边
            if(bFind) return true;
            return searchPart1(matrix, target, x1, midy+1, midx, y2);  //右上角
        }*/
        return true;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        return searchPart1(matrix, target, 0, 0, m-1, n-1);
    }
};