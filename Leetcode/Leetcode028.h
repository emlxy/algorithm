#include "stdafx.h"
#include <string>

class Solution028 {
public:
    void test()
    {
        std::string s1 = "mississippi";
        std::string s2 = "issip";
        strStr(s1, s2);
    }
    int strStr(std::string haystack, std::string needle) {
        if(needle.size() == 0) return -1;
        int m = haystack.size();
        int n = needle.size();

        char **dp = new char*[n];
        for(int i=0; i<n; i++)
            dp[i] = new char[256];
        memset(dp[0], 0, 256);

        dp[0][needle.at(0)] = 1;
        int x = 0;
        for(int i = 1; i<n; i++)      //kmp算法构建dp
        {
            for(int c=0; c<256; c++)
            {
                dp[i][c] = dp[x][c];
            }
            dp[i][needle.at(i)] = i+1;
            x = dp[x][needle.at(i)];
        }

        int j = 0;
        int pos = -1;  //不存在返回-1
        for(int k=0; k<m; k++)
        {
            j = dp[j][haystack.at(k)];
            if(j == n)
            {
                pos = k-n+1;
                break;
            }
        }
        return pos;
    }
};