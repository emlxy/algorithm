#include <vector>

class Solution123 {
public:
    void test()
    {
        vector<int> vec = { 3, 3, 5, 0, 0, 3, 1, 4 };
        int n = maxProfit(vec);
        int na = n;
    }

    void generateLeft(vector<int> &prices, int *leftArray)
    {
        int index = 0;
        leftArray[0] = 0;
        int basemin = INT_MAX;
        int maxnum = 0;
        while(index < prices.size())
        {
            if(prices[index] > basemin)
            {
                maxnum = max(prices[index] - basemin, maxnum);
            }
            else if(prices[index] < basemin)
            {
                basemin = prices[index];
            }
            leftArray[index+1] = max(leftArray[index], maxnum);
            index++;
        }
    }

    void generateRight(vector<int> &prices, int *rightArray)
    {
        rightArray[prices.size()] = 0;
        int index = prices.size()-1;
        int basemax = INT_MIN;
        int maxnum = 0;
        while(index >= 0)
        {
            if(prices[index] < basemax)
            {
                maxnum = max(basemax - prices[index], maxnum);
            }
            else if(prices[index] > basemax)
            {
                basemax = prices[index];
            }
            rightArray[index] = max(rightArray[index+1], maxnum);
            index--;
        }
    }

    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int *leftArray = new int[m+1];
        int *rightArray = new int[m+1];
        generateLeft(prices, leftArray);
        generateRight(prices, rightArray);

        int maxnum = 0;
        for(int i=0; i<=m; i++)
        {
            maxnum = max(leftArray[i]+rightArray[i], maxnum);
        }
        return maxnum;
    }
};


/*超时版本*/
class Solution {
public:
    int oneTimeMaxProfit(vector<int>& prices,int left, int right)
    {
        if(left>= right) return 0;
        int leftnum = INT_MAX;
        int maxnum = 0;
        while(left < right)
        {
            if(prices[left] > leftnum)
            {
                maxnum = max(prices[left] - leftnum, maxnum);
            }
            else if(prices[left] < leftnum)
            {
                leftnum = prices[left];
            }
            left++;
        }
        return maxnum;
    }

    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int *leftArray = new int[m+1];
        int *rightArray = new int[m+1];
        for(int i=0; i<=m; i++)
            leftArray[i] = oneTimeMaxProfit(prices, 0, i);
        for(int i=0; i<=m; i++)
            rightArray[i] = oneTimeMaxProfit(prices, i, m);

        //单调递增(从左到右)
        for(int i=1; i<=m; i++)
        {
            if(leftArray[i] < leftArray[i-1])
                leftArray[i] = leftArray[i-1];
        }
        //单调递减(从左到右)
        for(int i=m-1; i>=0; i--)
        {
            if(rightArray[i] < rightArray[i+1])
                leftArray[i] = leftArray[i+1];
        }
        int maxnum = 0;
        for(int i=0; i<=m; i++)
        {
            maxnum = max(leftArray[i]+rightArray[i], maxnum);
        }
        return maxnum;
    }
};