#include <atcoder/all>
#include <iostream>

#include "atcoder/lazysegtree.hpp"

using namespace atcoder;
using namespace std;

struct model {
  int a;
  int w;
  int v;

  model add(model &other) {
    int a0 = this->a + other.a;
    int w0 = this->w + other.w;
    int v0 = this->v + other.v + (other.w - other.a) * this->a;
    return model{a0, w0, v0};
  }

  model reverse() {
    int a0 = this->w - this->a;
    int w0 = this->w;
    int v0 = this->a * (this->w - this->a) - this->v;
    return model{a0, w0, v0};
  }

  static model op(model lhs, model rhs) { return lhs.add(rhs); }

  static model e() { return model{0, 0, 0}; }
};

struct functional {
  bool b;

  functional(bool b) : b(b){};

  model apply(model &m) { return b ? m.reverse() : m; }

  static model mapping(functional f, model m) { return f.apply(m); }

  static functional composition(functional f, functional g) {
    return functional(f.b != g.b);
  }

  static functional id() { return functional(false); }
};

int main() {
  int n, q;
  cin >> n >> q;

  lazy_segtree<model, model::op, model::e,  //
               functional, functional::mapping, functional::composition,
               functional::id>
      tree(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.set(i, model{a, 1, 0});
  }

  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    l -= 1;
    if (t == 1) {
      tree.apply(l, r, functional(true));
    }

    if (t == 2) {
      model m = tree.prod(l, r);
      cout << m.v << endl;
    }
  }

  return 0;
}
