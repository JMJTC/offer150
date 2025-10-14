#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26]{};
        for (int i : hash)
        {
            cout << i << " ";
        }
        for (char c : magazine)
        {
            hash[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            if (hash[c - 'a'] == 0)
            {
                return false;
            }
            hash[c - 'a']--;
        }
        return true;
    }

    // 使用标准库
    bool canConstruct2(string ransomNote, string magazine)
    {
        unordered_map<char, int> hash;
        for (char c : magazine)
        {
            hash[c]++;
        }
        for (char c : ransomNote)
        {
            if (hash[c] == 0)
            {
                return false;
            }
            hash[c]--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct2("aa", "ab") << endl;
    return 0;
}