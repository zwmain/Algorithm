#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] > b[0]) {
            return true;
        } else if (a[0] < b[0]) {
            return false;
        } else {
            return a[1] < b[1];
        }
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i) {
            if (people[i][1] == i) {
                continue;
            }
            vector<int> cur = people[i];
            for (int j = i; j > cur[1]; --j) {
                people[j] = people[j - 1];
            }
            people[cur[1]] = cur;
        }
        return people;
    }
};
