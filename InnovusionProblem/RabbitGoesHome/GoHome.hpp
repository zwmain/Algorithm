#include <utility>
#include <vector>

class Rabbit {
public:
    Rabbit(size_t M, size_t N, const std::vector<std::pair<size_t, size_t>>& snakeSite);
    size_t goHomeA();

private:
    std::vector<std::vector<int>> _cells;
    size_t _pathCnt = 0;
    std::vector<std::pair<size_t, size_t>> _dirs = { { 1, 0 }, { 0, 1 } };

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
    goHomeA(0, 0);
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
