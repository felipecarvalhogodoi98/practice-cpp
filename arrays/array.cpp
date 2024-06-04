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

  bool Array::isEmpty() {
    return _size == 0;
  }

  int Array::at(int index) {
    if (index < 0 || index >= _size) {
      std::cout << "Index invalid."
                << std::endl;
      exit(EXIT_FAILURE);
    }

    return _data[index];
  }

  void Array::push(int item) {
    resize(_size + 1);

    _data[_size++] = item;
  }

  void Array::insert(int index, int item) {
    if (index < 0 || index >= _size) {
      std::cout << "Index invalid."
                << std::endl;
      exit(EXIT_FAILURE);
    }

    resize(_size + 1);

    for (int i = _size + 1; i > index; i--) {
      _data[i] = _data[i - 1];
    }

    _data[index] = item;
    _size++;
  }

  void Array::prepend(int item) {
    insert(0, item);
  }

  int Array::pop() {
    int item = _data[_size - 1];

    resize(_size - 1);
    --_size;
    
    return item;
  }

  int Array::deleteByIndex(int index) {
    if (index < 0 || index >= _size) {
      std::cout << "Index invalid."
                << std::endl;
      exit(EXIT_FAILURE);
    }
    int item = _data[index];

    for (int i = index; i < _size - 1; i++)
    {
      _data[i] = _data[i + 1];
    }

    resize(_size - 1);
    _size--;

    return item;
  }

  void Array::removeItem(int item) {
    for (int i = 0; i < _size; i++)
    {
      if (_data[i] == item) {
        deleteByIndex(i);
      }
    }
  }

  int Array::findIndex(int item) {
    int i = 0;
    while (i < _size && _data[i] != item)
    {
      i++;
    }

    if (i == _size)
      return -1;

    return i;
  }

  void Array::display() {
    std::cout << "----------------" << std::endl;
    std::cout << "Size: " << _size << std::endl;
    std::cout << "Capacity: " << _capacity << std::endl;
    std::cout << "Data: ";

    for (int i = 0; i < _size; i++)
    {
      std::cout << _data[i] << " ";
    }

    std::cout << std::endl;
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

  void Array::resize(int candidateCapacity) {
    if (candidateCapacity > _capacity) {
      upCapacity(candidateCapacity);
    } else if (_size <= _capacity / shrinkFactor) {
      downCapacity(candidateCapacity);
    }
  }

  void Array::upCapacity(int candidateCapacity) {
    int newCapacity = determineCapacity(candidateCapacity);

    if (_capacity != newCapacity) {
      std::unique_ptr<int[]> newData(new int[newCapacity]);

      for (int i = 0; i < _size; i++) {
        newData[i] = _data[i];
      }

      _data = std::move(newData);
      _capacity = newCapacity;
    }
  }

  void Array::downCapacity(int candidateCapacity) {
    int newCapacity = _capacity / shrinkFactor;

    if (newCapacity >= minCapacity) {
      std::unique_ptr<int[]> newData(new int[newCapacity]);

      for (int i = 0; i < _size; i++) {
        newData[i] = _data[i];
      }

      _data = std::move(newData);
      _capacity = newCapacity;
    }
  }
}