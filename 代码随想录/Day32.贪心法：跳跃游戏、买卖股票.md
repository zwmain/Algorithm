# Day32.贪心法：跳跃游戏、买卖股票的最佳时机II

## 0122.买卖股票的最佳时机II

链接：[0122.买卖股票的最佳时机II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

由于不能同时持有多只股票，那么买卖动作可以拆分为每一天。

比如第一天买进，第三天卖出，可以拆分为第一天买进，第二天卖出；第二天买进，第三天卖出。

那么为了保证最终结果最大，只要买间隔为正的股票就可以了。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};

```


## 0055.跳跃游戏

链接：[0055.跳跃游戏](https://leetcode.cn/problems/jump-game/)

不用想太多，每次走最大的就可以了

```c++
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.empty() || nums.size() == 1) {
            return true;
        }
        int cover = 0;
        for (int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

```



## 0045.跳跃游戏II

链接：[0045.跳跃游戏II](https://leetcode.cn/problems/jump-game-ii/)

没理解

```c++
class Solution {
public:
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return 0;
        }
        int curDistance = 0; // 当前覆盖最远距离下标
        int ans = 0; // 记录走的最大步数
        int nextDistance = 0; // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖最远距离下标
            if (i == curDistance) { // 遇到当前覆盖最远距离下标
                if (curDistance != nums.size() - 1) { // 如果当前覆盖最远距离下标不是终点
                    ans++; // 需要走下一步
                    curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
                    if (nextDistance >= nums.size() - 1) {
                        break; // 下一步的覆盖范围已经可以达到终点，结束循环
                    }
                } else {
                    break; // 当前覆盖最远距离下标是集合终点，不用做ans++操作了，直接结束
                }
            }
        }
        return ans;
    }
};

```


