#include "Utils.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push_back(c);
            } else {
                char t = stk.back();
                if (t == c) {
                    stk.pop_back();
                } else {
                    stk.push_back(c);
                }
            }
        }
        return stk;
    }
};
