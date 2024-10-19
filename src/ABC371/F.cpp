#include <atcoder/all>
#include <iostream>
#include <limits>

using namespace atcoder;
using namespace std;

using ll = long long;

struct model {
  int w;

  ll val;

  ll xms, xmx;

  model(ll val) : w(1), val(val), xms(val), xmx(val) {}

  model(int w, ll val, ll xms, ll xmx) : w(w), val(val), xms(xms), xmx(xmx) {}

  model add(model &other) const {
    ll xms = min(this->xms, other.xms);
    ll xmx = max(this->xmx, other.xmx);
    return model{this->w + other.w, this->val + other.val, xms, xmx};
  }

  static model e() {
    return model{0, 0LL,                                                   //
                 numeric_limits<int>::max(), numeric_limits<int>::min()};  //
  }

  static model op(model lhs, model rhs) { return lhs.add(rhs); }
};

struct functional {
  bool b;
  ll val;

  model apply(model &m) const {
    return this->b ? model{m.w, this->val * m.w, val, val} : m;
  }
  static model mapping(functional f, model m) { return f.apply(m); }

  static functional composition(functional f1, functional f2) {
    return f1.b ? f1 : f2;
  }

  static functional id() { return functional{false, 0LL}; }
};

int main() {
  int n;
  cin >> n;

  lazy_segtree<model, model::op, model::e,               //
               functional, functional::mapping,          //
               functional::composition, functional::id>  //
      tree(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    model m = x - i;
    tree.set(i, m);
  }

  int q;
  cin >> q;

  ll cost = 0;
  for (int i = 0; i < q; i++) {
    int t;
    ll g;
    cin >> t >> g;
    t--;
    g -= t;

    model m = tree.get(t);
    if (m.val < g) {
      int r = tree.max_right(t, [g](model m) { return m.xmx < g; });
      cost += g * (r - t) - tree.prod(t, r).val;

      tree.apply(t, r, functional{true, g});
    } else {
      int l = tree.min_left(t, [g](model m) { return g < m.xms; });
      cost += tree.prod(l, t + 1).val - g * (t - l + 1);

      tree.apply(l, t + 1, functional{true, g});
    }
  }

  cout << cost << endl;

  return 0;
}
