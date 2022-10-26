# Day01.二分查找、移除元素

## 0704.二分查找

题目链接：[0704.二分查找](https://leetcode.cn/problems/binary-search/)

思路：二分查找，仅对有序数组有效。每次需要数组的中间值，与目标值比较大小，如果中间值比目标值大，说明目标值位置在left与mid中间，区间缩小一半；
同理，如果中间值比目标值小，说明目标值在mid与right中间，区间缩小一半。

二分查找最容易出错的地方是区间的确定，分为左闭右闭和左闭右开两种。不管哪一种，模板如下：

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

right的取值决定了区间类型，`right = nums.size() - 1`为左闭右闭区间，即`[left,right]`；`right = nums.size()`为左闭右开区间，即`[left,right)`

左闭右闭时，循环条件中就是`<=`，因为是闭区间，right指向的值也应该被取到，如果为`<`，那么会少一个值。
判断语句中`right = mid - 1`，mid不是目标位置，不应该被取到，如果不减1，那么因为是闭区间，mid还是有可能被取到。因此左闭右闭区间的代码为：

```c++
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        // 左闭右闭区间
        int right = nums.size() - 1;
        // 当左闭右闭区间时，左右是可以相等的
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            if (cur == target) {
                return mid;
            } else if (cur > target) {
                // 当右边为闭合时，right需要mid-1
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
```

左闭右开时，循环中的条件就是`<`，因为是开区间，right可能并不在数组合法区间内，会有越界的风险，因此不能等于，只能小于。
判断语句中`right = mid`，mid不是目标位置，不应该被取到，又因为这里是开区间，本来就取不到，所以直接赋值即可。
如果这里mid减1，那么就会因为开区间，取不到mid前面的那个值。左闭右开区间代码：

```c++
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        // 左闭右开区间
        int right = nums.size();
        // 当左闭右开时，左右不能相等
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            if (cur == target) {
                return mid;
            } else if (cur > target) {
                // 当左闭右开时，right值就是mid，不需要mid-1
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
```

## 0027.移除元素

题目链接：[0027.移除元素](https://leetcode.cn/problems/remove-element/)

思路1：借助`erase`接口，循环遍历数组，遇到目标值时，调用接口移除元素。由于元素删除后，后续元素会前移，就相当于索引后移，因此删除时索引不变。
直到数组被删到只剩索引大小或者索引位置不等于目标值时，索引才会后移。

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t ind = 0;
        while (ind < nums.size()) {
            while (ind < nums.size() && nums[ind] == val) {
                nums.erase(nums.begin() + ind);
            }
            ++ind;
        }
        return nums.size();
    }
};

```

思路2：暴力解法，记录初始长度，使用索引遍历数组，寻找与目标相同的位置，然后从当前索引的后一个位置开始，将后面的值前移，同时长度减1，这就相当与删除了一个元素。
同样，因为是后面的值覆盖前面的值，就相当于索引后移，因此删除时，索引不变。只有当索引不是目标值时才向后移动。

由于这题不考虑顺序问题，所以在前移元素时，可以只把最后位置的和当前覆盖即可。可以减少复杂度。

```c++
class Solution {
public:
    int removeElement2(vector<int>& nums, int val)
    {
        if (nums.empty()) {
            return 0;
        }
        size_t length = nums.size();
        size_t ind = 0;
        // length随着元素移除会不断变小，当为0时退出
        while (length > 0 && ind < length) {
            if (nums[ind] == val) {
                // 当前值与目标值相等时，将后面的元素前移，覆盖当前值，这种方法可以保证元素顺序
                // 如果不考虑元素顺序，可以直接将最后一个元素放置在此处
                for (size_t i = ind + 1; i < length; ++i) {
                    nums[i - 1] = nums[i];
                }
                --length;
            } else {
                ++ind;
            }
        }
        return length;
    }
};

```

思路3：双指针法。删除的基本思想是旧元素覆盖新元素。快指针指向新元素，需要保留的元素；慢指针指向旧元素，需要被覆盖的元素。快指针从0开始，一直向后移动；慢指针从0开始，只有在被覆盖后才向后移动。
如果数组的前面没遇到目标值，那么快慢指针就会一直相等，快指针一直后移，因为没遇到目标值，会走覆盖的逻辑，慢指针也会一直后移。

参考连接：[代码随想录-移除元素](https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html)

学习视频：[代码随想录-移除元素](https://www.bilibili.com/video/BV12A4y1Z7LP)

```c++
class Solution {
public:
    // 双指针
    // 删除元素的基本思想是：将目标元素后面的元素前移，将快指针指向新数组中的元素
    // 慢指针指向旧数组中应该被替换的位置
    int removeElement2(vector<int>& nums, int val)
    {
        size_t slow = 0; // 指向需要被替换的位置
        size_t fast = 0; // 指向需要保留的位置
        for (fast; fast < nums.size(); ++fast) {
            // 只有当fast位置不等于目标值时，才会替换前面的位置
            // 当fast位置等于目标值时，跳过，slow位置没有被替换，因此不后移
            if (nums[fast] != val) {
                // 只有当fast不等于目标值时才会发生替换，++slow
                // 这里如果slow和fast可能相等
                nums[slow] = nums[fast];
                ++slow;
            }
            // 不管是不是等于目标值，fast会一直后移
        }
        return slow;
    }
};

```

