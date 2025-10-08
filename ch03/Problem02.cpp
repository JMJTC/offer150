#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 1;
        int length = s.size();
        if (length == 0)
        {
            return 0;
        }
        unordered_set<char> set;
        int l = 0, r = 1;
        set.insert(s[l]);
        while (r < length)
        {
            if (set.count(s[r]) > 0)
            {
                // 存在 ,移动左指针
                while (set.count(s[r]) > 0)
                {
                    set.erase(s[l++]);
                }
            }
            set.insert(s[r++]);
            ans = max(ans, r - l);
        }
        return ans;
    }
};

int main()
{
    Solution test;
    test.lengthOfLongestSubstring("abcabcbb");
    return 0;
}