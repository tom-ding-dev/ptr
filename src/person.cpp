#include "mylib/person.h"
#include <iostream>

namespace mylib {

Person::Person(const std::string& name, int age)
    : name_(name), age_(age) {}

Person::~Person() = default;

void Person::greet() const {
    std::cout << "Hello, my name is " << name_ << " and I am " << age_ << " years old." << std::endl;
}

int Person::getAge() const {
    return age_;
}

const std::string& Person::getName() const {
    return name_;
}

} // namespace mylib
