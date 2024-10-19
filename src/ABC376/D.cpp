#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using ll = long long;

constexpr ll INF = (1LL << 60);

// 辺の情報
struct Edge {
  // 行先
  int to;

  // コスト
  int cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
ll Dijkstra(const Graph& graph, std::vector<long long>& distances,
            int startIndex) {
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  q.emplace((distances[startIndex] = 0), startIndex);

  ll start_d = INF;

  while (!q.empty()) {
    const long long distance = q.top().first;
    const int from = q.top().second;
    q.pop();

    // 最短距離でなければ処理しない
    if (distances[from] < distance) {
      continue;
    }

    // 現在の頂点からの各辺について
    for (const auto& edge : graph[from]) {
      // to までの新しい距離
      const long long d = (distances[from] + edge.cost);
      if (edge.to == startIndex) {
        start_d = min(d, start_d);
      }

      // d が現在の記録より小さければ更新
      if (d < distances[edge.to]) {
        q.emplace((distances[edge.to] = d), edge.to);
      }
    }
  }
  return start_d;
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    graph[s].push_back({t, 1});
  }

  vector<ll> distances(n, INF);
  ll d = Dijkstra(graph, distances, 0);

  cout << (d == INF ? -1 : d) << endl;

  return 0;
}
