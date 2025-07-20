#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using Pair = pair<ll, ll>;

int main() {
  ll n;
  cin >> n;
  int m;
  cin >> m;

  vector<Pair> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i].first >> x[i].second;
  }

  map<ll, ll> mp;
  for (auto &[a, b] : x) {
    if (mp.count(a - b)) {
      auto &d = min(mp[a - b], a);
      mp[a - b] = d;
    } else {
      mp[a - b] = a;
    }
  }

  ll cnt = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    auto &[d, a] = *it;
    if (a <= n) {
      ll v = (n - a) / d + 1;
      cnt += v;
      n -= v * d;
    }
  }
  cout << cnt << endl;

  return 0;
}
