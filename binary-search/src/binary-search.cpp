#include "binary-search.h"

namespace F {
  template <typename T>
  int binary_search(T key, T array[], int min, int max) {
    if (max < min)
      return -1;

    int mid = findMid(min, max);

    if (array[mid] < key)
      return binary_search(key, array, mid + 1, max);
    else if (array[mid] > key)
      return binary_search(key, array, min, mid - 1);

    return mid;
  }
}