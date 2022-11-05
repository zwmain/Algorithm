#include "Utils.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push(c);
            } else {
                char e = 0;
                if (c == ')') {
                    e = '(';
                } else if (c == ']') {
                    e = '[';
                } else if (c == '}') {
                    e = '{';
                } else {
                    stk.push(c);
                    continue;
                }
                char t = stk.top();
                if (e == t) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
