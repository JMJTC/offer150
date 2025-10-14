#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> set{};
        // row
        for (int i = 0; i < 9; i++)
        {
            set.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (set.find(board[i][j]) != set.end()) // or set.count(board[i][j]) > 0
                    {
                        return false;
                    }
                    set.insert(board[i][j]); // or set.emplace(board[i][j])
                }
            }
        }
        // col
        for (int i = 0; i < 9; i++)
        {
            set.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (set.find(board[j][i]) != set.end())
                    {
                        return false;
                    }
                    set.insert(board[j][i]);
                }
            }
        }
        // 3*3
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                set.clear();
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        if (board[k][l] != '.')
                        {
                            if (set.find(board[k][l]) != set.end())
                            {
                                return false;
                            }
                            set.insert(board[k][l]);
                        }
                    }
                }
            }
        }
        return true;
    }

    // 优化
    bool isValidSudoku2(vector<vector<char>> &board)
    {
        bool row_has[9][9]{};        // row_has[i][x] 表示 i 行是否有数字 x
        bool col_has[9][9]{};        // col_has[j][x] 表示 j 列是否有数字 x
        bool sub_box_has[3][3][9]{}; // sub_box_has[i'][j'][x] 表示 (i',j') 宫是否有数字 x

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char b = board[i][j];
                if (b == '.')
                {
                    continue;
                }
                int x = b - '1'; // 字符 '1'~'9' 转成数字 0~8
                if (row_has[i][x] || col_has[j][x] || sub_box_has[i / 3][j / 3][x])
                { // 重复遇到数字 x
                    return false;
                }
                // 标记行、列、宫包含数字 x
                row_has[i][x] = col_has[j][x] = sub_box_has[i / 3][j / 3][x] = true;
            }
        }

        return true;
    }
};