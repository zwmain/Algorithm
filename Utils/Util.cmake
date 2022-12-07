# CMake util
macro(AlgoTemplate)
    # 设置C++标准
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Win MSVC下需要手动指定源码编码类型
    if(MSVC)
        add_compile_options("/source-charset:utf-8")
    endif()

    set(UTIL_DIR "../../Utils")
    set(UTIL_FILE "${UTIL_DIR}/Utils.hpp")

    add_definitions(-DINPUT_PATH="${PROJECT_SOURCE_DIR}/input.txt")

    add_definitions(-DINPUT_DIR="${PROJECT_SOURCE_DIR}/")

    add_executable(${PROJECT_NAME} main.cpp main.h ${UTIL_FILE})

    target_include_directories(${PROJECT_NAME} PUBLIC ${UTIL_DIR})
endmacro()
