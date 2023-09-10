#include "sort.h"
#include <stddef.h>
#include <stdio.h>

void swap(size_t a, size_t b, int *src) {
  int temp = src[a];
  src[a] = src[b];
  src[b] = temp;
}

void bubble_sort(size_t size, int *src) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (src[j] > src[j + 1]) {
        swap(j, j + 1, src);
      }
    }
  }
}

size_t partition(int low, int high, int *src) {
  int pivot = src[high];
  int idx = low - 1;

  for (int i = low; i < high; i++) {
    if (src[i] <= pivot) {
      idx++;
      swap(i, idx, src);
    }
  }

  idx++;

  src[high] = src[idx];
  src[idx] = pivot;

  return idx;
}

void qs(int low, int high, int *src) {
  if (low >= high) {
    return;
  }

  size_t pivotIdx = partition(low, high, src);
  qs(low, pivotIdx - 1, src);
  qs(pivotIdx + 1, high, src);
}

void quick_sort(size_t size, int *src) { qs(0, size - 1, src); }
