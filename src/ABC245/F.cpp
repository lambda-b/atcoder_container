#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

class Graph {
  vector<vector<int>> adj;

  void depth_first_search(int u, vector<bool> &visited, set<int> &searching,
                          set<int> &target) {
    visited[u] = true;
    searching.insert(u);
    for (int v : adj[u]) {
      if (!visited[v]) {
        depth_first_search(v, visited, searching, target);
      }
      if (searching.find(v) != searching.end() ||
          target.find(v) != target.end()) {
        target.insert(u);
      }
    }
    searching.erase(u);
  }

 public:  //
  Graph(int n) : adj(n) {}

  void add_edge(int u, int v) { adj[u].push_back(v); }

  int depth_first_search() {
    vector<bool> visited(adj.size());
    set<int> searching;
    set<int> target;
    for (int u = 0; u < adj.size(); u++) {
      if (!visited[u]) {
        depth_first_search(u, visited, searching, target);
      }
    }
    return target.size();
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph.add_edge(u - 1, v - 1);
  }

  cout << graph.depth_first_search() << endl;

  return 0;
}
