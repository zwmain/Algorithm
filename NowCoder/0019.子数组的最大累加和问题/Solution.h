#pragma once
#include<vector>
using namespace std;
class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        int max_sum = arr[0];
        int sum = max_sum;
        for (int cur = 1; cur < arr.size(); cur++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += arr[cur];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};