#include <algorithm>
#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int op_max(int lhs, int rhs) { return max(lhs, rhs); }

int e() { return -1; }

int main() {
  int n, q;
  cin >> n >> q;

  segtree<int, op_max, e> tree(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.set(i, a);
  }

  for (int i = 0; i < q; i++) {
    int t, x, v;
    cin >> t >> x >> v;

    if (t == 1) {
      tree.set(x - 1, v);
    }

    if (t == 2) {
      int ans = tree.prod(x - 1, v);
      cout << ans << endl;
    }

    if (t == 3) {
      int r = tree.max_right(x - 1, [&](int a) { return a < v; });
      cout << r + 1 << endl;
    }
  }

  return 0;
}
