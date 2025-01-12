#include <bits/stdc++.h>

#include <atcoder/all>
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
void dijkstra(const Graph& graph, std::vector<int>& distances, int startIndex) {
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
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  int start(0), goal(0);
  Graph graph1(h * w), graph2(h * w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      if (s[i][j] == 'S') {
        start = i * w + j;
      }
      if (s[i][j] == 'G') {
        goal = i * w + j;
      }
      if ((i + j) % 2 == 0) {
        if (i > 0 && s[i - 1][j] != '#') {
          graph1[i * w + j].push_back({(i - 1) * w + j, 1});
        }
        if (i < h - 1 && s[i + 1][j] != '#') {
          graph1[i * w + j].push_back({(i + 1) * w + j, 1});
        }
        if (j > 0 && s[i][j - 1] != '#') {
          graph2[i * w + j].push_back({i * w + j - 1, 1});
        }
        if (j < w - 1 && s[i][j + 1] != '#') {
          graph2[i * w + j].push_back({i * w + j + 1, 1});
        }
      } else {
        if (j > 0 && s[i][j - 1] != '#') {
          graph1[i * w + j].push_back({i * w + j - 1, 1});
        }
        if (j < w - 1 && s[i][j + 1] != '#') {
          graph1[i * w + j].push_back({i * w + j + 1, 1});
        }
        if (i > 0 && s[i - 1][j] != '#') {
          graph2[i * w + j].push_back({(i - 1) * w + j, 1});
        }
        if (i < h - 1 && s[i + 1][j] != '#') {
          graph2[i * w + j].push_back({(i + 1) * w + j, 1});
        }
      }
    }
  }

  vector<int> dist1(h * w, INF), dist2(h * w, INF);
  dijkstra(graph1, dist1, start);
  dijkstra(graph2, dist2, start);

  if (dist1[goal] == INF && dist2[goal] == INF) {
    cout << -1 << endl;
  } else if (dist1[goal] < dist2[goal]) {
    cout << dist1[goal] << endl;
  } else {
    cout << dist2[goal] << endl;
  }

  return 0;
}
