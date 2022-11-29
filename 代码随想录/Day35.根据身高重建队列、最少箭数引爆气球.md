# Day35.根据身高重建队列、最少箭数引爆气球

## 0860.柠檬水找零

链接：[0860.柠檬水找零](https://leetcode.cn/problems/lemonade-change/)

只有三种情况：

1. 5元，直接手下
2. 10元，找零5，同时10增加
3. 20元，找零15，优先10+5，其次5*3

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        // 只有三种情况
        // 分别记录三种面值的数量
        // 由于20面值只进不出，所以也可以不做记录
        int five = 0;
        int ten = 0;
        for (int b : bills) {
            if (b == 5) {
                // 直接收取
                ++five;
                continue;
            }
            if (b == 10) {
                if (five <= 0) {
                    // 没有5了
                    return false;
                }
                --five;
                ++ten;
                continue;
            }
            if (b == 20) {
                // 遇到20就要找15，优先10+5，其次5*3
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

```





## 0406.根据身高重建队列

链接：[0406.根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)

涉及两个维度，需要一个一个维度考虑。

先按身高递减排序，如果相同，k小的在前。

排序完成后，对于某一个元素来说，在其前面的元素一定大于当前元素。

那么直接从前往后，把元素插入到k值下标处即可。这样就在保证前面元素都比他大的情况下，确定了比他大元素的数量。

```cpp
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] > b[0]) {
            return true;
        } else if (a[0] < b[0]) {
            return false;
        } else {
            return a[1] < b[1];
        }
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i) {
            if (people[i][1] == i) {
                continue;
            }
            vector<int> cur = people[i];
            for (int j = i; j > cur[1]; --j) {
                people[j] = people[j - 1];
            }
            people[cur[1]] = cur;
        }
        return people;
    }
};

```





## 0452.用最少数量的箭引爆气球

链接：[0452.用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

从重叠区域最多的地方发射，用到的箭最少。

按区间左位置排序，从第二个区间开始判断，如果重叠，就扩展最小右边界；如果不重叠，箭支+1

```cpp
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int res = 1; // 至少需要一支箭
        // 从第二个气球开始
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1]) {
                // 当前左边界大于前一个右边界
                // 箭+1
                ++res;
            } else {
                // 扩展当前最小右边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};

```



