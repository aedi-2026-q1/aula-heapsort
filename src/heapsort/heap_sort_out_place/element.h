#ifndef ELEMENT_H
#define ELEMENT_H

// Assumes element is a primitive type

#include <limits.h>

// Sentinel value defined as the minimum int, which is unlikely to be a valid element in typical use cases.
#define ELEMENT_NULL INT_MIN

typedef int Element;

void element_print(Element element);
int element_compare(Element a, Element b);

#endif