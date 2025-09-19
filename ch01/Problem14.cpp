#include <vector>
using namespace std;

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ans = 0, minS = 0, s = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            s += gas[i] - cost[i];
            if (s < minS)
            {
                minS = s;
                ans = i + 1;
            }
        }
        return s < 0 ? -1 : ans;
    }
};