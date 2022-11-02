#include "Utils.hpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int i = 0;
        for (; i < s.size(); i += 2 * k) {
            // 先计算剩余字符串长度
            // 然后根据剩余字符串长度决定反转多少字符
            int num = s.size() - i;
            if (num < k) {
                reverse(s, i, s.size() - 1);
            } else {
                reverse(s, i, i + k - 1);
            }
        }
        return s;
    }
    // 为了让代码逻辑更清晰，将纯反转字符串独立出来
    // 接收左闭右闭区间
    void reverse(string& s, int left, int right)
    {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};
