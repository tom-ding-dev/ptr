// b.cc
#include <iostream>
#include "a.h"

void print_from_b() {
    std::cout << "Entering module B..." << std::endl;
    print_from_a();
}