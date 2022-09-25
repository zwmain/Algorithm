#include <utility>
#include <vector>
#include <iostream>

/**
 * @brief 兔子回家
 * 矩阵中0-未访问；1-有蛇；2-已访问
 */
class Rabbit {
public:
    /**
     * @brief 构造函数，一个MxN矩阵，和蛇的位置
     *
     * @param M 列数
     * @param N 行数
     * @param snakeSite 蛇的位置（行，列）
     */
    Rabbit(size_t M, size_t N, const std::vector<std::pair<size_t, size_t>>& snakeSite);

    /**
     * @brief 路径数量
     *
     * @return 路径数量
     */
    size_t goHomeA();

private:
    std::vector<std::vector<int>> _cells;
    size_t _pathCnt = 0;
    std::vector<std::pair<size_t, size_t>> _dirs = { { 1, 0 }, { 0, 1 } };

    /**
     * @brief 路径数量回溯法实现
     *
     * @param row 当前位置行
     * @param col 当前位置列
     */
    void goHomeA(size_t row, size_t col);
};

Rabbit::Rabbit(size_t M, size_t N, const std::vector<std::pair<size_t, size_t>>& snakeSite)
{
    _cells.resize(N);
    for (auto& arr : _cells) {
        arr.resize(M);
        std::fill(arr.begin(), arr.end(), 0);
    }
    for (auto& p : snakeSite) {
        if (!(p.first < _cells.size() && p.second < _cells[0].size())) {
            continue;
        }
        _cells[p.first][p.second] = 1;
    }
}

size_t Rabbit::goHomeA()
{
    _cells[0][0] = 2;
    _pathCnt=0;
    goHomeA(0, 0);
    _cells[0][0] = 0;
    return _pathCnt;
}

void Rabbit::goHomeA(size_t row, size_t col)
{
    if (row == _cells.size() - 1 && col == _cells[0].size() - 1) {
        ++_pathCnt;
        return;
    }
    for (auto& dir : _dirs) {
        size_t r = row + dir.first;
        size_t c = col + dir.second;
        if (!(r < _cells.size() && c < _cells[0].size()) || _cells[r][c] != 0) {
            continue;
        }
        _cells[r][c] = 2;
        goHomeA(r, c);
        _cells[r][c] = 0;
    }
}
