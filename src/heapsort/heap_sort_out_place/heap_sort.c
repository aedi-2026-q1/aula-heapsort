#include "heap_sort.h"
#include "binary_heap.h"

void heapsort(Element *array, size_t n) {
    BinaryHeap* heap = bheap_create(n);

    for (size_t i = 0; i < n; i++) {
        bheap_insert(heap, array[i]);
    }

    for (size_t i = n; i > 0; i--) {
        array[i - 1] = bheap_extract(heap);
    }

    bheap_destroy(heap);

}