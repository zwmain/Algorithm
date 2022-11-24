# Day30.N皇后、解数独、重新安排行程

## 0051.N皇后

链接：[0051.N皇后](https://leetcode.cn/problems/n-queens/)

参考[代码随想录](https://programmercarl.com/0051.N%E7%9A%87%E5%90%8E.html)

棋盘是二维的，在递归函数中传入`row`表示其中1维，在函数循环中表示另一维

```c++
class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessBoard;
        for (int i = 0; i < n; ++i) {
            string line;
            line.append(n, '.');
            chessBoard.push_back(line);
        }
        backtracking(chessBoard, n, 0);
        return _res;
    }

private:
    vector<vector<string>> _res;
    void backtracking(vector<string>& chessBoard, int n, int row)
    {
        if (row == n) {
            _res.push_back(chessBoard);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!isValid(chessBoard, n, row, i)) {
                continue;
            }
            chessBoard[row][i] = 'Q';
            backtracking(chessBoard, n, row + 1);
            chessBoard[row][i] = '.';
        }
    }

    bool isValid(vector<string>& chessBoard, int n, int row, int col)
    {
        // 检查行
        for (int i = 0; i < n; ++i) {
            if (i == col) {
                continue;
            }
            if (chessBoard[row][i] == 'Q') {
                return false;
            }
        }
        // 检查列
        for (int i = 0; i < n; ++i) {
            if (i == row) {
                continue;
            }
            if (chessBoard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查左上角
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查右下角
        for (int i = row + 1, j = col + 1; i < n && j < n; ++i, ++j) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查左下角
        for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查右上角
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

```


## 0037.解数独

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



