#include "mempool.h"
#include <stdio.h>

int main() {
    mp_init(1024);

    int* a = mp_alloc(sizeof(int) * 10, "Array A");
    char* b = mp_alloc(100, "Buffer B");

    mp_free(a);
    mp_free(a); // double free test

    mp_destroy();
    return 0;
}
