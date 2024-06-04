#include <iostream>
#include "array.h"
#include "array.cpp"

int main(int argc, char *argv[]) {
  F::Array arr(10);
  std::cout << arr.getCapacity() << std::endl;
  std::cout << arr.getSize() << std::endl;
}