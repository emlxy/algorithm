#include "stdafx.h"
#include <string>

class Solution043 {
public:
    void test()
    {
        string s1 = "2", s2 = "3";
        multiply(s1, s2);
    }
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if (m == 1 && num1 == "0") return "0";
        if (n == 1 && num2 == "0") return "0";

        int *pRes = new int[m+n];
        memset(pRes, 0, sizeof(int)*(m + n));
        int nFlag = 0;
        for(int i=m; i>0; i--)
        {
            int mul_1 = num1[i-1] - '0';
            for(int j=n; j>0; j--)
            {
                int mul_2 = num2[j-1] - '0';
                int res = mul_1 * mul_2 + pRes[i+j-1];
                pRes[i+j-1] = res % 10;
                pRes[i+j-2] += res / 10;
            }
        }

        string strRes;
        int index = 0;
        while(index < m+n && pRes[index] == 0) index++;
        for(int i = index; i<m+n; i++)
        {
            strRes += ('0' + pRes[i]);
        }
        return strRes;
    }
};