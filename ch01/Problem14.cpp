#include <vector>
using namespace std;

// 已经在谷底了，怎么走都是向上
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 初始化三个变量:
        // ans: 记录可能的起始加油站位置
        // minS: 记录遍历过程中油量的最小值
        // s: 记录当前累计的油量
        int ans = 0, minS = 0, s = 0;

        // 遍历所有加油站
        for (int i = 0; i < gas.size(); i++)
        {
            // 计算从当前加油站出发，到达下一站后的剩余油量
            s += gas[i] - cost[i];

            // 如果当前累计油量小于之前记录的最小值，则更新最小值和可能的起始位置
            // 这里的逻辑是：如果从某个点开始，到当前点的累计油量是最小的，
            // 那么从这个点的下一站开始，可能是更好的起点
            if (s < minS)
            {
                minS = s;
                ans = i + 1;
            }
        }

        // 检查是否存在可行解：如果总油量小于总消耗，则无法完成一圈，返回-1
        // 否则返回找到的起始位置
        return s < 0 ? -1 : ans;
    }
};