#include "stdafx.h"
#include <string>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/


class Solution013 {
public:
    void test()
    {
        romanToInt("IV");
    }
    int getnum(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(std::string s) {
        int res = 0;
        int pre = 0;
        int cur = 0;
        for (char c : s)
        {
            cur = getnum(c);
            (cur > pre && pre > 0) ? res -= pre : res += pre;
            pre = cur;
        }
        res += cur;
        return res;
    }
};