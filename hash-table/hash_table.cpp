#include "hash_table.h"

namespace F {
  template<class T>
  HashTable<T>::HashTable () {
    _capacity = initialCapacity;
    _size = 0;
    _data = new Element<T>*[initialCapacity];
    assert(_data != 0);

    for (int i = 0; i < initialCapacity; i++) {
      _data[i] = nullptr;
    }
  }

  template<class T>
  HashTable<T>::~HashTable () {
    for (int i = 0; i < _capacity; i++) {
        Element<T> *item = _data[i];
        Element<T> *next = nullptr;
        _data[i] = nullptr;
        while (item){
          next = item->getNext();
          delete item;
          item = next;
        }
    }

    delete _data;
  }

  template<class T>
  int HashTable<T>::hash(int m, std::string key) {
    int hashValue = 0;

    for (std::string::size_type i = 0; i < key.size(); i++) {
      char caracter = key[i];

      hashValue = hashValue * key[i] + 13;
    }

    return abs(hashValue % m);
  }

  template<class T>
  void HashTable<T>::add(std::string key, T value){
    int hashValue = hash(_capacity, key);
    Element<T> *newElement = new Element<T>(key, value);


    Element<T> *aux = _data[hashValue];
    while (aux && aux->getKey().compare(key) != 0) {
      aux = aux->getNext();
    }

    if (aux && aux->getKey().compare(key) == 0) {
      aux->setValue(value);
      return;
    }
    else
    {
      newElement->setNext(_data[hashValue]);
      _data[hashValue] = newElement;
    }

    _size++;

    if (_size > _capacity) {
      resize(_capacity * growthFactor);
    }
  }

  template<class T>
  void HashTable<T>::remove(std::string key) {
    int hashValue = hash(_capacity, key);
    Element<T> *curr = _data[hashValue];
    Element<T> *prev = nullptr;

    while (curr && key.compare(curr->getKey()) != 0) {
      prev = curr;
      curr = curr->getNext();
    }

    if (curr && key.compare(curr->getKey()) == 0) {
      if (prev == nullptr)
        _data[hashValue] = curr->getNext();
      else
        prev->setNext(curr->getNext());

      delete curr;

      _size--;
    }

    if (_size > 0 && _size < _capacity / shrinkFactor) {
      resize(_capacity / growthFactor);
    }
  }

  template<class T>
  Element<T>* HashTable<T>::get(std::string key){
    int hashValue = hash(_capacity, key);
    Element<T> *el = _data[hashValue];

    while (el && key.compare(el->getKey()) != 0) {
      el = el->getNext();
    }

    return el;
  }

  template<class T>
  bool HashTable<T>::exists(std::string key){
    int hashValue = hash(_capacity, key);
    Element<T> *item = _data[hashValue];

    while (item && key.compare(item->getKey()) != 0) {
      item = item->getNext();
    }

    return (item && key.compare(item->getKey()) == 0);
  }

  template<class T>
  void HashTable<T>::resize(int newCapacity) {
    Element<T>** newData = new Element<T>*[newCapacity];
    Element<T> *curr = nullptr;
    Element<T> *next = nullptr;

    for (int i = 0; i < newCapacity; ++i) {
      newData[i] = nullptr;
    }

    for (int i = 0; i < _capacity; i++)
    {
      curr = _data[i];

      while (curr)
      {
        next = curr->getNext();

        int newHashValue = hash(newCapacity, curr->getKey());

        if (newData[newHashValue] != nullptr)
          curr->setNext(newData[newHashValue]);
        else 
          curr->setNext(nullptr);

        newData[newHashValue] = curr;

        curr = next;
      }

      _data[i] = nullptr;
    }

    delete[] _data;
    _data = newData;
    _capacity = newCapacity;
  }
}