#include <string>
using namespace std;
class Solution
{
    bool is_covered(int cnt_s[], int cnt_t[])
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        return true;
    }

  public:
    string minWindow(string s, string t)
    {
        int cnt_s[128]{};
        int cnt_t[128]{};
        for (char c : t)
        {
            cnt_t[c]++;
        }
        int m = s.size();
        int ans_left = -1, ans_right = m;
        int left = 0;
        for (int right = 0; right < m; right++)
        {
            cnt_s[s[right]]++; // 右端点字母移入子串
            while (is_covered(cnt_s, cnt_t))
            {
                if (right - left < ans_right - ans_left)
                {
                    ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};