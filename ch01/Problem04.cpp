#include <algorithm>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
// 80. 删除有序数组中的重复项 II

class Problem04
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 1;
        int preCount = 0;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == pre)
            {
                preCount++;
            }
            else
            {
                preCount = 0;
                pre = nums[i];
            }

            if (preCount < 2)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};