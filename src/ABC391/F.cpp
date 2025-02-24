#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

ll triplet(ll &a, ll &b, ll &c) { return a * b + b * c + c * a; }

struct model {
  ll val;
  int i, j, k;

  bool operator<(const model &other) const {
    if (val == other.val) {
      if (i != other.i) {
        return i < other.i;
      }
      if (j != other.j) {
        return j < other.j;
      }
      if (k != other.k) {
        return k < other.k;
      }
    }
    return val > other.val;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n), b(n), c(n);
  for (auto &v : a) {
    cin >> v;
  }
  for (auto &v : b) {
    cin >> v;
  }
  for (auto &v : c) {
    cin >> v;
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  set<model> q;
  q.emplace(triplet(a[0], b[0], c[0]), 0, 0, 0);
  for (int l = 1; l < k; l++) {
    auto it = q.begin();
    auto [_, i, j, k] = *it;
    q.erase(it);

    if (i + 1 < (int)a.size()) {
      q.emplace(triplet(a[i + 1], b[j], c[k]), i + 1, j, k);
    }
    if (j + 1 < (int)b.size()) {
      q.emplace(triplet(a[i], b[j + 1], c[k]), i, j + 1, k);
    }
    if (k + 1 < (int)c.size()) {
      q.emplace(triplet(a[i], b[j], c[k + 1]), i, j, k + 1);
    }
  }
  cout << q.begin()->val << endl;

  return 0;
}
