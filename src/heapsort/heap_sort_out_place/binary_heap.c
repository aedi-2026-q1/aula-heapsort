#include "binary_heap.h"

#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap {
    Element* data;
    size_t capacity;
    size_t size;
};

BinaryHeap* bheap_create(size_t capacity) {
    BinaryHeap* bheap = malloc(sizeof(BinaryHeap));

    bheap->data = malloc(capacity * sizeof(Element));
    bheap->capacity = capacity;
    bheap->size = 0;

    return bheap;
}

void bheap_destroy(BinaryHeap* bheap) {
    free(bheap->data);
    free(bheap);
}

size_t left(size_t index) {
    return index * 2 + 1;
}

size_t right(size_t index) {
    return index * 2 + 2;
}

size_t parent(size_t index) {
    return (index - 1) / 2;
}

bool has_left(BinaryHeap* bheap, size_t index) {
    return left(index) < bheap->size;
}

bool has_right(BinaryHeap* bheap, size_t index) {
    return right(index) < bheap->size;
}

bool has_parent(size_t index) {
    return index > 0;
}

Element get_left(BinaryHeap* bheap, size_t index) {
    if (!has_left(bheap, index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[left(index)];
}

Element get_right(BinaryHeap* bheap, size_t index) {
    if (!has_right(bheap, index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[right(index)];
}

Element get_parent(BinaryHeap* bheap, size_t index) {
    if (!has_parent(index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[parent(index)];
}

Element get(BinaryHeap* bheap, size_t index) {
    if (index >= bheap->size) {
        return ELEMENT_NULL;
    }

    return bheap->data[index];
}

void swap_at(BinaryHeap* bheap, size_t i, size_t j) {
    Element temp = bheap->data[i];
    bheap->data[i] = bheap->data[j];
    bheap->data[j] = temp;
}

void sift_up(BinaryHeap* bheap) {
    size_t cur = bheap->size - 1;

    while (has_parent(cur) && element_compare(get(bheap, cur), get_parent(bheap, cur)) > 0) {
        swap_at(bheap, cur, parent(cur));
        cur = parent(cur);
    }
}

/**
 * Returns the index of the child with the maximum value among the left and right children of the given index.
 * Assumes that the given index has at least a left child.
 */
size_t maximum_child(BinaryHeap* bheap, size_t cur) {
    size_t left_child = left(cur);

    if (!has_right(bheap, cur)) {
        return left_child;
    }

    size_t right_child = right(cur);

    return element_compare(get(bheap, left_child), get(bheap, right_child)) >= 0 
        ? left_child 
        : right_child;
}

void sift_down(BinaryHeap* bheap) {
    size_t cur = 0;

    while (has_left(bheap, cur)) {
        size_t max_child = maximum_child(bheap, cur);

        if (element_compare(get(bheap, cur), get(bheap, max_child)) >= 0) {
            return;
        }

        swap_at(bheap, cur, max_child);
        cur = max_child;
    }
}

void bheap_insert(BinaryHeap* bheap, Element element) {
    if (bheap_is_full(bheap)) {
        return;
    }

    bheap->data[bheap->size] = element;
    bheap->size++;
    sift_up(bheap);
}

Element bheap_extract(BinaryHeap* bheap) {
    if (bheap->size == 0) {
        return ELEMENT_NULL;
    }

    Element result = bheap->data[0];

    bheap->data[0] = bheap->data[bheap->size - 1];
    bheap->size--;
    sift_down(bheap);

    return result;
}

Element bheap_peek(BinaryHeap *heap) {
    if (heap->size == 0) {
        return ELEMENT_NULL;
    }

    return heap->data[0];
}

size_t bheap_size(BinaryHeap* bheap) {
    return bheap->size;
}

bool bheap_is_empty(BinaryHeap* bheap) {
    return bheap->size == 0;
}

bool bheap_is_full(BinaryHeap* heap) {
    return heap->size == heap->capacity;
}

void bheap_print(BinaryHeap* bheap) {
    for (size_t i = 0; i < bheap->size; i++) {
        element_print(bheap->data[i]);
        printf(" ");
    }
    printf("\n");
}

