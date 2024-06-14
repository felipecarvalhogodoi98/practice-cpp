#include <iostream>
#include <assert.h>

#include "binary-search.test.h"
#include "../src/binary-search.h"
#include "../src/binary-search.cpp"


namespace F {
  void binary_search_test() {
    std::string arrayString[ARRAY_SIZE] = {
      "a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
  
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
      assert(F::binary_search<std::string>(arrayString[i], arrayString, 0, ARRAY_SIZE - 1) == i);
    }

    assert(F::binary_search<std::string>("do not exist", arrayString, 0, ARRAY_SIZE - 1) == -1);
    assert(F::binary_search<std::string>("not exist", arrayString, 0, ARRAY_SIZE - 1) == -1);

    int arrayInt[ARRAY_SIZE] = {
      5, 12, 63, 89, 93, 105, 127, 169, 184, 199};
  
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
      assert(F::binary_search<int>(arrayInt[i], arrayInt, 0, ARRAY_SIZE - 1) == i);
    }

    std::cout << "All tests were successful!" << std::endl;
  }
}