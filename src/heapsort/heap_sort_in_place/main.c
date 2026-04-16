#include <stdio.h>

#include "heap_sort.h"

void printArray(Element* arr, int n) {
    for (int i = 0; i < n; i++) {
        element_print(arr[i]);
        printf(" ");
    }
    printf("\n");
}

int main() {
    Element a[] = {10};
    int aSize = 1;

    printArray(a, aSize);
    heapsort(a, aSize);
    printArray(a, aSize);

    printf("\n");

    Element b[] = {20, 5};
    int bSize = 2;

    printArray(b, bSize);
    heapsort(b, bSize);
    printArray(b, bSize);

    printf("\n");

    Element c[] = {28, 17, 99, 64, 3, 85, 12, 51, 70, 46, 2, 92, 10, 5, 31, 88, 61, 40, 96, 23};
    int cSize = 20;

    printArray(c, cSize);
    heapsort(c, cSize);
    printArray(c, cSize);

    return 0;
}