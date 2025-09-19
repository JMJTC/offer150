#include <vector>
using namespace std;

// https://leetcode.cn/problems/candy/?envType=study-plan-v2&envId=top-interview-150
// 135. 分发糖果
class Solution
{
  public:
    /**
     * @brief 计算根据孩子评分分发糖果的最小总数
     * @param ratings 每个孩子的评分数组
     * @return int 分发的糖果最小总数
     * @note 题目规则：
     * 1. 每个孩子至少获得1颗糖果
     * 2. 评分更高的孩子必须比他相邻的孩子获得更多的糖果
     */
    int candy(vector<int> &ratings)
    {
        int ans = 0; // 总糖果数

        // 初始化每个孩子至少1颗糖果
        vector<int> candy(ratings.size(), 1);

        // 第一次遍历：从左到右，确保右边评分高的孩子获得更多糖果
        for (int i = 1; i < ratings.size(); i++)
        {
            // 如果当前孩子评分高于左边孩子，则糖果数比左边多1
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // 第二次遍历：从右到左，确保左边评分高的孩子获得更多糖果
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            // 如果当前孩子评分高于右边孩子，且糖果数不大于右边孩子，则糖果数比右边多1
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
            }
            // 累加当前孩子的糖果数到总数中
            ans += candy[i];
        }

        // 加上最后一个孩子的糖果数并返回
        return ans + candy[ratings.size() - 1];
    }
};