#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

class Graph {
  vector<vector<int>> _graph;
  vector<int> _dist;
  int h, w;

 public:
  Graph(int h, int w) : _graph(2 * h * w), _dist(2 * h * w, -1), h(h), w(w) {}
  void add_edge(pair<int, int> s, pair<int, int> t, int layer) {
    auto &[x1, y1] = s;
    auto &[x2, y2] = t;
    int s0 = x1 * w + y1 + layer * h * w;
    int t0 = x2 * w + y2 + layer * h * w;
    _graph[s0].push_back(t0);
    _graph[t0].push_back(s0);
  }

  void add_edge_switch(pair<int, int> s, pair<int, int> t, int layer) {
    auto &[x1, y1] = s;
    auto &[x2, y2] = t;
    int s0 = x1 * w + y1 + layer * h * w;
    int t0 = x2 * w + y2 + layer * h * w;
    int t1 = (t0 + h * w) % (2 * h * w);
    _graph[s0].push_back(t1);
    _graph[t0].push_back(s0);
  }

  void add_edge_s_to_s(pair<int, int> s, pair<int, int> t) {
    auto &[x1, y1] = s;
    auto &[x2, y2] = t;
    int s0 = x1 * w + y1;
    int s1 = s0 + h * w;
    int t0 = x2 * w + y2;
    int t1 = t0 + h * w;
    _graph[s0].push_back(t1);
    _graph[t1].push_back(s0);
    _graph[s1].push_back(t0);
    _graph[t0].push_back(s1);
  }

  void bfs(pair<int, int> s) {
    auto &[x, y] = s;
    int start = x * w + y;
    _dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &nv : _graph[v]) {
        if (_dist[nv] == -1) {
          _dist[nv] = _dist[v] + 1;
          q.push(nv);
        }
      }
    }
  }

  int dist(pair<int, int> t) {
    auto &[x, y] = t;
    int target0 = x * w + y;
    int target1 = target0 + h * w;
    if (_dist[target0] == -1) {
      return _dist[target1];
    }
    if (_dist[target1] == -1) {
      return _dist[target0];
    }
    return min(_dist[target0], _dist[target1]);
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  pair<int, int> start, goal;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'S') {
        start = {i, j};
      }
      if (a[i][j] == 'G') {
        goal = {i, j};
      }
    }
  }

  Graph g(h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      vector<pair<int, int>> c = {{i - 1, j}, {i, j - 1}};
      if (a[i][j] == '.' || a[i][j] == 'S' || a[i][j] == 'G') {
        for (auto p : c) {
          auto &[x, y] = p;
          if (x < 0 || x >= h || y < 0 || y >= w) {
            continue;
          }
          switch (a[x][y]) {
            case '#':
              break;
            case 'o':
              g.add_edge({i, j}, {x, y}, 0);
              break;
            case 'x':
              g.add_edge({i, j}, {x, y}, 1);
              break;
            case '?':
              g.add_edge_switch({i, j}, {x, y}, 0);
              g.add_edge_switch({i, j}, {x, y}, 1);
              break;
            default:
              g.add_edge({i, j}, {x, y}, 0);
              g.add_edge({i, j}, {x, y}, 1);
              break;
          }
        }
      }
      if (a[i][j] == 'o') {
        for (auto p : c) {
          auto &[x, y] = p;
          if (x < 0 || x >= h || y < 0 || y >= w) {
            continue;
          }
          switch (a[x][y]) {
            case '#':
            case 'x':
              break;
            case '?':
              g.add_edge_switch({i, j}, {x, y}, 0);
              break;
            default:
              g.add_edge({i, j}, {x, y}, 0);
              break;
          }
        }
      }

      if (a[i][j] == 'x') {
        for (auto p : c) {
          auto &[x, y] = p;
          if (x < 0 || x >= h || y < 0 || y >= w) {
            continue;
          }
          switch (a[x][y]) {
            case '#':
            case 'o':
              break;
            case '?':
              g.add_edge_switch({i, j}, {x, y}, 1);
              break;
            default:
              g.add_edge({i, j}, {x, y}, 1);
              break;
          }
        }
      }
      if (a[i][j] == '?') {
        for (auto p : c) {
          auto &[x, y] = p;
          if (x < 0 || x >= h || y < 0 || y >= w) {
            continue;
          }
          switch (a[x][y]) {
            case '#':
              break;
            case 'o':
              g.add_edge_switch({x, y}, {i, j}, 0);
              break;
            case 'x':
              g.add_edge_switch({x, y}, {i, j}, 1);
              break;
            case '?':
              g.add_edge_s_to_s({i, j}, {x, y});
              break;
            default:
              g.add_edge_switch({x, y}, {i, j}, 0);
              g.add_edge_switch({x, y}, {i, j}, 1);
              break;
          }
        }
      }
    }
  }

  g.bfs(start);
  cout << g.dist(goal) << endl;

  return 0;
}
