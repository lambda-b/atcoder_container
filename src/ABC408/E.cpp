#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

// 辺の情報
struct Edge {
  // 行先
  int to;

  // コスト
  uint label;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<int, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void dijkstra(const Graph& graph, std::vector<uint>& distances,
              int startIndex) {
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  q.emplace((distances[startIndex] = 0), startIndex);

  while (!q.empty()) {
    const long long distance = q.top().first;
    const int from = q.top().second;
    q.pop();

    // 最短距離でなければ処理しない
    if (distances[from] < distance) {
      continue;
    }

    // 現在の頂点からの各辺について
    auto& edges = graph[from];
    for (auto e = edges.begin(); e != edges.end(); e++) {
      // to までの新しい距離
      const uint d = (distances[from] | e->label);

      // d が現在の記録より小さければ更新
      if (d < distances[e->to]) {
        q.emplace((distances[e->to] = d), e->to);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    uint c;
    cin >> u >> v >> c;
    u--;
    v--;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  vector<uint> distances(n, UINT32_MAX);
  distances[0] = 0;
  dijkstra(graph, distances, 0);

  cout << distances[n - 1] << endl;

  return 0;
}
