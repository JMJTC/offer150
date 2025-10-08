#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 定义解决方案类
class Solution
{
  public:
    /**
     * 算法思路：
     * 本题的目标是在字符串 s 中找出由单词数组 words 中所有单词拼接组成的子串的起始索引。
     * 由于 words 中的单词可以任意排列组合，且每个单词长度固定，因此采用滑动窗口结合哈希表的方法来解决。
     * 
     * 1. 预处理阶段：
     *    - 检查输入字符串 s 和单词数组 words 是否为空，若为空直接返回空结果。
     *    - 获取单个单词的长度 wordLen 和单词数组中单词的数量 numWords。
     *    - 计算由所有单词拼接组成的子串的总长度 windowLen。
     *    - 使用哈希表 targetCount 统计每个单词在 words 数组中出现的次数。
     * 
     * 2. 滑动窗口阶段：
     *    - 外层循环：以单个单词的长度 wordLen 为步长进行滑动，共执行 wordLen 次。
     *    - 初始化滑动窗口的左右边界 left 和 right，以及用于记录当前窗口中单词出现次数的哈希表 windowCount，
     *      还有记录当前窗口中有效单词数量的 count。
     *    - 内层循环：使用滑动窗口遍历字符串 s，每次从右边界截取一个单词：
     *        a. 若截取的单词在 targetCount 中存在：
     *           - 将该单词在 windowCount 中的计数加 1，有效单词数量 count 加 1。
     *           - 若该单词在 windowCount 中的数量超过 targetCount 中的数量，移动左边界 left，
     *             减少对应单词的计数和有效单词数量，直到符合条件。
     *           - 若当前窗口中有效单词数量等于 numWords，说明找到一个符合条件的子串，记录左边界。
     *        b. 若截取的单词不在 targetCount 中：
     *           - 重置窗口，清空 windowCount，将 count 置为 0，将左边界移动到右边界的位置。
     * 
     * 3. 返回结果：
     *    - 遍历结束后，返回所有符合条件的子串的起始索引数组。
     * 
     * 时间复杂度：O(L * N / L) = O(N)，其中 L 是单个单词的长度，N 是字符串 s 的长度。
     * 空间复杂度：O(M)，其中 M 是 words 数组中不同单词的数量，主要用于存储 targetCount 和 windowCount。
     */
    // 查找字符串 s 中由 words 数组中所有单词拼接组成的子串的起始索引
    // 时间复杂度：O(L * N / L) = O(N)，其中 L 是单个单词的长度，N 是字符串 s 的长度。
    // 外层循环执行 L 次，内层滑动窗口每次最多遍历 N / L 个单词。
    // 空间复杂度：O(M)，其中 M 是 words 数组中不同单词的数量，主要用于存储 targetCount 和 windowCount。
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // 用于存储符合条件的子串的起始索引
        vector<int> ans;
        // 如果输入字符串 s 为空或者单词数组 words 为空，直接返回空结果
        if (s.empty() || words.empty())
            return ans;

        // 获取单个单词的长度
        int wordLen = words[0].size();
        // 获取单词数组中单词的数量
        int numWords = words.size();
        // 计算由所有单词拼接组成的子串的总长度
        int windowLen = wordLen * numWords;

        // 统计每个单词在 words 数组中出现的次数
        unordered_map<string, int> targetCount;
        for (const string &w : words)
            targetCount[w]++;

        // 外层循环，以单个单词的长度为步长进行滑动
        for (int i = 0; i < wordLen; i++)
        {
            // 初始化滑动窗口的左右边界
            int left = i, right = i;
            // 统计当前窗口中每个单词出现的次数
            unordered_map<string, int> windowCount;
            // 记录当前窗口中有效单词的数量
            int count = 0;

            // 当右边界加上一个单词的长度不超过字符串 s 的长度时，继续滑动窗口
            while (right + wordLen <= s.size())
            {
                // 从右边界开始截取一个单词
                string word = s.substr(right, wordLen);
                // 右边界向右移动一个单词的长度
                right += wordLen;

                // 如果截取的单词在 targetCount 中存在
                if (targetCount.find(word) != targetCount.end())
                {
                    // 当前窗口中该单词的计数加 1
                    windowCount[word]++;
                    // 当前窗口中有效单词的数量加 1
                    count++;

                    // 超过目标数量，左指针收缩
                    while (windowCount[word] > targetCount[word])
                    {
                        // 获取左边界的单词
                        string leftWord = s.substr(left, wordLen);
                        // 当前窗口中左边界单词的计数减 1
                        windowCount[leftWord]--;
                        // 左边界向右移动一个单词的长度
                        left += wordLen;
                        // 当前窗口中有效单词的数量减 1
                        count--;
                    }

                    // 当前窗口匹配，记录左边界
                    if (count == numWords)
                    {
                        // 将当前窗口的左边界添加到结果数组中
                        ans.push_back(left);
                    }
                }
                else
                {
                    // 不在words中，重置窗口
                    // 清空当前窗口的单词计数
                    windowCount.clear();
                    // 重置当前窗口中有效单词的数量为 0
                    count = 0;
                    // 将左边界移动到右边界的位置
                    left = right;
                }
            }
        }

        // 返回符合条件的子串的起始索引数组
        return ans;
    }
};
