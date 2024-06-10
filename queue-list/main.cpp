#include "src/queue.cpp"
#include "src/queue.h"

int main () {
  F::Queue<int>* q = new F::Queue<int>();

  q->print();
  q->enqueue(1);
  
  q->enqueue(2);
  
  q->enqueue(3);
  
  q->enqueue(4);
  q->print();

  std::cout << q->dequeue() << std::endl;
  std::cout << q->dequeue() << std::endl;
  std::cout << q->dequeue() << std::endl;
  std::cout << q->dequeue() << std::endl;

  return 0;
}