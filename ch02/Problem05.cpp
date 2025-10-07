#include <algorithm>
#include <vector>
using namespace std;

// 定义一个 Solution 类，用于解决算法问题
class Solution
{
  public:
    // 三数之和函数，使用二分查找的方法找到所有和为 0 的不重复三元组
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;  // 用于存储最终结果的二维向量
        vector<int> data;         // 该变量未使用，可考虑移除
        sort(nums.begin(), nums.end());  // 对输入数组进行排序，方便后续去重和查找
        int n = nums.size();      // 获取数组的长度

        // 遍历数组，固定第一个数
        for (int index1 = 0; index1 < n - 2; ++index1)
        {
            // 去重：避免第一个数重复
            if (index1 > 0 && nums[index1] == nums[index1 - 1])
                continue;

            int index2 = n - 1;  // 初始化第二个数的指针为数组末尾
            // 当第一个数的索引小于第二个数索引减 1 时继续循环
            while (index1 < index2 - 1)
            {
                int target = 0 - nums[index1] - nums[index2];  // 计算需要查找的第三个数的值

                // 二分查找第三个数
                auto it = lower_bound(nums.begin() + index1 + 1, nums.begin() + index2, target);
                int idx = it - nums.begin();  // 获取找到的数的索引

                // 如果找到了目标数且其索引小于第二个数的索引
                if (it != nums.begin() + index2 && *it == target)
                {
                    ans.push_back({nums[index1], nums[idx], nums[index2]});  // 将满足条件的三元组加入结果集

                    // 去重：第二、第三个数
                    while (index2 > 0 && nums[index2] == nums[index2 - 1])
                        index2--;
                    index2--;
                }
                else
                {
                    // 调整右指针
                    index2--;
                }
            }
        }

        return ans;  // 返回最终结果
    }

    // 三数之和函数，使用双指针的方法找到所有和为 0 的不重复三元组
    vector<vector<int>> threeSum1(vector<int> &nums)
    {
        vector<vector<int>> ans;  // 用于存储最终结果的二维向量
        sort(nums.begin(), nums.end());  // 对输入数组进行排序，方便后续去重和查找
        int n = nums.size();      // 获取数组的长度

        // 遍历数组，固定第一个数
        for (int i = 0; i < n - 2; ++i)
        {
            // 1️⃣ 第一个数去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;     // 初始化左指针为第一个数的下一个位置
            int right = n - 1;    // 初始化右指针为数组末尾

            // 当左指针小于右指针时继续循环
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];  // 计算当前三个数的和

                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});  // 将满足条件的三元组加入结果集

                    // 2️⃣ 左指针去重
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // 3️⃣ 右指针去重
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;  // 和小于 0，左指针右移增大和
                }
                else
                {
                    right--; // 和大于 0，右指针左移减小和
                }
            }
        }

        return ans;  // 返回最终结果
    }
};
