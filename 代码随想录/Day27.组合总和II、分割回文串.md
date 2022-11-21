# Day27.组合总和II、分割回文串

# 0039.组合总和

链接：[0039.组合总和](https://leetcode.cn/problems/combination-sum/)

这题的终止条件是sum值与目标值是否相等。如果sum大于目标，则直接终止递归；如果等于则收集结果，结束递归；如果小于目标则继续递归。

由于元素可以重复，那么下次递归的起始索引就可以从当前所以开始，而不用+1

```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        backtracking(candidates, target, 0, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(const vector<int> candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                _path.push_back(candidates[i]);
                // 这里元素可以重复，所以下一层递归的索引可以和当前一样
                backtracking(candidates, target, sum + candidates[i], i);
                _path.pop_back();
            }
        }
    }
};

```



## 0040.组合总和II

链接：[0040.组合总和II](https://leetcode.cn/problems/combination-sum-ii/)

回溯法会形成一个回溯二叉树，这里引入一个树层和树枝的概念。

树枝就相当于二叉树的深度方向，纵向。

树层就相当于二叉树的广度方向，横向。

对于这道题，我们需要的是树层去重。对于`1,1,1,2,5,6,7,8`来说，为方便去重，已经排序。`1,1,1`可以`1,1,2`也可以，因为虽然1重复，但是只是值重复，它们的下标并没有重复。
所以树枝不需要去重。但是对于第一个1，会产生`1,2,5`，第二个1也会产生`1,2,5`，这就不行，因为两个组合相同，产生了重复，所以我们需要跳过这种情况。

借助`used`数组，如果是在树枝中，深度递归，几个1都可能处在被使用的状态，这是可以的，所以即便当前值和前一个值相同，也不需要跳过。

但是以第一个1的情况都遍历完了，该从第二个1开始遍历，这时，第一个1已经不用了，未被使用，此时第二个1就需要跳过了。

不借助`used`数组，由于在在回溯中，会传入一个索引值，这个索引就是遍历的起始索引，但是索引本身没有变化。那么这个索引某种程度上就可以代表树的层深。
那么只要i值大于层深，就可以保证在树层中去重。（这里我也不是很理解）

```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        // 排序，方便去重
        sort(candidates.begin(), candidates.end());
        _used.resize(candidates.size());
        fill(_used.begin(), _used.end(), false);
        backtracking(candidates, target, 0, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;
    vector<bool> _used;

    void backtracking(const vector<int>& candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                // 去重，当前值和前面值相同
                // 并且，只有才前面值没有使用的状态下才能去重
                // 因为，这里只需要树层去重，而不需要树枝去重
                if (i > 0 && _used[i - 1] == false && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                _path.push_back(candidates[i]);
                _used[i] = true;
                // 这里使用的是i+1
                backtracking(candidates, target, sum + candidates[i], i + 1);
                _used[i] = false;
                _path.pop_back();
            }
        }
    }

    void backtracking2(const vector<int>& candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                // 去重，当前值和前面值相同
                // 并且，去重仅限在树层内，而不是树枝内
                // ind某种意义上代表了回溯二叉树的层数
                if (i > ind && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                _path.push_back(candidates[i]);
                _used[i] = true;
                // 这里使用的是i+1
                backtracking2(candidates, target, sum + candidates[i], i + 1);
                _used[i] = false;
                _path.pop_back();
            }
        }
    }
};

```



## 0131.分割回文串

链接：[0131.分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)

分割子串，其实就是在确定一个`[i,startInd]`区间，一个闭区间就是一个子串

为避免重复确定子串，可以在分割后，立即判断是不是回文，如果不是，就没必要递归分割了。

```c++
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return _res;
    }

private:
    vector<vector<string>> _res;
    vector<string> _path;

    // startInd是子串的开始
    void backtracking(const string& s, int startInd)
    {
        if (startInd >= s.size()) {
            _res.push_back(_path);
            return;
        }

        for (int i = startInd; i < s.size(); ++i) {
            // 判断[startInd,i]区间的子串是否是回文串
            if (!isPalindrome(s, startInd, i)) {
                continue;
            }
            _path.push_back(s.substr(startInd, i - startInd + 1));
            backtracking(s, i + 1);
            _path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int i, int j)
    {
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                break;
            }
        }
        return i == j || i == j + 1;
    }
};

```

