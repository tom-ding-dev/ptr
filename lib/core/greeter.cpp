#include "core/greeter.h"

namespace core {
Greeter::Greeter(const std::string& who) : who_(who) {}
std::string Greeter::greet() const {
    return "Hello, " + who_ + "!";
}
}
