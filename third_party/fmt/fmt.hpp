// // // third_party/fmt/fmt.hpp

// // #pragma once
// // #include <string>
// // #include <sstream>

// // namespace fmt {
// //     template <typename... Args>
// //     std::string format(const std::string& fmt, Args... args) {
// //         std::ostringstream oss;
// //         // 简化：只替换第一个 {}
// //         size_t pos = fmt.find("{}");
// //         if (pos != std::string::npos) {
// //             oss << fmt.substr(0, pos) << args... << fmt.substr(pos+2);
// //         }
// //         return oss.str();
// //     }
// // }


// // third_party/fmt/fmt.hpp
// #pragma once
// #include <string>
// #include <sstream>

// namespace fmt {

// // 辅助函数：将 args 逐个写入 ostream
// template <typename... Args>
// void write_args(std::ostringstream& oss, Args&&... args) {
//     // C++17 折叠表达式（推荐）
//     (oss << ... << args);
// }

// // 简化版 format：只替换第一个 {}
// template <typename... Args>
// std::string format(const std::string& fmt, Args&&... args) {
//     std::ostringstream oss;
//     size_t pos = fmt.find("{}");
//     if (pos != std::string::npos) {
//         oss << fmt.substr(0, pos);
//         write_args(oss, std::forward<Args>(args)...);
//         oss << fmt.substr(pos + 2);
//     } else {
//         oss << fmt; // 没有 {}，直接输出
//     }
//     return oss.str();
// }

// } // namespace fmt


// third_party/fmt/fmt.hpp
#pragma once
#include <string>
#include <sstream>
#include <vector>

namespace fmt {

// 辅助函数：将任意值转为字符串
template <typename T>
std::string to_string(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// 核心 format 函数
template <typename... Args>
std::string format(const std::string& fmt, Args&&... args) {
    std::string result = fmt;
    std::vector<std::string> args_str = { to_string(args)... };

    size_t arg_index = 0;
    size_t pos = 0;

    // 逐个查找 {} 并替换
    while (arg_index < args_str.size()) {
        pos = result.find("{}", pos);
        if (pos == std::string::npos) {
            break;
        }
        result.replace(pos, 2, args_str[arg_index]);
        pos += args_str[arg_index].length();  // 移动到替换后的位置
        arg_index++;
    }

    return result;
}

} // namespace fmt