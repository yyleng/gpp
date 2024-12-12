#include <iostream>

struct MyGlobal {
    MyGlobal() { std::cout << "This might fail!\n"; }
} global;

int main() {
    std::cout << "Main runs.\n";
    return 0;
}
