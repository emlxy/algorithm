#include <string>
#include <vector>
#include <queue>
#include <map>

class Solution127 {
public:
    void test()
    {
        string beginword = "hit";
        string endword = "cog";
        vector<string> vec = { "hot", "dot", "dog", "lot", "log", "cog" };
        ladderLength(beginword, endword, vec);

    }
    bool isOneDiff(string &str1, string &str2)
    {
        bool bDiff = false;
        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i] != str2[i])
            {
                if(!bDiff) bDiff = true;
                else return false;
            }
        }
        if(!bDiff) return false;
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> wordId;
        vector<string> idWord;
        int id = 0;
        for(string s : wordList)
        {
            wordId[s] = id++;
            idWord.push_back(s);
        }
        if(!wordId.count(endWord)) return 0;
        if(!wordId.count(beginWord))
        {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        vector<vector<int>> edges;
        edges.resize(id);

        for(int i=0; i<id; i++)
        {
            for(int j=i+1; j<id; j++)
            {
                if(isOneDiff(idWord[i], idWord[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        queue<vector<int>> q;
        q.push(vector<int>{wordId[beginWord]});

        int len = 0;
        int dest = wordId[endWord];
        vector<int> cost(id, id);
        cost[wordId[beginWord]] = 0;
        while(!q.empty())
        {
            vector<int> now = q.front();
            q.pop();

            int last = now.back();
            if(last == dest)
            {
                len = now.size();
                break;
            }
            else
            {
                vector<int> tmp = edges[last];
                for(int to : tmp)
                {
                    if(cost[last] + 1 <= cost[to])
                    {
                        cost[to] = cost[last] + 1;
                        vector<int> tt(now);
                        tt.push_back(to);
                        q.push(tt);
                    }
                }
            }

        }
        return len;
    }
};