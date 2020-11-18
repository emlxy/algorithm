#include "stdafx.h"
#include <map>
#include <string>

class Solution030 {
public:
    void test()
    {
        string s = "mississippi";
        vector<string> vec = { "mississippis" };
        findSubstring(s, vec);
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;

        int n = words.size();
        int len = words[0].length();

        map<string, int> need;
        map<string, int> window;
        int valid = 0;
        for (int i = 0; i < words.size(); i++)
        {
            need[words[i]]++;
        }

        for (int i = 0; i < len; i++)
        {
            int left = i;
            valid = 0;
            window.clear();  //这里记得条件清空

            //判断条件适用这个，0<=-1,为true。。
            //for (int right = left; right <= (s.length() - len); right += len)

            int edge = s.length() - len;
            for (int right = left; right <= edge; right += len)
            {
                string strRight = s.substr(right, len);
                if (need.count(strRight) > 0)
                {
                    window[strRight]++;
                    valid++;
                    if (window[strRight] > need[strRight])  //找到多余的，依次向后移动
                    {
                        while (true)
                        {
                            string strLeft = s.substr(left, len);
                            bool bStop = false;
                            if (strLeft == strRight)
                                bStop = true;
                            valid--;
                            window[strLeft]--;
                            left += len;      //几个条件中都要注意更新left的值，left一定小于right
                            if (bStop) break;
                        }
                    }
                    if (valid == words.size())  //找到结果
                    {
                        res.push_back(left);
                        string strLeft = s.substr(left, len);
                        window[strLeft]--;
                        valid--;
                        left += len;
                    }
                }
                else  //找到一个不是words list中的
                {
                    left = right + len;
                    window.clear();
                    valid = 0;
                }
            }
        }
        return res;
    }
};