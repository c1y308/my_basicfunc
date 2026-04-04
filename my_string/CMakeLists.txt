# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称与语言
project(MyString)

# 设置 C++ 标准（如 C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 强制使用指定标准

# 包含头文件目录
include_directories(my_string)


# 添加可执行文件（指定源码文件）
add_executable(my_string my_string.cpp)