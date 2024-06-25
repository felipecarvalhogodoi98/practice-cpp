#include <iostream>
#include "max-heap.cpp"
#include "max-heap.h"

const int size = 10;
const int tam = 50;

int main (int argc, char* argv[]) {
  int array[size] = {1, 20, 21, 12, 18, 85, 17, 22, 27, 60};
  int arraySortedExpected[size] = {1, 12, 17, 18, 20, 21, 22, 27, 60, 85};

  F::MaxHeap *heap = new F::MaxHeap(tam);
  int max = INT32_MAX;

  heap->printDebug();
  heap->insert(20);
  heap->insert(10);
  heap->insert(1);
  heap->insert(100);
  heap->insert(40);
  heap->insert(5);
  heap->insert(17);
  heap->insert(4);
  heap->insert(9);
  heap->insert(15);
  heap->insert(13);
  heap->insert(50);
  heap->insert(max);
  heap->printDebug();

  assert(max == heap->max());

  heap->remove(10);
  heap->printDebug();

  int heapSize = heap->getSize();
  int last = heap->max();
  for (int i = 0; i < heapSize; i++)
  {
    int actual = heap->max();
    heap->remove();

    std::cout << actual << " ";
    // heap->printDebug();
    assert(last >= actual);
    last = actual;
  }
  std::cout << std::endl;

  F::heapify(array, size);
  F::heapSort(array, size);
  std::cout << "Heap Sort" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";

    assert(array[i] == arraySortedExpected[i]);
  }
  std::cout << std::endl;

  return 0;
}