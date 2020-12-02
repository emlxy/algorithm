#include <string>
#include <vector>

class Solution093 {
public:
    void test()
    {
        string s = "25525511135";
        restoreIpAddresses(s);
    }

    bool isvalid(string &str)
    {
        int res = 0;
        for (int i = 0; i < str.length(); i++)
        {
            res = (str[i] - '0') + res * 10;
        }
        return res <= 255;
    }

    void backtrack(string &s, int startIndex, int numIndex, string &track, vector<string> &vecres)
    {
        if(numIndex == 5)
        {
            if (startIndex == s.length())
                vecres.push_back(track.substr(0, track.length()-1));
            return;
        }

        for(int i=1; i<=3; i++)
        {
            if(startIndex + i > s.length()) break;
            if(s[startIndex] == '0')
            {
                track += s.substr(startIndex, 1);
                track += string(1,'.');
                backtrack(s, startIndex+1, numIndex+1, track, vecres);
                track = track.substr(0, track.length() - (1 + i));
                return;
            }

            string str = s.substr(startIndex, i);
            if(!isvalid(str)) continue;

            track += s.substr(startIndex, i);
            track += string(1,'.');
            backtrack(s, startIndex+i, numIndex+1, track, vecres);
            track = track.substr(0, track.length()-(1+i));
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(len>12 || len<4) return vector<string>();

        vector<string> vecres;
        string track;
        backtrack(s, 0, 1, track, vecres);

        return vecres;
    }
};