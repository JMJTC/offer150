#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> res(numRows);
        int index = 0;
        bool flag = true;
        for (char c : s)
        {
            res[index] += c;
            if (index == 0)
            {
                flag = true;
            }
            if (index == numRows - 1)
            {
                flag = false;
            }
            index += flag ? 1 : -1;
        }
        for (int i = 1; i < numRows; i++)
        {
            res[0] += res[i];
        }
        return res[0];
    }
};