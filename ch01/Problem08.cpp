#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
// 122. 买卖股票的最佳时机 II

class Problem08
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int length = prices.size();
        for (int i = 1; i < length; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};