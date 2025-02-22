#include <bits/stdc++.h>

#include <atcoder/all>
#include <cmath>
#include <limits>

using namespace std;
using namespace atcoder;

constexpr int INF = numeric_limits<int>::max();

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
void dijkstra(const Graph& graph, std::vector<long long>& distances,
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
      const long long d = (distances[from] + e->cost);

      // d が現在の記録より小さければ更新
      if (d < distances[e->to]) {
        q.emplace((distances[e->to] = d), e->to);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int m = n * n;
  Graph graph(m + 1);
  for (int i = 0; i < n; i++) {
    graph[m].push_back({i * n + i, 0});
  }
  map<char, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] != '-') {
        graph[m].push_back({i * n + j, 1});
        mp[c[i][j]].push_back({i, j});
      }
    }
  }

  for (auto& e : mp) {
    for (auto& p : e.second) {
      for (auto& q : e.second) {
        int u = p.second * n + q.first;
        int v = p.first * n + q.second;
        graph[u].push_back({v, 2});
      }
    }
  }

  vector<long long> distances(m + 1, INF);
  dijkstra(graph, distances, m);
  for (int i = 0; i < m; i++) {
    if (distances[i] == INF) {
      cout << -1;
    } else {
      cout << distances[i];
    }
    if ((i + 1) % n == 0) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
