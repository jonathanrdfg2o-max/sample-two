#include "mempool.h"
#include <stdio.h>

int main(void) {
    printf("[MP] Demo started\n");

    mp_init(1024);

    int* a = mp_alloc(sizeof(int) * 10, "Array A");
    char* b = mp_alloc(100, "Buffer B");

    mp_free(a);
    mp_free(a); // intentional double free for demo

    // b intentionally not freed (leak demo)

    mp_destroy();

    printf("[MP] Demo finished, exiting normally\n");
    return 0;
}
