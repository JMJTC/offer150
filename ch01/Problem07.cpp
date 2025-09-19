#include <vector>
using namespace std;

class Problem07
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int length = prices.size();
        int minPrice = prices[0];
        for (int i = 1; i < length; i++)
        {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};