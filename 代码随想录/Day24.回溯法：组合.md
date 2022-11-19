# Day24.回溯法：组合

回溯法模板：

```c++
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

```


链接：[0077.组合](https://leetcode.cn/problems/combinations/)

准备一个结果数组，还有一个路径数组，记录每次搜索的路径，当路径长度等于k的时候，一次搜索结束。

还要记录每层开始搜索的索引，防止值重复。

剪枝：以4，4为例，那么结果只有一种，第一层从1开始，2、3、4都是没意义的，也就是说第一层的范围就只有一个数，深层也会受限。

如果for循环选择的起始位置之后的元素个数 已经不足 我们需要的元素个数了，那么就没有必要搜索了。


```c++
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(int n, int k, int ind)
    {
        if (_path.size() == k) {
            _res.push_back(_path);
            return;
        }
        // 已经选择的元素个数：path.size();
        // 还需要的元素个数为: k - path.size();
        // 在集合n中，这一层范围最大可以取到: n - (k - path.size()) + 1
        for (int i = ind; i <= n - (k - _path.size()) + 1; ++i) {
            _path.push_back(i);
            backtracking(n, k, i + 1);
            _path.pop_back();
        }
    }
};

```

