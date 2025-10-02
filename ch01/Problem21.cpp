#include <algorithm>
#include <string>
using namespace std;
class Solution
{
  public:
    string reverseWords(string s)
    {
        string res = "";
        int index = s.length() - 1;
        while (index >= 0)
        {
            if (s[index] == ' ')
            {
                index--;
            }
            else
            {
                int start = index;
                while (index >= 0 && s[index] != ' ')
                {
                    index--;
                }
                res += s.substr(index + 1, start - index);
                res += ' ';
            }
        }
        if (res.length() > 0)
        {
            res.pop_back(); // remove the last space
        }
        return res;
    }

    // 原地算法
    string reverseWords2(string s)
    {
        int length = s.length();
        if (length == 0)
        {
            return s;
        }
        // 移除多余空格
        removeExtraSpaces(s);
        // 反转字符串
        reverse(s.begin(), s.end());
        // 反转每个单词
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            while (j < s.length() && s[j] != ' ')
            {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }

    void removeExtraSpaces(string &s)
    {
        int slowIndex = 0, fastIndex = 0;
        // 移除字符串前面的空格
        while (s.length() > 0 && fastIndex < s.length() && s[fastIndex] == ' ')
        {
            fastIndex++;
        }
        // 移除字符串中间的空格
        for (; fastIndex < s.length(); fastIndex++)
        {
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ')
            {
                continue;
            }
            else
            {
                s[slowIndex++] = s[fastIndex]; // 将不是空格的字符赋给slowIndex
            }
        }
        // 移除字符串末尾的空格
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
        {
            s.resize(slowIndex - 1); // 慢指针指向字符串末尾空格，resize去除末尾空格
        }
    }
};

int main()
{
    Solution s;
    string str = "a good   example";
    s.reverseWords2(str);
    return 0;
}