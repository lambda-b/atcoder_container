#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  ll cnt = 0LL;
  ll m = 0LL;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      m += i - cnt;
      cnt += 1;
    }
  }

  ll ans = m;
  ll c = 0LL;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      c += 1LL;
    } else {
      m += 2LL * c - cnt;
      ans = min(ans, m);
    }
  }

  cout << ans << endl;

  return 0;
}
