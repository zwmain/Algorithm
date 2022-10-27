# 0209.长度最小的子数组

链接：[0209.长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

思路：双指针滑动窗口。分快慢指针，快指针先走，扩大窗口。慢指针后走，收缩窗口。要注意循环的终止条件一定是快指针。快指针每次向后走一步，走之前记得更新当前状态。
慢指针在满足条件后才会走，每次也是只走1步，只要条件依然满足，那么窗口会一直收缩，只有在条件不满足或者到达快指针位置时才停止收缩。

注意：在实现时，sum的求解、条件判断、最小值更新，都是在索引+1之前完成的。

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        size_t slow = 0;
        size_t fast = 0;
        int minLen = numeric_limits<int>::max();
        int sum = 0;
        // 注意这里一定是fast做判断
        // fast先走，且每次只走1步
        while (fast < nums.size()) {
            // sum加上当前fast位置的值
            sum += nums[fast];
            // 慢指针移动，收缩窗口，每次收缩1步
            // 只要满足条件，窗口会一直收缩
            while (sum >= target) {
                int len = fast - slow + 1;
                if (len < minLen) {
                    minLen = len;
                }
                if (slow == fast) {
                    return 1;
                }
                // 收缩窗口
                sum -= nums[slow];
                ++slow;
            }
            // fast每次只后移1步
            ++fast;
        }
        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};
```

可以总结出一个模板

```c++
size_t slow=0;
size_t fast=0;
while(fast/* 终止条件 */){
    // 代码逻辑
    while(/* 慢指针移动的条件 */){
        // 代码逻辑
        ++slow;
    }
    ++fast;
}
```
