#include "mylib/person.h"
#include "mylib/student.h"
#include "mylib/utils.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

TEST(PersonTest, BasicInfo) {
    mylib::Person p("Tom", 40);
    EXPECT_EQ(p.getName(), "Tom");
    EXPECT_EQ(p.getAge(), 40);
}

TEST(StudentTest, InheritanceAndCourses) {
    std::vector<std::string> courses = {"Math", "Physics"};
    mylib::Student s("Jerry", 18, courses);
    EXPECT_EQ(s.getName(), "Jerry");
    EXPECT_EQ(s.getAge(), 18);
    EXPECT_EQ(s.getCourses().size(), 2);
    s.addCourse("CS");
    EXPECT_EQ(s.getCourses().size(), 3);
}

TEST(UtilsTest, FindMaxAndException) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(mylib::findMax(nums), 3);
    std::vector<int> empty;
    EXPECT_THROW(mylib::findMax(empty), std::runtime_error);
}

TEST(UtilsTest, LambdaAndFunction) {
    bool called = false;
    mylib::callFunction([&called](const std::string& msg) {
        called = (msg == "test");
    }, "test");
    EXPECT_TRUE(called);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
