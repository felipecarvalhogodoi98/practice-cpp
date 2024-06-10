#include <iostream>
#include "queue.h"

namespace F {
  template<class T>
  Queue<T>::Queue() 
    : _remove(0), 
    _insert(0), 
    _capacity(sizeQueue + 1) { }

  template<class T>
  Queue<T>::~Queue() { }

  template<class T>
  bool Queue<T>::empty() {
    return _remove == _insert;
  }

  template<class T>
  bool Queue<T>::full() {
    return (_insert + 1) % _capacity == _remove;
  }

  template<class T>
  void Queue<T>::enqueue(T item) {
    if (full()) {
      std::cout << "Cannot enqueue. Full queue!" << std::endl;
      exit(EXIT_FAILURE);
    }

    _data[_insert] = item;
    _insert = (_insert + 1) % _capacity;
  }

  template<class T>
  T Queue<T>::dequeue() {
    if (empty()) {
      std::cout << "Cannot dequeue. Empty queue!" << std::endl;
      exit(EXIT_FAILURE);
    }

    T data = _data[_remove];
    _remove = (_remove + 1) % _capacity;

    return data;
  }

  template<class T>
  void Queue<T>::print() {
    std::cout << "------------------" << std::endl;
    std::cout << "Remove: " << _remove << std::endl;
    std::cout << "Insert: " << _insert << std::endl;
    
    if (!empty())
      for (int i = 0; i < _capacity; i++) {
        if (_remove < _insert) {

          if (i >= _remove && i < _insert)
            std::cout << _data[i] << " ";
          else 
            std::cout << "- ";
        
        } else {

          if (i >= _remove || i < _insert)
            std::cout << _data[i] << " ";
          else 
            std::cout << "- ";
        }
      }
    else
      std::cout << "Empty queue.";

    std::cout << std::endl;
  }
}