#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

ll op(const ll a, const ll b) { return a + b; }

ll e() { return 0LL; }

int main() {
  int n;
  ll s;
  cin >> n >> s;

  segtree<ll, op, e> tree(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    tree.set(i, a);
  }

  ll all = tree.all_prod();
  s = s % all;
  ll t = all - s;
  string result = "No";
  for (int i = 0; i < n; i++) {
    int rs = tree.max_right(i, [&](ll v) { return v <= s; });
    int rt = tree.max_right(i, [&](ll v) { return v <= t; });
    if (tree.prod(i, rs) == s) {
      result = "Yes";
      break;
    }
    if (tree.prod(i, rt) == t) {
      result = "Yes";
      break;
    }
  }

  cout << result << endl;

  return 0;
}
