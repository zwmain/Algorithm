#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
