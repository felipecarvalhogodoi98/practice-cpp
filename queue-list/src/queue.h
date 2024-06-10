#include "queue_element.h"

#ifndef QUEUE_
#define QUEUE_

namespace F {
  template<class T>
  class Queue {
    public:
      Queue();
      ~Queue();

      void enqueue(const T &item);
      T dequeue();
      bool empty();

      void print();

    private:
      QueueElement<T> *_head;
      QueueElement<T> *_tail;
  };
}

#endif