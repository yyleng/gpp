#include <iostream>
#include <stdio.h>
#include <string>

int myfunc(int a) {
    printf("myfunc a is %d\n", a);
    return 0;
}

// extern "C" 使得 func 函数名不会进行修饰
extern "C" void func() {
    int i = 1;
    ++i;
    printf("%d\n", i);

    // 无法调用 c++ 中的 std::cout
    // 因为 std::cout 是全局静态对象，无法确定在执行当前函数前 std::cout
    // 已经初始化完毕了

    // std::cout << "func2 执行\n";

    std::string a("aaa");
    printf("%s\n", a.c_str());

    // 还可以调用 main 函数
    extern int main();
    int result = main();

    myfunc(result);

    // 必须有，否则会有段错误
    exit(0);
}

extern "C" void func2() {
    printf("2\n");
    exit(0);
}

int main() {
    // 如果 main 在 func 中被调用的话，不能有 std::cout
    // std::cout << "main 执行\n";
    return 0;
}
