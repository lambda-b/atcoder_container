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

/**
 * @brief the square root test
 * calculate the maximum value not over square root of x
 */
int main() {
  for (int i = 1; i < 200; i++) {
    cout << i << " " << sqrt_ll(i) << endl;
  }

  return 0;
}
