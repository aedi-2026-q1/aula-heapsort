#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdbool.h>
#include <stddef.h>

#include "element.h"

typedef struct BinaryHeap BinaryHeap;

BinaryHeap* bheap_create(size_t capacity);
void bheap_destroy(BinaryHeap* heap);
void bheap_insert(BinaryHeap *heap, Element element);
Element bheap_extract(BinaryHeap *heap);
Element bheap_peek(BinaryHeap *heap);
size_t bheap_size(BinaryHeap* heap);
bool bheap_is_empty(BinaryHeap* heap);
bool bheap_is_full(BinaryHeap* heap);
void bheap_print(BinaryHeap* heap);

#endif