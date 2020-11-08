#include "stdafx.h"
#include <vector>
#include <string>

class Solution010 {
public:
    void test()
    {
        std::string s = "mississippi";
        std::string p = "mis*is*p*.";
        bool bflag = isMatch(s, p);
        int a = 1;
    }
    bool isMatch(std::string s, std::string p) {
        int slen = s.length();
        int plen = p.length();

        bool **dp = new bool*[slen +1];
        for (int i = 0; i <= slen; i++)
            dp[i] = new bool[plen+1];   //bool的初始值不确定

        //base case
        for (int i = 0; i <= slen; i++)
            dp[i][0] = false;
        dp[0][0] = true;
        for(int j = 1; j<=plen; j++)
            dp[0][j] = p.at(j-1) == '*' ? dp[0][j - 2] : false;

        for(int i = 1; i <= slen; i++)
            for(int j = 1; j <= plen; j++)
            {
                if (p.at(j-1) == '.' || p.at(j-1) == s.at(i-1))
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p.at(j-1) == '*')
                {
                    if (p.at(j-2) == '.' || p.at(j-2) == s.at(i-1))
                    {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];  //因为题目中规定了*之前必须有有效字符，所以j-2不会越界
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else
                {
                    dp[i][j] = false;  //因为bool类型初始值不确定
                    //return false;    //不能直接return。因为有可能会被后面的*把这个消掉
                }
            }
        return dp[slen][plen];
    }
};