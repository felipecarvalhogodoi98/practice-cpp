#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>

#ifndef GRAPH_H
#define GRAPH_H

namespace F {
  class Graph {
  public:
    std::map<int, bool> visited;
    std::map<int, std::list<int>> graph;
    std::vector<std::vector<int>> graphM;
    int n;

    Graph(int n) : n(n), graphM(n, std::vector<int>(n, 0)) {} 

    // Add an directed edge.
    void addEdge(int v, int e);
    // DFS recursive.
    void dfsRecursive(int v);
    // DFS recursive with matrix.
    void dfsRecursiveM(int v);
    // DFS.
    void dfs(int v);
    // DFS with matrix.
    void dfsM(int v);

    // BFS.
    void bfs(int v);
    // DFS with matrix.
    void bfsM(int v);

  private:
    void _dfsRecursive(int v);
    void _dfsRecursiveM(int v);
    void _cleanVisiteds();
  };
} // namespace F

#endif