#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

#include "atcoder/segtree.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();

ll e() { return INF; }

ll op(ll a, ll b) { return min(a, b); }

int main() {
  int n;
  cin >> n;

  ll m;
  cin >> m;

  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  segtree<ll, op, e> tree(n);
  for (int i = 0; i < n; i++) {
    tree.set(i, p[i]);
  }

  int cnt = 0;
  while (true) {
    ll mm = tree.all_prod();
    if (mm > m) {
      break;
    }
    m -= mm;
    cnt += 1;

    int idx = tree.max_right(0, [mm](ll x) { return x > mm; });
    tree.set(idx, mm + 2LL * p[idx]);
  }

  cout << cnt << endl;

  return 0;
}
