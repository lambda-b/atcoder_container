#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0LL;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] >= n - i) {
      ans = max(n - i, ans);
    }
  }
  cout << ans << endl;

  return 0;
}
