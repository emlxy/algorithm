#include "stdafx.h"
#include <vector>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
class Solution012 {
public:
    void test()
    {
        intToRoman(8);
    }
    std::string getnumchar(int num)  //题目规定num不超过3999
    {
        switch (num)
        {
        case 1:
            return "I";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 9:
            return "IX";
        case 10:
            return "X";
        case 40:
            return "XL";
        case 50:
            return "L";
        case 90:
            return "XC";
        case 100:
            return "C";
        case 400:
            return "CD";
        case 500:
            return "D";
        case 900:
            return "CM";
        case 1000:
            return "M";
        }
        std::string res;
        if (num / 10 == 0)
        {
            if (num > 5) {
                res = "V";
                num -= 5;
            }
            while (num > 0)
            {
                res += "I";
                num--;
            }
        }
        else if (num / 100 == 0)
        {
            if (num > 50)
            {
                res = "L";
                num -= 50;
            }
            while (num > 0)
            {
                res += "X";
                num -= 10;
            }
        }
        else if (num / 1000 == 0)
        {
            if (num > 500)
            {
                res = "D";
                num -= 500;
            }
            while (num > 0)
            {
                res += "C";
                num -= 100;
            }
        }
        else if (num / 10000 == 0)
        {
            while (num > 0)
            {
                res += "M";
                num -= 1000;
            }
        }
        return res;
    }
    std::string intToRoman(int num) {
        std::string res;
        std::vector<int> vec;
        int nFlag = 1;
        while (num > 0)
        {
            int c = num % 10;
            vec.push_back(c*nFlag);
            num /= 10;
            nFlag *= 10;
        }
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            res += getnumchar(vec[i]);
        }
        return res;
    }
};