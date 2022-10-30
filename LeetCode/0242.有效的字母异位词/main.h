#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> cntArr(26);
        for (size_t i = 0; i < cntArr.size(); ++i) {
            cntArr[i] = 0;
        }
        for (char c : s) {
            cntArr[c - 'a'] += 1;
        }
        for (char c : t) {
            cntArr[c - 'a'] -= 1;
        }
        for (size_t i = 0; i < 26; ++i) {
            if (cntArr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
