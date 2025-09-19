#include <algorithm>
#include <vector>
using namespace std;

class Problem11
{
  public:
    int hIndex(vector<int> &citations)
    {
        int length = citations.size();
        vector<int> data(length + 1);
        for (int i : citations)
        {
            data[min(length, i)]++;
        }
        int s = 0;
        for (int i = length; i >= 0; i--)
        {
            s += data[i];
            if (s >= i)
            {
                return i;
            }
        }
        return -1;
    }
};