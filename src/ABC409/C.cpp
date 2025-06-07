#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> d(n);
  for (int i = 1; i < n; i++) {
    cin >> d[i];
  }
  if (l % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> p(n);
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + d[i];
    p[i] = p[i] % l;
  }
  sort(p.begin(), p.end());
  vector<ll> counts(l, 0LL);
  for (int i = 0; i < n; i++) {
    counts[p[i]] += 1LL;
  }

  ll cnt = 0LL;
  int dl = l / 3;
  for (int i = 0; i < n; i++) {
    if (p[i] >= dl) {
      break;
    }
    int px = p[i] + dl;
    int py = p[i] + 2 * dl;
    cnt += counts[px] * counts[py];
  }
  cout << cnt << endl;

  return 0;
}
