#include <iostream>

#ifndef F_HASH_ELEMENT_H
#define F_HASH_ELEMENT_H

namespace F {
  template<class T>
  class Element {
    public:
      Element(std::string key, const T &value) : _key(key), _value(value), _next(nullptr) {};
      ~Element() { };
      std::string getKey() { return _key; }
      T getValue() { return _value; }
      Element* getNext() { return _next; }

      void setKey(std::string key) { _key = key; }
      void setValue(T value) { _value = value; }
      void setNext(Element<T>* e) { _next = e; }

      Element<T> &operator=(const Element<T> &) = delete;
      friend std::ostream& operator<<(std::ostream& os, const Element<T>& elem) {
        os << "[" << elem._key << ", " << elem._value << "]";
        return os;
      }
    private:
      std::string _key;
      T _value;
      Element *_next;
  };
}

#endif // ELEMENT