#include <memory>

#ifndef F_ARRAY_H
#define F_ARRAY_H

int minCapacity = 8;
int growthFactor = 2;
int shrinkFactor = 2;

namespace F 
{
  class Array {
    public:
      Array(int capacity);
      ~Array();
      // Return array size
      int getSize();
      // Return array capacity
      int getCapacity();
      // Return true if array is empty
      bool isEmpty();
      // Return item at index
      int at(int index);
      // Push item on array
      void push(int item);
      // Insert item at index
      void insert(int index, int item);
      // Insert item at index 0
      void prepend(int item);
      // Remove last element
      int pop();
      // Remove element by index
      int deleteByIndex(int index);
      // Remove all item from array
      void removeItem(int item);
      // Find item on array, return first occurency
      int findIndex(int item);
      // Print array
      void display();

    private:
      int _capacity;
      int _size;
      std::unique_ptr<int[]> _data;

      void resize(int newCapacity);
      void upCapacity(int candidateCapacity);
      void downCapacity(int candidateCapacity);
      int determineCapacity(int candidateCapacity);
  };
}

#endif