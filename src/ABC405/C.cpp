#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  ll v = a[0];
  ll s = 0LL;
  for (int i = 1; i < n; i++) {
    s += v * a[i];
    v += a[i];
  }

  cout << s << endl;

  return 0;
}
