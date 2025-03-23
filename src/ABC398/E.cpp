#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

using namespace std;
using namespace atcoder;
using namespace boost;
using namespace graph;
using namespace concepts;

// Custom BFS Visitor to record distances
class bfs_distance_visitor : public default_bfs_visitor {
 public:
  bfs_distance_visitor(std::vector<int> &distances) : distances_(distances) {}

  template <typename Edge, typename Graph>
  void tree_edge(Edge e, const Graph &g) const {
    auto u = source(e, g);
    auto v = target(e, g);
    distances_[v] = distances_[u] + 1;
  }

 private:
  std::vector<int> &distances_;
};

int main() {
  int n;
  cin >> n;

  set<pair<int, int>> edges;
  adjacency_list<vecS, vecS, undirectedS> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    add_edge(u, v, g);
    edges.insert({u, v});
  }

  vector<int> distances(n, -1);
  distances[0] = 0;
  bfs_distance_visitor vis(distances);

  breadth_first_search(g, vertex(0, g), visitor(vis));

  set<pair<int, int>> evens;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (edges.contains({i, j})) {
        continue;
      }
      if (distances[i] % 2 != distances[j] % 2) {
        evens.insert({i + 1, j + 1});
      }
    }
  }
  int size = (int)evens.size();
  if (size % 2 == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
    auto it = evens.begin();
    cout << it->first << " " << it->second << endl;
    evens.erase(it);
  }

  while (true) {
    int u, v;
    cin >> u >> v;
    if (u < 0) {
      break;
    }
    evens.erase({u, v});
    auto it = evens.begin();
    cout << it->first << " " << it->second << endl;
    evens.erase(it);
  }

  return 0;
}
