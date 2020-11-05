#include "stdafx.h"
#include <string>

class Solution008 {
public:
    void test()
    {
        int num = myAtoi("-42");
    }

    int myAtoi(std::string s) {
        int res = 0;
        int bflag = 1;
        bool bStart = false;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.at(i);

            if (c == ' ')
            {
                if (bStart)
                    break;
                else
                    continue;
            }
            if (c == '-' || c == '+')
            {
                if (bStart) break;
                bStart = true;
                bflag = c == '-' ? -1 : 1;
                continue;
            }
            if (c >= '0' && c <= '9')
            {
                bStart = true;

                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && c > '7')) return INT_MAX;
                if (res < INT_MIN / 10 || (res == INT_MIN / 10 && c > '8')) return INT_MIN;
                res = (std::abs(res) * 10 + c - '0') * bflag;
            }
            else
                break;
        }
        return res;
    }
};