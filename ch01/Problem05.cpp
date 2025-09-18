#include <vector>
using namespace std;

// https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150
// 169. 多数元素

class Problem150
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int ans = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == ans)
            {
                count++;
            }
            else
            {
                if (--count < 0)
                {
                    count = 0;
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};