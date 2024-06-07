#include <memory>

#ifndef LINKED_LIST
#define LINKED_LIST

namespace F{
template <class T>
class Node {
  public:
    Node(const T &value) : _data(value), _next(nullptr){}
    ~Node() {}
    const T &getData() { return _data; }
    void setData(const T &data) { return _data = data; }
    Node *getNext() { return _next; }
    void setNext(Node<T>* n) { _next = n; }

  private:
    T _data;
    Node* _next; 
};

template <class T>
class List {
  public:
    List();
    ~List();

    // Return list size.
    int size();
    // Return true if list is empty.
    bool empty();
    // Return value at index.
    const T value_at(int index);
    // Return value at index from list end.
    const T value_at_from_end(int index);
    // Push item on front of list.
    void push_front(const T & item);
    // Push item on back of list.
    void push_back(const T & item);
    // Remove item on front of list.
    const T pop_front();
    // Remove item on back of list.
    const T pop_back();
    // Return first item of list.
    const T front();
    // Return last item of list.
    const T back();
    // Insert item at index.
    void insert(int index, const T & item);
    // Remove item at index.
    const T erase(int index);
    // Reverse list
    void reverse();
    // Remove first ocurrency of item.
    void remove(const T & item);

    // Print list
    void print();
    void printDebug();

  private:
    Node<T>* _head; 
};
}

#endif