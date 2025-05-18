#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/visitors.hpp>
#include <iostream>
#include <vector>

struct my_visitor : public boost::default_bfs_visitor {
  std::vector<int>& distances;

  my_visitor(std::vector<int>& d) : distances(d) {}

  template <typename Edge, typename Graph>
  void tree_edge(Edge e, const Graph& g) {
    auto u = boost::source(e, g);
    auto v = boost::target(e, g);
    distances[v] = distances[u] + 1;
  }
};

int main() {
  using namespace boost;
  using Graph = adjacency_list<vecS, vecS, undirectedS>;
  Graph g(5);

  // グラフに辺を追加
  add_edge(0, 1, g);
  add_edge(0, 2, g);
  add_edge(1, 3, g);
  add_edge(1, 4, g);

  std::vector<int> distances(5, -1);
  distances[0] = 0;

  // structureを使ってBFSを実行
  breadth_first_search(g, vertex(0, g), visitor(my_visitor(distances)));

  // 結果表示
  for (int i = 0; i < 5; ++i) {
    std::cout << "vertex " << i << ": distance = " << distances[i] << std::endl;
  }
}