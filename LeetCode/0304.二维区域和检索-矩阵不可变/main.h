#include "Utils.hpp"

using namespace std;

#define INPUT_FILE "../input.txt"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        _pre_mat.resize(matrix.size() + 1);
        for (auto& arr : _pre_mat) {
            arr.resize(matrix[0].size() + 1);
        }
        for (size_t i = 0; i < _pre_mat[0].size(); ++i) {
            _pre_mat[0][i] = 0;
        }
        for (size_t i = 0; i < _pre_mat.size(); ++i) {
            _pre_mat[i][0] = 0;
        }
        for (size_t i = 1; i < _pre_mat.size(); ++i) {
            for (size_t j = 1; j < _pre_mat[i].size(); ++j) {
                _pre_mat[i][j]
                    = matrix[i - 1][j - 1]
                    + _pre_mat[i - 1][j]
                    + _pre_mat[j][j - 1]
                    - _pre_mat[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return _pre_mat[row2 + 1][col2 + 1] - _pre_mat[row1][col2 + 1] - _pre_mat[row2 + 1][col1] + _pre_mat[row1][col1];
    }

private:
    vector<vector<int>> _pre_mat;
};
