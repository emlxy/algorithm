#include "stdafx.h"
#include <string>
#include <vector>

class Solution006 {
public:
    void test()
    {
        std::string strEnd = convert("AB", 1);
    }
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::vector<std::string> res;
        for (int i = 0; i < numRows; i++)
        {
            res.push_back(string());
        }
        int iRow = 0;
        int nChange = 1;
        for (int i = 0; i < s.length(); i++)
        {
            res[iRow].push_back(s.at(i));

            iRow += nChange;
            if (iRow == numRows)
            {
                nChange = -1;
                iRow += nChange;
                iRow += nChange;
            }
            else if (iRow < 0)
            {
                nChange = 1;
                iRow += nChange;
                iRow += nChange;
            }
        }
        std::string strEnd;
        for (int i = 0; i < res.size(); i++)
            for (int j = 0; j < res[i].size(); j++)
                strEnd.push_back(res[i][j]);
        return strEnd;
    }
};
