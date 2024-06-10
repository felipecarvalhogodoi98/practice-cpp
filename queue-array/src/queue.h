#ifndef QUEUE_
#define QUEUE_

#define sizeQueue 4

namespace F {
  template<class T>
  class Queue {
    public:
      Queue();
      ~Queue();

      void enqueue(T item);
      T dequeue();
      bool empty();
      bool full();

      void print();

    private:
      int _remove;
      int _insert;
      int _capacity;
      T _data[sizeQueue + 1];
  };
}

#endif