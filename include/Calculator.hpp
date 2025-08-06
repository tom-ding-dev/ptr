// include/Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace math_utils {

class Calculator {
public:
    // 构造函数
    Calculator();

    // 成员函数
    double add(double a, double b);
    double subtract(double a, double b);
};

} // namespace math_utils

#endif // CALCULATOR_H