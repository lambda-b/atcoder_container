#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

struct Edge {
  int vertex;
  ll weight;
};

class Dfs {
  const vector<vector<Edge>> graph;
  vector<bool> visited;
  vector<ll> x;
  ll energy = 0;

 public:
  Dfs(int n, vector<vector<Edge>> &graph, vector<ll> &x)
      : graph(graph), x(x), visited(n) {}

  void search(int v, int p) {
    visited[v] = true;
    for (auto &u : graph[v]) {
      if (!visited[u.vertex]) {
        search(u.vertex, v);
      }
    }

    for (auto &u : graph[v]) {
      if (u.vertex == p) {
        energy += u.weight * abs(x[v]);
        x[p] += x[v];
        x[v] = 0;
        break;
      }
    }
  }

  ll &get() { return energy; }
};

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  vector<vector<Edge>> graph(n, vector<Edge>());
  for (int i = 1; i < n; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  Dfs dfs(n, graph, x);
  dfs.search(0, -1);
  cout << dfs.get() << endl;

  return 0;
}
