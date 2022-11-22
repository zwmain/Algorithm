#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0);
        return _res;
    }

private:
    vector<string> _res;
    vector<string> _path;

    void backtracking(const string& s, int startInd)
    {
        // 当path里有3组时，就可以判断了
        // 因为剩下的所有字符串为最后一组
        if (_path.size() == 3) {
            if (startInd >= s.size()) {
                return;
            }
            // 截取最后所有字符串
            string t = s.substr(startInd, s.size() - startInd);
            // 如果最后一段不是IP，那么直接返回
            if (!isIpNum(t)) {
                return;
            }
            string ip;
            for (auto& i : _path) {
                ip += i;
                ip.push_back('.');
            }
            ip += t;
            _res.push_back(ip);
            return;
        }
        for (int i = startInd; i < s.size() && i - startInd < 3; ++i) {
            string t = s.substr(startInd, i - startInd + 1);
            if (!isIpNum(t)) {
                continue;
            }
            _path.push_back(t);
            backtracking(s, i + 1);
            _path.pop_back();
        }
    }

    bool isIpNum(const string& s)
    {
        if (s.size() > 3) {
            return false;
        }
        if (s[0] == '0' && s.size() != 1) {
            return false;
        }
        int val = stoi(s);
        if (val < 0 || val > 255) {
            return false;
        }
        return true;
    }
};
