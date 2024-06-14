#ifndef F_BINARY_SEARCH_
#define F_BINARY_SEARCH_

namespace F {
  template <typename T>
  int binary_search(T key, T* array, int min, int max);
  int findMid(int min, int max) { return (min + max) / 2; }
}

#endif