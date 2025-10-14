#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        // 用于存储结果的字符串向量
        vector<string> ret;
        // 初始化索引i为0，用于遍历数组
        int i = 0;
        // 获取数组的大小
        int n = nums.size();
        // 当索引i小于数组大小时，继续循环
        while (i < n)
        {
            // 记录当前范围的起始索引
            int low = i;
            // 将索引i向后移动一位
            i++;
            // 检查后续的数字是否连续递增
            while (i < n && nums[i] == nums[i - 1] + 1)
            {
                // 如果连续，继续向后移动索引
                i++;
            }
            // 记录当前范围的结束索引
            int high = i - 1;
            // 将起始数字转换为字符串
            string temp = to_string(nums[low]);
            // 如果起始索引小于结束索引，说明这是一个范围而不是单个数字
            if (low < high)
            {
                // 添加范围符号"->"
                temp.append("->");
                // 添加结束数字
                temp.append(to_string(nums[high]));
            }
            // 将结果移动到结果向量中（使用move避免不必要的拷贝）
            ret.push_back(move(temp));
        }
        // 返回结果向量
        return ret;
    }
};