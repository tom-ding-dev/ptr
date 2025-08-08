#ifndef MYLIB_STUDENT_H
#define MYLIB_STUDENT_H

#include "mylib/person.h"
#include <string>
#include <vector>

namespace mylib {

class Student : public Person {
public:
    Student(const std::string& name, int age, const std::vector<std::string>& courses);
    ~Student();

    void greet() const override;
    void addCourse(const std::string& course);
    const std::vector<std::string>& getCourses() const;

private:
    std::vector<std::string> courses_;
};

} // namespace mylib

#endif // MYLIB_STUDENT_H
