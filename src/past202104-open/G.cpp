/// https://atcoder.jp/contests/past202104-open/tasks/past202104_g
#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>

#include "atcoder/segtree.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

constexpr ll INF = (1LL << 60);

// 辺の情報
struct Edge {
  // 行先
  int to;

  // コスト
  ll cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

ll op_max(ll a, ll b) { return max(a, b); }

ll e_max() { return -1LL; }

ll op_sum(ll a, ll b) { return a + b; }

ll e_sum() { return 0LL; }

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void custom_dijkstra(const Graph& graph, std::vector<int>& distances,
                     int startIndex, segtree<ll, op_max, e_max>& x) {  //
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
      int d = x.max_right(distances[from], [&](ll v) {  //
        return v < e->cost;
      }) + 1;

      // d が現在の記録より小さければ更新
      if (d < distances[e->to]) {
        q.emplace((distances[e->to] = d), e->to);
      }
    }
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  segtree<ll, op_max, e_max> x(q);
  for (int i = 0; i < q; i++) {
    ll v;
    cin >> v;
    x.set(i, v);
  }

  vector<int> distances(n, q + 1);
  custom_dijkstra(graph, distances, 0, x);

  segtree<ll, op_sum, e_sum> ans(q + 1);
  for (int i = 0; i < n; i++) {
    int p = distances[i];
    if (p <= q) {
      ans.set(p, ans.get(p) + 1);
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans.prod(0, i + 2) << endl;
  }

  return 0;
}
