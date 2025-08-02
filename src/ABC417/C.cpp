#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, ll> mp;
  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    ans += mp[i - a[i]];
    mp[i + a[i]] += 1LL;
  }

  cout << ans << endl;

  return 0;
}
