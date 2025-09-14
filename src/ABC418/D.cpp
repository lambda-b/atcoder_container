#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;

  bool b = true;
  int cnt_a = 0;
  int cnt_b = 0;
  for (auto &c : t) {
    if (c == '0') {
      b = !b;
    }
    if (b) {
      cnt_a += 1;
    } else {
      cnt_b += 1;
    }
  }

  ll ans = 0LL;
  for (auto &c : t) {
    ans += cnt_a;
    if (c == '1') {
      cnt_a -= 1;
    } else {
      cnt_b -= 1;
      swap(cnt_a, cnt_b);
    }
  }

  cout << ans << endl;

  return 0;
}
