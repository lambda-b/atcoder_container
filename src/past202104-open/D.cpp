/// https://atcoder.jp/contests/past202104-open/tasks/past202104_d
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll s = 0;
  for (int i = 0; i < k; i++) {
    s += a[i];
  }

  for (int i = 0; i < n - k + 1; i++) {
    cout << s << endl;
    s -= a[i];
    if (k + i != n) s += a[k + i];
  }

  return 0;
}
