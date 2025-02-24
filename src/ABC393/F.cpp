#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>

using namespace std;
using namespace atcoder;

using ll = long long;
using Pair = pair<int, ll>;

/**
 * LIS 最長単調増加部分列のアルゴリズムを使用する
 */
int main() {
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<Pair>> qs(n);
  for (int i = 0; i < q; i++) {
    int r;
    ll x;
    cin >> r >> x;
    qs[--r].push_back({i, x});
  }

  vector<int> ans(q);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    auto e = mp.lower_bound(a[i]);
    auto r = reverse_iterator(e);
    int size = r == mp.rend() ? 1 : 1 + r->second;
    for (auto it = e; it != mp.end() && it->second <= size;) {
      mp.erase(it++);
    }
    mp[a[i]] = size;

    for (auto &[k, x] : qs[i]) {
      auto f = mp.upper_bound(x);
      auto rx = reverse_iterator(f);
      ans[k] = rx->second;
    }
  }

  for (auto &b : ans) {
    cout << b << endl;
  }

  return 0;
}
