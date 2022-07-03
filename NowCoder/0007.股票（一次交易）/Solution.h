#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心
        int profit = 0;//利润
        int buy = prices[0];//买入时价格
        for (int i = 1; i < prices.size(); i++) {
            //如果此时利润最大，则更新利润
            if (prices[i] - buy > profit)
                profit = prices[i] - buy;
            //如果此时价格低于买入价格，将买入调至此价格
            if (prices[i] < buy)
                buy = prices[i];
        }
        return profit;
    }
};