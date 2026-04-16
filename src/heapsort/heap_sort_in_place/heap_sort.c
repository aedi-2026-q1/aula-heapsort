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

// TODO: sift_down_at

// TODO: heapify

// TODO: heapsort


