#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

#include "atcoder/segtree.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

constexpr int INF = numeric_limits<int>::max();

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  int ca = 0;
  int cb = 0;

  segtree<int, op, e> seg_a(n);
  segtree<int, op, e> seg_b(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      ca++;
    }
    if (s[i] == 'b') {
      cb++;
    }
    seg_a.set(i, ca);
    seg_b.set(i, cb);
  }

  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    int xa = seg_a.get(i);
    if (xa < a) {
      continue;
    }
    int xb = seg_b.get(i);
    int l = seg_a.min_left(i + 1, [&](int x) { return xa - x < a; });
    int r = seg_b.min_left(i + 1, [&](int x) { return xb - x < b; });

    ans += max(0, l - r);
  }

  cout << ans << endl;

  return 0;
}
