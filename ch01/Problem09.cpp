#include <vector>
using namespace std;
// https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
//  55. 跳跃游戏
class Problem09
{
  public:
    bool canJump(vector<int> &nums)
    {
        int length = nums.size();
        int maxReach = nums[0];
        for (int i = 1; i < length; i++)
        {
            if (maxReach < i)
            {
                return false;
            }
            maxReach = max(maxReach, nums[i] + i);
            if (maxReach >= length - 1)
            {
                return true;
            }
        }
        return true;
    }
};