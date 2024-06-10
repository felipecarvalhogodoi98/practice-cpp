#include <iostream>
#include "queue.h"

namespace F {
  template<class T>
  Queue<T>::Queue() : _head(nullptr), _tail(nullptr) { }

  template<class T>
  Queue<T>::~Queue() {
    QueueElement<T> *aux = _head;
    QueueElement<T> *temp = _head;

    while (aux) {
      temp = aux;
      aux = aux->getNext();
      delete temp;
    }
  }

  template<class T>
  bool Queue<T>::empty() {
    return _head == nullptr;
  }

  template<class T>
  void Queue<T>::enqueue(const T &item) {
    QueueElement<T> *newElement = new QueueElement<T>(item);
    
    if (_head == nullptr) {
      _head = _tail = newElement;
    } else {
      newElement->setPrev(_tail);
      _tail->setNext(newElement);
      _tail = newElement;
    }
  }

  template<class T>
  T Queue<T>::dequeue() {
    
    if (empty()) {
      std::cout << "Cannot dequeue from empty queue." << std::endl;
      exit(EXIT_FAILURE);
    }    

    T value = _head->getData();
    QueueElement<T> *aux = _head;

    if (_head == _tail)
    {
      _head = _tail = nullptr;
    }
    else
    {
      _head = _head->getNext();
      _head->setPrev(nullptr);
    }

    delete aux;

    return value;
  }

  template<class T>
  void Queue<T>::print() {
    QueueElement<T> *aux = _head;

    std::cout << "------------" << std::endl;

    if (empty()) {
      std::cout << "Empty queue.";
    }

    while (aux) {
      std::cout << aux->getData() << " ";
      aux = aux->getNext();
    }

    std::cout << std::endl;
  }
}