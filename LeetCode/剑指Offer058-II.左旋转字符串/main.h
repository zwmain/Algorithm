#include "Utils.hpp"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        // 逆序前半部分
        reverse(s, 0, n - 1);
        // 逆序后半部分
        reverse(s, n, s.size() - 1);
        // 整个逆序
        reverse(s, 0, s.size() - 1);
        return s;
    }
    void reverse(string& s, int left, int right)
    {
        if (right >= s.size()) {
            return;
        }
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};
