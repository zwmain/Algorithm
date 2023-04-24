/**
 * @file Stone.hpp
 * @author zwmain (zwmain@outlook.com)
 * @brief Find stone pair(s) 题解
 * @version 1.0
 * @date 2022-07-05
 *
 * @copyright Copyright (c) 2022 zwmain
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

typedef std::pair<int, int> Stone; // id, weight

/**
 * @brief 寻找一对重量差为指定值的石头
 *
 * @param weightArr 石头重量数组
 * @param diff 差值
 * @return std::pair<int, int> 差值为diff的一对石头的索引，当找不到时，值为{-1, -1}
 */
std::pair<int, int> findStonePairB1(const std::vector<int>& weightArr, int diff)
{
    std::vector<Stone> stoneArr;
    for (int i = 0; i < weightArr.size(); ++i) {
        stoneArr.emplace_back(i, weightArr[i]);
    }
    std::sort(stoneArr.begin(), stoneArr.end(), [](const Stone& a, const Stone& b) {
        return a.second < b.second;
    });
    int slow = 0;
    int fast = 1;
    while (fast < stoneArr.size()) {
        int d = stoneArr[fast].second - stoneArr[slow].second;
        if (d == diff) {
            return { slow, fast };
        } else if (d < diff) {
            ++fast;
        } else {
            ++slow;
            if (slow == fast) {
                ++fast;
            }
        }
    }
    return { -1, -1 };
}

/**
 * @brief 寻找一对重量差为指定值的石头
 *
 * @param stoneArr 石头重量数组
 * @param diff 差值
 * @return std::pair<size_t, size_t> 差值为diff的一对石头的索引，当找不到时，值为{-1, -1}
 */
std::pair<size_t, size_t> findStonePairB2(const std::vector<int>& stoneArr, int diff)
{
    std::pair<size_t, size_t> res { -1, -1 };
    // 石头重量和石头索引的字典
    std::unordered_map<int, size_t> stoneMap;
    for (size_t i = 0; i < stoneArr.size(); ++i) {
        // 计算当前石头加上差值后的值
        int tarVal = stoneArr[i] + diff;
        // 只有当目标值不存在时，加入字典
        if (stoneMap.find(tarVal) == stoneMap.end()) {
            stoneMap[tarVal] = i;
        }
    }
    for (size_t i = 0; i < stoneArr.size(); ++i) {
        // 把当前值当作目标值查询
        auto it = stoneMap.find(stoneArr[i]);
        // 如果查询到结果，说明目标值存在
        // 目标值对应的索引就是加上diff之前的石头的索引
        if (it != stoneMap.end() && it->second != i) {
            res = std::minmax(i, it->second);
            return res;
        }
    }
    return res;
}

/**
 * @brief 获取所有差值为指定值的石头
 *
 * @param stoneArr 石头重量数组
 * @param diff 差值
 * @return std::vector<std::pair<size_t, size_t>> 差值为diff的一组石头索引，找不到时数组为空
 */
std::vector<std::pair<size_t, size_t>> findStonePairs(const std::vector<int>& stoneArr, int diff)
{
    std::vector<std::pair<size_t, size_t>> res;
    // 石头重量和索引数组的字典
    std::unordered_map<int, std::vector<size_t>> stoneMap;
    for (size_t i = 0; i < stoneArr.size(); ++i) {
        // 计算目标值
        // 并将目标值相同的石头索引放入数组中
        int tarVal = stoneArr[i] + diff;
        auto it = stoneMap.find(tarVal);
        if (it == stoneMap.end()) {
            stoneMap.emplace(tarVal, std::vector<size_t>({ i }));
        } else {
            it->second.push_back(i);
        }
    }
    for (size_t i = 0; i < stoneArr.size(); ++i) {
        // 把当前值当作目标值查询
        auto it = stoneMap.find(stoneArr[i]);
        if (it == stoneMap.end()) {
            continue;
        }
        // 如果查询到结果，说明有一组石头加上差值后可以与当前石头相同
        for (size_t j : it->second) {
            res.push_back(std::minmax(i, j));
        }
    }
    return res;
}

/**
 * @brief 测试findStonePairB2
 *
 * @param stoneArr 石头重量数组
 * @param diff 差值
 * @param expectOutput 预期输出
 */
void testB(const std::vector<int>& stoneArr, int diff, const std::pair<size_t, size_t>& expectOutput)
{
    auto res = findStonePairB2(stoneArr, diff);
    std::cout << "Expect Output: " << expectOutput.first << "," << expectOutput.second << std::endl;
    std::cout << "Actual Output: " << res.first << "," << res.second << std::endl;
    if (res == expectOutput) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief 输出pair数组
 *
 * @param pairArr 待输出的数组
 */
void outputPairArr(const std::vector<std::pair<size_t, size_t>>& pairArr)
{
    bool isFirst = true;
    for (auto& p : pairArr) {
        if (isFirst) {
            isFirst = false;
        } else {
            std::cout << " # ";
        }
        std::cout << p.first << "," << p.second;
    }
    std::cout << std::endl;
}

/**
 * @brief 比较两个pair数组
 *
 * @param aArr a数组
 * @param bArr b数组
 * @return true 数组万全相同
 * @return false 数组至少有一个不同
 */
bool cmpPairArr(const std::vector<std::pair<size_t, size_t>>& aArr, const std::vector<std::pair<size_t, size_t>>& bArr)
{
    if (aArr.size() != bArr.size()) {
        return false;
    }
    for (size_t i = 0; i < aArr.size(); ++i) {
        if (aArr[i] != bArr[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief 测试findStonePairs
 *
 * @param stoneArr 石头重量数组
 * @param diff 差值
 * @param expectOutput 预期输出
 */
void testC(const std::vector<int>& stoneArr, int diff, const std::vector<std::pair<size_t, size_t>>& expectOutput)
{
    auto res = findStonePairs(stoneArr, diff);
    std::cout << "Expect Output: ";
    outputPairArr(expectOutput);
    std::cout << "Actual Output: ";
    outputPairArr(res);
    if (cmpPairArr(res, expectOutput)) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }
    std::cout << std::endl;
}
