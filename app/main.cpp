#include "core/greeter.h"
#include <iostream>

int main() {
    core::Greeter g("Modern C++");
    std::cout << g.greet() << std::endl;
    return 0;
}
