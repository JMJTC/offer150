#include <vector>
using namespace std;
class Solution
{
  public:
    // 空间复杂度：O(m*n) 时间复杂度: O(m * n + count(0) * (m + n))
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> flag(row, vector<bool>(col, false)); // 初始化
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!flag[i][j] && matrix[i][j] == 0)
                {
                    // 置0
                    for (int k = 0; k < row; k++)
                    {
                        if (matrix[k][j] != 0)
                        {
                            flag[k][j] = true;
                        }
                        matrix[k][j] = 0;
                    }
                    for (int k = 0; k < col; k++)
                    {
                        if (matrix[i][k] != 0)
                        {
                            flag[i][k] = true;
                        }
                        matrix[i][k] = 0;
                    }
                }
            }
        }
    }
    // 空间复杂度：O (m + n)
    void setZeroes2(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};