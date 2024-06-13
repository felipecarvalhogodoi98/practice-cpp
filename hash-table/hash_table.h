#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "element.h"

#ifndef F_HASH_TABLE_H
#define F_HASH_TABLE_H

#define initialCapacity 16
#define growthFactor 2
#define shrinkFactor 4

namespace F {
  template<class T>
  class HashTable {
    public:    
      HashTable();
      ~HashTable();
      int hash(int m, std::string key);
      void add(std::string key, T value);
      bool exists(std::string key);
      Element<T>* get(std::string key);
      void remove(std::string key);

      HashTable<T> &operator=(const HashTable<T> &) = delete;
      friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &ht)
      {
        for (int i = 0; i < ht._capacity; i++) {
          Element<T> *el = ht._data[i];

          os << i << ": ";

          if (el == nullptr)
            os << "NULL";

          while (el != nullptr) {
            os << *el;

            el = el->getNext();

            if (el)
              os << " -> ";
          }

          os << std::endl;
        }
        os << "-------------------------" << std::endl;
        return os;
      }

    private:
      Element<T>** _data;
      int _size;
      int _capacity;

      void resize(int newCapacity);
  };
}

#endif 