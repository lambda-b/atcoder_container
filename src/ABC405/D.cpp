#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/function.hpp>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/breadth_first_search.hpp"

using namespace std;
using namespace atcoder;

using namespace boost;
struct bfs_predecessor_visitor : public default_bfs_visitor {
  vector<int>& predecessors;

  bfs_predecessor_visitor(vector<int>& predecessors)
      : predecessors(predecessors) {}

  template <typename Edge, typename Graph>
  void tree_edge(Edge e, const Graph& g) {
    auto u = source(e, g);
    auto v = target(e, g);
    predecessors[v] = u;
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& x : s) {
    cin >> x;
  }

  adjacency_list<vecS, vecS, undirectedS> g(h * w + 1);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      if (s[i][j] == 'E') {
        add_edge(i * w + j, h * w, g);
      }
      if (i + 1 < h && s[i + 1][j] != '#') {
        add_edge(i * w + j, (i + 1) * w + j, g);
      }
      if (j + 1 < w && s[i][j + 1] != '#') {
        add_edge(i * w + j, i * w + j + 1, g);
      }
    }
  }

  vector<int> predecessors(h * w + 1, -h * w);

  breadth_first_search(g, vertex(h * w, g),
                       visitor(bfs_predecessor_visitor(predecessors)));

  for (int i = 0; i < h; i++) {
    string val = string(w, '#');
    for (int j = 0; j < w; j++) {
      int up = (i - 1) * w + j;
      int down = (i + 1) * w + j;
      int left = i * w + j - 1;
      int right = i * w + j + 1;
      if (s[i][j] == 'E') {
        val[j] = 'E';
      } else if (predecessors[i * w + j] == up) {
        val[j] = '^';
      } else if (predecessors[i * w + j] == down) {
        val[j] = 'v';
      } else if (predecessors[i * w + j] == left) {
        val[j] = '<';
      } else if (predecessors[i * w + j] == right) {
        val[j] = '>';
      }
    }
    cout << val << endl;
  }

  return 0;
}
