#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int n = words.size();
        vector<string> list;
        for (int i = 0; i < n;)
        {
            list.clear();
            list.push_back(words[i]);
            int cur = words[i++].length();
            while (i < n && cur + 1 + words[i].length() <= maxWidth)
            {
                cur += 1 + words[i].length();
                list.push_back(words[i++]);
            }

            // 最后一行 左对齐
            if (i == n)
            {
                string str = list[0];
                for (int k = 1; k < list.size(); k++)
                {
                    str += " ";
                    str += list[k];
                }
                while (str.length() < maxWidth)
                {
                    str += " ";
                }
                ans.push_back(str);
                break;
            }

            // 一个单词
            int count = list.size();
            if (count == 1)
            {
                string str = list[0];
                while (str.length() < maxWidth)
                {
                    str += " ";
                }
                ans.push_back(str);
                continue;
            }

            // 一般情况
            int wordWidth = cur - (count - 1);
            int spaceWidth = maxWidth - wordWidth;
            int spaceItemWidth = spaceWidth / (count - 1);
            string spaceItem = "";
            for (int k = 0; k < spaceItemWidth; k++)
            {
                spaceItem += " ";
            }
            string str = "";
            for (int k = 0, sum = 0; k < count; k++)
            {
                string item = list[k];
                str += item;
                if (k == count - 1)
                {
                    break;
                }
                str += spaceItem;
                sum += spaceItemWidth;
                int remain = count - k - 1 - 1;
                // 剩余间隙数量 * 最小单位空格长度 + 当前空格长度 < 当前行空格总长度，则在当前间隙多补充一个空格
                if (remain * spaceItemWidth + sum < spaceWidth)
                {
                    str += " ";
                    sum++;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};