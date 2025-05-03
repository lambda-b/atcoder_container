#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

constexpr int INF = 10000;

int main() {
  int n;
  cin >> n;

  vector<int> c(n);
  vector<int> a(n);

  for (int i = 1; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(n, INF);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= c[i]; j++) {
      if (a[i - j] > 0) {
        dp[i] = 1;
        break;
      } else {
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > 0) {
      ans += dp[i];
    }
  }

  cout << ans << endl;

  return 0;
}
