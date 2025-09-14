#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  int m = *a.rbegin();
  vector<ll> c(m + 1);
  c[0] = 0LL;
  c[1] = 1LL;
  for (int i = 1; i < m; i++) {
    auto it = lower_bound(a.begin(), a.end(), i);
    c[i + 1] = c[i] + (a.end() - it);
  }

  for (int i = 0; i < q; i++) {
    int b;
    cin >> b;

    if (b > m) {
      cout << -1 << endl;
    } else {
      cout << c[b] << endl;
    }
  }

  return 0;
}
