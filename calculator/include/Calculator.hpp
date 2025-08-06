// calculator/include/Calculator.hpp
#pragma once
#include <string>

namespace math_utils {

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
    // 新增：返回格式化结果
    std::string add_formatted(int a, int b);
};

} // namespace math_utils