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

## 阶段4补充：json-cpp 集成与使用步骤

1. 克隆 json-cpp 官方源码到 third_party/jsoncpp：
   ```bash
   git clone --depth=1 --branch 1.9.5 https://github.com/open-source-parsers/jsoncpp.git third_party/jsoncpp
   ```

2. 在 third_party/jsoncpp/BUILD 添加 Bazel 构建规则：
   ```python
   cc_library(
       name = "jsoncpp",
       srcs = glob(["src/lib_json/*.cpp"]),
       hdrs = glob(["include/**/*.h"]),
       includes = ["include"],
       visibility = ["//visibility:public"],
   )
   ```

3. 在主项目 BUILD 文件中，将 //third_party/jsoncpp:jsoncpp 添加为 person_lib/main 的 deps。

4. 代码中直接 #include <json/json.h>，即可使用 json-cpp API。

5. 编写 json_utils.h/cpp，实现对象的 JSON 序列化与反序列化。

## 阶段5：HTTP 服务端/客户端集成与运行

1. 下载 cpp-httplib 单头文件到 third_party/cpp-httplib/httplib.h：
   ```bash
   curl -L https://raw.githubusercontent.com/yhirose/cpp-httplib/v0.15.3/httplib.h -o third_party/cpp-httplib/httplib.h
   ```

2. 在 third_party/cpp-httplib/BUILD 添加 Bazel 构建规则：
   ```python
   cc_library(
       name = "httplib",
       hdrs = ["httplib.h"],
       includes = ["."],
       visibility = ["//visibility:public"],
   )
   ```

3. 在主项目 BUILD 文件中添加 http_server 和 http_client target，并依赖 //third_party/cpp-httplib:httplib。

4. 编写 http_server.cpp 和 http_client.cpp 示例代码，分别实现 HTTP 服务端和客户端。

5. 构建并运行服务端和客户端：
   ```bash
   bazel build //:http_server //:http_client
   bazel run //:http_server    # 新开终端运行服务端
   bazel run //:http_client    # 另一个终端运行客户端
   ```

---

如需继续扩展功能（如命令行解析、多线程、网络通信等），可随时提出！

# 编译运行方式

bazel run //:main