#include "max-heap.h"

namespace F {
  MaxHeap::MaxHeap(int capacity) {
    _capacity = capacity + 1;
    _size = 0;
    _array = new int[capacity];
  }

  MaxHeap::MaxHeap(int* array, int capacity) {
    _capacity = capacity;
    _size = 0;
    _array = new int[capacity];

    for (int i = 1; i < capacity; i++) {
      _array[i] = array[i];
      _size++;
    }

    for (int i = _size / 2; i >= 1; i--) {
      siftDown(i);
    }
  }

  MaxHeap::~MaxHeap() {
    delete[] _array;
  } 

  void MaxHeap::siftDown(int i) {
    int l = left(i);
    int r = right(i);
    int larger = i;

    if (l <= _size && _array[l] > _array[larger])
      larger = l;
    if (r <= _size && _array[r] > _array[larger])
      larger = r;

    if (larger != i) {
      swap(i, larger);
      siftDown(larger);
    }
  }

  void MaxHeap::insert(int item) {
    if(_size + 1 == _capacity) {
      std::cout << "Cannot insert on full MaxHeap!" << std::endl;
      exit(EXIT_FAILURE);
    }

    _size++;
    _array[_size] = item;
    siftUp(_size);
  }

  int MaxHeap::max() {
    if (_size == 0) {
      std::cout << "Cannot get max on empty MaxHeap!" << std::endl;
      exit(EXIT_FAILURE);
    }
    return _array[1];
  }

  void MaxHeap::remove() {
    remove(1);
  }

  void MaxHeap::remove(int index) {
    if (_size == 0) {
      std::cout << "Cannot remove on empty MaxHeap!" << std::endl;
      exit(EXIT_FAILURE);
    }

    if (_size < index || index < 1) {
      std::cout << "Cannot remove at index!" << std::endl;
      exit(EXIT_FAILURE);
    }

    swap(index, _size);
    _size--;
    siftDown(index);
  }

  void MaxHeap::siftUp(int i) {
    int p = parent(i);

    if (p >= 1 && _array[p] < _array[i]) {
      swap(p, i);
      siftUp(p);
    }
  }

  void MaxHeap::swap(int indexA, int indexB) {
    _array[indexA] = _array[indexA] ^ _array[indexB];
    _array[indexB] = _array[indexA] ^ _array[indexB];
    _array[indexA] = _array[indexA] ^ _array[indexB];
  }

  void MaxHeap::printDebug() {
    if (_size < 1)
      std::cout << "Empty heap.";
    else 
      for (int i = 1; i < _size + 1; i++)
      {
        std::cout << _array[i] << " ";
      }

    std::cout << std::endl;
  }

  void heapify(int* array, int capacity) {
    for (int i = capacity / 2; i >= 0; i--) {
      shiftDown(array, capacity, i);
    }
  }

  void heapSort(int* array, int capacity) {
    int aux;
    for (int i = capacity - 1; i > 0; i--)
    {
      aux = array[i];
      array[i] = array[0];
      array[0] = aux;

      shiftDown(array, i, 0);
    }
  }

  void shiftDown(int *array, int capacity, int i) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int larger = i;

    if (l < capacity && array[l] > array[larger])
      larger = l;
    if (r < capacity && array[r] > array[larger])
      larger = r;

    if (larger != i) {
      int aux = array[larger];
      array[larger] = array[i];
      array[i] = aux;
      shiftDown(array, capacity, larger);
    }
  }
}