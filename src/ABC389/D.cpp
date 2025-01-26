#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

ll sqrt_ll(ll x) {
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

struct Point {
  ll x, y;

  ll double_sq_radius() const {
    return 1LL + 2LL * x + 2LL * x * x + 2LL * y + 2LL * y * y;
  }

  bool operator<(const Point &other) const {
    return double_sq_radius() < other.double_sq_radius();
  }
};

int main() {
  ll r;
  cin >> r;

  ll dsr = 2LL * r * r;

  ll cnt = -3LL;
  for (int i = 0; i < r; i++) {
    ll x = (ll)i;
    ll a = 1LL + 2LL * x + 2LL * x * x;
    ll y = (sqrt_ll(1LL - 2LL * a + 2LL * dsr) - 1LL) / 2LL;
    y = y < x ? y : x;

    cnt += 4LL;
    cnt += 8LL * y;
    if (x == y && y != 0) {
      cnt -= 4LL;
    }
  }

  cout << cnt << endl;

  return 0;
}
