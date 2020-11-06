#include "stdafx.h"

class Solution009 {
public:
    void test()
    {
        bool bValid = isPalindrome(234);
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int temp = x;
        int res = 0;
        while (temp > 0)
        {
            int a = temp % 10;
            if ((res == INT_MAX / 10 && a > INT_MAX % 10) || res > INT_MAX / 10)
                return false;
            res = res * 10 + a;
            temp /= 10;
        }
        return res == x;
    }
};