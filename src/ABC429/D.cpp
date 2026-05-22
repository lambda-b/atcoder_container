#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

/**
 * 方針は合っていると思うが、サンプルケースだけOKで他がWA。
 */
int main() {
  int n, c;
  ll m;
  cin >> n >> m >> c;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll mm = *min_element(a.begin(), a.end());

  map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    ll x = a[i] - mm;
    cnt[x == 0 ? m : x] += 1;
  }

  ll base_key = 0LL;
  ll base_value = 0LL;
  ll ans = 0LL;
  auto it0 = cnt.begin();
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    auto &[key, value] = *it;
    for (auto it1 = it0;; ++it1 == cnt.end() ? it1 = cnt.begin() : it1) {
      auto &[key1, value1] = *it1;
      base_value += value1;
      if (base_value >= c) {
        ans += (key - base_key) * base_value;
        it0 = ++it1 == cnt.end() ? it1 = cnt.begin() : it1;
        break;
      }
    }
    base_key = key;
    base_value -= value;
  }
  cout << ans << endl;

  return 0;
}
