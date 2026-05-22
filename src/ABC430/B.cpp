#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int toInt(vector<string> &s, int u, int v, int m) {
  int ret = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i + u][j + v] == '#') {
        ret |= (1 << (i * m + j));
      }
    }
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  set<int> patterns;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      int x = toInt(s, i, j, m);
      patterns.insert(x);
    }
  }

  cout << (int)patterns.size() << endl;

  return 0;
}
