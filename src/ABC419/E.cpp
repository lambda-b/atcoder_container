#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>
#include <numeric>

using namespace std;
using namespace atcoder;

constexpr int INF = numeric_limits<int>::max();

int main() {
  int n, m, l;
  cin >> n >> m >> l;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> f(l, vector<int>(m));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < m; j++) {
      int s = 0;
      for (int k = i; k < n; k += l) {
        s += ((m + j) - a[k]) % m;
      }
      f[i][j] = s;
    }
  }

  vector<int> dp = f[0];
  for (int i = 1; i < l; i++) {
    vector<int> dp0(m, INF);
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        int &x = dp0[(j + k) % m];
        x = min(x, dp[j] + f[i][k]);
      }
    }
    dp = dp0;
  }

  cout << dp[0] << endl;

  return 0;
}
