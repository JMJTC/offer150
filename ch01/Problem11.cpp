#include <algorithm> // 提供min函数
#include <vector>    // 提供vector容器
using namespace std;

/**
 * @brief Problem11类 - 解决计算h-index问题
 * h-index是衡量研究人员学术产出影响力的指标，定义为：
 * 有h篇论文被引用了至少h次，且其余论文被引用次数不超过h次
 */
class Problem11
{
  public:
    /**
     * @brief 计算给定引用次数数组的h-index
     * @param citations 引用次数数组，每个元素表示对应论文的引用次数
     * @return int 计算得到的h-index值
     */
    int hIndex(vector<int> &citations)
    {
        // 获取论文总数
        int length = citations.size();
        
        // 创建一个计数数组，索引表示引用次数，值表示具有该引用次数的论文数
        // 由于h-index最大不可能超过论文总数，所以数组长度为length+1即可
        vector<int> data(length + 1);
        
        // 统计各引用次数的论文数量
        // 对于引用次数超过论文总数的论文，统一视为引用次数等于论文总数
        for (int i : citations)
        {
            data[min(length, i)]++;
        }
        
        // s表示引用次数大于等于i的论文总数
        int s = 0;
        
        // 从后往前遍历，找到最大的h值
        for (int i = length; i >= 0; i--)
        {
            // 累加引用次数大于等于i的论文数量
            s += data[i];
            
            // 当累计论文数大于等于当前引用次数阈值时，找到h-index
            if (s >= i)
            {
                return i;
            }
        }
        
        // 理论上不会执行到这里，但为了完整性返回-1
        return -1;
    }
};