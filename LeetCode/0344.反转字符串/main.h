#include "Utils.hpp"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        if (s.empty()) {
            return;
        }
        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};
