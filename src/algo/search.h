#ifndef SEARCH_H
#define SEARCH_H

#include <stdbool.h>

#define len(arr) sizeof arr / sizeof arr[0]

bool linear_search(int size, int *arr, int value);
bool binary_search(int size, int *arr, int value);

#endif // SEARCH_H
