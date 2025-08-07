#include "hello.h"
#include <cassert>
#include <iostream>

int main() {
    assert(hello() == "Hello, Bazel!");
    std::cout << "Test passed!" << std::endl;
    return 0;
}
