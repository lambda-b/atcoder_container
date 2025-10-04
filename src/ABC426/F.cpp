#include <bits/stdc++.h>

#include <atcoder/all>

#include "atcoder/lazysegtree.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
ll mapping(ll f, ll s) { return f + s; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

// なぜかlazy_segtreeがうまく動かない.
int main() {
  int n;
  cin >> n;
  lazy_segtree<ll, op, e, ll, mapping, composition, id> a(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.set(i, x);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    ll k;
    cin >> l >> r >> k;
    l--;

    ll s = a.prod(l, r);
    a.apply(0, 2, 1);
    ll t = a.prod(l, r);
    cout << s << endl;
    cout << t << endl;
    cout << a.all_prod() << endl;
    cout << a.prod(0, 2) << endl;
    for (int j = 0; j < n; j++) {
      cout << a.get(j) << (j == n - 1 ? '\n' : ' ');
    }
    for (int j = 0; j < n; j++) {
      cout << a.prod(j, j + 1) << (j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
