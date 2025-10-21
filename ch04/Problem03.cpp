#include <vector>
using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto matrixNew = matrix;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrixNew[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = matrixNew;
    }
};