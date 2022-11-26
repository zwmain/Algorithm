#include "Utils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (g.empty() || s.empty()) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childInd = 0;
        for (int i = g.size() - 1; i >= 0; --i) {
            int maxVal = s.back();
            if (maxVal >= g[i]) {
                childInd = i;
                break;
            }
        }

        int i = childInd;
        int j = s.size() - 1;
        int cnt = 0;
        while (i >= 0 && j >= 0) {
            if (s[j] >= g[i]) {
                ++cnt;
                --i;
                --j;
            } else {
                --i;
            }
        }
        return cnt;
    }
};

