# LeetCode算法题

LeetCode刷题列表

```cmake
cmake_minimum_required(VERSION 3.18.0)

project(ProjectName LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Win MSVC下需要手动指定源码编码类型
if (MSVC)
    add_compile_options("/utf-8")
endif()

set(UTIL_DIR "../0000.Utils")
set(UTIL_FILE "${UTIL_DIR}/Utils.hpp")

add_executable(${PROJECT_NAME} main.cpp main.h ${UTIL_FILE})

target_include_directories(${PROJECT_NAME} PUBLIC ${UTIL_DIR})

```

## 数组算法

## 双指针/索引

[0026.删除有序数组中的重复项](./0026.删除有序数组中的重复项)

[0027.移除元素](./0027.移除元素)

[0167.两数之和II-输入有序数组](./0167.两数之和II-输入有序数组)

### 前缀和数组

[0303.区域和检索-数组不可变](./0303.区域和检索-数组不可变)

[0304.二维区域和检索-矩阵不可变](./0304.二维区域和检索-矩阵不可变)
