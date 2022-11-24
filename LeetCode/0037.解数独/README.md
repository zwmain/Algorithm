# 0037.解数独

链接：[0037.解数独](https://leetcode.cn/problems/sudoku-solver/)

参考[代码随想录](https://programmercarl.com/0037.解数独.html)

这道题不太理解，写出来的答案总是超时

```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        backtracking(board);
    }

private:
    bool backtracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; ++k) {
                    if (!isValid(i, j, k, board)) {
                        continue;
                    }
                    board[i][j] = k;
                    bool isOk = backtracking(board);
                    if (isOk) {
                        // 如果已经找到了，就不找了
                        return isOk;
                    }
                    board[i][j] = '.';
                }
                // 这里已经尝试9个数了，这种方法无解
                return false;
            }
        }
        // 当遍历完了，填入的数说明都符合条件
        return true;
    }

    bool isValid(int row, int col, char k, vector<vector<char>>& board)
    {
        for (int r = 0; r < board.size(); ++r) {
            if (board[r][col] == k) {
                return false;
            }
        }
        for (int c = 0; c < board[0].size(); ++c) {
            if (board[row][c] == k) {
                return false;
            }
        }
        int startRow = row / 3;
        startRow *= 3;
        int startCol = col / 3;
        startCol *= 3;
        int heigh = startRow + 3;
        int width = startCol + 3;
        for (int r = startRow; r < heigh; ++startRow) {
            for (int c = startCol; c < width; ++startCol) {
                if (board[r][c] == k) {
                    return false;
                }
            }
        }
        return true;
    }
};

```


