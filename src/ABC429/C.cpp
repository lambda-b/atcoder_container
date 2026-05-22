#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    b[a[i] - 1] += 1;
  }

  ll s = 0LL;
  for (int i = 0; i < n; i++) {
    if (b[i] < 2) {
      continue;
    }

    s += b[i] * (b[i] - 1) / 2 * (n - b[i]);
  }

  cout << s << endl;

  return 0;
}
