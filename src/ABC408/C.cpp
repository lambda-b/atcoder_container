#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

#include "atcoder/lazysegtree.hpp"

using namespace std;
using namespace atcoder;

int op(int a, int b) { return a + b; }

int e() { return 0; }

int mapping(int f, int s) { return f + s; }

int composition(int f, int s) { return f + s; }

int id() { return 0; }

int main() {
  int n, m;
  cin >> n >> m;

  lazy_segtree<int, op, e, int, mapping, composition, id> seg(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    seg.apply(l, r + 1, 1);
  }

  int min_value = INT_MAX;
  for (int i = 0; i < n; i++) {
    min_value = min(min_value, seg.get(i));
  }

  cout << min_value << endl;

  return 0;
}
