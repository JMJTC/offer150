#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

// 定义一个解决方案类
class Solution
{
  public:
    // 函数用于计算和大于等于 target 的最短子数组长度
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 初始化结果为数组长度加 1，用于后续判断是否存在符合条件的子数组
        int ans = nums.size() + 1;
        // 定义一个双端队列，用于维护子数组元素
        deque<int> queue;
        // 获取数组的长度
        int length = nums.size();
        // 初始化子数组元素和为 0
        int sum = 0;

        // 遍历数组中的每个元素
        for (int i = 0; i < length; i++)
        {
            // 入队：将当前元素加入队列，并更新子数组元素和
            sum += nums[i];
            queue.push_back(nums[i]);

            // 当子数组元素和大于等于目标值时，尝试缩小子数组长度
            while (sum >= target)
            {
                // 更新最短子数组长度
                ans = min(ans, (int)queue.size());
                // 出队：移除队列头部元素，并更新子数组元素和
                sum -= queue.front();
                queue.pop_front();
            }
        }

        // 如果 ans 仍为初始值，说明不存在符合条件的子数组，返回 0；否则返回最短子数组长度
        return ans == nums.size() + 1 ? 0 : ans;
    }
};