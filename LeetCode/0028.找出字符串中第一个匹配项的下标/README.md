# 0028.找出字符串中第一个匹配项的下标

链接：[0028.找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

## 前缀表/数组

`prefix`数组中，每一个值`prefix[i]`所代表的是`[0,i]`区间内字符串的最长相等前后缀的**长度**

既然是前缀和后缀长度，那么这个长度所值的就是前缀字符串的**后一个**字符

对于首字符，没有前后缀或者前后缀为空字符串，因此`prefix[0]`的值为0，即前后缀长度为0。

0处没有前后缀，因此从1处开始找。设`cur`指向当前字符，cur就是已存在后缀想要扩展的值，他需要和已存在前缀想要扩展的值匹配，即和当前已存在前缀长度所指向的值匹配。

`cur`所指向的，永远是后缀的最后一个位置。

如果匹配不成功，前后缀扩展失败。因此最长前后缀长度需要收缩，收缩为前一个子串的最长相等前后缀长度，指向前一个子串的最长相等前缀的后一个字符。

如果匹配成功，那么前后缀扩展成功。那么长度+1。

## 匹配

匹配过程中，主串从0开始，一步一步后移，不会前移。

模式串从0开始，如果在某个位置匹配失败，会回退到前一个子串的最长相等前缀的后一个位置。即`j=prefix[j-1]`。

如果匹配成功，模式串后移。主串的后移交给`for`循环

如果模式串索引和模式串长度相同，那么说明模式串已经匹配完了。可以退出。

## 源码

```c++
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0) {
            return 0;
        }
        auto prefix = getPrefix(needle);
        // 从0开始遍历needle
        int j = 0;
        // 从0开始遍历haystack
        for (int i = 0; i < haystack.size(); ++i) {
            // 如果在某个位置匹配失败
            // 回退到前一个子串的最长相等前缀的后一个位置继续匹配
            while (j > 0 && needle[j] != haystack[i]) {
                j = prefix[j - 1];
            }
            // 如果匹配成功，needle后移一位，i会在for中后移
            if (needle[j] == haystack[i]) {
                ++j;
            }
            // 如果此时needle已经到末尾了，匹配结束
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
    vector<int> getPrefix(const string& patStr)
    {
        // 前缀数组的每一个值代表的都是前后缀长度
        // 初始化前缀数组，和字符串一样长
        vector<int> prefix(patStr.size());
        // 0处没有前后缀，因此相等前后缀长度为0
        prefix[0] = 0;
        // 初始最长相等前后缀长度，初始没有前后缀，为空，所以长度为0
        // 同时，这个长度所代表的索引，也指向已存在前缀的后面第一个字符
        // 初始状态下，不存在前后缀，空字符串，所以后面的第一个就是首字符
        // 观察已存在前后缀的后一个就相当于在原有基础上尝试各自扩展一位
        int l = 0;
        // 0处没有前后缀，从1开始找
        for (int cur = 1; cur < patStr.size(); ++cur) {
            // cur每次指向后缀想要扩展的值
            // l作为长度，指向前缀想要扩展的值
            while (l > 0 && patStr[cur] != patStr[l]) {
                // 不匹配，该子串，扩展失败
                // l收缩为前一个子串的最长相等前后缀长度，指向前一个子串的最长相等前缀的后一个字符
                l = prefix[l - 1];
            }
            // 退出循环，有两种情况
            // 匹配成功，最长相等前后缀长度+1
            if (patStr[cur] == patStr[l]) {
                l++;
            }
            // 匹配失败，但是长度已经为0了
            prefix[cur] = l;
        }
        return prefix;
    }
    vector<int> getPrefix2(const string& patStr)
    {
        // 初始化前缀数组，和字符串一样长，初始值全为0
        vector<int> prefix(patStr.size(), 0);
        // 因为第0个字符，没有前后缀，所以为0，直接从1开始
        for (int cur = 1; cur < patStr.size(); ++cur) {
            // cur是当前子串的后缀的最后一个值
            // 要想求prefix[cur]，需要参考前一个子串的最后一个值
            int tail = cur - 1;
            // prefix[tail]代表以tail处字符结尾的子串，其最长公共前后缀长度为prefix[tail]，假设这里prefix[tail]为k，
            // 那么说明相等的前缀长度为k，相等后缀长度也为k
            // 则[0,k)，左闭右开区间代表相等前缀范围，k-1处为相等前缀的最后一个位置，k处为相等前缀之后的第一个位置
            // 由于cur是当前后缀的最后一个位置，所以要和上一个前缀的后一个位置比较
            // 相当于原本两个相等的前后缀，各自往后扩展了一位，所以要比较这个扩展位是否一致
            if (patStr[cur] == patStr[prefix[tail]]) {
                // 如果一致，说明最长相等前后缀扩展了1位，长度+1
                prefix[cur] = prefix[tail] + 1;
            } else {
                // 如果不相等，说明扩展失败
                // 开始和以prefix[tail]处的子串比较，即tail=prefix[tail]
                // 直到cur和prefix[tail]处相等，或者tail已经到达0，退出
                while (tail > 0 && patStr[cur] != patStr[prefix[tail]]) {
                    // 最初这里在遇到tail等于prefix[tail]的时候，会死循环
                    // tail=prefix[tail]
                    tail = prefix[tail - 1];
                }
                // 退出时有两种情况，一种时cur的字符和prefix[tail]相等，tail也可以是0，和0处相等
                // 还有一种就是tail已经到达0了，还不相等，那么就直接把prefix[tail]赋值过去就可以了
                if (patStr[cur] == patStr[prefix[tail]]) {
                    prefix[cur] = prefix[tail] + 1;
                } else {
                    prefix[cur] = prefix[tail];
                }
            }
        }
        return prefix;
    }
};

```
