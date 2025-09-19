#include <vector>
using namespace std;

// 189. 轮转数组
// https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

class Problem06
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        auto reverse = [&](int i, int j) {
            while (i < j)
            {
                swap(nums[i++], nums[j--]);
            }
        };

        int length = nums.size();
        k %= length;
        reverse(0, length - 1);
        reverse(0, k - 1);
        reverse(k, length - 1);
    }
};