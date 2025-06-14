#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Node {
  set<int> patterns;
};

// 辺の情報
struct Edge {
  // 行先
  int to;

  // コスト
  int weight;
};

using Graph = vector<vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void dijkstra(const Graph& graph, vector<Node>& nodes, int startIndex) {
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  set<int> q;
  q.emplace(startIndex);

  while (!q.empty()) {
    const int node_index = *q.begin();
    q.erase(q.begin());

    // 現在の頂点からの各辺について
    const auto& from = nodes[node_index];
    auto& edges = graph[node_index];
    for (auto e = edges.begin(); e != edges.end(); e++) {
      // to までの新しい距離
      for (auto& val : from.patterns) {
        const int d = val ^ e->weight;
        auto& to = nodes[e->to];
        if (to.patterns.find(d) == to.patterns.end()) {
          to.patterns.insert(d);
          q.emplace(e->to);
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    graph[a].push_back({b, w});
  }

  vector<Node> nodes(n);
  nodes[0].patterns = {0};
  dijkstra(graph, nodes, 0);

  const auto& target = nodes[n - 1];
  if (target.patterns.empty()) {
    cout << -1 << endl;
  } else {
    cout << *target.patterns.begin() << endl;
  }

  return 0;
}
