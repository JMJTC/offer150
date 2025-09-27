#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution
{
  public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < s.size() && s[i + 1] == 'V')
                {
                    res += 4;
                    i++;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'X')
                {
                    res += 9;
                    i++;
                }
                else
                {
                    res += 1;
                }
            }
            else if (s[i] == 'V')
            {
                res += 5;
            }
            else if (s[i] == 'X')
            {
                if (i + 1 < s.size() && s[i + 1] == 'L')
                {
                    res += 40;
                    i++;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'C')
                {
                    res += 90;
                    i++;
                }
                else
                {
                    res += 10;
                }
            }
            else if (s[i] == 'L')
            {
                res += 50;
            }
            else if (s[i] == 'C')
            {
                if (i + 1 < s.size() && s[i + 1] == 'D')
                {
                    res += 400;
                    i++;
                }
                else if (i + 1 < s.size() && s[i + 1] == 'M')
                {
                    res += 900;
                    i++;
                }
                else
                {
                    res += 100;
                }
            }
            else if (s[i] == 'D')
            {
                res += 500;
            }
            else if (s[i] == 'M')
            {
                res += 1000;
            }
        }
        return res;
    }

    int romanToInt2(string s)
    {
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            char c1 = s[i];
            char c2 = s[i + 1];
            if (map[c1] < map[c2])
            {
                res -= map[c1];
            }
            else
            {
                res += map[c1];
            }
        }
        return res + map[s.back()];
    }
};