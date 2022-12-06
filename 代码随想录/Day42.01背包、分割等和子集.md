# Day42.01背包、分割等和子集

## 背包问题概述

01背包：n种物品，每种物品只有1个

完全背包：n种物品，每种物品无限个

多重背包：n种物品，每种物品个数各不相同

## 01背包

1. `dp[i][j]`含义：i为`[0,i]`区间内的物品，任取，放到容量为j的背包里，最大价值
2. 递推公式：对于当前`dp[i][j]`，如果不放当前第i个物品，那么`dp[i][j]`就等于`dp[i-1][j]`，和前面物品一样；如果放入当前物品，那么为了放入当前物品，背包预留空间至少要为`j-weight[i]`，同时为了让背包内尽可能的多放物品，不留余地，空出来的位置，刚好够当前物品重量就够了，所以`dp[i][j]`等于`dp[i-1][j-weight[i]]+value[i]`。放不放入，取最大值，`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])`
3. dp数组初始化：i总是依赖`i-1`，j同样依赖于前面的值。因此`i=0`和`j=0`时，都需要初始化。i为0，说明只有物品0，不论重量j取多少，只要大于等于当前重量，那么价值就是物品0的价值。如果j为0，说明背包容量为0，任何物品都放不下，价值总是为0
4. 遍历顺序：外层物体遍历，内层背包容量遍历，从小到大；当然也可以调整循环顺序，只要两层都是从小到大就可以了。

```c++
void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}

```



## 01背包-状态压缩

观察dp递推公式，只看i，i只依赖于`i-1`，也就是只依赖于前一行，那就可以将二维降为一维。

1. `dp[j]`的含义，容量为j的背包，所背的最大价值为`dp[j]`
2. 递推公式：不放物品i，`dp[j]=dp[j]`，就是第`i-1`号物品的最大价值；放物品i，`dp[j]=dp[j-weight[i]]+value[i]`。同样，要取最大值
3. 初始化：目前dp数组只保留了容量这一维。`dp[0]=0`，对于非0下标，因为`dp[j]`的值要和其本身比大小，所以取非负的最小值就可以了，即全部初始化为0
4. 遍历顺序：外层为物品遍历，从小到大；内层为容量遍历，**从大到小**，当前dp需要参考前面的值，但是因为少了一维当前层还是依赖于当前层，存在覆盖，如果从小到大遍历，前面的已经算过了，会重复计算。从大到小，一样依赖于前面的，但是先计算的是后面的值，前面的值不会覆盖。二维dp不会重复的原因是，当前值，依赖的是左上方的值，不在一个维度，所以不会覆盖。一维dp数组是重复利用的，新值与旧值要分开。因为压缩了i那一维，所以必须先遍历物品。

```c++
void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

```

