#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:

    int calculateProfit(vector<int>& prices, int i)
    {
        int profit = 0;
        int diff;

        if (i > prices.size() - 1)
            return 0;
        
        for (i; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] - prices[i] > 0)
                {
                    diff = prices[j] - prices[i] + calculateProfit(prices, j + 1);
                    if (diff > profit)
                    {
                        profit = diff;
                        // cout << "recursion loop " <<  prices[j] << " & " << prices[i] << " profit = " << profit << endl; 
                    }
                }
            }
        }
        return profit; 
    }


    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int diff;
        
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] - prices[i] > 0)
                {
                    diff = prices[j] - prices[i] + calculateProfit(prices, j + 1);
                    if (diff > profit)
                    {
                        profit = diff;
                        // cout << "main loop " <<  prices[j] << " & " << prices[i] << " profit = " << profit << endl; 
                        // cout << "----------------------" << endl;
                    }
                }
            }
        }
        return profit;
    }
};

*/


class Solution {
public:

    int maxProfit(vector<int>& prices)
    {
        // Status: Buy-true | Sell-false  
        bool status = false;
        int profit = 0;
        int buyValue;
        int lastIndex = prices.size() - 1;

        for (int i = 0; i <= lastIndex; i++)
        {
            if (status == false && i != lastIndex && (prices[i] < prices[i + 1]))
            {
                status = true;
                buyValue = prices[i];
                cout << "Buy at  [" << i << "] = " << buyValue << endl; 
            }
            if (status == true && (i == lastIndex || (prices[i] > prices[i + 1])))
            {
                status = false;
                profit += prices[i] - buyValue;
                cout << "Sell at [" << i << "] = " << prices[i] << " | Profit made = " << profit << endl; 
            }
        }
        return profit;
    }
};

void testcase(vector<int> nums)
{   
    cout << "--------------------------------\n";

    for (int num : nums)
        cout << num << ", ";
    cout << "\n" <<endl;

    Solution test;
    int maxProfit = test.maxProfit(nums);
    cout << "maxProfit = " << maxProfit << endl;
}

int main()
{
    testcase(vector<int>{7,1,5,3,6,4}); // 7
    testcase(vector<int>{1,2,3,4,5}); // 4
    testcase(vector<int>{0, 7}); // 7
    testcase(vector<int>{2, 2, 2}); // 0
    testcase(vector<int>{1, 0, 2}); // 2
    testcase(vector<int>{200, 100, 1000, 3, 5, 6, 6, 3000, 20}); // 3897

    testcase(vector<int>{7, 2, 3, 11, 4, 6, 1, 4}); // 14

    testcase(vector<int>{34,82,16,74,55,46,44,25,96,80,51,62,73,26,76,30,20,30,55,6,3,93}); // 374
}
