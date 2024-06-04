#include <memory>

#ifndef F_ARRAY_H // include guard
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
      int getSize();
      int getCapacity();
      bool isEmpty();
      int at(int index);
      void push(int item);
      void insert(int indice, int item);
      void prepend(int item);
      int pop();
      int deleteByIndice(int indice);
      void removeItem(int item);
      int find(int item);

    private:
      int _capacity;
      int _size;
      std::unique_ptr<int[]> _data;
      void resize(int newCapacity);

      int determineCapacity(int candidateCapacity);
  };
}

#endif