#include <vector>
using namespace std;
// https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
// 238. 除自身以外数组的乘积
class Problem13
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> pre(length, 1);
        vector<int> after(length, 1);
        for (int i = 1; i < length; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = length - 2; i >= 0; i--)
        {
            after[i] = after[i + 1] * nums[i + 1];
        }
        vector<int> ans(length);
        for (int i = 0; i < length; i++)
        {
            ans[i] = pre[i] * after[i];
        }
        return ans;
    }
};