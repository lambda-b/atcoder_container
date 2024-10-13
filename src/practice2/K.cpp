#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using mint = modint998244353;

struct Functional {
  mint b;
  mint c;

  Functional(mint b, mint c) : b(b), c(c) {}
  mint apply(mint x) { return b * x + c; }
};

mint op(mint a, mint b) { return a + b; }

mint e() { return 0; }

mint mapping(Functional f, mint x) { return f.apply(x); }

Functional composition(Functional f, Functional g) {
  return Functional(f.b * g.b, f.b * g.c + f.c);
}

Functional id() { return Functional(1, 0); }

int main() {
  int n, q;
  cin >> n >> q;

  lazy_segtree<mint, op, e, Functional, mapping, composition, id> tree(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.set(i, a);
  }

  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      int b, c;
      cin >> b >> c;
      tree.apply(l, r, Functional(b, c));
    }

    if (t == 1) {
      mint ans = tree.prod(l, r);
      cout << ans.val() << endl;
    }
  }

  return 0;
}
