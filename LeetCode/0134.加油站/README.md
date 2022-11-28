# 0134.加油站

链接：[0134.加油站](https://leetcode.cn/problems/gas-station/)

如果总油量大于总消耗，那么一定可以跑完。那么单个站点的剩余油量可能大于或小于0，但是总和一定大于0。

从0累加**剩余油量**，和为`curSum`，如果`curSum`小于0，说明`[0,i]`都不能作为起始位置，起始位置需要从`i+1`重新算，`curSum`也要重新置为0。

同时，记录`totalSum`表示总剩余量，如果最后小于0，说明无法走完一圈

```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) {
            return -1;
        }
        return start;
    }
};

```


