#include <bits/stdc++.h>

#include <atcoder/all>

#include "atcoder/lazysegtree.hpp"

using namespace std;
using namespace atcoder;

bool op(bool a, bool b) { return a || b; }
bool e() { return false; }
bool mapping(bool f, bool x) { return f ^ x; }
bool composition(bool f, bool g) { return f ^ g; }
bool id() { return false; }

int main() {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  lazy_segtree<bool, op, e, bool, mapping, composition, id> tree(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;

    tree.apply(l, r, true);
  }

  for (int i = 0; i < n; i++) {
    if (tree.get(i)) {
      cout << t[i];
    } else {
      cout << s[i];
    }
  }
  cout << endl;

  return 0;
}
