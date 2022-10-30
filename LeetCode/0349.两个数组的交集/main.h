#include "Utils.hpp"
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> repeat;
        for (int i : nums1) {
            repeat.insert(i);
        }
        vector<int> res;
        for (int i : nums2) {
            auto it = repeat.find(i);
            if (it != repeat.end()) {
                res.push_back(i);
                repeat.erase(it);
            }
        }
        return res;
    }
};
