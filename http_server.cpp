#include <iostream>
#include "httplib.h"

int main() {
    httplib::Server svr;
    svr.Get("/hello", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });
    std::cout << "HTTP 服务器启动于 http://localhost:8080/hello" << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}
