// calculator/src/Calculator.cpp
#include "Calculator.hpp"
// 引入 fmt 库
#include "fmt.hpp"

namespace math_utils {

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

// std::string Calculator::add_formatted(int a, int b) {
//     return fmt::format("{} + {} = {}", a, b, add(a, b));
// }

std::string Calculator::add_formatted(int a, int b) {
    return fmt::format("{} + {} = {}", a, b, add(a, b));  // 3 个参数
}


} // namespace math_utils