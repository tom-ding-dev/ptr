// // main.cpp
// #include <iostream>
// #include <fstream>
// #include <string>
// // 引入 JSON 库
// #include "json.hpp"
// // 引入计算器
// #include "Calculator.hpp"

// using namespace math_utils;

// int main() {
//     // 读取 JSON 配置
//     std::ifstream file("app/config.json");
//     nlohmann::json config;
//     file >> config;

//     Calculator calc;
//     int a = config["a"];
//     int b = config["b"];

//     if (config["operation"] == "add") {
//         std::cout << calc.add_formatted(a, b) << std::endl;
//     } else if (config["operation"] == "subtract") {
//         std::cout << a << " - " << b << " = " << calc.subtract(a, b) << std::endl;
//     }

//     return 0;
// }


// // app/main.cpp
// #include <iostream>
// #include <fstream>
// #include "json.hpp"
// #include "Calculator.hpp"

// using namespace math_utils;

// int main() {
//     // 方式1：直接读取（Bazel 会把 data 文件复制到运行目录）
//     std::ifstream file("./my_calculator_project/app/config.json");
//     if (!file.is_open()) {
//         std::cerr << "Cannot open config.json! Current path: " << std::filesystem::current_path() << std::endl;
//         return 1;
//     }

//     nlohmann::json config;
//     file >> config;

//     Calculator calc;
//     int a = config["a"];
//     int b = config["b"];

//     if (config["operation"] == "add") {
//         std::cout << calc.add_formatted(a, b) << std::endl;
//     } else if (config["operation"] == "subtract") {
//         std::cout << a << " - " << b << " = " << calc.subtract(a, b) << std::endl;
//     }

//     return 0;
// }


// app/main.cpp
#include <iostream>
#include <fstream>
#include <string>

// 引入 JSON 库
#include "json.hpp"
// 引入计算器
#include "Calculator.hpp"

// ✅ 引入 Bazel runfiles 头文件
#include "tools/cpp/runfiles/runfiles.h"

using namespace math_utils;

int main(int argc, char** argv) {
    // ✅ 创建 Runfiles 实例（使用 argv[0]）
    std::string error;
    std::unique_ptr<bazel::tools::cpp::runfiles::Runfiles> runfiles_obj(bazel::tools::cpp::runfiles::Runfiles::Create(argv[0], &error));
    if (!runfiles_obj) {
        std::cerr << "Failed to create Runfiles: " << error << std::endl;
        return 1;
    }

    // ✅ 使用 runfiles_obj->Rlocation() 查找文件
    // 格式: "workspace_name/package/file"
    std::string config_path = runfiles_obj->Rlocation("my_calculator_project/app/config.json");

    std::ifstream file(config_path);
    if (!file.is_open()) {
        std::cerr << "Cannot open config file at: " << config_path << std::endl;
        return 1;
    }

    nlohmann::json config;
    file >> config;

    int a = config["a"];
    int b = config["b"];
    Calculator calc;

    std::cout << calc.add_formatted(a, b) << std::endl;

    return 0;
}