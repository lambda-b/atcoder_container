#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

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
void Dijkstra(const Graph& graph, std::vector<long long>& distances,
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
  int h, w, d;
  cin >> h >> w >> d;

  vector<string> s(h);
  vector<int> pos;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'H') {
        pos.push_back(i * w + j);
      }
    }
  }

  Graph graph(h * w + 1);
  for (int i = 0; i < h * w; i++) {
    int r = i / w;
    int c = i % w;

    if (s[r][c] == '#') {
      continue;
    }
    vector<Edge>& edges = graph[i];
    if (r - 1 >= 0 && s[r - 1][c] != '#') {
      int vertex = (r - 1) * w + c;
      edges.push_back({vertex, 1});
    }

    if (r + 1 < h && s[r + 1][c] != '#') {
      int vertex = (r + 1) * w + c;
      edges.push_back({vertex, 1});
    }

    if (c - 1 >= 0 && s[r][c - 1] != '#') {
      int vertex = r * w + c - 1;
      edges.push_back({vertex, 1});
    }

    if (c + 1 < w && s[r][c + 1] != '#') {
      int vertex = r * w + c + 1;
      edges.push_back({vertex, 1});
    }
  }

  vector<Edge>& edges = graph[h * w];
  for (int p : pos) {
    edges.push_back({p, 0});
  }

  vector<ll> distances(h * w, INF);
  Dijkstra(graph, distances, h * w);

  int ans = 0;
  for (int i = 0; i < h * w; i++) {
    if (distances[i] <= d) {
      ans += 1;
    }
  }

  cout << ans << endl;

  return 0;
}
