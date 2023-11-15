#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_EQ(got, expected)                                        \
  if (got != expected)                                                  \
  {                                                                     \
    fprintf(stderr, "Assert fail at Line %d. Expected: %d, got: %d.\n", \
            __LINE__, expected, got);                                   \
    exit(EXIT_FAILURE);                                                 \
  }

#define ASSERT_TRUE(got)                                                    \
  if (!got)                                                                 \
  {                                                                         \
    fprintf(stderr,                                                         \
            "Assert fail at Line %d. Expected to be true but got false.\n", \
            __LINE__);                                                      \
    exit(EXIT_FAILURE);                                                     \
  }

#define ASSERT_FALSE(got)                                                   \
  if (got)                                                                  \
  {                                                                         \
    fprintf(stderr,                                                         \
            "Assert fail at Line %d. Expected to be false but got true.\n", \
            __LINE__);                                                      \
    exit(EXIT_FAILURE);                                                     \
  }

#define ASSERT_ARR_EQ(size, expected, got)                                \
  for (int i = 0; i < size; i++)                                          \
    if (expected[i] != got[i])                                            \
    {                                                                     \
      fprintf(stderr, "Assert fail at Line %d. Expected: %d, got: %d.\n", \
              __LINE__, expected[i], got[i]);                             \
      exit(EXIT_FAILURE);                                                 \
    }

#define ASSERT_MAT_EQ(rows, cols, expected, got)                            \
  for (int i = 0; i < rows; i++)                                            \
    for (int j; j < cols; j++)                                              \
      if (expected[i][j] != got[i][j])                                      \
      {                                                                     \
        fprintf(stderr, "Assert fail at Line %d. Expected: %d, got: %d.\n", \
                __LINE__, expected[i][j], got[i][j]);                       \
        exit(EXIT_FAILURE);                                                 \
      }

#endif // TEST_H
