#include "mempool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    void* ptr;
    size_t size;
    const char* tag;
    int freed;
} Block;

static unsigned char* pool;
static size_t pool_size;
static size_t offset;

static Block blocks[1024];
static int block_count;

void mp_init(size_t size) {
    pool = malloc(size);
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
    for (int i = 0; i < block_count; i++) {
        if (!blocks[i].freed) {
            printf("[LEAK] %s (%zu bytes) at %p\n",
                blocks[i].tag, blocks[i].size, blocks[i].ptr);
        }
    }
    printf("=======================\n");
}

void mp_destroy(void) {
    mp_report();
    free(pool);
    printf("[MP] Pool destroyed\n");
}
