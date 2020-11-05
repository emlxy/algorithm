#include "stdafx.h"
#include <string>

class Solution005 {
public:
    void test()
    {
        std::string s = "sdfsddddsfdsdf";
        std::string max = longestPalindrome(s);
    }
    std::string getmax(std::string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right))
        {
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    std::string longestPalindrome(std::string s) {
        std::string maxstr = "";
        std::string s1 = "";
        std::string s2 = "";
        for (int i = 0; i < s.length(); i++)
        {
            s1 = getmax(s, i, i);
            s2 = getmax(s, i, i+1);

            maxstr = s1.size() > maxstr.size() ? s1 : maxstr;
            maxstr = s2.size() > maxstr.size() ? s2 : maxstr;
        }
        return maxstr;
    }
};
