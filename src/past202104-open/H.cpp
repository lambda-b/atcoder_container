/// https://atcoder.jp/contests/past202104-open/tasks/past202104_h
#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = unsigned long long;

int main() {
  int n, m, k;
  ll q;
  cin >> n >> m >> k >> q;

  vector<ll> a, b;
  for (int i = 0; i < n; i++) {
    ll p;
    int t;
    cin >> p >> t;

    if (t == 1) {
      a.push_back(p);
    } else {
      b.push_back(p);
    }
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> bb;
  int size_b = b.size();
  for (int i = 0; i < min(size_b, m); i++) {
    bb.push_back(b[i]);
  }

  int size_a = a.size();

  ll s = 0LL;
  for (auto v : bb) {
    s += v;
  }

  int c = 0;
  for (int i = size_b; i < m; i++) {
    if (c % k == 0) {
      s += q;
    }
    s += a[c++];
  }

  auto itb = bb.rbegin();
  ll ans = s;
  for (int i = c; i < size_a && itb != bb.rend(); i++) {
    if (i % k == 0) {
      s += q;
    }
    s += a[i];
    s -= *itb;
    itb++;

    ans = min(ans, s);
  }

  cout << ans << endl;

  return 0;
}
