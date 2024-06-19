#include "binary-tree.h"

namespace F {
  template<class T>
  BinaryTree<T>::~BinaryTree() {
    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty())
    {
      Node<T>* aux = q.front();
      q.pop();

      if (aux) {
        q.push(aux->getLeft());
        q.push(aux->getRight());

        aux->setLeft(nullptr);
        aux->setRight(nullptr);

        delete aux;
      }
    }
  }

  template<class T>
  void BinaryTree<T>::insert(int key, T value) {
    root = _insert(root, key, value);
  }

  template<class T>
  void BinaryTree<T>::remove(int key) {
    root = _remove(root, key);
  }

  template<class T>
  Node<T>* BinaryTree<T>::_remove(Node<T>* node, int key) {
    if (!node)
      return nullptr;
    
    else if (key < node->getKey())
      node->setLeft(_remove(node->getLeft(), key));
    else if (key > node->getKey())
      node->setRight(_remove(node->getRight(), key));

    else {
      if (!node->getLeft() && !node->getRight()) {
        delete node;
        return nullptr;
      } 
      else if (!node->getLeft()){
        Node<T> *temp = node;
        node = node->getRight();
        delete temp;
      }
      else if (!node->getRight()){
        Node<T> *temp = node;
        node = node->getLeft();
        delete temp;
      } 
      else {
        Node<T> *temp = _getSucessor(node);
        node->setValue(temp->getValue());
        node->setKey(temp->getKey());
        node->setRight(_remove(node->getRight(), temp->getKey()));
      }
    }

    return node;
  }

  template<class T>
  Node<T>* BinaryTree<T>::_insert(Node<T>* node, int key, T value) {
    if (!node)
      return new Node<T>(key, value);

    if (node->getKey() > key)
      node->setLeft(_insert(node->getLeft(), key, value));

    if (node->getKey() < key)
      node->setRight(_insert(node->getRight(), key, value));

    return node;
  }

  template<class T>
  bool BinaryTree<T>::search(int key) {
    return _search(root, key);
  }

  template<class T>
  bool BinaryTree<T>::_search(Node<T>* node, int key) {
    if (!node)
      return false;

    if (node->getKey() < key)
      return _search(node->getRight(), key);
    if (node->getKey() > key)
      return _search(node->getLeft(), key);

    return true;
  }

  template <class T>
  void BinaryTree<T>::preOrder() {
    _preOrder(root);
    std::cout << std::endl;
  }

  template <class T>
  void BinaryTree<T>::_preOrder(Node<T>* node) {
    if (node) {
      std::cout << node << " ";
      _preOrder(node->getLeft());
      _preOrder(node->getRight());
    }
  }

  template <class T>
  void BinaryTree<T>::inOrder() {
    _inOrder(root);
    std::cout << std::endl;
  }

  template <class T>
  void BinaryTree<T>::_inOrder(Node<T>* node) {
    if (node) {
      _inOrder(node->getLeft());
      std::cout << node << " ";
      _inOrder(node->getRight());
    }
  }

  template <class T>
  void BinaryTree<T>::posOrder() {
    _posOrder(root);
    std::cout << std::endl;
  }

  template <class T>
  void BinaryTree<T>::_posOrder(Node<T>* node) {
    if (node) {
      _posOrder(node->getLeft());
      _posOrder(node->getRight());
      std::cout << node << " ";
    }
  }

  template <class T>
  int BinaryTree<T>::countNodes() {
    return _countNodes(root);
  }

  template <class T>
  int BinaryTree<T>::_countNodes(Node<T>* node) {
    int numNodes = 0;

    if (node)
    {
      numNodes++;
      if (node->getLeft())
        numNodes += _countNodes(node->getLeft());
      if (node->getRight())
        numNodes += _countNodes(node->getRight());
    }

    return numNodes;
  }

  template <class T>
  int BinaryTree<T>::getHeight() {
    return _getHeight(root);
  }

  template <class T>
  int BinaryTree<T>::_getHeight(Node<T>* node) {
    int numNodes = 0;

    if (node)
    {
      numNodes = 1;
      int left = 0, right = 0;
      if (node->getLeft())
        left = _getHeight(node->getLeft());
      if (node->getRight())
        right = _getHeight(node->getRight());

      numNodes += std::max(left, right);
    }

    return numNodes;
  }

  template <class T>
  Node<T>* BinaryTree<T>::getMin() {
    return _getMin(root);
  }

  template <class T>
  Node<T>* BinaryTree<T>::_getMin(Node<T>* node) {
    Node<T> *aux = root;
    Node<T> *prev = nullptr;

    while (aux) {
      prev = aux;
      aux = aux->getLeft();
    }
    
    return prev;
  }


  template <class T>
  Node<T>* BinaryTree<T>::getMax() {
    return _getMax(root);
  }

  template <class T>
  Node<T>* BinaryTree<T>::_getMax(Node<T>* node) {
    Node<T> *aux = root;
    Node<T> *prev = nullptr;

    while (aux) {
      prev = aux;
      aux = aux->getRight();
    }
    
    return prev;
  }

  template <class T>
  Node<T>* BinaryTree<T>::_getSucessor(Node<T>* node) {
    Node<T>* current = node->getRight();
    while (current && current->getLeft()) {
      current = current->getLeft();
    }
    
    return current;
  }

  template <class T>
  bool BinaryTree<T>::isBinaryTree() {
    return _isBinaryTree(root);
  }

  template <class T>
  bool BinaryTree<T>::_isBinaryTree(Node<T>* node) {
    if (!node)
      return true;
    return (
        isSubTreeLesser(node->getLeft(), node->getKey()) && isSubTreeGreater(node->getRight(), node->getKey()) && _isBinaryTree(node->getLeft()) && _isBinaryTree(node->getRight()));
  }

  template <class T>
  void BinaryTree<T>::print() {
    std::unordered_map<int, std::queue<Node<T> *>> levels;
    int level = 0;

    levels[level].push(root);

    while (levels.find(level) != levels.end() && !levels[level].empty()) {
      Node<T> *aux = levels[level].front();
      levels[level].pop();
      if (aux) {
        levels[level + 1].push(aux->getLeft());
        levels[level + 1].push(aux->getRight());
      }

      std::cout << aux << " ";

      if (levels[level].empty()) {
        level++;
        std::cout << std::endl;
      }
    }
  }
}