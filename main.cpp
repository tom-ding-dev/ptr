// main.cpp
#include <iostream>
#include "Calculator.hpp"  // 使用双引号，因为我们包含的是项目内的头文件

using namespace math_utils;

int main() {
    Calculator calc;

    std::cout << "5 + 3 = " << calc.add(5, 3) << std::endl;
    std::cout << "5 - 3 = " << calc.subtract(5, 3) << std::endl;

    return 0;
}