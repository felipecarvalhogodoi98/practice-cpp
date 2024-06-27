#include <iostream>
#include "graph.h"
#include "graph.cpp"

int main(int argc, char* argv[]) {
  // image_graphs/graph1.png
  F::Graph graph1;

  graph1.addEdge(0, 1);
  graph1.addEdge(0, 2);
  graph1.addEdge(1, 0);
  graph1.addEdge(1, 2);
  graph1.addEdge(1, 3);
  graph1.addEdge(2, 0);
  graph1.addEdge(2, 1);
  graph1.addEdge(2, 4);
  graph1.addEdge(3, 1);
  graph1.addEdge(3, 4);
  graph1.addEdge(3, 5);
  graph1.addEdge(4, 2);
  graph1.addEdge(4, 3);
  graph1.addEdge(4, 5);
  graph1.addEdge(5, 3);
  graph1.addEdge(5, 4);
  int startVertex = 3;
  std::cout << "DFS recursive on graph1 starting at node " << startVertex << std::endl;
  graph1.dfsRecursive(startVertex);
  std::cout << std::endl;

  return 0;
}