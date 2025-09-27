#include <vector>
using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150
// 42. 接雨水
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int length = height.size();
        int ans = 0;
        // 前后缀
        vector<int> leftMax(length), rightMax(length);
        leftMax[0] = height[0];
        for (int i = 1; i < length; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[length - 1] = height[length - 1];
        for (int i = length - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 0; i < length; i++)
        {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    // 空间优化
    int trap2(vector<int> &height)
    {
        int length = height.size();
        int ans = 0;
        int leftMax = height[0], rightMax = height[length - 1];
        for (int i = 1, j = length - 2; i <= j;)
        {
            if (leftMax < rightMax)
            {
                ans += max(leftMax - height[i], 0);
                leftMax = max(leftMax, height[i]);
                i++;
            }
            else
            {
                ans += max(rightMax - height[j], 0);
                rightMax = max(rightMax, height[j]);
                j--;
            }
        }
        return ans;
    }
};