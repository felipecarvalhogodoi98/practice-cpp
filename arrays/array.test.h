#ifndef F_ARRAY_TEST_H
#define F_ARRAY_TEST_H

namespace F 
{
  class ArrayTest {
    public:
      void runTests();
      void testSize();
      void testCapacity();
      void testIsEmpty();
      void testPush();
      void testAt();
      void testInsert();
      void testPrepend();
      void testPop();
      void testDelete();
      void testRemove();
      void testFindIndex();
  };
}

#endif