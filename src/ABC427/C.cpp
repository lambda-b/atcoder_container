#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    g[u].push_back(v);
  }

  int p = 1 << (n - 1);

  int ans = m;
  for (int i = 1; i < p; i++) {
    bitset<10> bs(i);

    int cnt = 0;
    for (int j = 0; j < n; j++) {
      for (auto &k : g[j]) {
        if (bs[j] == bs[k]) {
          cnt += 1;
        }
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
