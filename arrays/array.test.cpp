#include "array.test.h"
#include "array.h"
#include "array.cpp" 
#include <iostream>
#include <cassert>

namespace F
{
  void ArrayTest::runTests() {
    testSize();
    testCapacity();
    testIsEmpty();
    testPush();
    testAt();
    testInsert();
    testPrepend();
    testPop();
    testDelete();
    testRemove();
    testFindIndex();
  }

  void ArrayTest::testSize() {
    F::Array arr(3);
    assert(arr.getSize() == 0);

    int items_to_add = 5;
    for (int i = 0; i < items_to_add; ++i) {
      arr.push(i + 1);
    }

    assert(arr.getSize() == items_to_add);
  }

  void ArrayTest::testCapacity() {
    F::Array arr(1);
    assert(arr.getCapacity() == minCapacity);
  }

  void ArrayTest::testIsEmpty() {
    F::Array arr(3);
    assert(arr.isEmpty());
  }

  void ArrayTest::testPush() {
    F::Array arr(3);
    arr.push(1);
    arr.push(2);
    arr.push(3);
    assert(arr.at(0) == 1);
    assert(arr.at(1) == 2);
    assert(arr.at(2) == 3);
  }

  void ArrayTest::testAt() {
    F::Array arr(minCapacity);
    
    arr.push(1);
    arr.push(2);
    arr.push(3);

    assert(arr.at(2) == 3);
  }

  void ArrayTest::testInsert() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity; i++) {
      arr.push(0);
    }
    int index_to_insert = 4;
    int item_to_insert = 12;
    arr.insert(index_to_insert, item_to_insert);

    assert(arr.at(index_to_insert) == item_to_insert);
  }

  void ArrayTest::testPrepend() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity; i++) {
      arr.push(0);
    }
    int item_to_insert = 12;
    arr.prepend(item_to_insert);

    assert(arr.at(0) == item_to_insert);
  }

  void ArrayTest::testPop() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity; i++) {
      arr.push(i);
    }
    
    assert(arr.pop() == minCapacity - 1);
  }

  void ArrayTest::testDelete() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity; i++) {
      arr.push(i);
    }

    arr.deleteByIndex(minCapacity/2);

    assert(arr.findIndex(minCapacity/2) == -1);
  }

  void ArrayTest::testRemove() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity; i++) {
      arr.push(i % 5);
    }
    int item_to_remove = 3;
    arr.removeItem(item_to_remove);

    assert(arr.findIndex(item_to_remove) == -1);
  }

  void ArrayTest::testFindIndex() {
    F::Array arr(minCapacity);

    for (int i = 0; i < minCapacity * 3; i++) {
      arr.push(i);
    }
    int item_to_find = minCapacity * 3;
    
    assert(arr.findIndex(item_to_find) == -1);

    item_to_find = minCapacity * 3 - 6;
    
    assert(arr.findIndex(item_to_find) == item_to_find);
  }
}
