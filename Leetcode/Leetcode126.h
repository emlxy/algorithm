#include <string>
#include <vector>
#include <queue>
#include <map>
//自己重写bfs写法
class Solution126 {
public:
    void test()
    {
        string beginword = "hit";
        string endword = "cog";
        vector<string> vec = { "hot", "dot", "dog", "lot", "log", "cog" };
        findLadders(beginword, endword, vec);
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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> wordId;
        vector<string> idWord;
        int id = 0;
        for(auto s : wordList)
        {
            wordId[s] = id++;
            idWord.push_back(s);
        }
        if(!wordId.count(endWord)) return {};

        if(!wordId.count(beginWord))
        {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        vector<vector<int>> edges;
        edges.resize(idWord.size());
        for(int i=0; i<idWord.size(); i++)
        {
            for(int j=i+1; j<idWord.size(); j++)
            {
                if(isOneDiff(idWord[i], idWord[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        vector<int> cost(idWord.size(), idWord.size());
        cost[wordId[beginWord]] = 0;

        int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        q.push(vector<int>{wordId[beginWord]});
        while(!q.empty())
        {
            vector<int> now = q.front();
            q.pop();

            int last = now.back();
            if(last == dest)
            {
                vector<string> vec;
                for (int index : now) {
                    vec.push_back(idWord[index]);
                }
                res.push_back(vec);
            }
            else
            {
                for(int i=0; i<edges[last].size(); i++)
                {
                    int to = edges[last][i];
                    if(cost[last] + 1 <= cost[to])
                    {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
};
