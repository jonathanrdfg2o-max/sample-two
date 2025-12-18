#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <stddef.h>

void mp_init(size_t size);
void* mp_alloc(size_t size, const char* tag);
void mp_free(void* ptr);
void mp_report(void);
void mp_destroy(void);

#endif
