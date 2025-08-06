// src/Calculator.cpp
#include "Calculator.hpp"
#include <iostream>

namespace math_utils {

Calculator::Calculator() {
    // 构造函数实现（可以为空）
}

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

} // namespace math_utils