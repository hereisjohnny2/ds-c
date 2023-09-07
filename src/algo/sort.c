#include "sort.h"
#include <string.h>

void bubble_sort(size_t size, int *src) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (src[j] > src[j + 1]) {
        int temp = src[j];
        src[j] = src[j + 1];
        src[j + 1] = temp;
      }
    }
  }
}
