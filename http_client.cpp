#include <iostream>
#include "httplib.h"

int main() {
    httplib::Client cli("localhost", 8080);
    if (auto res = cli.Get("/hello")) {
        std::cout << "响应: " << res->status << "\n" << res->body << std::endl;
    } else {
        std::cout << "请求失败" << std::endl;
    }
    return 0;
}
