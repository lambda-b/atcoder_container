#include <bits/stdc++.h>

#include <atcoder/all>

#include "atcoder/twosat.hpp"

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  two_sat ts(n);
  for (int i = 1; i < n; i++) {
    if (abs(a[i - 1] - a[i]) > k) {
      ts.add_clause(i - 1, false, i, false);
    }
    if (abs(a[i - 1] - b[i]) > k) {
      ts.add_clause(i - 1, false, i, true);
    }
    if (abs(b[i - 1] - a[i]) > k) {
      ts.add_clause(i - 1, true, i, false);
    }
    if (abs(b[i - 1] - b[i]) > k) {
      ts.add_clause(i - 1, true, i, true);
    }
  }

  cout << (ts.satisfiable() ? "Yes" : "No") << endl;

  return 0;
}
