#include <iostream>
#include "graph.h"
#include "graph.cpp"

void runTest(F::Graph g, std::string name, int start) {
  std::cout << "-----------------------" << name <<  "---------------------" << std::endl;
  
  std::cout << "DFS------------------------------" << std::endl;
  std::cout << "DFS recursive on " << name <<  " starting at node " << start << std::endl;
  g.dfsRecursive(start);
  std::cout << "DFS on " << name <<  "  starting at node " << start << std::endl;
  g.dfsRecursive(start);
  std::cout << "DFS matrix on " << name <<  "  starting at node " << start << std::endl;
  g.dfsM(start);
  std::cout << "DFS matrix recursive on " << name <<  " starting at node " << start << std::endl;
  g.dfsRecursiveM(start);

  std::cout << "BFS------------------------------" << std::endl;
  std::cout << "BFS on  " << name <<  "  starting at node " << start << std::endl;
  g.bfs(start);
  std::cout << "BFS matrix on  " << name <<  "  starting at node " << start << std::endl;
  g.bfsM(start);
}

int main(int argc, char* argv[]) {
  // image_graphs/graph_1.png
  F::Graph graph1(6);

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

  runTest(graph1, "graph1", 2);

  // image_graphs/graph_2.png
  F::Graph graph2(11);

  graph2.addEdge(0, 1);
  graph2.addEdge(0, 2);
  graph2.addEdge(1, 3);
  graph2.addEdge(1, 4);
  graph2.addEdge(2, 5);
  graph2.addEdge(2, 6);
  graph2.addEdge(3, 7);
  graph2.addEdge(4, 8);
  graph2.addEdge(4, 9);
  graph2.addEdge(5, 10);

  runTest(graph2, "graph2", 0);
  return 0;
}