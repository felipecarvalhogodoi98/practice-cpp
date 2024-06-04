#include <iostream>
#include "array.h"

namespace F
{
  Array::Array(int capacity) : _size(0) {
    if (capacity < 1) {
      std::cout << "Cannot initialize vector with capacity < 1\n"
                << std::endl;
    }

    int determinedCapacity = determineCapacity(capacity);

    _capacity = determinedCapacity;
    _data = std::unique_ptr<int[]>(new int[determinedCapacity]);
  }

  Array::~Array() {
    
  }

  int Array::getCapacity() {
    return _capacity;
  }

  int Array::getSize() {
    return _size;
  }

  int Array::determineCapacity(int candidateCapacity) {
    if (candidateCapacity < minCapacity)
      return minCapacity;

    int trueCapacity = 1;
    while (trueCapacity < candidateCapacity)
    {
      trueCapacity *= growthFactor;
    }

    return trueCapacity;
  }
}