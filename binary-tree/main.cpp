#include "binary-tree.cpp"
#include "binary-tree.h"

int main (int argc, char* argv[]) {
  F::BinaryTree<std::string>* bt = new F::BinaryTree<std::string>();

  bt->insert(10, "ten");
  bt->insert(12, "twelve");
  bt->insert(8, "eight");
  bt->insert(150, "hundred fifty");
  bt->insert(1, "one");
  bt->insert(4, "four");
  bt->insert(20, "twenty");
  bt->insert(100, "hundred");
  bt->insert(11, "eleven");
  bt->insert(160, "hundred sixty");
  bt->inOrder();
  std::cout << "Nodes: " << bt->countNodes() << std::endl;
  std::cout << "Height: " << bt->getHeight() << std::endl;
  std::cout << "Min: " << bt->getMin() << std::endl;
  std::cout << "Max: " << bt->getMax() << std::endl;
  std::cout << "Is Binary Tree: " << bt->isBinaryTree() << std::endl;

  bt->print();
  bt->remove(10);
  bt->remove(11);
  bt->remove(100);
  bt->remove(4);
  bt->remove(150);
  bt->remove(8);
  bt->remove(20);
  bt->remove(160);
  bt->remove(12);
  bt->remove(1);
  return 0;
}