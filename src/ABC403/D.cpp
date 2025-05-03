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
    for (int i = 1; i <= mx; i++) {
      s += max(0, dp[i] - 1);
    }
    cout << s << endl;
    return 0;
  }

  vector<vector<int>> b;
  for (int i = 1; i <= d; i++) {
    vector<int> c;
    for (int j = i; j <= mx; j += d) {
      if (dp[j] > 0) {
        c.push_back(dp[j]);
      } else {
        if ((int)c.size() > 0) {
          b.push_back(c);
        }
        c.clear();
      }
    }
    if ((int)c.size() > 0) {
      b.push_back(c);
    }
  }

  int s = 0;
  for (auto &c : b) {
    int odd = 0;
    int even = 0;
    for (int i = 0; i < (int)c.size(); i++) {
      if (i % 2 == 0) {
        even += c[i];
      } else {
        odd += c[i];
      }
    }

    s += min(odd, even);
  }

  cout << s << endl;

  return 0;
}
