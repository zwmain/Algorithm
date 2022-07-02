# 0304.二维区域和检索-矩阵不可变

链接：[0304.二维区域和检索-矩阵不可变](https://leetcode.cn/problems/range-sum-query-2d-immutable/)

## 我的解法

在做这道题时，我已经做了一维数组区域和那道题，题号是0303

同样采用前缀和思路，只是这次是前缀矩阵

矩阵中`pre[i][j]`代表`matrix[i-1][j-1]`子矩阵内所有原素的和

```c++
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

```

但是上述代码并不能得到正确答案
