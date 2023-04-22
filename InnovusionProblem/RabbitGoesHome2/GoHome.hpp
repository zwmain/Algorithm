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

    size_t goHome1Dp();

    size_t goHome2Dp();

    /**
     * @brief 路径数量，回溯算法
     *
     * @return 路径数量
     */
    size_t goHome1Backtrack();

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

inline size_t Rabbit::goHome1Dp()
{
    // 使用动态规划算法
    // dp[i][j]含义：走到i,j位置有多少种走法
    // 递推公式：只能向下或者向右，所以当前状态只能由上面和左边推到出来，dp[i][j]=dp[i-1][j]+dp[i][j-1]
    // 初始化：最上面和最左面必须初始化，dp[0][j]=1,dp[i][0]=1，如果中间某一个有障碍，那么后面所有都为0
    // 遍历顺序：从上到下，从左到右
    std::vector<std::vector<int>> dp(_cells.size(), std::vector<int>(_cells[0].size()));
    int val = 1;
    for (int i = 0; i < _cells.size(); ++i) {
        if (_cells[i][0] == 1) {
            val = 0;
        }
        dp[i][0] = val;
    }
    val = 1;
    for (int j = 0; j < _cells[0].size(); ++j) {
        if (_cells[0][j] == 1) {
            val = 0;
        }
        dp[0][j] = val;
    }
    for (int i = 1; i < _cells.size(); ++i) {
        for (int j = 1; j < _cells[0].size(); ++j) {
            if (_cells[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp.back().back();
}

inline size_t Rabbit::goHome2Dp()
{
    const size_t M = _cells.size();
    const size_t N = _cells[0].size();
    std::vector<int> dp(N, 0);
    for (int j = 0; j < N && _cells[0][j] == 0; ++j) {
        dp[j] = 1;
    }
    for (int i = 1; i < M; ++i) {
        _cells[i][0] == 1 ? dp[0] = 0 : dp[0] = 1;
        for (int j = 1; j < N; ++j) {
            if (_cells[i][j] == 1) {
                dp[j] = 0;
            } else {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp.back();
}

size_t Rabbit::goHome1Backtrack()
{
    _cells[0][0] = 2;
    _pathCnt = 0;
    goHomeA(0, 0);
    _cells[0][0] = 0;
    return _pathCnt;
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
