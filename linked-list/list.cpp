#include <iostream>
#include "list.h"

namespace F {
  template <class T>
  List<T>::List() {
    _head = nullptr;
  }

  template <class T>
  List<T>::~List() {
    Node<T>* current = _head;
    Node<T>* next = _head;

    while (current) {
      next = current->getNext();
      delete current;
      current = next;
    }
  }

  template <class T>
  int List<T>::size() {
    int i = 0;
    Node<T>* aux = _head;

    while (aux != nullptr) {
      i++;
      aux = aux->getNext();
    }
    
    return i;
  }
  
  template <class T>
  bool List<T>::empty() {
    return _head == nullptr;
  }

  template <class T>
  const T List<T>::value_at(int index) {
    Node<T>* node = _head;
    int i = 0;

    while (index != i && node) {
      node = node->getNext();
      i++;
    }

    if (i != index) {
      std::cout << "Index out of bounds." << std::endl;
      exit(EXIT_FAILURE);
    }

    return node->getData();
  }

  template <class T>
  const T List<T>::value_at_from_end(int index) {
    int listSize = size() - 1;
    int n = listSize - index;

    if (n > listSize || n < 0) {
      std::cout << "Index out of bounds." << std::endl;
      exit(EXIT_FAILURE);
    }
    Node<T> *node = _head;
    while (n > 0)
    {
      node = node->getNext();
      n--;
    }

    return node->getData();
  }

  template <class T>
  void List<T>::push_front(const T & item) {
    Node<T>* newNode = new Node<T>(item);
    newNode->setNext(_head);
    _head = newNode;
  }

  template <class T>
  void List<T>::print() {
    Node<T>* aux = _head;
    
    if (aux)
      while (aux) {
        std::cout << aux->getData() << " ";
        aux = aux->getNext();
      }
    else std::cout << "Empty list";
    std::cout << std::endl;
  }

  template <class T>
  void List<T>::printDebug() {
    std::cout << "-----------" << std::endl;
    std::cout << "Size: " << size() << std::endl;
    std::cout << "Empty: " << empty() << std::endl;

    print();
  }

  template <class T>
  void List<T>::push_back(const T & item) {
    if (!_head) {
      Node<T>* newNode = new Node<T>(item);
      _head = newNode;
    } else {
      Node<T>* aux = _head;

      while(aux->getNext()) {
        aux = aux->getNext();
      }

      Node<T>* newNode = new Node<T>(item);
      aux->setNext(newNode);
    }    
  }

  template <class T>
  const T List<T>::pop_front() {
    if (empty()) {
      std::cout << "Cannot pop on empty list." << std::endl;
      exit(EXIT_FAILURE);
    }

    Node<T>* node = _head;
    T data = node->getData();

    _head = node->getNext();
    delete node;

    return data;
  }

  template <class T>
  const T List<T>::pop_back() {
    if (empty()) {
      std::cout << "Cannot pop on empty list." << std::endl;
      exit(EXIT_FAILURE);
    }

    Node<T>* current = _head;
    Node<T>* previous = nullptr;
    
    while (current->getNext()) {
      previous = current;
      current = current->getNext();
    }
    
    T data = current->getData();

    if (previous) {
      previous->setNext(nullptr);
    }

    if (current == _head)
      _head = nullptr;

    delete current;
    return data;
  }

  template <class T>
  const T List<T>::front() {
    if (empty()) {
      std::cout << "Empty list" << std::endl;
      exit(EXIT_FAILURE);
    }

    return _head->getData();
  }

  template <class T>
  const T List<T>::back() {
    if (empty()) {
      std::cout << "Empty list" << std::endl;
      exit(EXIT_FAILURE);
    }

    Node<T> *node = _head;

    while (node->getNext())
      node = node->getNext();


    return node->getData();
  }
  template <class T>
  void List<T>::insert(int index, const T & item) {
    Node<T> *newNode = new Node<T>(item);

    Node<T> *current = _head;
    Node<T> *prev = nullptr;
    int i = 0;

    while (i != index && current) {
      prev = current;
      current = current->getNext();
      i++;
    }

    if (i != index) {
      std::cout << "Index out of bounds." << std::endl;
      exit(EXIT_FAILURE);
    }

    if (prev == nullptr) {
      newNode->setNext(current);
      _head = newNode;
    } else {
      newNode->setNext(current);
      prev->setNext(newNode);
    }
  }

  template<class T>
  const T List<T>::erase(int index) {
    if (empty()) {
      std::cout << "Empty list." << std::endl;
      exit(EXIT_FAILURE);
    }

    int i = 0;
    Node<T> *current = _head;
    Node<T> *previuos = nullptr;

    while (i != index && current) {
      previuos = current;
      current = current->getNext();
      i++;
    }

    if (i != index) {
      std::cout << "Index out of bounds." << std::endl;
      exit(EXIT_FAILURE);
    }

    if (previuos)
      previuos->setNext(current->getNext());
    else
      _head = current->getNext();

    T data = current->getData();
    delete current;
    return data;
  }

  template<class T>
  void List<T>::reverse() {
    Node<T> *previous = nullptr;
    Node<T> *current = _head;
    Node<T> *next = nullptr;

    while (current) {
      next = current->getNext();
      current->setNext(previous);

      previous = current;
      current = next;
    }

    _head = previous;
  }

  template<class T>
  void List<T>::remove(const T & item) {
    int i = 0;
    bool removed = false;
    Node<T> *node = _head;

    while (node && !removed) {
      if (node->getData() == item){
        erase(i);
        removed = true;
      }

      node = node->getNext();
      i++;
    }
  }
}