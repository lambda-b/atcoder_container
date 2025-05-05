#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  int mx = 0;
  for (auto &x : a) {
    cin >> x;
    mx = max(mx, x);
  }

  vector<int> dp(mx + 1, 0);
  for (int i = 0; i < n; i++) {
    dp[a[i]]++;
  }

  if (d == 0) {
    int s = 0;
    for (int i = 0; i <= mx; i++) {
      s += max(0, dp[i] - 1);
    }
    cout << s << endl;
    return 0;
  }

  int s = 0;
  for (int i = 0; i < d; i++) {
    int p1 = 0;
    int p2 = 0;
    for (int j = i + d; j <= mx; j += d) {
      int tmp = p1;
      p1 = min(p1 + dp[j], p2 + dp[j - d]);
      p2 = tmp;
    }
    s += p1;
  }

  cout << s << endl;

  return 0;
}
