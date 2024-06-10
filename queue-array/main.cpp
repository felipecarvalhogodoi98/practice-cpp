#include "src/queue.cpp"
#include "src/queue.h"

int main() {
  F::Queue<int> *q = new F::Queue<int>();

  q->print();
  q->enqueue(2);
  q->print();
  q->enqueue(3);
  q->print();
  q->enqueue(4);
  q->print();
  q->enqueue(5);
  q->print();

  std::cout << "->>removed: " << q->dequeue() << std::endl;
  q->print();

  std::cout << "->>removed: " << q->dequeue() << std::endl;
  q->print();

  std::cout << "->>removed: " << q->dequeue() << std::endl;
  q->print();

  std::cout << "->>removed: " << q->dequeue() << std::endl;
  q->print();
  
  q->print();
  q->enqueue(2);
  q->print();
  q->enqueue(3);
  q->print();
  q->enqueue(4);
  q->print();
  q->enqueue(5);
  q->print();

  std::cout << "->>removed: " << q->dequeue() << std::endl;
  q->print();

  return 0;
}