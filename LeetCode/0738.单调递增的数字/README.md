# 0738.单调递增的数字

链接：[0738.单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/)

为了方便处理，将输入的数字转换为字符串。

从后往前遍历，如果出现前一个数大于当前数的情况，那么前数直接减1，由于高位减1，那么后面的可以全部设置为9

```c++
class Solution {
public:
    int monotoneIncreasingDigits(int n)
    {
        string strNum = to_string(n);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};

```



