# 0055.跳跃游戏

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



