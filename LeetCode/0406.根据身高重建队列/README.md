# 0406.根据身高重建队列

链接：[0406.根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)

涉及两个维度，需要一个一个维度考虑。

先按身高递减排序，如果相同，k小的在前。

排序完成后，对于某一个元素来说，在其前面的元素一定大于当前元素。

那么直接从前往后，把元素插入到k值下标处即可。这样就在保证前面元素都比他大的情况下，确定了比他大元素的数量。

```c++
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



