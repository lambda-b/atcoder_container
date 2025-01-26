#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = __int128;

ll sqrt_ll(ll x) {
  assert(x >= 0);
  ll f = x / 2LL;
  ll b = 0LL;
  ll u = x;
  while (f * f > x || (f + 1) * (f + 1) <= x) {
    if (f * f > x) {
      u = f;
      f = (b + u) / 2;
    } else {
      b = f + 1;
      f = (b + u) / 2;
    }
  }
  return f;
}

int main() {
  long long r_value;
  cin >> r_value;
  ll r = (ll)r_value;

  ll cnt = 4LL * (r - 1) + 1;
  for (int i = 1; i < r; i++) {
    ll x = (ll)i;
    ll y = (-1LL + sqrt_ll(4LL * r * r - (2 * x + 1) * (2 * x + 1))) / 2LL;

    cnt += 4LL * y;
  }

  long long ans = (long long)cnt;
  cout << ans << endl;

  return 0;
}
