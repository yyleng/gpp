#include <iostream>

template <int N> struct EntryPoint {
    EntryPoint() {
        std::cout << "Compile-time entry point logic: " << N << std::endl;
    }
};

// 实例化模板以触发逻辑
EntryPoint<42> myEntry;

int main() {
    std::cout << "This is main." << std::endl;
    return 0;
}
