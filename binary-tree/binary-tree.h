#include <iostream>
#include <queue>
#include <unordered_map>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

namespace F {
  template <class T>
  class Node {
    public:
      Node(int key, T value) : _key(key), _value(value), _right(nullptr), _left(nullptr) {}
      Node(int key, T value, Node<T>* left, Node<T>* right) : _key(key), _value(value), _right(right), _left(left) {}
      ~Node() {}

      int getKey() {return _key;}
      T getValue() {return _value;}
      Node<T>* getRight() {return _right;}
      Node<T>* getLeft() {return _left;}
      void setKey(int key) { _key = key; }
      void setValue(T value) { _value = value; }
      void setRight(Node<T>* node) { _right = node; }
      void setLeft(Node<T>* node) { _left = node; }

      Node<T> *&operator=(const Node<T> &) = delete;
      friend std::ostream &operator<<(std::ostream &os, const Node<T> &n)
      {
        os << "[" << n.getKey() << ", " << n.getValue() << "]";
        return os;
      }

      friend std::ostream &operator<<(std::ostream &os, Node<T>* n)
      {
        if (n)
          os << "[" << n->getKey() << ", " << n->getValue() << "]";
        else
          os << "null";
        
        return os;
      }

      bool operator<(const Node& other) const {
        return _key < other.getKey();
      }

      bool operator>(const Node& other) const {
        return _key > other.getKey();
      }

      bool operator==(const Node& other) const {
        return _key == other.getKey();
      }

      static int getInvalidKey() { return -1; }

    private:
      int _key;
      T _value;
      Node<T>* _right;
      Node<T>* _left;
  };

  template<class T>
  class BinaryTree {
    public:
      BinaryTree() : root(nullptr) {}
      ~BinaryTree();
      void insert(int key, T value);
      void remove(int key);
      bool search(int key);
      void print();
      void preOrder();
      void inOrder();
      void posOrder();
      int countNodes();
      int getHeight();
      bool isBinaryTree();
      Node<T>* getMin();
      Node<T>* getMax();

      private:
        Node<T>* root;

        bool _search(Node<T>* node, int key);
        Node<T>* _insert(Node<T>* node, int key, T value);
        Node<T>* _remove(Node<T>* node, int key);

        void _preOrder(Node<T>* node);
        void _inOrder(Node<T>* node);
        void _posOrder(Node<T>* node);
        int _countNodes(Node<T>* node);
        int _getHeight(Node<T>* node);
        Node<T>* _getMin(Node<T>* node);
        Node<T>* _getMax(Node<T>* node);
        Node<T>* _getSucessor(Node<T>* node);
        bool _isBinaryTree(Node<T>* node);

        bool isSubTreeLesser(Node<T> *node, int key) { return !node || node->getKey() < key; }
        bool isSubTreeGreater(Node<T> *node, int key) { return !node || node->getKey() > key; }
  };
}

#endif