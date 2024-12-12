#include <cstdio>
#include <cstdlib>

// 手动实现 _start
extern "C" void _start() {
    printf("Custom _start called\n");

    // 调用 main 函数
    extern int main();
    int result = main();

    // 正常退出程序
    _Exit(result);
}

int main() {
    printf("This is main\n");
    return 0;
}
