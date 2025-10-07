#include <algorithm>
#include <string>

using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int length = s.length();
        string str = "";
        for (int i = 0; i < length; i++)
        {
            if (isCharterOrDigiter(s[i]))
            {
                str += s[i];
            }
        }
        length = str.length();
        for (int i = 0; i < length / 2; i++)
        {
            if (str[i] != str[length - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    bool isCharterOrDigiter(char &ch)
    {
        if ('0' <= ch && '9' >= ch)
        {
            return true;
        }
        if ('a' <= ch && 'z' >= ch)
        {
            return true;
        }
        if ('A' <= ch && 'Z' >= ch)
        {
            ch = 'a' + ch - 'A';
            return true;
        }
        return false;
    }
};