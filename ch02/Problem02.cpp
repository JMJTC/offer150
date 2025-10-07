#include <string>
using namespace std;

class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        int index = 0;
        int length = t.size();
        for (int i = 0; i < length && index < s.size(); i++)
        {
            if (s[index] == t[i])
            {
                index++;
            }
        }
        return index == s.size();
    }
};