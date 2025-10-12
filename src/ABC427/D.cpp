#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

string func(vector<vector<int>> &g, string &s, bool pattern) {
  int n = (int)g.size();
  string t = string(n, '*');
  for (int i = 0; i < n; i++) {
    if (pattern) {
      bool a = all_of(g[i].begin(), g[i].end(),
                      [&s](const int &e) { return s[e] == 'A'; });
      t[i] = a ? 'A' : 'B';
    } else {
      bool b = all_of(g[i].begin(), g[i].end(),
                      [&s](const int &e) { return s[e] == 'B'; });
      t[i] = b ? 'B' : 'A';
    }
  }
  return t;
}

int main() {
  int test_cases;
  cin >> test_cases;

  for (int _ = 0; _ < test_cases; _++) {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
    }

    bool pattern = true;
    for (int i = 0; i < 2 * k; i++) {
      s = func(g, s, pattern);
      pattern = !pattern;
    }
    string ans = s[0] == 'A' ? "Alice" : "Bob";
    cout << ans << endl;
  }

  return 0;
}
