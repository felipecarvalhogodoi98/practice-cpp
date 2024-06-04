#include <iostream>
#include "array.test.h"
#include "array.test.cpp"

int main(int argc, char *argv[]) {
  F::ArrayTest test;

  test.runTests();
  return 0;
}