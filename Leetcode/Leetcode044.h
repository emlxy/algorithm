#include "stdafx.h"
#include <string>

class Solution044 {
public:
    void test()
    {
        string s1 = "adceb", s2 = "*a*b";
        //string s1 = "a", s2 = "*a";
        bool a = isMatch(s1, s2);
        int aa = 0; 
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if (p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }
        return dp[m][n];
    }
};