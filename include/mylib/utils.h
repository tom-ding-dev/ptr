#ifndef MYLIB_UTILS_H
#define MYLIB_UTILS_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>

namespace mylib {

// 模板函数：查找最大值
template<typename T>
T findMax(const std::vector<T>& vec) {
    if (vec.empty()) throw std::runtime_error("Vector is empty");
    return *std::max_element(vec.begin(), vec.end());
}

// Lambda表达式和std::function示例
inline void printWithLambda(const std::vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;
}

inline void callFunction(const std::function<void(const std::string&)>& func, const std::string& msg) {
    func(msg);
}

} // namespace mylib

#endif // MYLIB_UTILS_H
