#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "heap_sort.h"

/** Binary heap helper functions */

size_t left(size_t index) {
    return index * 2 + 1;
}

size_t right(size_t index) {
    return index * 2 + 2;
}

size_t parent(size_t index) {
    return (index - 1) / 2;
}

bool has_left(size_t size, size_t index) {
    return left(index) < size;
}

bool has_right(size_t size, size_t index) {
    return right(index) < size;
}

bool has_parent(size_t index) {
    return index > 0;
}

Element get(Element* data, size_t size, size_t index) {
    if (index >= size) {
        return ELEMENT_NULL;
    }

    return data[index];
}

void swap_at(Element* data, size_t i, size_t j) {
    Element temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

/**
 * Returns the index of the child with the maximum value among the left and right children of the given index.
 * Assumes that the given index has at least a left child.
 */
size_t maximum_child(Element* data, size_t size, size_t cur) {
    size_t left_child = left(cur);

    if (!has_right(size, cur)) {
        return left_child;
    }

    size_t right_child = right(cur);

    return element_compare(get(data, size, left_child), get(data, size, right_child)) >= 0
        ? left_child
        : right_child;
}

/**
 * Heapsort-specific functions
 */

void sift_down_at(Element* data, size_t size, size_t i) {
    size_t cur = i;

    while (has_left(size, cur)) {
        size_t max_child = maximum_child(data, size, cur);

        if (element_compare(get(data, size, cur), get(data, size, max_child)) >= 0) {
            return;
        }

        swap_at(data, cur, max_child);
        cur = max_child;
    }
}

void heapify(Element* data, size_t size) {
    if (size < 2) {
        return;
    }

    for (size_t i = parent(size - 1) + 1; i > 0; i--) { // add 1 to avoid underflow
        sift_down_at(data, size, i - 1);
    }
}

void heapsort(Element* data, size_t size) {
    size_t heap_size = size;

    heapify(data, heap_size);
    for (size_t i = 0; i < size; i++) {
        swap_at(data, 0, heap_size - 1);
        heap_size--;
        sift_down_at(data, heap_size, 0);
    }
}


