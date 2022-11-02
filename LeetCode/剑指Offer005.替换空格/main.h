#include "Utils.hpp"

using namespace std;

class Solution {
public:
    string replaceSpace(string s)
    {
        if (s.empty()) {
            return s;
        }
        int cnt = 0;
        for (char c : s) {
            if (c == ' ') {
                ++cnt;
            }
        }
        int left = s.size() - 1;
        if (cnt > 0) {
            s.append(2 * cnt, 'a');
        }
        int right = s.size() - 1;
        while (left >= 0 && right > left) {
            if (s[left] != ' ') {
                s[right] = s[left];
                --left;
                --right;
            } else {
                s[right] = '0';
                --right;
                s[right] = '2';
                --right;
                s[right] = '%';
                --right;
                --left;
            }
        }
        return s;
    }
};
