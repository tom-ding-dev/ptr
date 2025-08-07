// a.cc
#include <iostream>
#include "my_math.h"  // 来自 third_party/libmath

void print_from_a() {
    std::cout << "Hello from module A, 3 + 5 = " << multiply(3, 5) << std::endl;
}