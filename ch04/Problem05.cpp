#include <math.h>
#include <vector>
using namespace std;

class Solution
{
  public:
    // 0 -> 1 : 2
    // 1 -> 1 : 1
    // 0 -> 0 : 0
    // 1 -> 0 : -1
    void gameOfLife(vector<vector<int>> &board)
    {
        int neighbors[3]{0, -1, 1};
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int liveCount = 0;
                for (int n = 0; n < 3; n++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        if (n != 0 || m != 0)
                        {
                            int r = i + neighbors[n];
                            int c = j + neighbors[m];
                            if (r >= 0 && r < row && c >= 0 && c < col)
                            {
                                if (abs(board[r][c]) == 1)
                                {
                                    liveCount++;
                                }
                            }
                        }
                    }
                }
                // 处理对应的情况
                // 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
                if (board[i][j] == 1 && liveCount < 2)
                {
                    board[i][j] = -1;
                }
                // 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
                if (board[i][j] == 1 && liveCount >= 2 && liveCount <= 3)
                {
                    board[i][j] = 1;
                }
                // 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
                if (board[i][j] == 1 && liveCount > 3)
                {
                    board[i][j] = -1;
                }
                // 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
                if (board[i][j] == 0 && liveCount == 3)
                {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] > 0)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};