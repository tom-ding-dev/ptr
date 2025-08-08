
#include "mylib/person.h"
#include "mylib/student.h"
#include "mylib/utils.h"
#include "mylib/json_utils.h"
#include <memory>
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>

int main() {
    // 智能指针与多态
    std::unique_ptr<mylib::Person> p1 = std::make_unique<mylib::Person>("Alice", 30);
    std::unique_ptr<mylib::Person> p2 = std::make_unique<mylib::Student>("Bob", 20, std::vector<std::string>{"Math", "CS"});
    p1->greet();
    p2->greet();

    // 模板函数与异常处理
    std::vector<int> nums = {1, 5, 3, 9, 2};
    try {
        int maxVal = mylib::findMax(nums);
        std::cout << "Max value: " << maxVal << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Lambda表达式与std::function
    mylib::printWithLambda(nums);
    mylib::callFunction([](const std::string& msg) {
        std::cout << "Lambda says: " << msg << std::endl;
    }, "Hello from lambda!");

    // STL算法与range-based for
    for (auto& n : nums) n *= 2;
    mylib::printWithLambda(nums);

    // JSON序列化与文件读写
    mylib::Student s("Eve", 22, {"Math", "English"});
    Json::Value s_json = mylib::studentToJson(s);
    std::ofstream ofs("student.json");
    ofs << s_json;
    ofs.close();
    std::cout << "Student saved to student.json" << std::endl;

    // 从文件读取并反序列化
    std::ifstream ifs("student.json");
    Json::Value s_json_in;
    ifs >> s_json_in;
    mylib::Student s2 = mylib::studentFromJson(s_json_in);
    std::cout << "Loaded student: ";
    s2.greet();

    return 0;
}
