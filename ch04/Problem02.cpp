#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     * 螺旋矩阵遍历函数
     * @param matrix 二维矩阵
     * @return 返回螺旋遍历后的结果数组
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 检查矩阵是否为空或第一行为空
        if (matrix.empty() || matrix[0].empty())
            return {};
        // 获取矩阵的行数和列数
        int row = matrix.size(), col = matrix[0].size();
        // 创建结果数组并预留足够空间
        vector<int> ans;
        ans.reserve(row * col);

        // 定义四个方向：右、下、左、上
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // 定义上下左右四个边界
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        // 初始化当前位置和方向
        int x = 0, y = 0, dir = 0;

        // 遍历直到所有元素都被访问
        while (ans.size() < row * col)
        {
            // 将当前元素加入结果数组
            ans.push_back(matrix[x][y]);
            // 计算下一个位置的坐标
            int nx = x + direction[dir][0];
            int ny = y + direction[dir][1];

            // 检查下一个位置是否越界
            if (nx < top || nx > bottom || ny < left || ny > right)
            {
                // 收缩边界
                if (dir == 0) // 向右时，上边界下移
                    top++;
                else if (dir == 1) // 向下时，右边界左移
                    right--;
                else if (dir == 2) // 向左时，下边界上移
                    bottom--;
                else if (dir == 3) // 向上时，左边界右移
                    left++;

                // 改变方向
                dir = (dir + 1) % 4;
                // 重新计算下一个位置的坐标
                nx = x + direction[dir][0];
                ny = y + direction[dir][1];
            }

            // 更新当前位置
            x = nx;
            y = ny;
        }

        // 返回结果数组
        return ans;
    }
};

int main()
{
    Solution sol{}; // construct the object, not declare a function
    vector<vector<int>> matrix{
        {1}, {2}, {3}, {4}};
    vector<int> ans = sol.spiralOrder(matrix);
    for (int i : ans)
    {
        std::cout << i << ' ';
    }
    return 0;
}