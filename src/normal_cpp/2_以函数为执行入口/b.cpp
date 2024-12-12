#include <iostream>

__attribute__((constructor)) void myEntryPoint() {
    // std::cout 是一个全局静态对象，位于
    //         C++ 标准库中，通常在程序的初始化阶段被构造。如果
    //     __attribute__((constructor)) 修饰的函数早于 std::cout
    //         的初始化执行，就可能导致访问未初始化的对象，从而引发段错误。

    // std::cout << "This runs before main!" << std::endl;

    // 改用 c 的 printf 函数
    printf("This runs before main!");
}

int main() {
    std::cout << "This is main." << std::endl;
    return 0;
}
