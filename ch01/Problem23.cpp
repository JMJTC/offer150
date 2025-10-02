#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int ans = -1;
        if (needle.size() == 0)
            return 0;
        int length1 = haystack.size();
        int length2 = needle.size();
        if (length1 < length2)
        {
            return ans;
        }
        for (int i = 0; i < length1 - length2 + 1; i++)
        {
            if (haystack.substr(i, length2) == needle)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }

    // KMP算法
    // 使用KMP算法实现字符串匹配
    int strStr2(string haystack, string needle)
    {
        // 初始化结果为-1，表示未找到匹配
        int ans = -1;
        // 如果模式串为空，直接返回0
        if (needle.size() == 0)
        {
            return 0;
        }
        // 获取主串和模式串的长度
        int length1 = haystack.size();
        int length2 = needle.size();
        // 如果主串长度小于模式串长度，直接返回-1
        if (length1 < length2)
        {
            return ans;
        }
        // 在主串和模式串的开头插入空格，使下标从1开始
        haystack.insert(0, " ");
        needle.insert(0, " ");
        // 获取模式串的next数组
        vector<int> next = getNext(needle);
        // i 为主串的指针，j 为模式串的指针
        for (int i = 1, j = 0; i <= haystack.size(); i++)
        {
            // 当不匹配且j > 0时，根据next数组回退j
            while (j > 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }
            // 如果当前字符匹配，模式串指针j后移
            if (haystack[i] == needle[j + 1])
            {
                j++;
            }
            // 如果模式串指针j等于模式串长度，说明找到匹配
            if (j == length2)
            {
                // 返回匹配的起始位置（由于前面插入了空格，需要减去模式串长度）
                return i - length2;
            }
        }
        // 未找到匹配，返回-1
        return ans;
    }

    // 获取模式串的next数组
    vector<int> getNext(string s)
    {
        // 初始化next数组，大小与模式串相同
        vector<int> next(s.size());
        // i 为当前遍历的位置，j 为最长公共前后缀的长度
        for (int i = 2, j = 0; i < s.size(); i++)
        {
            // 当不匹配且j > 0时，根据next数组回退j
            // 注意：这里应该回退到j的前一个状态，即next[j]，而不是next[i]
            while (j > 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            // 如果当前字符匹配，最长公共前后缀长度加1
            if (s[i] == s[j + 1])
            {
                j++;
            }
            // 记录当前位置的最长公共前后缀长度
            next[i] = j;
        }

        return next;
    }
};