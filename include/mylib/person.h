#ifndef MYLIB_PERSON_H
#define MYLIB_PERSON_H

#include <string>
#include <memory>

namespace mylib {

class Person {
public:
    Person(const std::string& name, int age);
    virtual ~Person();

    virtual void greet() const;
    int getAge() const;
    const std::string& getName() const;

private:
    std::string name_;
    int age_;
};

} // namespace mylib

#endif // MYLIB_PERSON_H
