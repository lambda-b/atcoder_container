#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

/**
 * 約数分割法
 */
mint sum_floor_div(ll n) {
  mint res = 0;
  ll k = 1;
  while (k <= n) {
    ll v = n / k;
    ll next_k = n / v + 1;
    mint count = next_k - k;
    res += count * v;
    k = next_k;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;

  mint n1 = n;
  mint n2 = n1 * n1;

  mint ans = n2 - sum_floor_div(n) - (n1 * (n1 - 1)) / 2;
  cout << ans.val() << endl;

  return 0;
}
