#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
    unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};

  public:
    bool isValid(string s)
    {
        if (s.length() % 2)
        { // s 长度必须是偶数
            return false;
        }
        stack<char> st;
        for (char c : s)
        {
            // mp.contains(c) 用来判断 c 是不是 mp 的一个 key
            if (mp.find(c) != mp.end())
            {               // c 是左括号
                st.push(c); // 入栈
            }
            else
            { // c 是右括号
                if (st.empty() || st.top() != mp[c])
                {
                    return false; // 没有左括号，或者左括号类型不对
                }
                st.pop(); // 出栈
            }
        }
        return st.empty(); // 所有左括号必须匹配完毕
    }
};