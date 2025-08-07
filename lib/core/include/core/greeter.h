#pragma once
#include <string>

namespace core {
class Greeter {
public:
    Greeter(const std::string& who);
    std::string greet() const;
private:
    std::string who_;
};
}
