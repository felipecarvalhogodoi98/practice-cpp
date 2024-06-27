#include "graph.h"

namespace F {
  void Graph::addEdge(int v, int e) {
    graph[v].push_back(e);
  }

  void Graph::_cleanVisiteds() {
    for (auto& pair : visited) {
      pair.second = false;
    }
  }

  void Graph::dfsRecursive(int v) {
    _cleanVisiteds();
    _dfsRecursive(v);
  }

  void Graph::_dfsRecursive(int v) {
    visited[v] = true;

    std::cout << v << " ";

    for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
      if (!visited[*i]) {
        _dfsRecursive(*i);
      }
    }
  }

  void Graph::dfs(int v) {
    _cleanVisiteds();
    visited[v] = true;

    std::cout << v << " ";

    // TODO:
  }
} // namespace F