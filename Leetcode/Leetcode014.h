#include "stdafx.h"
#include <string>
#include <vector>

class Solution014 {
public:
    void test()
    {
        std::vector<std::string> vec = {};
        longestCommonPrefix(vec);
    }
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) return "";   //因为下面用了strs[0]，需要判断
        std::string strmax = strs[0];
        int minlen = strmax.length();
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            int nCommon = 0;
            while (j < strs[i].size() && j < strs[i - 1].size())
            {
                if (strs[i].at(j) != strs[i-1].at(j))
                    break;
                j++;
                if (j > minlen)
                    break;
            }
            minlen = min(minlen, j);
        }
        return strmax.substr(0, minlen);
    }
};