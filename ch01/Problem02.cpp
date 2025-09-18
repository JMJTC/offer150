#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
// 27. 移除元素
class Problem02
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};