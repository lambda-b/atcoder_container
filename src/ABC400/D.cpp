#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

#include "boost/graph/graph_selectors.hpp"
#include "boost/pending/property.hpp"

using namespace std;
using namespace atcoder;
using namespace boost;

using ll = long long;
using graph_t = adjacency_list<listS, vecS, directedS, no_property,
                               property<edge_weight_t, ll>>;
using vertex_descriptor = graph_traits<graph_t>::vertex_descriptor;
using edge_descriptor = graph_traits<graph_t>::edge_descriptor;
using weight_map_t = property_map<graph_t, edge_weight_t>::type;

void add_edge(int u, int v, ll weight, graph_t &g, weight_map_t &weight_map) {
  edge_descriptor e;
  bool inserted;
  tie(e, inserted) = add_edge(u, v, g);
  if (inserted) {
    weight_map[e] = weight;
  }
}

/**
 * @see
 * https://boostjp.github.io/archive/boost_docs/libs/graph/examples/dijkstra-example.cpp.html
 */
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  pair<int, int> start, goal;
  cin >> start.first >> start.second;
  cin >> goal.first >> goal.second;
  start.first--;
  start.second--;
  goal.first--;
  goal.second--;

  graph_t g(h * w);
  weight_map_t weight_map = get(edge_weight, g);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i > 0) {
        if (s[i - 1][j] == '#') {
          add_edge(i * w + j, (i - 1) * w + j, 1, g, weight_map);
          if (i > 1) {
            add_edge(i * w + j, (i - 2) * w + j, 1, g, weight_map);
          }
        } else {
          add_edge(i * w + j, (i - 1) * w + j, 0, g, weight_map);
        }
      }
      if (i < h - 1) {
        if (s[i + 1][j] == '#') {
          add_edge(i * w + j, (i + 1) * w + j, 1, g, weight_map);
          if (i < h - 2) {
            add_edge(i * w + j, (i + 2) * w + j, 1, g, weight_map);
          }
        } else {
          add_edge(i * w + j, (i + 1) * w + j, 0, g, weight_map);
        }
      }
      if (j > 0) {
        if (s[i][j - 1] == '#') {
          add_edge(i * w + j, i * w + (j - 1), 1, g, weight_map);
          if (j > 1) {
            add_edge(i * w + j, i * w + (j - 2), 1, g, weight_map);
          }
        } else {
          add_edge(i * w + j, i * w + (j - 1), 0, g, weight_map);
        }
      }
      if (j < w - 1) {
        if (s[i][j + 1] == '#') {
          add_edge(i * w + j, i * w + (j + 1), 1, g, weight_map);
          if (j < w - 2) {
            add_edge(i * w + j, i * w + (j + 2), 1, g, weight_map);
          }
        } else {
          add_edge(i * w + j, i * w + (j + 1), 0, g, weight_map);
        }
      }
    }
  }

  vector<vertex_descriptor> predecessors(num_vertices(g));
  vector<ll> distances(num_vertices(g), -1);
  int start_vertex = start.first * w + start.second;
  dijkstra_shortest_paths(
      g, start_vertex,
      predecessor_map(&predecessors[0]).distance_map(&distances[0]));

  cout << distances[goal.first * w + goal.second] << endl;

  return 0;
}
