#include <iostream>
#include <utility>
#include <vector>

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

    /**
     * @brief 路径数量，优化
     *
     * @return 路径数量
     */
    size_t goHomeB();

    /**
     * @brief 路径数量，返回所有路径
     *
     * @return 所有路径
     */
    std::vector<std::vector<std::pair<size_t, size_t>>> goHomeD();

    /**
     * @brief 路径数量，返回所有路径
     *
     * @return 所有路径
     */
    std::vector<std::vector<std::pair<size_t, size_t>>> goHomeE();

private:
    std::vector<std::vector<int>> _cells;
    size_t _pathCnt = 0;
    std::vector<std::pair<size_t, size_t>> _dirs = { { 1, 0 }, { 0, 1 } };
    std::vector<std::pair<int, int>> _eDirs = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    /**
     * @brief 路径数量回溯法实现
     *
     * @param row 当前位置行
     * @param col 当前位置列
     */
    void goHomeA(size_t row, size_t col);

    /**
     * @brief 所有路径，回溯法实现
     *
     * @param row 当前位置行
     * @param col 当前位置列
     * @param onePath 一条路径
     * @param allPath 所有路径
     */
    void goHomeD(
        size_t row,
        size_t col,
        std::vector<std::pair<size_t, size_t>>& onePath,
        std::vector<std::vector<std::pair<size_t, size_t>>>& allPath);

    /**
     * @brief 所有路径，回溯法实现
     *
     * @param row 当前位置行
     * @param col 当前位置列
     * @param onePath 一条路径
     * @param allPath 所有路径
     */
    void goHomeE(
        size_t row,
        size_t col,
        std::vector<std::pair<size_t, size_t>>& onePath,
        std::vector<std::vector<std::pair<size_t, size_t>>>& allPath);
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
    _pathCnt = 0;
    goHomeA(0, 0);
    _cells[0][0] = 0;
    return _pathCnt;
}

size_t Rabbit::goHomeB()
{
    // todo 优化实现
    return 0;
}

std::vector<std::vector<std::pair<size_t, size_t>>> Rabbit::goHomeD()
{
    std::vector<std::vector<std::pair<size_t, size_t>>> allPath;
    std::vector<std::pair<size_t, size_t>> onePath;
    _cells[0][0] = 2;
    onePath.push_back({ 0, 0 });
    goHomeD(0, 0, onePath, allPath);
    _cells[0][0] = 0;
    return allPath;
}
std::vector<std::vector<std::pair<size_t, size_t>>> Rabbit::goHomeE()
{
    std::vector<std::vector<std::pair<size_t, size_t>>> allPath;
    std::vector<std::pair<size_t, size_t>> onePath;
    _cells[0][0] = 2;
    onePath.push_back({ 0, 0 });
    goHomeE(0, 0, onePath, allPath);
    _cells[0][0] = 0;
    return allPath;
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

void Rabbit::goHomeD(
    size_t row,
    size_t col,
    std::vector<std::pair<size_t, size_t>>& onePath,
    std::vector<std::vector<std::pair<size_t, size_t>>>& allPath)
{
    if (row == _cells.size() - 1 && col == _cells[0].size() - 1) {
        allPath.push_back(onePath);
        return;
    }
    for (auto& dir : _dirs) {
        size_t r = row + dir.first;
        size_t c = col + dir.second;
        if (!(r < _cells.size() && c < _cells[0].size()) || _cells[r][c] != 0) {
            continue;
        }
        _cells[r][c] = 2;
        onePath.push_back({ r, c });
        goHomeD(r, c, onePath, allPath);
        _cells[r][c] = 0;
        onePath.pop_back();
    }
}

void Rabbit::goHomeE(
    size_t row,
    size_t col,
    std::vector<std::pair<size_t, size_t>>& onePath,
    std::vector<std::vector<std::pair<size_t, size_t>>>& allPath)
{
    if (row == _cells.size() - 1 && col == _cells[0].size() - 1) {
        allPath.push_back(onePath);
        return;
    }
    for (auto& dir : _eDirs) {
        int r = row + dir.first;
        int c = col + dir.second;
        if (!(r < _cells.size() && c < _cells[0].size()) || _cells[r][c] != 0) {
            continue;
        }
        _cells[r][c] = 2;
        onePath.push_back({ r, c });
        goHomeE(r, c, onePath, allPath);
        _cells[r][c] = 0;
        onePath.pop_back();
    }
}
