#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;
using ll = long long;

struct Reference {
  ll value;
  int ref;

  bool operator<(const Reference &other) const { return value < other.value; }
};

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(6));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
    }
  }

  vector<Reference> b(n * 6);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      b[6 * i + j] = {a[i][j], i};
    }
  }

  sort(b.begin(), b.end());
  mint base = ((mint)1) / ((mint)6);

  map<ll, mint> prob;
  vector<int> c(n);
  mint current = 1;
  int zeros = n;
  for (auto &x : b) {
    if (zeros > 0) {
      if (c[x.ref] == 0) {
        zeros -= 1;
      }
      c[x.ref] += 1;

      if (zeros == 0) {
        for (auto &y : c) {
          current *= base * y;
        }
        prob[x.value] = current;
      }
      continue;
    }

    mint bef = c[x.ref];
    mint aft = ++c[x.ref];
    current *= (aft / bef);
    prob[x.value] = current;
  }

  mint bb = 0;
  mint ans = 0;
  for (auto &[x, p] : prob) {
    ans += x * (p - bb);
    bb = p;
  }

  cout << ans.val() << endl;

  return 0;
}
