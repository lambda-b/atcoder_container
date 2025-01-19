#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> b;
  for (int i = n / 2; i < n; i++) {
    b.push_back(a[i]);
  }

  auto it0 = b.begin();
  int k = 0;
  for (int i = 0; i < n / 2; i++) {
    ll &v = a[i];
    auto it = lower_bound(it0, b.end(), 2 * v);
    if (it == b.end()) {
      break;
    }
    k++;
    it0 = next(it);
  }

  cout << k << endl;

  return 0;
}
