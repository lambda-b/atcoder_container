#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      g[n].push_back(i);
    } else {
      g[a - 1].push_back(i);
      g[b - 1].push_back(i);
    }
  }

  // BFS
  vector<int> dist(n + 1, -1);
  dist[n] = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto &nv : g[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        q.push(nv);
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] != -1) {
      cnt += 1;
    }
  }
  cout << cnt << endl;

  return 0;
}
