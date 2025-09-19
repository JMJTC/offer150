#include <vector>
using namespace std;

class Problem10
{
  public:
    int jump(vector<int> &nums)
    {
        int count = 1;
        int length = nums.size();
        if (length <= 1)
        {
            return 0;
        }
        int index = 1;
        int maxReach = nums[0];
        while (maxReach < length - 1)
        {
            count++;
            int temp = maxReach;
            for (int i = index; i <= temp; i++)
            {
                maxReach = max(maxReach, nums[i] + i);
            }
            index = temp + 1;
        }
        return count;
    }
};