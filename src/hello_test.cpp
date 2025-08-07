#include "include/hello.h"
#include <string>
#include <cassert>

int main() {
    std::string result = hello();
    assert(result == "Hello, Bazel!");
    return 0;
}
