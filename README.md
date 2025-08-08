# 项目阶段性记录

## 阶段1：基础C++11项目结构
- 使用 Bazel 构建系统，创建了 hello/ 目录和基本 BUILD 文件。
- 实现了 `Person` 类，包含头文件和实现文件，使用命名空间。
- main.cpp 演示了智能指针、auto、range-based for、nullptr 等 C++11 特性。

## 阶段2：扩展C++11知识点
- 新增 `Student` 类，继承自 `Person`，演示了继承与多态。
- 新增模板函数、lambda 表达式、std::function、异常处理、STL 容器与算法等示例。
- main.cpp 展示了多种现代C++用法。

## 阶段3：单元测试集成
- 添加 GoogleTest 框架的 Bazel 配置（gtest_binary），实现了 Person、Student、工具函数的单元测试。
- 由于依赖配置问题，测试暂未通过。

## 阶段4：JSON序列化与文件读写
- 集成 json-cpp 库（通过 Bazel WORKSPACE 和 BUILD 文件）。
- 新增 `json_utils.h/cpp`，实现 Person/Student 的 JSON 序列化与反序列化。
- main.cpp 演示了对象的 JSON 文件保存与读取。

---

如需继续扩展功能（如命令行解析、多线程、网络通信等），可随时提出！

# 编译运行方式

bazel run //:main 