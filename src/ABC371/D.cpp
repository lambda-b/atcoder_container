#include <algorithm>
#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;
using ll = long long;

ll op(ll lhs, ll rhs) { return lhs + rhs; }

ll e() { return 0LL; }

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  segtree<ll, op, e> tree(n);
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    tree.set(i, p);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int li, ri;
    cin >> li >> ri;
    int l = lower_bound(x.begin(), x.end(), li) - x.begin();
    int r = upper_bound(x.begin(), x.end(), ri) - x.begin();

    ll s = tree.prod(l, r);
    cout << s << endl;
  }

  return 0;
}
