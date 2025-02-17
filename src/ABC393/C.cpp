#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  set<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (u == v) {
      continue;
    }
    if (u > v) {
      swap(u, v);
    }
    edges.insert({u, v});
  }

  int e = (int)edges.size();
  cout << m - e << endl;

  return 0;
}
