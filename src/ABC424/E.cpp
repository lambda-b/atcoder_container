#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int _ = 0; _ < test_cases; _++) {
    int n;
    ll k, x;
    cin >> n >> k >> x;
    map<double, ll> a;
    for (int i = 0; i < n; i++) {
      double a_i;
      cin >> a_i;
      a[a_i] += 1LL;
    }

    while (k > 0) {
      auto [d, c] = *a.rbegin();
      ll y = min(c, k);
      a[d / 2.] += 2 * y;
      a[d] -= y;
      k -= y;
      if (k > 0) {
        a.erase(d);
      }
    }

    for (auto it = a.rbegin(); it != a.rend(); it++) {
      auto [d, c] = *it;
      x -= min(c, x);
      if (x == 0) {
        cout << fixed << setprecision(20) << d << endl;
        break;
      }
    }
  }

  return 0;
}
