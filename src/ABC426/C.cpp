#include <bits/stdc++.h>

#include <atcoder/all>

#include "atcoder/fenwicktree.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  fenwick_tree<ll> fw(n);
  for (int i = 0; i < n; i++) {
    fw.add(i, 1);
  }

  int v = 0;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if (x < v) {
      cout << 0 << endl;
      continue;
    }

    ll s = fw.sum(v, x + 1);
    cout << s << endl;
    fw.add(y, s);
    v = x + 1;
  }

  return 0;
}
