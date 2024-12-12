#include <chrono>
#include <iostream>

void process(int x) {
    if (x == 1) {
    } else if (x == 2) {
    } else if (x == 3) // 大多数都是3
    {
    } else {
    }
}

void process2(int x) {
    if (x == 1) {
    } else if (x == 2) {
    } else if (__builtin_expect(x == 3, 1)) // 大多数都是3
    {
    } else {
    }
}

void process3(int x) {
    if (x == 3) {
    } else if (x == 2) {
    } else if (x == 1) // 大多数都是3
    {
    } else {
    }
}

template <typename F, int time = 10000000> void call(F f) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < time; ++i) {
        f(3);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();
    std::cout << typeid(f).name() << "run time is " << duration << " us\n";
}

int main() {
    call(process);
    call(process2);
    call(process3);
    return 0;
}
