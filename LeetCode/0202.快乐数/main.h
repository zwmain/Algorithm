#include "Utils.hpp"
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> numSet;
        int sum = 0;
        while (true) {
            sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            auto it = numSet.find(sum);
            if (it == numSet.end()) {
                numSet.insert(sum);
                n = sum;
            } else {
                return false;
            }
        }
    }

    int getSum(int n)
    {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
