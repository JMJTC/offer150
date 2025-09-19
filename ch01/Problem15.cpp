#include <vector>
using namespace std;

// https://leetcode.cn/problems/candy/?envType=study-plan-v2&envId=top-interview-150
// 135. 分发糖果
class Solution
{
  public:
    int candy(vector<int> &ratings)
    {
        int ans = 0;
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
            }
            ans += candy[i];
        }
        return ans + candy[ratings.size() - 1];
    }
};