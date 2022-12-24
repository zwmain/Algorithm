# 代码随想录60天总结

在代码随想录的最后几天，阳了，身体状态很差，还好跟上了进度。

这60天，是系统性学习的过程，有些题真的是醍醐灌顶，仿佛开启了新世界的大门；有些题难了一些，但是在前面类似简单题的铺垫下，还是可以理解的；当然，也有些题，还是不理解。

刷算法题最难的地方还是“坚持”，以前刷题，总是刷两题就不刷了，没能坚持下来，也没能形成文档。在代码随想录这里刷题的60天，每道题，都会有记录，理解或深或浅，但是一定会有记录。

隔一段时间再看前面的记录，好像还能理解当时的思考过程，复习也比较轻松。

对于有些题，例如二分法，不同情况的代码模板，几乎到了可以背代码的程度：

```c++
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = /* 取值是 nums.size 或者 nums.size-1 */
        while (left /* < 或者 <= */ right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            if (cur == target) {
                return mid;
            } else if (cur > target) {
                right = /* mid 或者 mid - 1 */
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

```
