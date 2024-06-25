#include <iostream>
#include <assert.h>
#include <random>
#include <unistd.h>
#include "bubble-sort.cpp"
#include "insertion-sort.cpp"
#include "merge-sort.cpp"
#include "quick-sort.cpp"
#include "selection-sort.cpp"

static std::mt19937 generator(std::random_device{}());

int getRandomInt(int max) {
  std::uniform_int_distribution<int> distribution(0, max - 1);
  return distribution(generator);
}

int* getRandomArray(int size, int max) {
  int* array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = getRandomInt(max);
  }

  return array;
}

int main() {
  int max = 9999;
  int size = 100;
  int* array = getRandomArray(size, max);

  // F::bubbleSort(array, size - 1);
  // F::insertionSort(array, size - 1);
  // F::mergeSort(array, 0, size - 1);
  // F::quickSort(array, 0, size - 1);
  F::selectionSort(array, size - 1);

  int last = array[0];
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";

    assert(array[i] >= last);
    last = array[i];
  }

  std::cout << std::endl;
  return 0; 
}