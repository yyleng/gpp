#include <stdio.h>
#include <stdlib.h>

void func() {
    printf("func 执行\n");
    exit(0);
}

int func2() {
    printf("func2 执行\n");
    exit(0);
}

int main() {
    printf("main 执行\n");
    return 0;
}
