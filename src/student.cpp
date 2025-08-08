#include "mylib/student.h"
#include <iostream>

namespace mylib {

Student::Student(const std::string& name, int age, const std::vector<std::string>& courses)
    : Person(name, age), courses_(courses) {}

Student::~Student() = default;

void Student::greet() const {
    Person::greet();
    std::cout << "I am a student. My courses are: ";
    for (const auto& c : courses_) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

void Student::addCourse(const std::string& course) {
    courses_.push_back(course);
}

const std::vector<std::string>& Student::getCourses() const {
    return courses_;
}

} // namespace mylib
