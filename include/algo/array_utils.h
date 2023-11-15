#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#define ARR_LEN(arr) sizeof arr / sizeof arr[0]

#define ARR_PRINT(size, arr)                                                   \
  printf("[%s] = \n\t{", #arr);                                                \
  for (int i = 0; i < size; i++)                                               \
    printf("%d,", arr[i]);                                                     \
  printf("}\n");

#endif // ARRAY_UTILS_H
