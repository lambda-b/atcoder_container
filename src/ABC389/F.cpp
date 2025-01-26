#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

ll op(ll a, ll b) { return max(a, b); }

ll e() { return 0LL; }

ll mapping(ll f, ll x) { return f + x; }

ll composite(ll f, ll g) { return f + g; }

ll id() { return 0LL; }

constexpr ll LIMIT = 5e5;

int main() {
  int n;
  cin >> n;

  vector<ll> a(LIMIT);
  iota(a.begin(), a.end(), 1LL);
  lazy_segtree<ll, op, e, ll, mapping, composite, id> tree(a);
  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    auto left = tree.max_right(0, [&](ll x) { return x < l; });
    auto right = tree.max_right(0, [&](ll x) { return x <= r; });
    tree.apply(left, right, 1LL);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    ll ans = tree.get(x - 1);
    cout << ans << endl;
  }

  return 0;
}
