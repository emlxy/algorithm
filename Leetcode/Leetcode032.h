#include "stdafx.h"
#include <string>
#include <stack>

class Solution032 {
public:
    void test()
    {
        std::string s = ")()())";
        longestValidParentheses(s);
    }
    int longestValidParentheses(std::string s) {
        int maxlen = 0;
        int len = 0;
        std::stack<char> stk;
        for(char c : s)
        {
            if(c == '(')
            {
                stk.push(c);
            }
            else
            {
                if(stk.empty())
                {
                    continue;
                }
                else if(stk.top() == ')')
                {
                    len = 0;
                    while(!stk.empty()) stk.pop();
                }
                else
                {
                    len += 2;
                    maxlen = maxlen > len ? maxlen : len;
                    stk.pop();
                }
            }
        }
        return maxlen;
    }
};