#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

using namespace std;
using namespace atcoder;

using point = pair<int, int>;

constexpr int INF = numeric_limits<int>::max();

struct Node {
  int lx, rx;
  int ly, ry;
  int dx, dy;

  auto operator<=>(const Node &other) const = default;
};

class Graph {
  vector<string> s;
  point t;
  int h, w;

 public:
  Graph(vector<string> &s, point &t) : s(s), t(t) {
    h = (int)s.size();
    w = (int)s[0].size();
  }

  vector<Node> adjacent(const Node &v) const {
    auto &[x, y] = t;
    int x1 = x + v.dx;
    int y1 = y + v.dy;
    vector<Node> rtn;
    if (!(valid(x1 + 1, y1) && x1 + 1 < v.rx && s[x1 + 1][y1] == '#')) {
      int lx = max(v.dx + 1, v.lx);
      if (lx <= v.rx) {
        rtn.push_back({lx, v.rx, v.ly, v.ry, v.dx + 1, v.dy});
      }
    }
    if (!(valid(x1 - 1, y1) && x1 - 1 >= v.lx && s[x1 - 1][y1] == '#')) {
      int rx = min(h + v.dx - 1, v.rx);
      if (v.lx <= rx) {
        rtn.push_back({v.lx, rx, v.ly, v.ry, v.dx - 1, v.dy});
      }
    }
    if (!(valid(x1, y1 + 1) && y1 + 1 < v.ry && s[x1][y1 + 1] == '#')) {
      int ly = max(v.dy + 1, v.ly);
      if (ly <= v.ry) {
        rtn.push_back({v.lx, v.rx, ly, v.ry, v.dx, v.dy + 1});
      }
    }
    if (!(valid(x1, y1 - 1) && y1 - 1 >= v.ly && s[x1][y1 - 1] == '#')) {
      int ry = min(w + v.dy - 1, v.ry);
      if (v.ly <= ry) {
        rtn.push_back({v.lx, v.rx, v.ly, ry, v.dx, v.dy - 1});
      }
    }
    return rtn;
  }

  bool valid(int x, int y) const { return 0 <= x && x < h && 0 <= y && y < w; }

  int count(Node v) {
    int cnt = 0;
    for (int i = v.lx; i < v.rx; i++) {
      for (int j = v.ly; j < v.ry; j++) {
        if (s[i][j] == '#') {
          cnt += 1;
        }
      }
    }
    return cnt;
  }

  map<Node, int> bfs() {
    Node initial{0, h, 0, w, 0, 0};

    // BFS
    map<Node, int> dist;
    dist[initial] = 0;
    queue<Node> q;
    q.push(initial);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto &nv : adjacent(v)) {
        if (dist.find(nv) == dist.end()) {
          dist[nv] = dist[v] + 1;
          q.push(nv);
        }
      }
    }
    return dist;
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  point t = {-1, -1};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'T') {
        t = {i, j};
      }
    }
  }

  Graph g(s, t);
  map<Node, int> dist = g.bfs();
  int ans = INF;
  for (auto &entry : dist) {
    auto &[v, d] = entry;
    if (g.count(v) == 0) {
      ans = min(ans, d);
    }
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
