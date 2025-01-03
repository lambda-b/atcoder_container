#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n + 1), c(n + m + 1);
  for (auto it = a.begin(); it != a.end(); it++) {
    cin >> *it;
  }
  for (auto it = c.begin(); it != c.end(); it++) {
    cin >> *it;
  }

  vector<ll> b(m + 1);
  for (int i = m; i >= 0; i--) {
    ll s = 0LL;
    for (int j = min(m, i + n); j > i; j--) {
      s += a[i + n - j] * b[j];
    }
    b[i] = (c[i + n] - s) / a[n];
  }

  for (auto it = b.begin(); it < b.end(); it++) {
    if (it != b.begin()) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
