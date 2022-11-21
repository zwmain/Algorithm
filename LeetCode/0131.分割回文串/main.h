#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
