#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> c(n);
  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;
      c[x].push_back(i);
    }
    d[i] = k;
  }

  int s = 0;
  for (int i = 0; i < m; i++) {
    if (d[i] == 0) {
      s++;
    }
  }

  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    b--;

    for (auto &p : c[b]) {
      d[p]--;
      if (d[p] == 0) {
        s++;
      }
    }
    cout << s << endl;
  }

  return 0;
}
