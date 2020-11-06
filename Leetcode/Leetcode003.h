#include "stdafx.h"
#include <string>
#include <set>

class Solution003 {
public:
    void test()
    {

    }

    //»¬¶¯´°¿Ú
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty())
            return 0;
        int left = 0, right = 0;
        int maxlen = 0;
        std::set<char> set_window;
        for (int i = 0; i < s.length(); i++)
        {
            while (set_window.count(s[i]))
            {
                set_window.erase(s[left]);
                left++;
            }

            set_window.insert(s[i]);
            maxlen = maxlen > (i - left + 1) ? maxlen : (i - left + 1);
        }
        return maxlen;
    }
};
