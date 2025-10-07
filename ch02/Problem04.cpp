#include <algorithm>
#include <vector>
using namespace std;

// 定义一个解决方案类
class Solution
{
  public:
    // 计算给定高度数组所能容纳的最大水量
    // 参数 height: 一个整数向量，表示一系列垂直线的高度
    // 返回值: 这些垂直线所能容纳的最大水量
    int maxArea(vector<int> &height)
    {
        // 初始化左指针，指向数组的起始位置
        int left = 0;
        // 初始化右指针，指向数组的末尾位置
        int right = height.size() - 1;
        // 初始化最大水量为 0
        int ans = 0;

        // 使用双指针法，当左指针小于右指针时继续循环
        while (left < right)
        {
            // 计算当前左右指针所围成的容器的水量，并更新最大水量
            ans = max(min(height[left], height[right]) * (right - left), ans);

            // 如果左指针指向的高度小于右指针指向的高度，移动左指针向右
            if (height[left] < height[right])
            {
                left++;
            }
            // 否则，移动右指针向左
            else
            {
                right--;
            }
        }

        // 返回计算得到的最大水量
        return ans;
    }
};