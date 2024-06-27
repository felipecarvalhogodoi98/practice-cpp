#include <iostream>
#include <map>
#include <list>
#include <queue>

#ifndef GRAPH_H
#define GRAPH_H

namespace F {
  class Graph {
  public:
    std::map<int, bool> visited;
    std::map<int, std::list<int>> graph;

    void addEdge(int v, int e);
    void dfsRecursive(int v);
    void dfs(int v);

  private:
    void _dfsRecursive(int v);
    void _cleanVisiteds();
  };
} // namespace F

#endif