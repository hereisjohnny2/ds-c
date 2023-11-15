#include "algo/search.h"
#include <assert.h>
#include <stdio.h>

bool linear_search(int size, int *arr, int value)
{
  if (!arr || size == 0)
  {
    return false;
  }

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == value)
    {
      return true;
    }
  }

  return false;
}

bool binary_search(int size, int *arr, int value)
{
  if (!arr || size == 0)
  {
    return false;
  }

  int low = 0, high = size;

  do
  {
    int midpoint = low + (high - low) / 2;
    int v = arr[midpoint];
    if (v == value)
    {
      return true;
    }
    else if (v > value)
    {
      high = midpoint;
    }
    else
    { // High is exclusive
      low = midpoint + 1;
    }
  } while (low < high);

  return false;
}
