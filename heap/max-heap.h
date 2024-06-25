#include <iostream>
#include <assert.h>

#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

namespace F {
  class MaxHeap {
    public:
      MaxHeap(int capacity);
      MaxHeap(int *array, int capacity);
      ~MaxHeap();
      MaxHeap(const MaxHeap &) = delete;
      MaxHeap &operator=(const MaxHeap &) = delete;
      int getSize() { return _size; }
      int getCapcity() { return _capacity; }
      // Insert an item on max heap.
      void insert(int item);
      // Return max element.
      int max();
      // Remove max element.
      void remove();
      // Remove at index.
      void remove(int index);
      
      void printDebug();

    private:
      int *_array;
      int _capacity;
      int _size;

      // Return the element on left side of the i
      int left(int i) { return i * 2; }
      // Return the element on right side of the i
      int right(int i) { return i * 2 + 1; }
      // Return parent of i
      int parent(int i) { 
        if (i > 0)
          return i / 2;
        return 0;
      }
      // Swap two values on array.
      void swap(int indexA, int indexB);
      // Recursively fix sub-tree moving up a heap
      void siftUp(int i);
      // Recursively fix sub-tree moving down a heap
      void siftDown(int i);
  };

  void heapify(int *array, int capacity);
  void heapSort(int *array, int capacity);
  void shiftDown(int *array, int capacity, int i);
}


#endif