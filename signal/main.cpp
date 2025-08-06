#include <iostream>
#include <csignal>        // for signal()
#include <atomic>         // for std::atomic
#include <thread>         // for std::this_thread::sleep_for
#include <chrono>         // for std::chrono

// 原子布尔变量，用于通知程序退出
std::atomic<bool> g_stop(false);

// 信号处理函数 —— 只做一件事：设置标志
void signal_handler(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        g_stop.store(true, std::memory_order_relaxed);
        // 注意：这里不要用 std::cout！它不是异步信号安全的
        // 输出留在主循环中处理
    }
}

int main() {
    // 注册信号处理函数
    std::signal(SIGINT,  signal_handler);  // Ctrl+C
    std::signal(SIGTERM, signal_handler);  // kill 命令

    std::cout << "程序启动。按 Ctrl+C 退出...\n";

    while (!g_stop.load(std::memory_order_relaxed)) {
        // 模拟工作
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // 安全地输出状态
        std::cout << "运行中... (等待中断)\n";
    }

    // 走到这里，说明收到信号，可以安全清理
    std::cout << "\n收到退出信号，正在清理资源...\n";

    // 执行清理操作（关闭文件、网络连接等）
    // ...

    std::cout << "资源清理完成，程序退出。\n";
    return 0;
}