#include "graph.h"

namespace F {
  void Graph::addEdge(int v, int e) {
    graphM[v][e] = 1;
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
    std::cout << std::endl;
  }

  void Graph::dfsRecursiveM(int v) {
    _cleanVisiteds();
    _dfsRecursiveM(v);
    std::cout << std::endl;
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

  void Graph::_dfsRecursiveM(int v) {
    visited[v] = true;

    std::cout << v << " ";

    for (auto i = 0; i < n; i++) {
      if (graphM[v][i] != 0) {
        if (!visited[i]) {
          _dfsRecursive(i);
        }
      }
      
    }
  }

  void Graph::dfs(int v) {
    _cleanVisiteds();

    std::stack<int> s;
    
    visited[v] = true;
    s.push(v);

    while (!s.empty()) {
      int vertex = s.top();
      s.pop();
      std::cout << vertex << " ";

      for (auto& neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          s.push(neighbor);
        }
      }
    }

    std::cout << std::endl;
  }

  void Graph::dfsM(int v) {
    _cleanVisiteds();

    std::stack<int> s;
    
    visited[v] = true;
    s.push(v);

    while (!s.empty()) {
      int vertex = s.top();
      s.pop();
      std::cout << vertex << " ";

      for (int i = n - 1; i >= 0;  i--) {
        if (graphM[vertex][i] != 0)
          if (!visited[i]) {
            visited[i] = true;
            s.push(i);
          }
      }
    }

    std::cout << std::endl;
  }

  void Graph::bfs(int v) {
    _cleanVisiteds();

    std::queue<int> q;
    
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
      int vertex = q.front();
      q.pop();
      std::cout << vertex << " ";

      for (auto& neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }

    std::cout << std::endl;
  }

  void Graph::bfsM(int v) {
    _cleanVisiteds();

    std::queue<int> q;

    visited[v] = true;
    q.push(v);

    while(!q.empty()) {
      int vertex = q.front();
      q.pop();

      std::cout << vertex << " ";

      for (int i = 0; i < n; i++) {
        if (graphM[vertex][i] != 0)
          if (!visited[i]) {
            visited[i] = true;
            q.push(i);
          }
      }
    }

    std::cout << std::endl;
  }
} // namespace F