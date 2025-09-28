#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        if (strs.empty())
        {
            return ans;
        }
        int length = strs.size();
        for (int i = 0; i < strs[0].length(); i++)
        {
            for (int j = 1; j < length; j++)
            {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};