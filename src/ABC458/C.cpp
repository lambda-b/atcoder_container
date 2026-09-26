#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'C') {
      ans += min(i + 1, n - i);
    }
  }
  cout << ans << endl;

  return 0;
}
