#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int length = numbers.size();
        int index1 = 0;
        int index2 = length - 1;
        while (numbers[index1] + numbers[index2] != target && index1 < index2)
        {
            if (numbers[index1] + numbers[index2] > target)
            {
                index2--;
            }
            else
            {
                index1++;
            }
        }
        return {index1 + 1, index2 + 1};
    }
};