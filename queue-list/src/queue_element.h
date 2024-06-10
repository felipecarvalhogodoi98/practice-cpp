#ifndef QUEUE_ELEMENT
#define QUEUE_ELEMENT

namespace F {

  template<class T>
  class QueueElement {
    public:
      QueueElement(const T &data) : _data(data), _next(nullptr), _prev(nullptr) {} 
      ~QueueElement() {}
      QueueElement(const QueueElement &) = delete;
      QueueElement &operator=(const QueueElement &) = default;
      const T &getData() { return _data; }
      QueueElement<T>* getNext() { return _next; }
      QueueElement<T>* getPrev() { return _prev; }
      void setData(const T &data) { _data = data; }
      void setNext(QueueElement<T>* element) { _next = element; }
      void setPrev(QueueElement<T>* element) { _prev = element; }
    private:
      T _data;
      QueueElement<T> *_next;
      QueueElement<T> *_prev;
  };
}

#endif