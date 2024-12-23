#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

struct Model {
  int c;
  ll s;

  void add(ll x) {
    c += 1;
    s += x;
  }
};

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int k_max = 25;
  ll kk = 1LL;
  vector<ll> cur(k_max + 1, 0LL);
  for (int i = 0; i < k_max; i++) {
    map<ll, Model> mp;
    for (int j = 0; j < n; j++) {
      ll &x = a[j];
      ll key = ((-x % kk) + kk) % kk;
      Model &m1 = mp[key];
      m1.add(x);

      ll key2 = x % kk;
      Model &m2 = mp[key2];
      cur[i] += m2.s + x * m2.c;
    }
    kk *= 2;
  }

  ll ans = 0LL;
  ll val = 1LL;
  for (int i = 0; i < k_max; i++) {
    ans += (cur[i] - cur[i + 1]) / val;
    val *= 2LL;
  }

  cout << ans << endl;

  return 0;
}
