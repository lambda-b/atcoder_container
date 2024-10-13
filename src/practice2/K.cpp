#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using mint = modint998244353;

struct HierarchicalMint {
  mint val;
  int hierarchy;
};

struct Functional {
  mint b;
  mint c;

  Functional(mint b, mint c) : b(b), c(c) {}
  HierarchicalMint apply(HierarchicalMint x) {
    mint hierarchy = x.hierarchy;
    return HierarchicalMint{b * x.val + hierarchy * c, x.hierarchy};
  }
};

HierarchicalMint op(HierarchicalMint a, HierarchicalMint b) {
  return HierarchicalMint{a.val + b.val, a.hierarchy + b.hierarchy};
}

HierarchicalMint e() { return HierarchicalMint{0, 1}; }

HierarchicalMint mapping(Functional f, HierarchicalMint x) {
  return f.apply(x);
}

Functional composition(Functional f, Functional g) {
  return Functional{f.b * g.b, f.b * g.c + f.c};
}

Functional id() { return Functional{1, 0}; }

int main() {
  int n, q;
  cin >> n >> q;

  lazy_segtree<HierarchicalMint, op, e, Functional, mapping, composition, id>
      tree(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.set(i, HierarchicalMint{a, 1});
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
      cout << tree.prod(l, r).val.val() << endl;
    }
  }

  return 0;
}
