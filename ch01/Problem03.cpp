#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

// 26. 删除有序数组中的重复项
class Problem03
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 1;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != pre)
            {
                nums[index++] = nums[i];
                pre = nums[i];
            }
        }
        return index;
    }
};

int main()
{
    vector<int> nums({1, 1, 2});
    cout << Problem03().removeDuplicates(nums) << endl;
    return 0;
}