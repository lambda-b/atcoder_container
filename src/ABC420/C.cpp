#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  ll s = 0LL;
  for (int i = 0; i < n; i++) {
    s += min(a[i], b[i]);
  }

  for (int i = 0; i < q; i++) {
    char c;
    int x;
    ll v;
    cin >> c >> x >> v;
    x--;
    s -= min(a[x], b[x]);

    if (c == 'A') {
      a[x] = v;
    }
    if (c == 'B') {
      b[x] = v;
    }
    s += min(a[x], b[x]);
    cout << s << endl;
  }

  return 0;
}
