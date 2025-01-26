#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = unsigned __int128;

/**
 * 二分探索
 * sup{v in ll | g(v) <= x} を返す
 */
template <class G>
ll binary_search(ll x, G g, ll upper_limit) {
  ll u = upper_limit;
  ll b = 0;
  ll v = (u + b) / 2;

  while (true) {
    if (g(v) > x) {
      u = v;
      v = (u + b) / 2;
      continue;
    }
    if (g(v + 1) <= x) {
      b = v;
      v = (u + b) / 2;
      continue;
    }
    return v;
  }
}

int main() {
  int n;
  cin >> n;

  long long m_value;
  cin >> m_value;
  ll m = (ll)m_value;

  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    long long price;
    cin >> price;
    p[i] = (ll)price;
  }

  ll v = binary_search(
      m,
      [&](const ll &x) {
        ll s = 0LL;
        for (ll &price : p) {
          ll k = ((x / price) + 1LL) / 2LL;
          s += k * k * price;
        }
        return s;
      },
      m);

  ll cnt = 0LL;
  ll s = 0LL;
  for (ll &price : p) {
    ll k = ((v / price) + 1LL) / 2LL;
    s += k * k * price;
    cnt += k;
  }

  cnt += (m - s) / (v + 1);
  long long ans = (long long)cnt;
  cout << ans << endl;

  return 0;
}
