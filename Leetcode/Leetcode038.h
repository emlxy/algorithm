#include "stdafx.h"
#include <string>
//主要就是统计每个字符出现的次数

class Solution038 {
public:
    char getcharfromnum(int num)
    {
        return '0' + num;
    }

    std::string countAndSay(int n) {
        std::string str = "1";
        std::string temp = "";
        int i = 2;
        while(i <= n)
        {
            char pre = ' ';
            int count = 0;
            for(char c : str)
            {
                if(c != pre)
                {
                    if(count > 0)
                    {
                        char nCount = getcharfromnum(count);
                        temp.push_back(nCount);
                        temp.push_back(pre);
                    }
                    count = 1;
                    pre = c;
                }
                else
                {
                    count++;
                }
            }
            if(count > 0)
            {
                char nCount = getcharfromnum(count);
                temp.push_back(nCount);
                temp.push_back(pre);
            }
            str = temp;
            temp = "";
            i++;
        }
        return str;
    }
};