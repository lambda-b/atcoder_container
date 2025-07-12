#include <bits/stdc++.h>

#include <atcoder/all>
#include <queue>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int n1 = (int)a.size();
  vector<ll> d(n1 - 1);
  for (int i = 1; i < n1; i++) {
    d[i - 1] = a[i] - a[i - 1];
  }

  ll ans = a.back() - a.front();
  sort(d.rbegin(), d.rend());
  for (int i = 0; i < min(n1 - 1, m - 1); i++) {
    ans -= d[i];
  }
  cout << ans << endl;

  return 0;
}
