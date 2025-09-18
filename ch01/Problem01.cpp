#include <vector>
using namespace std;

// https://leetcode.cn/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
// 88. 合并两个有序数组
class Problem01
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int index1 = m - 1;
        int index2 = n - 1;
        int index = m + n - 1;
        while (index2 >= 0)
        {
            // 将nums2 合并到nums1
            if (index1 >= 0 && nums1[index1] >= nums2[index2])
            {
                nums1[index--] = nums1[index1--];
            }
            else
            {
                nums1[index--] = nums2[index2--];
            }
        }
    }
};