#include <bits/stdc++.h>

#include <atcoder/all>
#include <queue>

using namespace std;
using namespace atcoder;

constexpr int INF = 1e9;

pair<int, int> func(vector<pair<int, int>> &dp, const vector<vector<int>> &g,
                    const string &s, int v, int p) {
  if (dp[v].first != INF && dp[v].second != INF) {
    return dp[v];
  }
  if (s[v] == 'S') {
    dp[v] = {0, INF};
  }

  for (int nv : g[v]) {
    if (nv == p) {
      continue;
    }
    auto [x, y] = func(dp, g, s, nv, v);
    vector<int> vec = {x + 1, y + 1, dp[v].first, dp[v].second};
    sort(vec.begin(), vec.end());
    dp[v].first = vec[0];
    dp[v].second = vec[1];
  }

  return dp[v];
}

/**
 * 時間内に解けなかった。
 * おそらく各頂点についてSまでの距離上位2つを求めればよい。
 * それをBFS的に実装したかったが、実装がうまくいかなかった。
 */
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  string s;
  cin >> s;

  vector<pair<int, int>> dp(n, {INF, INF});
  for (int i = 0; i < n; i++) {
    func(dp, g, s, i, -1);
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      cout << dp[i].first + dp[i].second << endl;
    }
  }

  return 0;
}
