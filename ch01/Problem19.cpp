#include <string>
using namespace std;
class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        int length = s.length();
        int ans = 0;
        int index = length - 1;
        while (index >= 0 && s[index] == ' ')
        {
            index--;
        }
        for (; index >= 0; index--)
        {
            if (s[index] != ' ')
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};