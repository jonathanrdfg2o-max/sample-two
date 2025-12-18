#include "mempool.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* ptr;
    size_t size;
    const char* tag;
    int freed;
} Block;

static unsigned char* pool = NULL;
static size_t pool_size = 0;
static size_t offset = 0;

static Block blocks[1024];
static int block_count = 0;

void mp_init(size_t size) {
    pool = (unsigned char*)malloc(size);
    pool_size = size;
    offset = 0;
    block_count = 0;
    printf("[MP] Pool initialized (%zu bytes)\n", size);
}

void* mp_alloc(size_t size, const char* tag) {
    if (offset + size > pool_size) {
        printf("[MP][ERROR] Out of memory\n");
        return NULL;
    }

    void* ptr = pool + offset;
    offset += size;

    blocks[block_count++] = (Block){ptr, size, tag, 0};
    printf("[MP][ALLOC] %s (%zu bytes) -> %p\n", tag, size, ptr);
    return ptr;
}

void mp_free(void* ptr) {
    for (int i = 0; i < block_count; i++) {
        if (blocks[i].ptr == ptr) {
            if (blocks[i].freed) {
                printf("[MP][ERROR] Double free detected: %p\n", ptr);
                return;
            }
            blocks[i].freed = 1;
            printf("[MP][FREE] %s -> %p\n", blocks[i].tag, ptr);
            return;
        }
    }
    printf("[MP][ERROR] Invalid free: %p\n", ptr);
}

void mp_report(void) {
    printf("\n==== Memory Report ====\n");
    int leaks = 0;
    for (int i = 0; i < block_count; i++) {
        if (!blocks[i].freed) {
            leaks++;
            printf("[LEAK] %s (%zu bytes) at %p\n",
                   blocks[i].tag,
                   blocks[i].size,
                   blocks[i].ptr);
        }
    }
    if (!leaks) {
        printf("No leaks detected ✅\n");
    }
    printf("=======================\n");
}

void mp_destroy(void) {
    mp_report();
    free(pool);
    pool = NULL;
    printf("[MP] Pool destroyed\n");
}
