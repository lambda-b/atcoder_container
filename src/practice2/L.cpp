#include <atcoder/all>
#include <iostream>

#include "atcoder/lazysegtree.hpp"

using namespace atcoder;
using namespace std;

struct model {
  /** 区間内の1の個数 */
  long a;

  /** 区間の幅 - (w - a)で0の個数になる */
  long w;

  /** 区間の転倒数 */
  long v;

  model add(model &other) const {
    long a0 = this->a + other.a;
    long w0 = this->w + other.w;
    long v0 = this->v + other.v + (other.w - other.a) * this->a;
    return model{a0, w0, v0};
  }

  model reverse() const {
    long a0 = this->w - this->a;
    long w0 = this->w;
    long v0 = this->a * (this->w - this->a) - this->v;

    return model{a0, w0, v0};
  }

  static model op(model lhs, model rhs) { return lhs.add(rhs); }

  static model e() { return model{0, 0, 0}; }
};

struct functional {
  /** 反転するかどうか */
  bool b;

  functional(bool b) : b(b){};

  model apply(model &m) const { return b ? m.reverse() : m; }

  static model mapping(functional f, model m) { return f.apply(m); }

  static functional composition(functional f, functional g) {
    return functional(f.b != g.b);
  }

  static functional id() { return functional(false); }
};

int main() {
  long n, q;
  cin >> n >> q;

  lazy_segtree<model, model::op, model::e,  //
               functional, functional::mapping, functional::composition,
               functional::id>
      tree(n);

  for (long i = 0; i < n; i++) {
    long a;
    cin >> a;
    tree.set(i, model{a, 1, 0});
  }

  for (long i = 0; i < q; i++) {
    long t, l, r;
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
