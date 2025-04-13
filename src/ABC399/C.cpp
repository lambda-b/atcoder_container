#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using Graph = vector<vector<int>>;

// DFS
void dfs(const Graph &g, int v, int p, vector<bool> &visited, int &cnt) {
  visited[v] = true;
  for (int u : g[v]) {
    if (u == p) continue;
    if (!visited[u]) {
      dfs(g, u, v, visited, cnt);
    } else {
      cnt++;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int cnt = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(g, i, -1, visited, cnt);
    }
  }
  cout << cnt / 2 << endl;

  return 0;
}
